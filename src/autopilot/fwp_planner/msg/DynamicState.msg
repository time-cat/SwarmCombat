# 该消息用于在 ROS 网络中传输 BHDynamic.h 中定义的 State_Output 结构体的数据。
# 字段名和类型与 C++ 结构体中的成员完全对应。
# This message represents the data from the State_Output C++ struct defined in BHDynamic.h for use in the ROS network.
# Field names and types correspond directly to the members of the C++ struct.

float64 posi_n       # 北向位置输出，m (North position output, m)
float64 posi_e       # 东向位置输出，m (East position output, m)
float64 posi_d       # 地向位置输出，m (Down position output, m)
float64 orient_x     # 四元数输出，x 
float64 orient_y     # 四元数输出，y
float64 orient_z     # 四元数输出，z
float64 orient_w     # 四元数输出，w
float64 vel          # 合速度输出，m/s (Total velocity output, m/s)
float64 vel_alpha    # 速度倾角, deg (Velocity inclination angle, deg)
float64 vel_bete     # 速度偏角, deg (Velocity sideslip angle, deg)
float64 angle_alpha  # 攻角，输出暂为0 (Angle of attack, temp 0)
float64 abgle_bete   # 侧滑角，输出暂为0 (Sideslip angle, temp 0)