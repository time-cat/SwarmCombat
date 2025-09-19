import os
import yaml
import tempfile
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, GroupAction, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import PushRosNamespace
from launch.conditions import IfCondition

from launch.launch_context import LaunchContext
from ament_index_python.packages import get_package_share_directory

# OpaqueFunction allows us to execute arbitrary Python code during launch
def generate_rviz_config(context):
    """
    This function is executed at launch time.
    It generates a temporary RViz config file based on launch arguments.
    This version corrects the class name for the 'Group' display.
    """
    # Get the resolved values of the launch arguments
    namespace = LaunchConfiguration('namespace').perform(context)
    tf_frame = LaunchConfiguration('tf_frame').perform(context)

    uav_displays = [
        {
            'Name': 'Path', # 在组内，名称可以简化
            'Class': 'rviz_default_plugins/Path',
            'Enabled': True,
            'Topic': {'Value': f"/{namespace}/history_path", 'Depth': 5, 'Reliability Policy': 'Reliable'},
            'Color': '239; 41; 41',
            'Line Style': 'Billboards',
            'Line Width': 0.8
        },
        {
            'Name': 'Marker', # 在组内，名称可以简化
            'Class': 'rviz_default_plugins/Marker',
            'Enabled': True,
            'Topic': {'Value': f"/{namespace}/uav_name_marker", 'Depth': 5, 'Reliability Policy': 'Reliable'}
        },
        {
            'Name': 'RobotModel', # 在组内，名称可以简化
            'Class': 'rviz_default_plugins/RobotModel',
            'Enabled': True,
            'Description Topic': {'Value': f"/{namespace}/robot_description", 'Depth': 5, 'Reliability Policy': 'Reliable'},
            # 注意: TF Prefix 已经被 robot_state_publisher 的 frame_prefix 参数处理，这里不再需要
            'TF Prefix': namespace 
        }
    ]
    
    # Python dictionary representing the RViz config
    rviz_config = {
        'Panels': [
            # ... (Panels configuration is correct and remains unchanged) ...
            {'Class': 'rviz_common/Displays', 'Name': 'Displays', 'Splitter Ratio': 0.542},
            {'Class': 'rviz_common/Selection', 'Name': 'Selection'},
            {'Class': 'rviz_common/Tool Properties', 'Name': 'Tool Properties', 'Splitter Ratio': 0.588},
            {'Class': 'rviz_common/Views', 'Name': 'Views', 'Splitter Ratio': 0.5},
            {'Class': 'rviz_common/Time', 'Name': 'Time'}
        ],
        'Visualization Manager': {
            'Global Options': {
                'Background Color': '243; 243; 243',
                'Fixed Frame': tf_frame,
                'Frame Rate': '30',
            },
            'Displays': [
                # Grid, Axes, TF configurations are correct
                {'Name': 'Grid', 'Class': 'rviz_default_plugins/Grid', 'Enabled': True, 'Color': '160; 160; 164', 'Plane': 'XY', 'Cell Size': 20.0, 'Plane Cell Count': 100, 'Reference Frame': '<Fixed Frame>'},
                {'Name': 'WorldOrigin', 'Class': 'rviz_default_plugins/Axes', 'Enabled': True, 'Length': 7.0, 'Radius': 0.5},
                {'Name': 'TF', 'Class': 'rviz_default_plugins/TF', 'Enabled': True, 'Show Names': True},
                {
                    'Name': namespace, # Group 的名字就是无人机的名字空间
                    'Class': 'rviz_common/Group',
                    'Enabled': True,
                    'Displays': uav_displays # 将上面定义的显示项列表嵌套进来
                }
            ],
            # Tools and Views configurations are correct
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
        # Window Geometry remains correct
        'Window Geometry': {
            'Height': 749, 'Width': 1328, 'X': 1073, 'Y': 631,
            'QMainWindow State': '000000ff00000000fd0000000400000000000001690000022ffc0200000008fb0000001200530065006c0065006300740069006f006e00000001e10000009b0000005c00fffffffb0000001e0054006f006f006c002000500072006f007000650072007400690065007302000001ed000001df00000185000000b0fb000000120056006900650077007300200054006f006f02000001df000002110000018500000122fb000000200054006f006f006c002000500072006f0070006500720074006900650073003203000002880000011d000002210000017afb000000100044006900730070006c006100790073010000003d0000022f000000c900fffffffb0000002000730065006c0065006300740069006f006e00200062007500660066006500720200000138000000aa0000023a00000294fb00000014005700690064006500530074006500720065006f02000000e6000000d2000003ee0000030bfb0000000c004b0069006e0065006300740200000186000001060000030c00000261000000010000015f00000247fc0200000003fb0000001e0054006f006f006c002000500072006f00700065007200740069006500730100000041000000780000000000000000fb0000000a00560069006500770073000000003d00000247000000a400fffffffb0000001200530065006c0065006300740069006f006e010000025a000000b200000000000000000000000200000490000000a9fc0100000001fb0000000a00560069006500770073030000004e00000080000002e10000019700000003000005300000005efc0100000002fb0000000800540069006d0065010000000000000530000003bc00fffffffb0000000800540069006d00650100000000000004500000000000000000000003c10000022f00000004000000040000000800000008fc0000000100000002000000010000000a0054006f006f006c00730100000000ffffffff0000000000000000'
        }
    }
    
    # --- 文件写入和节点创建部分，保持不变 ---
    tmp_file = tempfile.NamedTemporaryFile(mode='w', delete=False, suffix='.rviz')
    try:
        yaml.dump(rviz_config, tmp_file)
        tmp_file.close()
        rviz_config_path = tmp_file.name
    except Exception as e:
        print(f"Error writing temporary rviz config: {e}")
        return []

    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config_path],
        parameters=[{'use_sim_time': LaunchConfiguration('use_sim_time')}]
    )
    
    return [rviz_node]



