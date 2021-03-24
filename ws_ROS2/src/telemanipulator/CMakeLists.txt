cmake_minimum_required(VERSION 3.5)
project(telemanipulator)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(control_msgs REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(pivot_msg REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
  rclcpp
  rclcpp_components
  std_msgs
  std_srvs
  control_msgs
  moveit_msgs
  moveit_ros_planning_interface
)


include_directories(
  include
)

set(KEY_SERVO_CONVERT_NAME key_to_servo)
add_library(key_to_servo SHARED src/key_to_servo.cpp)
ament_target_dependencies(${KEY_SERVO_CONVERT_NAME} ${THIS_PACKAGE_INCLUDE_DEPENDS})
rclcpp_components_register_nodes(${KEY_SERVO_CONVERT_NAME} "moveit_servo::KeyToServoPub")

add_library(keyboard_as_pivot_input SHARED src/keyboard_as_pivot_input.cpp)
ament_target_dependencies(keyboard_as_pivot_input ${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_target_dependencies(keyboard_as_pivot_input pivot_msg)
rclcpp_components_register_nodes(keyboard_as_pivot_input "telemanipulator::PivotInput")

add_library(pivot_to_twist SHARED src/pivot_to_twiststamped.cpp)
ament_target_dependencies(pivot_to_twist ${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_target_dependencies(pivot_to_twist pivot_msg)
rclcpp_components_register_nodes(pivot_to_twist "telemanipulator::PivotToTwist")

add_library(pivot_transform src/homogeneous_matrix.cpp src/pivot_transformation.cpp)
target_link_libraries(pivot_to_twist pivot_transform)


install(
  TARGETS
    ${KEY_SERVO_CONVERT_NAME} keyboard_as_pivot_input pivot_to_twist pivot_transform
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})
install(DIRECTORY config DESTINATION share/${PROJECT_NAME})
install(DIRECTORY msg DESTINATION share/${PROJECT_NAME})

ament_package()
