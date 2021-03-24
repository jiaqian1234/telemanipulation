//
// Created by lijiaqian on 1/5/21.
//
#include <controller_manager_msgs/SwitchController.h>
#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <controller_manager/controller_loader_interface.h>
#include <controller_manager/controller_loader.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "robot_state_initializer_node");
    ros::NodeHandle node_handle;

    std::vector<double> panda_ready_state{0.4, 0.2, 0.3, -1.5, 0, 1.5, 0.5};

    // define variables
    std::string joint_position_command_topic{"/panda/position_controller/command"},
            controller_manager_switch_topic{"/panda/controller_manager/switch_controller"};
    ros::ServiceClient switch_controller_client =
            node_handle.serviceClient<controller_manager_msgs::SwitchController>(controller_manager_switch_topic);
    ros::Publisher joint_position_publisher =
            node_handle.advertise<std_msgs::Float64MultiArray>(joint_position_command_topic, 100);

    // sleep for 2 seconds in order to make sure that the system is up and running
    ros::Duration(2.0).sleep();

    // 0. load position controller


    // 1. switch from default joint trajectory controller to position controller
    std::string trajectory_controller{"trajectory_controller"}, position_controller{"position_controller"};
    std::vector<std::string> stop_controllers{trajectory_controller};
    std::vector<std::string> start_controllers{position_controller};

    controller_manager_msgs::SwitchController srv_switch_controller;
    srv_switch_controller.request.stop_controllers = stop_controllers;
    srv_switch_controller.request.start_controllers = start_controllers;
    srv_switch_controller.request.strictness = controller_manager_msgs::SwitchControllerRequest::BEST_EFFORT;

    // housekeeping for logging
    std::ostringstream stream_start_controllers, stream_stop_controllers;
    for (const auto &elem : start_controllers) {
        stream_start_controllers << elem << ", ";
    }
    for (const auto &elem : stop_controllers) {
        stream_stop_controllers << elem << ", ";
    }

    if (switch_controller_client.call(srv_switch_controller)) {
        ROS_WARN_STREAM("Success switching controllers from " << stream_stop_controllers.str() << " to "
                                                              << stream_start_controllers.str());
    } else {
        ROS_WARN_STREAM("Error switching controllers from " << stream_stop_controllers.str() << " to "
                                                            << stream_start_controllers.str());
        return -1;
    }

    // 2. publish the desired joint position to the custom controller
    std_msgs::Float64MultiArray command_msg;
    command_msg.data = panda_ready_state;
    joint_position_publisher.publish(command_msg);

    // sleep for 5 seconds in order to make sure that the controller finishes moving the robot
    ros::Duration(5.0).sleep();

    // 3. Restore default controllers
    std::swap(stop_controllers, start_controllers);
    srv_switch_controller.request.stop_controllers = stop_controllers;
    srv_switch_controller.request.start_controllers = start_controllers;

    if (switch_controller_client.call(srv_switch_controller)) {
        ROS_WARN_STREAM("Success switching controllers from " << stream_stop_controllers.str() << " to "
                                                              << stream_start_controllers.str());
    } else {
        ROS_WARN_STREAM("Error switching controllers from " << stream_stop_controllers.str() << " to "
                                                            << stream_start_controllers.str());
        return -1;
    }

    ros::spin();
    return 0;
}
