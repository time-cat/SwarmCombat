import os
import re
import yaml
import tempfile
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, OpaqueFunction, IncludeLaunchDescription, GroupAction
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory

# --- UAVs Configuration ---
# A centralized list to define all UAVs to be launched.
# This makes it easy to add, remove, or modify UAVs and their initial poses.
UAV_CONFIGS = [
    {'name': 'fw1',   'team': 'red',  'fov_range': 2000.0, 'com_range': 2000.0, 'exp_range': 80.0, 'x': 0.0,  'y': 0.0,    'yaw': 0.0},
    {'name': 'fw2',   'team': 'red',  'fov_range': 2000.0, 'com_range': 2000.0, 'exp_range': 80.0, 'x': 0.0,  'y': -20.0,  'yaw': 0.0},
    {'name': 'fw3',   'team': 'red',  'fov_range': 2000.0, 'com_range': 2000.0, 'exp_range': 80.0, 'x': 0.0,  'y': -40.0,  'yaw': 0.0},
    {'name': 'fw4',   'team': 'red',  'fov_range': 2000.0, 'com_range': 2000.0, 'exp_range': 80.0, 'x': 0.0,  'y': -60.0,  'yaw': 0.0},
    {'name': 'fw5',   'team': 'red',  'fov_range': 2000.0, 'com_range': 2000.0, 'exp_range': 80.0, 'x': 0.0,  'y': -80.0,  'yaw': 0.0},
    {'name': 'fw101', 'team': 'blue', 'fov_range': 2000.0, 'com_range': 2000.0, 'exp_range': 80.0, 'x': 600.0, 'y': 0.0,    'yaw': 3.14},
    {'name': 'fw102', 'team': 'blue', 'fov_range': 2000.0, 'com_range': 2000.0, 'exp_range': 80.0, 'x': 600.0, 'y': -20.0,  'yaw': 3.14},
    {'name': 'fw103', 'team': 'blue', 'fov_range': 2000.0, 'com_range': 2000.0, 'exp_range': 80.0, 'x': 600.0, 'y': -40.0,  'yaw': 3.14},
    {'name': 'fw104', 'team': 'blue', 'fov_range': 2000.0, 'com_range': 2000.0, 'exp_range': 80.0, 'x': 700.0, 'y': 0.0,  'yaw': 3.14},
    {'name': 'fw105', 'team': 'blue', 'fov_range': 2000.0, 'com_range': 2000.0, 'exp_range': 80.0, 'x': 700.0, 'y': -20.0,  'yaw': 3.14},
    {'name': 'fw106', 'team': 'blue', 'fov_range': 2000.0, 'com_range': 2000.0, 'exp_range': 80.0, 'x': 700.0, 'y': -40.0,  'yaw': 3.14},
    # Add more UAVs here as needed
]


def generate_multi_rviz_config(context):
    """
    An OpaqueFunction that runs at launch time. It dynamically generates a single
    RViz configuration file that includes a display group for each UAV
    defined in the UAV_CONFIGS list.
    """
    tf_frame = LaunchConfiguration('tf_frame').perform(context)
    
    all_uav_displays = []
    for uav in UAV_CONFIGS:
        namespace = uav['name']
        uav_group = {
            'Name': namespace,
            'Class': 'rviz_common/Group',
            'Enabled': True,
            'Displays': [
                { 'Name': 'Path', 'Class': 'rviz_default_plugins/Path', 'Enabled': True, 'Topic': {'Value': f"/{namespace}/history_path", 'Depth': 5, 'Reliability Policy': 'Reliable'}, 'Color': '239; 41; 41', 'Line Style': 'Billboards', 'Line Width': 0.8},
                { 'Name': 'Marker', 'Class': 'rviz_default_plugins/Marker', 'Enabled': True, 'Topic': {'Value': f"/{namespace}/uav_name_marker", 'Depth': 5, 'Reliability Policy': 'Reliable'}},
                { 'Name': 'RobotModel', 'Class': 'rviz_default_plugins/RobotModel', 'Enabled': True, 'Description Topic': {'Value': f"/{namespace}/robot_description", 'Depth': 5, 'Reliability Policy': 'Reliable'}, 'TF Prefix': namespace }
            ]
        }
        all_uav_displays.append(uav_group)

    rviz_config = {
        'Panels': [ 
            {'Class': 'rviz_common/Displays', 'Name': 'Displays'},
            {'Class': 'rviz_common/Selection', 'Name': 'Selection'},
            {'Class': 'rviz_common/Tool Properties', 'Name': 'Tool Properties'},
            {'Class': 'rviz_common/Views', 'Name': 'Views'},
            # {'Class': 'rviz_common/Time', 'Name': 'Time'}
        ],
        'Visualization Manager': {
            'Global Options': {
                'Background Color': '243; 243; 243',
                'Fixed Frame': tf_frame,
                'Frame Rate': '30',
            },
            'Displays': [
                {'Name': 'Grid', 'Class': 'rviz_default_plugins/Grid', 'Enabled': True, 'Color': '160; 160; 164', 'Plane': 'XY', 'Cell Size': 20.0, 'Plane Cell Count': 100, 'Reference Frame': '<Fixed Frame>'},
                {'Name': 'WorldOrigin', 'Class': 'rviz_default_plugins/Axes', 'Enabled': True, 'Length': 7.0, 'Radius': 0.5},
                {'Name': 'TF', 'Class': 'rviz_default_plugins/TF', 'Enabled': True, 'Show Names': True},
                *all_uav_displays
            ],
            'Tools': [
                {'Class': 'rviz_default_plugins/Interact', 'Hide Inactive Objects': True},
                {'Class': 'rviz_default_plugins/MoveCamera'},
                {'Class': 'rviz_default_plugins/Select'},
                {'Class': 'rviz_default_plugins/FocusCamera'},
                {'Class': 'rviz_default_plugins/Measure'},
                {'Class': 'rviz_default_plugins/SetInitialPose', 'Topic': '/initialpose'},
                {'Class': 'rviz_default_plugins/SetGoal', 'Topic': '/goal_pose'},
            ],
            'Views': {
                'Current': { 'Class': 'rviz_default_plugins/Orbit', 'Name': 'Current View', 'Distance': 831.13, 'Field of View': 0.785, 'Focal Point': {'X': 27.6, 'Y': 25.5, 'Z': 11.6}, 'Pitch': 1.56, 'Yaw': 4.55 }
            }
        },
        'Window Geometry': {
            'Height': 1100, 'Width': 1800, 'X': 100, 'Y': 100,
        }
    }

    tmp_file = tempfile.NamedTemporaryFile(mode='w', delete=False, suffix='.rviz')
    yaml.dump(rviz_config, tmp_file)
    tmp_file.close()
    
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2_multi',
        arguments=['-d', tmp_file.name],
        parameters=[{'use_sim_time': LaunchConfiguration('use_sim_time')}]
    )
    return [rviz_node]


