import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import PushRosNamespace, Node
from ament_index_python.packages import get_package_share_directory
from launch.conditions import IfCondition

def generate_launch_description():
    """
    This launch file starts the simulation for a single fixed-wing UAV.
    It can optionally include its corresponding visualization components.
    """
    fw_plane_pkg_dir = get_package_share_directory('fw_plane')

    # Define the path to the URDF file.
    urdf_path = os.path.join(fw_plane_pkg_dir, 'model', 'plane.urdf')
    with open(urdf_path, 'r') as f:
        robot_description_content = f.read()
    
    use_sim_time_arg = DeclareLaunchArgument('use_sim_time', default_value='true')
    namespace_arg = DeclareLaunchArgument('namespace', default_value='fw0')
    x_arg = DeclareLaunchArgument('x', default_value='0.0', description='Initial North position (m)')
    y_arg = DeclareLaunchArgument('y', default_value='0.0', description='Initial East position (m)')
    z_arg = DeclareLaunchArgument('z', default_value='-100.0', description='Initial Down position (m)')
    roll_arg = DeclareLaunchArgument('roll', default_value='0.0', description='Initial roll angle (rad)')
    pitch_arg = DeclareLaunchArgument('pitch', default_value='0.0', description='Initial pitch angle (rad)')
    yaw_arg = DeclareLaunchArgument('yaw', default_value='0.0', description='Initial yaw angle (rad)')
    airspeed_arg = DeclareLaunchArgument('airspeed', default_value='10.0', description='Initial airspeed (m/s)')
    simulation_rate_arg = DeclareLaunchArgument('simulation_rate', default_value='200.0', description='Physics simulation frequency (Hz)')
    gps_lat_arg = DeclareLaunchArgument('gps_origin_lat', default_value='47.397742', description='GPS origin latitude')
    gps_lon_arg = DeclareLaunchArgument('gps_origin_lon', default_value='8.545594', description='GPS origin longitude')
    gps_alt_arg = DeclareLaunchArgument('gps_origin_alt', default_value='488.0', description='GPS origin altitude')

    tf_frame_arg = DeclareLaunchArgument('tf_frame', default_value='odom', description='Global TF frame for visualization.')
    # A control flag to decide whether to launch the visualization part.
    launch_visualizer_arg = DeclareLaunchArgument(
        'launch_visualizer',
        default_value='true',
        description='If true, launches the visualization nodes and RViz.'
    )

    # Group the simulation nodes under a common namespace.
    namespaced_simulation_group = GroupAction(
        actions=[
            PushRosNamespace(LaunchConfiguration('namespace')),
            Node(
                package='robot_state_publisher',
                executable='robot_state_publisher',
                name='robot_state_publisher',
                output='screen',
                parameters=[
                    {'use_sim_time': LaunchConfiguration('use_sim_time')},
                    {'robot_description': robot_description_content},
                    {'frame_prefix': [LaunchConfiguration('namespace'), '/']}
                ],
            ),

            Node(
                package='fw_plane',
                executable='fw_sim_node',
                name='fw_simulator',
                output='screen',
                parameters=[
                    {'use_sim_time': LaunchConfiguration('use_sim_time')},
                    {'initial_state.north': LaunchConfiguration('x')},
                    {'initial_state.east': LaunchConfiguration('y')},
                    {'initial_state.down': LaunchConfiguration('z')},
                    {'initial_state.roll': LaunchConfiguration('roll')},
                    {'initial_state.pitch': LaunchConfiguration('pitch')},
                    {'initial_state.yaw': LaunchConfiguration('yaw')},
                    {'initial_state.airspeed': LaunchConfiguration('airspeed')},
                    {'rate.simulation': LaunchConfiguration('simulation_rate')},
                    {'gps_origin.latitude': LaunchConfiguration('gps_origin_lat')},
                    {'gps_origin.longitude': LaunchConfiguration('gps_origin_lon')},
                    {'gps_origin.altitude': LaunchConfiguration('gps_origin_alt')},
                ]
            ),
        ]
    )

    # Include the visualization launch file. This promotes modularity.
    visualizer_launcher = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(fw_plane_pkg_dir, 'launch', 'single_fw_visual.launch.py')
        ),
        # Pass necessary arguments from this parent launch file to the included child file.
        launch_arguments={
            'namespace': LaunchConfiguration('namespace'),
            'use_sim_time': LaunchConfiguration('use_sim_time'),
            'tf_frame': LaunchConfiguration('tf_frame'),
            'base_link_frame': [LaunchConfiguration('namespace'), '/', 'base_link'], 
            'propeller_rpm': '2000.0'
        }.items(),
        condition=IfCondition(LaunchConfiguration('launch_visualizer'))
    )

    return LaunchDescription([
        # Add all argument declarations to the LaunchDescription.
        use_sim_time_arg,
        namespace_arg,
        x_arg,
        y_arg,
        z_arg,
        roll_arg,
        pitch_arg,
        yaw_arg,
        airspeed_arg,
        simulation_rate_arg,
        gps_lat_arg,
        gps_lon_arg,
        gps_alt_arg,

        tf_frame_arg,
        launch_visualizer_arg,
        
        # Add the actions (node groups, includes) to the LaunchDescription.
        namespaced_simulation_group,
        visualizer_launcher,
    ])