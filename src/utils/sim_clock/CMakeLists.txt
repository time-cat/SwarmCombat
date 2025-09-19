cmake_minimum_required(VERSION 3.8)
project(sim_clock)

# 1. Find all necessary dependency packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosgraph_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# 2. Define the service files to be generated
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/SetRate.srv"
)

# 3. Define your C++ executable
add_executable(sim_clock_node src/sim_clock_node.cpp)

# 4. Set up dependencies for your executable
#    This command handles include directories from OTHER packages
ament_target_dependencies(sim_clock_node
  rclcpp
  rosgraph_msgs
  std_srvs
)

# 5. *** THIS IS THE CANONICAL SOLUTION ***
#    Link the executable against the generated interfaces from THIS package.
#    This command correctly sets up both include paths and build-order dependencies.
rosidl_target_interfaces(sim_clock_node ${PROJECT_NAME} "rosidl_typesupport_cpp")

# 6. Define installation rules so `ros2 run` and `ros2 launch` can find your files
install(TARGETS
  sim_clock_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

# This command ensures all parts of the package are correctly installed
ament_package()