def generate_launch_description():
    """
    Launch file to start a single fixed-wing simulation, its visualizer,
    and optionally a pre-configured RViz instance to follow the drone.
    """
    
    # --- New arguments for RViz and control ---
    launch_rviz_arg = DeclareLaunchArgument(
        'launch_rviz', default_value='true',
        description='Whether to launch RViz2 with a generated config.')

    camera_distance_arg = DeclareLaunchArgument(
        'camera_distance', default_value='30.0',
        description='Camera distance from the UAV in RViz.')
    
    camera_pitch_arg = DeclareLaunchArgument(
        'camera_pitch', default_value='0.6',
        description='Camera pitch angle in RViz (radians).')

    fw_plane_pkg_dir = get_package_share_directory('fw_plane')
    urdf_model_path_arg = DeclareLaunchArgument(
        'urdf_model_path',
        default_value=os.path.join(fw_plane_pkg_dir, 'model', 'plane.urdf'),
        description='Path to the URDF file of the fixed-wing plane.'
    )
    with open(os.path.join(fw_plane_pkg_dir, 'model', 'plane.urdf'), 'r') as f:
        robot_description_content = f.read()

    # --- Declare all original launch arguments ---
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time', default_value='true',
        description='If true, use simulation clock.')
    namespace_arg = DeclareLaunchArgument(
        'namespace', default_value='fw0',
        description='Namespace for the UAV.')
    x_arg = DeclareLaunchArgument('x', default_value='0.0', description='Initial North position (m)')
    y_arg = DeclareLaunchArgument('y', default_value='0.0', description='Initial East position (m)')
    z_arg = DeclareLaunchArgument('z', default_value='-100.0', description='Initial Down position (m)')
    roll_arg = DeclareLaunchArgument('roll', default_value='0.0', description='Initial roll angle (rad)')
    pitch_arg = DeclareLaunchArgument('pitch', default_value='0.0', description='Initial pitch angle (rad)')
    yaw_arg = DeclareLaunchArgument('yaw', default_value='0.0', description='Initial yaw angle (rad)')
    airspeed_arg = DeclareLaunchArgument('airspeed', default_value='15.0', description='Initial airspeed (m/s)')
    simulation_rate_arg = DeclareLaunchArgument(
        'simulation_rate', default_value='100.0', 
        description='Physics simulation frequency (Hz)')
    gps_lat_arg = DeclareLaunchArgument('gps_origin_lat', default_value='47.397742', description='GPS origin latitude')
    gps_lon_arg = DeclareLaunchArgument('gps_origin_lon', default_value='8.545594', description='GPS origin longitude')
    gps_alt_arg = DeclareLaunchArgument('gps_origin_alt', default_value='488.0', description='GPS origin altitude')
    tf_frame_arg = DeclareLaunchArgument('tf_frame', default_value='odom', description='Global TF frame for visualization')
    base_link_frame_arg = DeclareLaunchArgument(
        'base_link_frame', 
        default_value='base_link', 
        description='Base link TF frame name for this UAV')
    propeller_rpm_arg = DeclareLaunchArgument(
        'propeller_rpm', default_value='2000.0', 
        description='Propeller RPM for visualization')
    uav_name_arg = DeclareLaunchArgument(
        'uav_name', default_value=LaunchConfiguration('namespace'),
        description='Display name for the UAV in RViz')

    # --- Group actions for namespacing ---
    namespaced_group = GroupAction(
        actions=[
            PushRosNamespace(LaunchConfiguration('namespace')),
            ### 新增 ###: robot_state_publisher 节点
            # 这个节点负责发布 TF 变换
            Node(
                package='robot_state_publisher',
                executable='robot_state_publisher',
                name='robot_state_publisher',
                output='screen',
                parameters=[
                    {'use_sim_time': LaunchConfiguration('use_sim_time')},
                    # robot_description 参数会使节点发布 /robot_description 话题
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
            Node(
                package='fw_plane',
                executable='fw_visualizer_node',
                name='fw_visualizer',
                output='screen',
                parameters=[
                    {'use_sim_time': LaunchConfiguration('use_sim_time')},
                    {'tf_frame': LaunchConfiguration('tf_frame')},
                    {'base_link_frame': [LaunchConfiguration('namespace'), '/', LaunchConfiguration('base_link_frame')]}, 
                    {'propeller_rpm': LaunchConfiguration('propeller_rpm')},
                    {'uav_name': LaunchConfiguration('uav_name')},
                    {'propeller_joint_name': 'rotor_puller_joint'}
                ]
            )
        ]
    )

    # --- RViz generation and launch ---
    # This OpaqueFunction will only be executed if the 'launch_rviz' argument is true.
    rviz_launcher = OpaqueFunction(
        function=generate_rviz_config,
        condition=IfCondition(LaunchConfiguration('launch_rviz'))
    )

    # --- Create the final launch description ---
    ld = LaunchDescription()
    # Add all argument declarations
    ld.add_action(launch_rviz_arg)
    ld.add_action(camera_distance_arg)
    ld.add_action(camera_pitch_arg)
    ld.add_action(use_sim_time_arg)
    ld.add_action(namespace_arg)
    ld.add_action(urdf_model_path_arg)
    ld.add_action(x_arg)
    ld.add_action(y_arg)
    ld.add_action(z_arg)
    # ... (add all other original arguments) ...
    ld.add_action(roll_arg)
    ld.add_action(pitch_arg)
    ld.add_action(yaw_arg)
    ld.add_action(airspeed_arg)
    ld.add_action(simulation_rate_arg)
    ld.add_action(gps_lat_arg)
    ld.add_action(gps_lon_arg)
    ld.add_action(gps_alt_arg)
    ld.add_action(tf_frame_arg)
    ld.add_action(base_link_frame_arg)
    ld.add_action(propeller_rpm_arg)
    ld.add_action(uav_name_arg)

    # Add the nodes and the rviz launcher
    ld.add_action(namespaced_group)
    ld.add_action(rviz_launcher)

    return ld