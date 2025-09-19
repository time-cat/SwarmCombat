// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sim_msgs:msg/DeathNotice.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__DEATH_NOTICE__STRUCT_H_
#define SIM_MSGS__MSG__DETAIL__DEATH_NOTICE__STRUCT_H_

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

/// Struct defined in msg/DeathNotice in the package sim_msgs.
typedef struct sim_msgs__msg__DeathNotice
{
  std_msgs__msg__Header header;
  bool death;
} sim_msgs__msg__DeathNotice;

// Struct for a sequence of sim_msgs__msg__DeathNotice.
typedef struct sim_msgs__msg__DeathNotice__Sequence
{
  sim_msgs__msg__DeathNotice * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sim_msgs__msg__DeathNotice__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SIM_MSGS__MSG__DETAIL__DEATH_NOTICE__STRUCT_H_
