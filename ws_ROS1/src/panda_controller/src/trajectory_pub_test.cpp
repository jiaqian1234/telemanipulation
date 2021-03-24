//
// Created by lijiaqian on 12/9/20.
//
#include <moveit/move_group_interface/move_group_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>
#include <moveit/trajectory_processing/iterative_time_parameterization.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sample_timed_cartesian");
    ros::NodeHandle node_handle;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    // wait for robot init of robot_state_initializer
    ROS_INFO_NAMED("constraint_planner", ">>>>>>>>>>>>>>>>> WAITING FOR ROBOT INIT <<<<<<<<<<<<<<<<");
    ros::Duration(5.0).sleep();
    ROS_INFO_NAMED("constraint_planner", ">>>>>>>>>>>>>>>>> WAKING UP AFTER INIT <<<<<<<<<<<<<<<<");

    // Visualization Setup
    namespace rvt = rviz_visual_tools;
    moveit_visual_tools::MoveItVisualTools visual_tools("panda_link0");
    visual_tools.deleteAllMarkers();
    visual_tools.loadRemoteControl();

    Eigen::Isometry3d text_pose = Eigen::Isometry3d::Identity();
    text_pose.translation().z() = 1.75;
    visual_tools.publishText(text_pose, "Sample timed cartesian planner node", rvt::WHITE, rvt::XLARGE);

    // Batch publishing is used to reduce the number of messages being sent to RViz for large visualizations
    visual_tools.trigger();

    moveit::planning_interface::MoveGroupInterface group("panda_arm");

    ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
    moveit_msgs::DisplayTrajectory display_trajectory;

    moveit::planning_interface::MoveGroupInterface::Plan plan;
    group.setStartStateToCurrentState();

    std::vector<geometry_msgs::Pose> waypoints;

    // initial pose of the robot
    geometry_msgs::Pose start_pose = group.getCurrentPose().pose;

    // waypoints of the target trajectory
    geometry_msgs::Pose target_pose_1 = group.getCurrentPose().pose;
    geometry_msgs::Pose target_pose_2 = group.getCurrentPose().pose;
    geometry_msgs::Pose target_pose_3 = group.getCurrentPose().pose;

    target_pose_1.position.z = start_pose.position.z - 0.4;
    target_pose_1.position.y = start_pose.position.y;
    target_pose_1.position.x = start_pose.position.x + 0.5;
    waypoints.push_back(target_pose_1);

    target_pose_2.position.z = 0.6;
    target_pose_2.position.y = -0.6;
    target_pose_2.position.x = 0;
    waypoints.push_back(target_pose_2);

    target_pose_3.position.z = 0.6;
    target_pose_3.position.y = -0.032;
    target_pose_3.position.x = -0.6;
    waypoints.push_back(target_pose_3);

    moveit_msgs::RobotTrajectory trajectory_msg;
    group.setPlanningTime(10.0);

    double fraction = group.computeCartesianPath(waypoints,0.01,0.0,trajectory_msg, false);

    // The trajectory needs to be modified so it will include velocities as well.
    // Create a RobotTrajectory object
    robot_trajectory::RobotTrajectory rt(group.getCurrentState()->getRobotModel(), "panda_arm");

    // Get a RobotTrajectory from trajectory
    rt.setRobotTrajectoryMsg(*group.getCurrentState(), trajectory_msg);

    // Create a IterativeParabolicTimeParameterization object
    trajectory_processing::IterativeParabolicTimeParameterization iptp;
    // Compute computeTimeStamps
    bool success = iptp.computeTimeStamps(rt);
    ROS_INFO("Computed time stamp %s",success?"SUCCEDED":"FAILED");
    rt.getRobotTrajectoryMsg(trajectory_msg);

    // adjust velocities, accelerations and time_from_start
    for(int i = 0; i < trajectory_msg.joint_trajectory.points.size(); i++)
    {
        trajectory_msg.joint_trajectory.points[i].time_from_start.operator*=(2);
        for(int j = 0; j < trajectory_msg.joint_trajectory.points.at(i).velocities.size(); j++)
        {
            if(trajectory_msg.joint_trajectory.points.at(i).velocities.at(j) != 0.0){
                trajectory_msg.joint_trajectory.points.at(i).velocities.at(j) /= 2;
            }
        }

        for(int j = 0; j < trajectory_msg.joint_trajectory.points.at(i).accelerations.size(); j++)
        {
            trajectory_msg.joint_trajectory.points.at(i).accelerations.at(j) =
                    sqrt(std::abs(trajectory_msg.joint_trajectory.points.at(i).accelerations.at(j)));
        }
    }

    plan.trajectory_ = trajectory_msg;
    ROS_INFO("Visualizing plan 4 (cartesian path) (%.2f%% acheived)",fraction * 100.0);

    group.execute(plan);

    ros::shutdown();
    return 0;
}

