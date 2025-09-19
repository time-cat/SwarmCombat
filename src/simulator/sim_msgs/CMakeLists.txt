# --- 这是接口包的标准CMakeLists.txt模板 ---

cmake_minimum_required(VERSION 3.8)
project(sim_msgs)

# 1. 找到构建所需的依赖
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
# 因为.msg文件内部用到了std_msgs，所以这里也要找到它
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# 这是整个文件里最核心的命令。
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/DeathNotice.msg"
  "msg/ExplosionReport.msg"
  "msg/PerceivedState.msg"
  "msg/FwControl.msg"
  
  DEPENDENCIES std_msgs geometry_msgs
)

# 3. 这个命令确保所有文件都被正确安装
ament_package()