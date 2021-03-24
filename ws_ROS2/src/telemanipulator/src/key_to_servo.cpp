#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <control_msgs/msg/joint_jog.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <moveit_msgs/msg/planning_scene.hpp>
#include <thread>


// We'll just set up parameters here
const std::string KEY_TOPIC = "/cmd_vel";
const std::string TWIST_TOPIC = "/servo_server/delta_twist_cmds";
//const std::string JOINT_TOPIC = "/servo_server/delta_joint_cmds";
const size_t ROS_QUEUE_SIZE = 10;
const std::string EEF_FRAME_ID = "panda_link_ee";
const std::string BASE_FRAME_ID = "panda_link_0";

static const rclcpp::Logger LOGGER = rclcpp::get_logger("telemanipulator.key_to_servo");

namespace moveit_servo
{
class KeyToServoPub : public rclcpp::Node
{
public:
  KeyToServoPub(const rclcpp::NodeOptions& options)
    : Node("key_to_twist_publisher", options), frame_to_publish_(BASE_FRAME_ID)
  {
    // Setup pub/sub
    key_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
        KEY_TOPIC, ROS_QUEUE_SIZE, std::bind(&KeyToServoPub::keyCB, this, std::placeholders::_1));

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

  }


  void keyCB(const geometry_msgs::msg::Twist::SharedPtr msg)
  {
    // Create the messages we might publish
    auto twist_msg = std::make_unique<geometry_msgs::msg::TwistStamped>();

    // Convert the key_board message to Twist and publish
      twist_msg->header.frame_id = frame_to_publish_;
      twist_msg->header.stamp = this->now();
      twist_msg->twist = *msg;
      twist_pub_->publish(std::move(twist_msg));
  }

private:
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr key_sub_;
  rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr twist_pub_;
  //rclcpp::Publisher<control_msgs::msg::JointJog>::SharedPtr joint_pub_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr servo_start_client_;
  std::string frame_to_publish_;

};  // class KeyToServoPub

}  // namespace moveit_servo

// Register the component with class_loader
#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(moveit_servo::KeyToServoPub)

