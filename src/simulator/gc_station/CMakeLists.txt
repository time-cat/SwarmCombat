cmake_minimum_required(VERSION 3.8)
project(gc_station)

# --- 基础配置 ---
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# --- 查找依赖包 ---
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sim_msgs REQUIRED) # 依赖我们自己的消息包
find_package(visualization_msgs REQUIRED) # 为可视化节点添加
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)             # 为可视化节点添加
find_package(tf2_geometry_msgs REQUIRED)   # 为可视化节点添加
find_package(geometry_msgs REQUIRED)       # 为可视化节点添加

# --- 添加可执行文件 ---
add_executable(gcs_visualizer_node src/gcs_visualizer_node.cpp)

# --- 链接依赖 ---

ament_target_dependencies(gcs_visualizer_node
    rclcpp
    std_msgs
    sim_msgs
    visualization_msgs
    tf2_ros
    tf2_geometry_msgs
    geometry_msgs
)

# --- 安装 ---
install(TARGETS
    gcs_visualizer_node
    DESTINATION lib/${PROJECT_NAME}
)

# # 添加 include 目录，以便其他包可以找到 fw_dynamics.hpp
# install(
#     DIRECTORY include/
#     DESTINATION include
# )

# install(DIRECTORY
#   launch
#   DESTINATION share/${PROJECT_NAME}
# )

# install(DIRECTORY
#     model
#     DESTINATION share/${PROJECT_NAME}
# )

ament_package()