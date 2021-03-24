# telemanipulation
Control the end effctot of robot in real-time based on moveit/servo 
- [telemanipulation](#telemanipulation)
  * [Introduction](#introduction)
    + [Control simulated in the RVIZ](#control-simulated-in-the-rviz)
    + [Control w.r.t cartesian coordinate](#control-wrt-cartesian-coordinate)
    + [Control w.r.t pivot coordinate](#control-wrt-pivot-coordinate)
  * [Usage](#usage)
    + [Control simulated in the RVIZ](#control-simulated-in-the-rviz-1)
    + [Control w.r.t cartesian coordinate](#control-wrt-cartesian-coordinate-1)
    + [Control w.r.t pivot coordinate](#control-wrt-pivot-coordinate-1)
  * [Installation](#installation)
  * [Prerequisites](#prerequisites)
    + [Install ros foxy](#install-ros-foxy)
    + [Install moveit 2](#install-moveit-2)
    + [Insstall ros noetix](#insstall-ros-noetix)

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>


## Introduction

### Control simulated in the RVIZ ###
The keyboard serves as input giving the velocity of the end effctor of robot w.r.t cartersian coordinaten. The moveit servo module transforms the input into the joint trajectories and sends them to the controller, which controls the simulation of robot in the RVIZ.
![rosgraph_o](https://user-images.githubusercontent.com/65122353/112300976-c18c1480-8c99-11eb-9a8a-8fb266858730.png)
Demo
https://user-images.githubusercontent.com/65122353/112301533-568f0d80-8c9a-11eb-8d4c-3c2d2145ee61.mp4

### Control w.r.t cartesian coordinate ###
The simulation occurs in the Gazebo. The movei/servo module is developed unter ROS2, while the controller adapt to the Gazebo is based on the ROS1. Thus a bridge to connect ROS1 and ROS2 is necessary.  
rosgraph_ROS1
![rosgraph_ros1](https://user-images.githubusercontent.com/65122353/112305114-9bb53e80-8c9e-11eb-9b2f-a899b46732f5.png)
rosgragh_ROS2
![rosgraph](https://user-images.githubusercontent.com/65122353/112305160-a96ac400-8c9e-11eb-98e6-c434fdece7dc.png)
Demo
https://user-images.githubusercontent.com/65122353/112339433-f01ce600-8cbf-11eb-8392-9a188ec65aee.mp4

### Control w.r.t pivot coordinate ###
The simulation occurs also in the Gazebo based on ROS1 and ROS2. This time the input is in the form of a four elements vector (pan->pitch, tilt->yaw, spin->roll, depth->insertion). The end effector of the robot moves w.r.t reference coordinate at the pivot point.
![The-forceps-working-through-a-restrained-pivot-point-was-controlled-by-five-axes](https://user-images.githubusercontent.com/65122353/112367237-f8821a80-8cd9-11eb-8733-afe5e7066e31.png)

## Usage
### Control simulated in the RVIZ ###
```bash
source /opt/ros/noetic/setup.bash
source /telemanipulation/ws_ros2/devel/setup.bash
roslaunch telemanipulation controll_loop.launch 
```

### Control w.r.t cartesian coordinate ###
```bash
cd catmux
tmux
catmux_create_session control_cartsian_ROS1_2.yaml
```

### Control w.r.t pivot coordinate ###
```bash
cd catmux
tmux
catmux_create_session control_pivot_ROS1_2.yaml
```

## Installation
If you made sure all the Prerequisites are satisfied, the installation of this stack should be quite painless.
```bash
cd ~/ws_ros1
source /opt/ros/noetic/setup.bash
catkin_make
cd ~/ws_ros2
source /opt/ros/foxy/setup.bash
colcon build
```
## Prerequisites
The installation is based on Ubuntu 20.04
### Install ros foxy ###
https://docs.ros.org/en/foxy/Installation/Linux-Install-Binary.html
### Install moveit 2 ###
https://moveit.ros.org/install-moveit2/source/
### Insstall ros noetix ###
http://wiki.ros.org/noetic/Installation



