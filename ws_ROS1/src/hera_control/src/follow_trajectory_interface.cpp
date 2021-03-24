//
// Created by lijiaqian on 12/9/20.
//
#include <ros/ros.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <actionlib/client/simple_action_client.h>
#include <memory>
#include <trajectory_msgs/JointTrajectory.h>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_state/robot_state.h>
#include <moveit/robot_trajectory/robot_trajectory.h>
#include <moveit/trajectory_processing/iterative_spline_parameterization.h>
#include <moveit_msgs/RobotTrajectory.h>
#include <moveit/move_group_interface/move_group_interface.h>


typedef actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> TrajClient;
class TrajectoryInterface
{
private:
    ros::NodeHandle nh;
    std::shared_ptr<TrajClient> client;
    ros::Subscriber trajectory_sub;
    moveit::core::RobotModelPtr robotModel_;
public:
    TrajectoryInterface(moveit::core::RobotModelPtr robotModelPtr);
    void trajectory_callback(trajectory_msgs::JointTrajectoryConstPtr msg);

};

TrajectoryInterface::TrajectoryInterface(moveit::core::RobotModelPtr robotModelPtr): robotModel_(robotModelPtr)
{
    client = std::make_shared<TrajClient>("follow_joint_trajectory", true);
    trajectory_sub = nh.subscribe("/out/joint_trajectory", 50, &TrajectoryInterface::trajectory_callback,this);
}



void TrajectoryInterface::trajectory_callback(trajectory_msgs::JointTrajectoryConstPtr msg)
{
    // 1.subcribe the topic in the type of trajectory trajectory_msgs::JointTrajectory
    trajectory_msgs::JointTrajectory trajectory = *msg;
    control_msgs::FollowJointTrajectoryGoal goal;
    trajectory.header.stamp = ros::Time::now()+ros::Duration(0.05);

    // Bug: the first waypoints of trajectory is empty
    trajectory.points.erase(trajectory.points.begin()+1);

    for (int i = 1; i < trajectory.points.size(); ++i)
    {
        trajectory.points[i].time_from_start = ros::Duration(i * 0.3);
    }

    goal.trajectory = trajectory;
    client->sendGoal(goal);

}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "follow_trajectory_interface");

    const std::string PLANNING_GROUP = "panda_arm";
    robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
    robot_state::RobotModelPtr robot_model = robot_model_loader.getModel();

    TrajectoryInterface trajectoryInterface(robot_model);
    ros::spin();
    return 0;
}

