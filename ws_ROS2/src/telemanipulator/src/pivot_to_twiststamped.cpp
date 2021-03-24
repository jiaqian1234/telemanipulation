//
// Created by lijiaqian on 1/20/21.
//
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <thread>
#include <fstream>

// moveit
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>


// for pivot transform
#include "pivot_msg/msg/pivot.hpp"
#include "pivot_transformation.h"

#include "homogeneous_matrix.h"
#include "pivot_transformation.h"


// We'll just set up parameters here
const std::string PIVOT_TOPIC = "/pivot";
const std::string TWIST_TOPIC = "/servo_server/delta_twist_cmds";
const size_t ROS_QUEUE_SIZE = 10;
const std::string EEF_FRAME_ID = "panda_link_ee";
const std::string BASE_FRAME_ID = "panda_link_0";
static const std::string PLANNING_GROUP = "panda_arm";
static const rclcpp::Logger LOGGER = rclcpp::get_logger("telemanipulator::PivotToTwist");


struct Quaternion {
    double w, x, y, z;
};

struct EulerAngles {
    double roll, pitch, yaw;
};

EulerAngles ToEulerAngles(Quaternion q) {
    EulerAngles angles;

    // roll (x-axis rotation)
    double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
    double cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
    angles.roll = std::atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = 2 * (q.w * q.y - q.z * q.x);
    if (std::abs(sinp) >= 1)
        angles.pitch = std::copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        angles.pitch = std::asin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
    double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
    angles.yaw = std::atan2(siny_cosp, cosy_cosp);

    return angles;
}

