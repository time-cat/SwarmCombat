// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fwp_planner:msg/DynamicState.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__STRUCT_H_
#define FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/DynamicState in the package fwp_planner.
/**
  * 该消息用于在 ROS 网络中传输 BHDynamic.h 中定义的 State_Output 结构体的数据。
  * 字段名和类型与 C++ 结构体中的成员完全对应。
  * This message represents the data from the State_Output C++ struct defined in BHDynamic.h for use in the ROS network.
  * Field names and types correspond directly to the members of the C++ struct.
 */
typedef struct fwp_planner__msg__DynamicState
{
  /// 北向位置输出，m (North position output, m)
  double posi_n;
  /// 东向位置输出，m (East position output, m)
  double posi_e;
  /// 地向位置输出，m (Down position output, m)
  double posi_d;
  /// 四元数输出，x
  double orient_x;
  /// 四元数输出，y
  double orient_y;
  /// 四元数输出，z
  double orient_z;
  /// 四元数输出，w
  double orient_w;
  /// 合速度输出，m/s (Total velocity output, m/s)
  double vel;
  /// 速度倾角, deg (Velocity inclination angle, deg)
  double vel_alpha;
  /// 速度偏角, deg (Velocity sideslip angle, deg)
  double vel_bete;
  /// 攻角，输出暂为0 (Angle of attack, temp 0)
  double angle_alpha;
  /// 侧滑角，输出暂为0 (Sideslip angle, temp 0)
  double abgle_bete;
} fwp_planner__msg__DynamicState;

// Struct for a sequence of fwp_planner__msg__DynamicState.
typedef struct fwp_planner__msg__DynamicState__Sequence
{
  fwp_planner__msg__DynamicState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fwp_planner__msg__DynamicState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__STRUCT_H_