def generate_launch_description():
    """
    Launch file para iniciar una simulación de múltiples fixed-wings.
    Lanza la simulación para cada dron y una única instancia de RViz para visualizarlos todos.
    """
    fw_plane_pkg_dir = get_package_share_directory('fw_plane')

    # --- Argumentos Globales ---
    use_sim_time_arg = DeclareLaunchArgument('use_sim_time', default_value='true')
    launch_rviz_arg = DeclareLaunchArgument('launch_rviz', default_value='true')
    tf_frame_arg = DeclareLaunchArgument('tf_frame', default_value='odom')

    # --- Acciones de Lanzamiento ---
    launch_actions = []

    # Bucle para lanzar la simulación y el visualizador de cada dron
    for uav in UAV_CONFIGS:
        # 1. Lanzar la simulación base (sin su propio RViz)
        sim_launcher = IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(fw_plane_pkg_dir, 'launch', 'single_fw_sim.launch.py')
            ),
            launch_arguments={
                'use_sim_time': LaunchConfiguration('use_sim_time'),
                'namespace': uav['name'],
                'x': str(uav['x']),
                'y': str(uav['y']),
                'yaw': str(uav['yaw']),
                'launch_visualizer': 'false', # This prevents it from launching its own RViz instance.
                # 'simulation_rate': str(200)
            }.items()
        )
        launch_actions.append(sim_launcher)
        
        logic_node = Node(
             package='fwp_planner',
             executable='fw_logic_node',
             name='fw_logic',
             namespace=uav['name'],
             parameters=[
                 {'use_sim_time': LaunchConfiguration('use_sim_time')},
                 {'id': int(re.search(r'\d+', uav['name']).group(0)) },
                 {'team': uav['team']},
                 {'fov_range': uav['fov_range']},
                 {'com_range': uav['com_range']},
                 {'exp_range': uav['exp_range']},
             ]
        )
        launch_actions.append(logic_node)

        visualizer_node = Node(
             package='fw_plane',
             executable='fw_visualizer_node',
             name='fw_visualizer',
             namespace=uav['name'],
             parameters=[
                 {'use_sim_time': LaunchConfiguration('use_sim_time')},
                 {'tf_frame': LaunchConfiguration('tf_frame')},
                 {'base_link_frame': [LaunchConfiguration('namespace'), '/', 'base_link']},
                 {'uav_name': uav['name']},
             ]
        )
        launch_actions.append(visualizer_node)

    # 4. Lanzar una única instancia de RViz configurada para todos los drones
    rviz_launcher = OpaqueFunction(
        function=generate_multi_rviz_config,
        condition=IfCondition(LaunchConfiguration('launch_rviz'))
    )
    launch_actions.append(rviz_launcher)


    return LaunchDescription([
        use_sim_time_arg,
        launch_rviz_arg,
        tf_frame_arg,
        *launch_actions
    ])