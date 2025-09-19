import os
import yaml
import tempfile
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition
from launch.launch_context import LaunchContext

def generate_rviz_config(context: LaunchContext):
    """
    Función Opaque que se ejecuta en tiempo de lanzamiento.
    Genera un archivo de configuración temporal de RViz basado en los argumentos de lanzamiento,
    configurado para visualizar un único UAV.
    """
    # Obtiene los valores resueltos de los argumentos de lanzamiento
    namespace = LaunchConfiguration('namespace').perform(context)
    tf_frame = LaunchConfiguration('tf_frame').perform(context)

    uav_displays = [
        {
            'Name': 'Path',
            'Class': 'rviz_default_plugins/Path',
            'Enabled': True,
            'Topic': {'Value': f"/{namespace}/history_path", 'Depth': 5, 'Reliability Policy': 'Reliable'},
            'Color': '239; 41; 41',
            'Line Style': 'Billboards',
            'Line Width': 0.8
        },
        {
            'Name': 'Marker',
            'Class': 'rviz_default_plugins/Marker',
            'Enabled': True,
            'Topic': {'Value': f"/{namespace}/uav_name_marker", 'Depth': 5, 'Reliability Policy': 'Reliable'}
        },
        {
            'Name': 'RobotModel',
            'Class': 'rviz_default_plugins/RobotModel',
            'Enabled': True,
            'Description Topic': {'Value': f"/{namespace}/robot_description", 'Depth': 5, 'Reliability Policy': 'Reliable'},
            'TF Prefix': namespace
        }
    ]
    
    # Diccionario de Python que representa la configuración de RViz
    rviz_config = {
        'Panels': [
            {'Class': 'rviz_common/Displays', 'Name': 'Displays'},
            {'Class': 'rviz_common/Selection', 'Name': 'Selection'},
            {'Class': 'rviz_common/Tool Properties', 'Name': 'Tool Properties'},
            {'Class': 'rviz_common/Views', 'Name': 'Views'},
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
                {
                    'Name': namespace,
                    'Class': 'rviz_common/Group',
                    'Enabled': True,
                    'Displays': uav_displays
                }
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
                'Current': { 'Class': 'rviz_default_plugins/Orbit', 'Name': 'Current View', 'Distance': 500.0, 'Field of View': 0.785, 'Focal Point': {'X': 0, 'Y': 0, 'Z': 0}, 'Pitch': 0.6, 'Yaw': 0.785 }
            }
        },
        'Window Geometry': {
            'Height': 1100, 'Width': 1800, 'X': 100, 'Y': 100,
        }
    }
    
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
        parameters=[{'use_sim_time': LaunchConfiguration('use_sim_time')}],
        condition=IfCondition(LaunchConfiguration('launch_rviz'))
    )
    
    return [rviz_node]


def generate_launch_description():
    """
    Launch file para iniciar los componentes de visualización para un único UAV.
    """
    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true', description='If true, use simulation clock.'),
        DeclareLaunchArgument('namespace', default_value='fw0', description='Namespace for the UAV.'),
        DeclareLaunchArgument('tf_frame', default_value='odom', description='Global TF frame for visualization.'),
        DeclareLaunchArgument('base_link_frame', default_value='base_link', description='Name of the base_link TF frame for this UAV.'),
        DeclareLaunchArgument('propeller_rpm', default_value='2000.0', description='Propeller RPM for visualization.'),
        DeclareLaunchArgument('uav_name', default_value=LaunchConfiguration('namespace'), description='Name to display for the UAV in RViz.'),
        DeclareLaunchArgument('launch_rviz', default_value='true', description='Launch RViz2 with a generated configuration.'),
        
        Node(
            package='fw_plane',
            executable='fw_visualizer_node',
            name='fw_visualizer',
            namespace=LaunchConfiguration('namespace'),
            output='screen',
            parameters=[
                {'use_sim_time': LaunchConfiguration('use_sim_time')},
                {'tf_frame': LaunchConfiguration('tf_frame')},
                {'base_link_frame': LaunchConfiguration('base_link_frame')},
                {'propeller_rpm': LaunchConfiguration('propeller_rpm')},
                {'uav_name': LaunchConfiguration('uav_name')},
                {'propeller_joint_name': 'rotor_puller_joint'}
            ]
        ),
        
        OpaqueFunction(function=generate_rviz_config),
    ])