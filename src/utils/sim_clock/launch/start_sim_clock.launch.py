from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # Declare arguments to make the launch file configurable
    declare_freq_arg = DeclareLaunchArgument(
        'freq',
        default_value='100.0',
        description='The real-world frequency to publish the /clock topic (Hz)'
    )
    
    declare_rate_arg = DeclareLaunchArgument(
        'rate',
        default_value='1.0',
        description='The initial simulation speed factor (1.0 = real-time)'
    )
    
    declare_paused_arg = DeclareLaunchArgument(
        'paused',
        default_value='false',
        description='Whether to start the simulation in a paused state'
    )

    declare_start_time_arg = DeclareLaunchArgument(
        'start_time',
        default_value='0.0',
        description='The initial simulation time in seconds'
    )

    # The sim_clock node
    sim_clock_node = Node(
        package='sim_clock',
        executable='sim_clock_node',
        name='sim_clock', # You can rename the node at launch time
        output='screen',
        parameters=[{
            # IMPORTANT: This tells all nodes that use this parameter to use sim time
            'use_sim_time': True 
        }, {
            # Pass launch arguments to the node's parameters
            'publish_frequency': LaunchConfiguration('freq'),
            'initial_rate': LaunchConfiguration('rate'),
            'start_paused': LaunchConfiguration('paused'),
            'initial_sim_time': LaunchConfiguration('start_time'),
        }]
    )

    return LaunchDescription([
        declare_freq_arg,
        declare_rate_arg,
        declare_paused_arg,
        declare_start_time_arg,
        sim_clock_node,
    ])