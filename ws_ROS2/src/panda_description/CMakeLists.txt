cmake_minimum_required(VERSION 3.5)
project(panda_description)
find_package(ament_cmake REQUIRED)
ament_package()
install(DIRECTORY meshes urdf urdf2 config DESTINATION share/${PROJECT_NAME})
