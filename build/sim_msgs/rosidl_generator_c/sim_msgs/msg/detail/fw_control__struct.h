// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sim_msgs:msg/FwControl.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__FW_CONTROL__STRUCT_H_
#define SIM_MSGS__MSG__DETAIL__FW_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/FwControl in the package sim_msgs.
/**
  * 固定翼飞机高层控制指令
 */
typedef struct sim_msgs__msg__FwControl
{
  /// 期望的滚转角 (rad)
  double desired_roll;
  /// 期望的俯仰角 (rad)
  double desired_pitch;
  /// 期望的偏航角速度 (rad/s)
  double desired_yaw_rate;
  /// 期望的空速 (m/s)
  double desired_airspeed;
} sim_msgs__msg__FwControl;

// Struct for a sequence of sim_msgs__msg__FwControl.
typedef struct sim_msgs__msg__FwControl__Sequence
{
  sim_msgs__msg__FwControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sim_msgs__msg__FwControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SIM_MSGS__MSG__DETAIL__FW_CONTROL__STRUCT_H_
