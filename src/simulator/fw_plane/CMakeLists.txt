cmake_minimum_required(VERSION 3.8)
project(fw_plane)

# --- 基础配置 ---
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# --- 查找依赖包 ---
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sim_msgs REQUIRED) # 依赖我们自己的消息包
find_package(visualization_msgs REQUIRED) # 为可视化节点添加
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)             # 为可视化节点添加
find_package(tf2_geometry_msgs REQUIRED)   # 为可视化节点添加
find_package(geometry_msgs REQUIRED)       # 为可视化节点添加
find_package(Eigen3 3.3 REQUIRED NO_MODULE) # 依赖 Eigen
find_package(Boost REQUIRED COMPONENTS system) # 依赖 Boost (for odeint)

# --- 添加库文件 ---
set(BHDYNAMIC_LIB ${CMAKE_CURRENT_SOURCE_DIR}/include/BHDynamic/libBHDynamic.so)
install(FILES ${BHDYNAMIC_LIB}
    DESTINATION lib/${PROJECT_NAME}
)

# add_library(px4_lib_fw
#     include/px4_lib/drivers/drv_hrt.cpp
#     include/px4_lib/hysteresis/hysteresis.cpp
#     include/px4_lib/geo/geo.cpp
#     include/px4_lib/parameters/px4_parameters.cpp
#     include/px4_lib/uORB/uORB_sim.cpp
# )

# --- 添加可执行文件 ---
add_executable(fw_sim_node src/fw_sim_node.cpp)
add_executable(fw_visualizer_node src/fw_visualizer_node.cpp)

# --- 链接依赖 ---
ament_target_dependencies(fw_sim_node
    rclcpp
    nav_msgs
    sensor_msgs
    std_msgs
    sim_msgs
    tf2_ros
    tf2_geometry_msgs
)

ament_target_dependencies(fw_visualizer_node
    rclcpp
    nav_msgs
    sensor_msgs
    std_msgs
    sim_msgs
    visualization_msgs
    tf2_ros
    tf2_geometry_msgs
    geometry_msgs
)

# 链接 Eigen 和 Boost  px4_lib_fw BHDynamic
target_include_directories(fw_sim_node PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    ${Eigen3_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)
target_link_libraries(fw_sim_node
    ${BHDYNAMIC_LIB}
    Eigen3::Eigen
    Boost::system
)

# 链接 Eigen 和 Boost  px4_lib_fw BHDynamic
target_include_directories(fw_visualizer_node PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_link_libraries(fw_visualizer_node
    ${BHDYNAMIC_LIB}
)

# --- 安装 ---
install(TARGETS
    fw_sim_node
    fw_visualizer_node
    DESTINATION lib/${PROJECT_NAME}
)

# 添加 include 目录
install(
    DIRECTORY include/
    DESTINATION include
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY
    model
    DESTINATION share/${PROJECT_NAME}
)

ament_package()