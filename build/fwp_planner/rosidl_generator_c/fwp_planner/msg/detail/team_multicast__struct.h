// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fwp_planner:msg/TeamMulticast.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__STRUCT_H_
#define FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__STRUCT_H_

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
// Member 'known_teammates'
#include "fwp_planner/msg/detail/fused_teammate__struct.h"
// Member 'known_enemies'
#include "fwp_planner/msg/detail/fused_enemy__struct.h"
// Member 'dynamic_state'
#include "fwp_planner/msg/detail/dynamic_state__struct.h"

/// Struct defined in msg/TeamMulticast in the package fwp_planner.
/**
  * ==============================================================================
  * 描述: 团队内部组播的战术情报消息。
  *      由一个实体（无人机或地面站）发出，包含其所知的最全战场态势图。
  * ==============================================================================
 */
typedef struct fwp_planner__msg__TeamMulticast
{
  std_msgs__msg__Header header;
  int32_t sender_id;
  float multicast_range;
  /// 已知队友信息表格
  fwp_planner__msg__FusedTeammate__Sequence known_teammates;
  /// 已知敌方信息表格
  fwp_planner__msg__FusedEnemy__Sequence known_enemies;
  /// 发送者完整的状态信息
  fwp_planner__msg__DynamicState dynamic_state;
  /// 当前的存活状态
  bool is_alive;
} fwp_planner__msg__TeamMulticast;

// Struct for a sequence of fwp_planner__msg__TeamMulticast.
typedef struct fwp_planner__msg__TeamMulticast__Sequence
{
  fwp_planner__msg__TeamMulticast * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fwp_planner__msg__TeamMulticast__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__STRUCT_H_
