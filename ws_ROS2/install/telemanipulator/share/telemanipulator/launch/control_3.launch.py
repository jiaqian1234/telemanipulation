import os
import yaml
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

def load_file(package_name, file_path):
    package_path = get_package_share_directory(package_name)
    absolute_file_path = os.path.join(package_path, file_path)

    try:
        with open(absolute_file_path, 'r') as file:
            return file.read()
    except EnvironmentError: # parent of IOError, OSError *and* WindowsError where available
        return None

def load_yaml(package_name, file_path):
    package_path = get_package_share_directory(package_name)
    absolute_file_path = os.path.join(package_path, file_path)

    try:
        with open(absolute_file_path, 'r') as file:
            return yaml.safe_load(file)
    except EnvironmentError: # parent of IOError, OSError *and* WindowsError where available
        return None

def generate_launch_description():
    # Get parameters for the Servo node
    servo_yaml = load_yaml('telemanipulator', 'config/panda_simulated_config.yaml')
    servo_params = { 'moveit_servo' : servo_yaml }

    # Get URDF and SRDF
    robot_description_config = load_file('panda_description', 'urdf/panda.urdf')
    robot_description = {'robot_description' : robot_description_config}

    #robot_description_semantic_config = load_file('moveit_resources_panda_moveit_config', 'config/panda.srdf')
    robot_description_semantic_config = load_file('panda_description', 'urdf/panda.srdf')
    robot_description_semantic = {'robot_description_semantic' : robot_description_semantic_config}

    container = ComposableNodeContainer(
            name='moveit_servo_demo_container_2',
            namespace='/',
            package='rclcpp_components',
            executable='component_container',
            composable_node_descriptions=[
                ComposableNode(
                    package='telemanipulator',
                    plugin='telemanipulator::PivotInput',
                    name='PivotInput'),
                ComposableNode(
                    package='moveit_servo',
                    plugin='moveit_servo::ServoServer',
                    name='servo_server',
                    parameters=[servo_params, robot_description, robot_description_semantic],
                    extra_arguments=[{'use_intra_process_comms' : True}]),
                ComposableNode(
                    package='telemanipulator',
                    plugin='telemanipulator::PivotToTwist',
                    name='pivotToTwist',
                    parameters=[robot_description, robot_description_semantic],
                    extra_arguments=[{'use_intra_process_comms' : True}],
                ),
            ],
            output='screen',
    )



    
    return LaunchDescription([container])

