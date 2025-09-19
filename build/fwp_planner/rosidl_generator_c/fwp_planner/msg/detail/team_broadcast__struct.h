// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fwp_planner:msg/TeamBroadcast.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__TEAM_BROADCAST__STRUCT_H_
#define FWP_PLANNER__MSG__DETAIL__TEAM_BROADCAST__STRUCT_H_

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
// Member 'dynamic_state'
#include "fwp_planner/msg/detail/dynamic_state__struct.h"

/// Struct defined in msg/TeamBroadcast in the package fwp_planner.
/**
  * ==============================================================================
  * 描述: 团队内部广播的“心跳”消息，用于队友间共享自身精确状态。
  *      主要用于维持队形、避免碰撞和基本态势感知。
  * ==============================================================================
 */
typedef struct fwp_planner__msg__TeamBroadcast
{
  std_msgs__msg__Header header;
  int32_t sender_id;
  float broadcast_range;
  /// 发送者完整的状态信息
  fwp_planner__msg__DynamicState dynamic_state;
  /// 当前的存活状态
  bool is_alive;
} fwp_planner__msg__TeamBroadcast;

// Struct for a sequence of fwp_planner__msg__TeamBroadcast.
typedef struct fwp_planner__msg__TeamBroadcast__Sequence
{
  fwp_planner__msg__TeamBroadcast * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fwp_planner__msg__TeamBroadcast__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FWP_PLANNER__MSG__DETAIL__TEAM_BROADCAST__STRUCT_H_
