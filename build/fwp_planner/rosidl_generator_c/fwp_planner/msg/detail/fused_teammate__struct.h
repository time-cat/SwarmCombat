// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fwp_planner:msg/FusedTeammate.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__STRUCT_H_
#define FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/FusedTeammate in the package fwp_planner.
/**
  * ==============================================================================
  * 描述: TeamMulticast消息中，“队友信息表格”的一行。
  *      代表关于单个队友的融合情报。
  * ==============================================================================
 */
typedef struct fwp_planner__msg__FusedTeammate
{
  /// 队友ID
  int32_t id;
  /// 已知该队友正在攻击的目标ID (-1表示无目标)
  int32_t target_id;
  /// 该情报的时间戳
  builtin_interfaces__msg__Time timestamp;
} fwp_planner__msg__FusedTeammate;

// Struct for a sequence of fwp_planner__msg__FusedTeammate.
typedef struct fwp_planner__msg__FusedTeammate__Sequence
{
  fwp_planner__msg__FusedTeammate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fwp_planner__msg__FusedTeammate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__STRUCT_H_
