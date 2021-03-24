cmake_minimum_required(VERSION 2.8.3)
project(hera_control)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  control_msgs
  actionlib
  controller_manager
  controller_manager_msgs
  moveit_core
  trajectory_msgs
  moveit_ros_planning
  moveit_ros_planning_interface
  moveit_visual_tools
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES rrbot_control
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(robot_state_initializer_node src/robot_state_initializer_node.cpp)
add_executable(follow_trajectory_interface_node src/follow_trajectory_interface.cpp)

target_link_libraries(robot_state_initializer_node ${catkin_LIBRARIES})
target_link_libraries(follow_trajectory_interface_node ${catkin_LIBRARIES})


