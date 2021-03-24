# telemanipulation
Control the end effctot of robot in real-time based on moveit/servo 
1. Introduction
   1. Control simulated in the RVIZ
   1. Control based the cartesian coordinate
   1. Control based the pivot coordinate
1. Usage
1. Installation
1. Prerequisites

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
