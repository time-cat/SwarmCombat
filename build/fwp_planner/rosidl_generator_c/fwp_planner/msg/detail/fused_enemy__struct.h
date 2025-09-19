// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fwp_planner:msg/FusedEnemy.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__FUSED_ENEMY__STRUCT_H_
#define FWP_PLANNER__MSG__DETAIL__FUSED_ENEMY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/FusedEnemy in the package fwp_planner.
/**
  * ==============================================================================
  * 描述: TeamMulticast消息中，“敌方信息表格”的一行。
  *      代表关于单个敌方目标的融合情报。
  * ==============================================================================
 */
typedef struct fwp_planner__msg__FusedEnemy
{
  /// 敌方ID
  int32_t id;
  /// 已知的敌方位置
  geometry_msgs__msg__Point position;
  /// 该情报的时间戳
  builtin_interfaces__msg__Time timestamp;
} fwp_planner__msg__FusedEnemy;

// Struct for a sequence of fwp_planner__msg__FusedEnemy.
typedef struct fwp_planner__msg__FusedEnemy__Sequence
{
  fwp_planner__msg__FusedEnemy * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fwp_planner__msg__FusedEnemy__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FWP_PLANNER__MSG__DETAIL__FUSED_ENEMY__STRUCT_H_
