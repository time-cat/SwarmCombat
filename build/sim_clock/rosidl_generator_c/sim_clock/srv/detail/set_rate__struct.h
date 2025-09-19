// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sim_clock:srv/SetRate.idl
// generated code does not contain a copyright notice

#ifndef SIM_CLOCK__SRV__DETAIL__SET_RATE__STRUCT_H_
#define SIM_CLOCK__SRV__DETAIL__SET_RATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetRate in the package sim_clock.
typedef struct sim_clock__srv__SetRate_Request
{
  double rate;
} sim_clock__srv__SetRate_Request;

// Struct for a sequence of sim_clock__srv__SetRate_Request.
typedef struct sim_clock__srv__SetRate_Request__Sequence
{
  sim_clock__srv__SetRate_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sim_clock__srv__SetRate_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetRate in the package sim_clock.
typedef struct sim_clock__srv__SetRate_Response
{
  bool success;
  rosidl_runtime_c__String message;
} sim_clock__srv__SetRate_Response;

// Struct for a sequence of sim_clock__srv__SetRate_Response.
typedef struct sim_clock__srv__SetRate_Response__Sequence
{
  sim_clock__srv__SetRate_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sim_clock__srv__SetRate_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SIM_CLOCK__SRV__DETAIL__SET_RATE__STRUCT_H_
