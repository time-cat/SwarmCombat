// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sim_msgs:msg/ExplosionReport.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__STRUCT_H_
#define SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__STRUCT_H_

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
// Member 'exp_center'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/ExplosionReport in the package sim_msgs.
/**
  * ==============================================================================
  * 描述: 用于广播一次自杀式无人机的自爆事件。
  *      当一架无人机决定自爆时，它会发布此消息。
  *      所有其他实体（无论敌我）都会接收此消息，并根据自身位置判断是否在
  *      爆炸范围内而受到摧毁。
  * ==============================================================================
 */
typedef struct sim_msgs__msg__ExplosionReport
{
  /// 消息头部，包含了关键的时间戳信息
  std_msgs__msg__Header header;
  /// 自爆事件的核心信息
  /// 发动自爆攻击的无人机ID
  int32_t attacker_id;
  /// 自爆发生的中心点三维坐标 (x, y, z)
  geometry_msgs__msg__Point exp_center;
  /// 爆炸的有效杀伤半径，单位：米 (根据你的要求使用整数)
  float exp_range;
} sim_msgs__msg__ExplosionReport;

// Struct for a sequence of sim_msgs__msg__ExplosionReport.
typedef struct sim_msgs__msg__ExplosionReport__Sequence
{
  sim_msgs__msg__ExplosionReport * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sim_msgs__msg__ExplosionReport__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__STRUCT_H_
