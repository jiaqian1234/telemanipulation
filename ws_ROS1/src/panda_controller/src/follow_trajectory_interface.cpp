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
    void trajectory_callback_2(trajectory_msgs::JointTrajectoryConstPtr msg);

};

TrajectoryInterface::TrajectoryInterface(moveit::core::RobotModelPtr robotModelPtr): robotModel_(robotModelPtr)
{
    client = std::make_shared<TrajClient>("follow_joint_trajectory", true);
    trajectory_sub = nh.subscribe("/out/joint_trajectory", 50, &TrajectoryInterface::trajectory_callback_2,this);
}

void TrajectoryInterface::trajectory_callback(trajectory_msgs::JointTrajectoryConstPtr msg)
{
    control_msgs::FollowJointTrajectoryGoal goal;
    goal.trajectory = *msg;
    goal.trajectory.header.stamp = ros::Time::now() + ros::Duration(5);
    goal.trajectory.header.frame_id = "panda_link_0";
    // goal.trajectory.points = msg->points;
    goal.trajectory.joint_names.clear();
    goal.trajectory.joint_names.push_back("panda_joint_1");
    goal.trajectory.joint_names.push_back("panda_joint_2");
    goal.trajectory.joint_names.push_back("panda_joint_3");
    goal.trajectory.joint_names.push_back("panda_joint_4");
    goal.trajectory.joint_names.push_back("panda_joint_5");
    goal.trajectory.joint_names.push_back("panda_joint_6");
    goal.trajectory.joint_names.push_back("panda_joint_7");

    client->sendGoal(goal);
}

void TrajectoryInterface::trajectory_callback_2(trajectory_msgs::JointTrajectoryConstPtr msg)
{
    // 1.subcribe the topic in the type of trajectory trajectory_msgs::JointTrajectory
    trajectory_msgs::JointTrajectory trajectory = *msg;
    control_msgs::FollowJointTrajectoryGoal goal;
    trajectory.header.stamp = ros::Time::now()+ros::Duration(0.05);
//    trajectory.header.frame_id = "panda_link_0";
//    trajectory.joint_names.clear();
//    trajectory.joint_names.push_back("panda_joint_1");
//    trajectory.joint_names.push_back("panda_joint_2");
//    trajectory.joint_names.push_back("panda_joint_3");
//    trajectory.joint_names.push_back("panda_joint_4");
//    trajectory.joint_names.push_back("panda_joint_5");
//    trajectory.joint_names.push_back("panda_joint_6");
//    trajectory.joint_names.push_back("panda_joint_7");
    // Bug: the first waypoints of trajectory is empty
    trajectory.points.erase(trajectory.points.begin()+1);
//
//    // 2.convert trajectory_msgs::JointTrajectory to robot_trajectory::RobotTrajectory, which can be use for time parameterizing
//    robot_trajectory::RobotTrajectory robotTrajectory(robotModel_, "panda_arm");
//    moveit::core::RobotState ref_state(robotModel_);
//    for(auto j=0 ; j< trajectory.joint_names.size(); j++)
//        ref_state.setJointPositions(trajectory.joint_names.at(j),&trajectory.points.at(0).positions.at(j));
//    //ref_state.printStateInfo();
//    robotTrajectory.setRobotTrajectoryMsg(ref_state, trajectory);
//
////    const moveit::core::RobotState& copy = ref_state;
////    robotTrajectory.clear();
////    std::size_t state_count = trajectory.points.size();
////    ros::Time last_time_stamp = trajectory.header.stamp;
////    ros::Time this_time_stamp = last_time_stamp;
//
////    for (std::size_t i = 0; i < state_count; i++) {
////        if(i==1) continue;
////        this_time_stamp = trajectory.header.stamp + trajectory.points[i].time_from_start;
////        moveit::core::RobotStatePtr st(new moveit::core::RobotState(copy));
////        st->setVariablePositions(trajectory.joint_names, trajectory.points[i].positions);
////        if (!trajectory.points[i].velocities.empty())
////            st->setVariableVelocities(trajectory.joint_names, trajectory.points[0].velocities);
////        if (!trajectory.points[i].accelerations.empty())
////            st->setVariableAccelerations(trajectory.joint_names, trajectory.points[0].accelerations);
////        if (!trajectory.points[i].effort.empty())
////            st->setVariableEffort(trajectory.joint_names, trajectory.points[0].effort);
////        robotTrajectory.addSuffixWayPoint(st, (this_time_stamp - last_time_stamp).toSec());
////        robotTrajectory.addSuffixWayPoint(st, ros::Duration(0,5).toSec());
////        last_time_stamp = this_time_stamp;
////    }
//
//
//    // 3.add time stamp
//    trajectory_processing::IterativeSplineParameterization splineParameterization;
//    bool success=false;
//    try{success = splineParameterization.computeTimeStamps(robotTrajectory);}
//    catch (const std::exception& e) {
//        std::cout << e.what();
//    }
//    if(!success) std::cout << "Time parameterization is not successful"<< std::endl;
//    else std::cout << "Time parameterization is successful" << std::endl;
//
//
//    moveit_msgs::RobotTrajectory trajectory_with_timestamp;
//    robotTrajectory.getRobotTrajectoryMsg(trajectory_with_timestamp);
//    goal.trajectory = trajectory_with_timestamp.joint_trajectory;
//    client->sendGoal(goal);
//
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

