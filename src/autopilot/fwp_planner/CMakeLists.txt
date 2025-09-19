cmake_minimum_required(VERSION 3.8)
project(fwp_planner)

# 设置 C++ 标准为 17 (ROS 2 Humble 及更新版本推荐)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# 1. 查找依赖项
# 必须先找到 ament_cmake
find_package(ament_cmake REQUIRED)
# 查找所有在 package.xml 中列出的依赖包
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(sim_msgs REQUIRED)
# 查找消息生成器
find_package(rosidl_default_generators REQUIRED)


# 2. 处理本包内的自定义消息
# 这个命令会查找 "msg" 目录下的所有 .msg 文件 (这里是 DynamicState.msg)
# 并为它们生成 C++ 头文件 (例如 DyanmicState.hpp)
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/DynamicState.msg"
  "msg/FusedEnemy.msg"
  "msg/FusedTeammate.msg"
  "msg/TeamBroadcast.msg"
  "msg/TeamMulticast.msg"
  # 如果还有其他消息或服务，可以在这里继续添加
  # "msg/AnotherMessage.msg"
  # "srv/MyService.srv"
  DEPENDENCIES std_msgs geometry_msgs rclcpp builtin_interfaces
)


# 3. 定义并编译可执行节点
add_executable(fw_logic_node src/fw_logic_node.cpp)

# 链接依赖项到可执行文件
# 这是最关键的一步，它告诉编译器在哪里找到所需的头文件和库
ament_target_dependencies(fw_logic_node
  rclcpp
  geometry_msgs
  nav_msgs
  tf2
  tf2_geometry_msgs
  sim_msgs
  builtin_interfaces
)

# 链接 .msg 文件
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(fw_logic_node "${cpp_typesupport_target}")

# 安装可执行文件到 lib/<package_name>/ 目录下
install(TARGETS
  fw_logic_node
  DESTINATION lib/${PROJECT_NAME}
)


# 添加 include 目录
install(
    DIRECTORY include/
    DESTINATION include
)

# 安装 launch 文件
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

# 这是 ament 的魔法，确保所有必要的配置文件和标记被正确安装
ament_package()