template <std::size_t N>
void array_print(std::array<float, N> &array, std::string name){
    std::cout << name << ": ";
    for(unsigned int i=0; i<array.size(); i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

namespace telemanipulator
{
    class PivotToTwist : public rclcpp::Node
    {
    public:
        PivotToTwist(const rclcpp::NodeOptions& options)
                : Node("pivot_to_twist", options), frame_to_publish_(BASE_FRAME_ID)
        {
            // Setup pub/sub
            pivot_sub_ = this->create_subscription<pivot_msg::msg::Pivot>(
                    PIVOT_TOPIC, ROS_QUEUE_SIZE, std::bind(&PivotToTwist::pivotCB, this, std::placeholders::_1));

            twist_pub_ = this->create_publisher<geometry_msgs::msg::TwistStamped>(TWIST_TOPIC, ROS_QUEUE_SIZE);


            // Create a service client to start the ServoServer
            servo_start_client_ = this->create_client<std_srvs::srv::Trigger>("/servo_server/start_servo");
            if (servo_start_client_->wait_for_service(std::chrono::seconds(10)))
            {
                servo_start_client_->async_send_request(std::make_shared<std_srvs::srv::Trigger::Request>());
                RCLCPP_INFO(LOGGER, "service is available");
            }
            else
            {
                RCLCPP_WARN(LOGGER, "service not available, waiting again...");
            }
            result_file.open("result.dat");

        }


        void pivotCB(const pivot_msg::msg::Pivot::SharedPtr msg)
        {
            if (first_message){
                tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
                planning_scene_monitor_ = std::make_shared<planning_scene_monitor::PlanningSceneMonitor>(
                        this->shared_from_this(), robot_description_name, tf_buffer_, "planning_scene_monitor_pivot");
                planning_scene_monitor_->startStateMonitor("/panda/joint_states");
                first_message = false;
                return;
            }

            if (second_message){
                moveit::core::RobotStatePtr robotStatePtr = planning_scene_monitor_->getStateMonitor()->getCurrentState();
                ee_position = robotStatePtr->getGlobalLinkTransform(EEF_FRAME_ID).translation();
                ee_orientation = robotStatePtr->getGlobalLinkTransform(EEF_FRAME_ID).rotation().eulerAngles(0,1,2);// roll,pitch, yaw,
                for (unsigned i=0; i<3; i++){
                    pivot_point_position[i] = ee_position(i);}
                for (unsigned i=0; i<3; i++){
                    pivot_point_orientation[i] = ee_orientation(i);}
                pivotTransform.updateTrocarPoseAbsolute(pivot_point_position, pivot_point_orientation);
                second_message = false;
            }
            period_ = 0.03;
            pan_ = msg->pan; tilt_ = msg->tilt; spin_ = msg->spin; depth_ = msg->depth;
            timer_ =shared_from_this()->create_wall_timer(std::chrono::duration<double>(period_),
                                                               std::bind(&PivotToTwist::twist_pub, this));
        }

        void twist_pub(){
            moveit::core::RobotStatePtr robotStatePtr = planning_scene_monitor_->getStateMonitor()->getCurrentState();
            ee_position = robotStatePtr->getGlobalLinkTransform(EEF_FRAME_ID).translation();
            ee_orientation = robotStatePtr->getGlobalLinkTransform(EEF_FRAME_ID).rotation().eulerAngles(0,1,2);// roll,pitch, yaw,
            // 1. msg(delta span,tilt,spin,depth) -> pivot pose
            pivotTransform.updateTransformationRelative(pan_*period_, tilt_*period_, spin_*period_, depth_*period_);
            RotationMatrix pivot_rotate = pivotTransform.getRotationMatrix();
            Eigen::Matrix3d Rotation;
            //std::cout << "rotate_matrix" << std::endl;
            for (unsigned int i=0; i<3; i++){
                for (unsigned int j=0; j<3; j++){
                    Rotation(i, j) = pivot_rotate[i][j];
                    //std::cout << Rotation(i, j) << " ";
                }
            }
            //std::cout << std::endl;
            Eigen::Vector3d eulerAngles = Rotation.eulerAngles(0,1,2);
//            Quaternion new_quaternion;
//            new_quaternion.x = pivotTransform.getPivotPose()[3];
//            new_quaternion.y = pivotTransform.getPivotPose()[4];
//            new_quaternion.z = pivotTransform.getPivotPose()[5];
//            new_quaternion.w = pivotTransform.getPivotPose()[6];
////            EulerAngles eulerAngles = ToEulerAngles(new_quaternion);
//            Eigen::Quaterniond quaterniond(new_quaternion.w, new_quaternion.x, new_quaternion.y, new_quaternion.z);
//            Eigen::Vector3d eulerAngles = quaterniond.matrix().eulerAngles(0, 1, 2);

            std::array<float, 3> translation = pivotTransform.getTranslationVector();

            ////***********************************************************************////
            bool debug = true;
            count++;
            if(debug&&(count%10==1)){
                write_result(eulerAngles, result_file);

                array_print(translation, "soll_position");
                std::cout << " ist_position" << std::endl << ee_position << std::endl;
//                std::cout << "soll_orientation : " <<  eulerAngles.roll << " "<< eulerAngles.pitch <<" " << eulerAngles.yaw <<std::endl;
                std::cout << "soll_orientation " <<  eulerAngles[0] << " "<< eulerAngles[1]<<" " << eulerAngles[2] <<std::endl;
                std::cout << " ist_orientation" << std::endl << ee_orientation << std::endl;


                std::array<float, 4> PivotState = pivotTransform.getPivotState();
                std::array<float, 7> PivotPose = pivotTransform.getPivotPose();
                std::array<float, 6> TrocarState = pivotTransform.getTrocarState();
                std::array<float, 7> TrocarPose = pivotTransform.getTrocarPose();

                array_print(TrocarState, "TrocarState");
                array_print(TrocarPose, "TrocarPose");
                array_print(PivotState, "PivotState");
                array_print(PivotPose, "PivotPose");

                std::cout << "////***********************************************************************////" <<std::endl;
            }
            ////***************************************************************************////

            // 2. calculate delta x,y,z, delta phi_x,phi_y,phi_z as twist
            auto twist_msg = std::make_unique<geometry_msgs::msg::TwistStamped>();
            twist_msg->twist.linear.x = (translation[0] - ee_position[0])/period_;
            twist_msg->twist.linear.y = (translation[1] - ee_position[1])/period_;
            twist_msg->twist.linear.z = (translation[2] - ee_position[2])/period_;

//            twist_msg->twist.angular.x = calculate_angle(eulerAngles.roll, ee_orientation[0])/period_;
//            twist_msg->twist.angular.y = calculate_angle(eulerAngles.pitch, ee_orientation[1])/period_;
//            twist_msg->twist.angular.z = calculate_angle(eulerAngles.yaw, ee_orientation[2])/period_;
            twist_msg->twist.angular.x = calculate_angle(eulerAngles[0], ee_orientation[0])/period_;
            twist_msg->twist.angular.y = calculate_angle(eulerAngles[1], ee_orientation[1])/period_;
            twist_msg->twist.angular.z = calculate_angle(eulerAngles[2], ee_orientation[2])/period_;


            // 3. Create the messages we might publish
            twist_msg->header.frame_id = frame_to_publish_;
            twist_msg->header.stamp = this->now();
            twist_pub_->publish(std::move(twist_msg));
        }

        double calculate_angle(double angle_1, double angle_2){
            if (std::abs(angle_1-M_PI)<0.5 && std::abs(angle_2+M_PI)<0.5) angle_2 = angle_2 + 2*M_PI;
            else if (std::abs(angle_2-M_PI)<0.5 && std::abs(angle_1+M_PI)<0.5) angle_1 = angle_1 + 2*M_PI;
            else if(angle_1<0 && angle_2<0) return angle_2-angle_1;
            return angle_1 - angle_2;
        }

        void write_result(Eigen::Vector3d& soll_orientation, std::ofstream& file_name){
            if(file_name){
                file_name << soll_orientation[0] << " " << soll_orientation[1] << " " << soll_orientation[2] << " " << std::endl;
            }
        }
        void write_result(EulerAngles& soll_orientation, std::ofstream& file_name){
            if(file_name){
                file_name << soll_orientation.roll << " " << soll_orientation.pitch << " " << soll_orientation.yaw << " " << std::endl;
            }
        }

    private:
        rclcpp::Subscription<pivot_msg::msg::Pivot>::SharedPtr pivot_sub_;
        rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr twist_pub_;
        rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr servo_start_client_;
        std::string frame_to_publish_;

        std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
        std::shared_ptr<planning_scene_monitor::PlanningSceneMonitor> planning_scene_monitor_;
        std::string robot_description_name = "robot_description";
        Eigen::Vector3d ee_position;
        Eigen::Vector3d ee_orientation;

        std::array<float, 3> pivot_point_position;
        std::array<float, 3> pivot_point_orientation;
        bool first_message = true;
        bool second_message = true;
        PivotTransform pivotTransform; //is_degree set to false
        double period_;
        double pan_, tilt_, spin_, depth_;
        rclcpp::TimerBase::SharedPtr timer_;

        int count=0;
        std::ofstream result_file;


    };  // class PivotToTwist

}  // namespace telemanipulator

// Register the component with class_loader
#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(telemanipulator::PivotToTwist)


