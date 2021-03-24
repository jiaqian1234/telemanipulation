//
// Created by lijiaqian on 1/20/21.
//

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <thread>
#include "pivot_msg/msg/pivot.hpp"

// We'll just set up parameters here
const std::string KEY_TOPIC = "/cmd_vel";
const std::string PIVOT_TOPIC = "/pivot";
const size_t ROS_QUEUE_SIZE = 10;
static const rclcpp::Logger LOGGER = rclcpp::get_logger("telemanipulator.key_to_servo");


namespace telemanipulator {
    class PivotInput : public rclcpp::Node {
    public:
        PivotInput(const rclcpp::NodeOptions &options)
                : Node("pivot_input", options) {
            // Setup pub/sub
            key_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
                    KEY_TOPIC, ROS_QUEUE_SIZE, std::bind(&PivotInput::keyCB, this, std::placeholders::_1));

            pivot_pub_ = this->create_publisher<pivot_msg::msg::Pivot>(PIVOT_TOPIC, ROS_QUEUE_SIZE);
        }


        void keyCB(const geometry_msgs::msg::Twist::SharedPtr msg) {
            // Create the messages we might publish
            auto pivot_msg = std::make_unique<pivot_msg::msg::Pivot>();
            pivot_msg->pan = msg->linear.x;
            pivot_msg->tilt = msg->linear.y;
            pivot_msg->spin = msg->linear.z;
            pivot_msg->depth = msg->angular.z;
            pivot_pub_->publish(std::move(pivot_msg));
        }

    private:
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr key_sub_;
        rclcpp::Publisher<pivot_msg::msg::Pivot>::SharedPtr pivot_pub_;

    };  // class PivotInput
}

// Register the component with class_loader
#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(telemanipulator::PivotInput)

