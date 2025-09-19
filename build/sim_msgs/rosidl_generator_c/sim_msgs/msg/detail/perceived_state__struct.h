// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sim_msgs:msg/PerceivedState.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__PERCEIVED_STATE__STRUCT_H_
#define SIM_MSGS__MSG__DETAIL__PERCEIVED_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/PerceivedState in the package sim_msgs.
/**
  * ==============================================================================
  * 描述: 模拟传感器对一个实体的感知结果。
  *      当一个实体（如蓝方无人机）进入另一实体（如红方无人机）的探测范围时，
  *      红方无人机就在内部生成此消息，代表“我看到了一个目标”。
  *      这个消息本身不跨队发送，而是由接收方的探测逻辑在内部创建。
  * ==============================================================================
 */
typedef struct sim_msgs__msg__PerceivedState
{
  std_msgs__msg__Header header;
  /// 被感知到的实体的基本信息
  /// 被感知到的实体的唯一ID
  int32_t id;
  /// 被感知到的实体的位置坐标 (x, y, z)
  geometry_msgs__msg__Point position;
  /// 感知到的存活状态
  bool is_alive;
} sim_msgs__msg__PerceivedState;

// Struct for a sequence of sim_msgs__msg__PerceivedState.
typedef struct sim_msgs__msg__PerceivedState__Sequence
{
  sim_msgs__msg__PerceivedState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sim_msgs__msg__PerceivedState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SIM_MSGS__MSG__DETAIL__PERCEIVED_STATE__STRUCT_H_
