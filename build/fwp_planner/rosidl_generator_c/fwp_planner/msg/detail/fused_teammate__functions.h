// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from fwp_planner:msg/FusedTeammate.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__FUNCTIONS_H_
#define FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "fwp_planner/msg/rosidl_generator_c__visibility_control.h"

#include "fwp_planner/msg/detail/fused_teammate__struct.h"

/// Initialize msg/FusedTeammate message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * fwp_planner__msg__FusedTeammate
 * )) before or use
 * fwp_planner__msg__FusedTeammate__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__FusedTeammate__init(fwp_planner__msg__FusedTeammate * msg);

/// Finalize msg/FusedTeammate message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
void
fwp_planner__msg__FusedTeammate__fini(fwp_planner__msg__FusedTeammate * msg);

/// Create msg/FusedTeammate message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * fwp_planner__msg__FusedTeammate__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
fwp_planner__msg__FusedTeammate *
fwp_planner__msg__FusedTeammate__create();

/// Destroy msg/FusedTeammate message.
/**
 * It calls
 * fwp_planner__msg__FusedTeammate__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
void
fwp_planner__msg__FusedTeammate__destroy(fwp_planner__msg__FusedTeammate * msg);

/// Check for msg/FusedTeammate message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__FusedTeammate__are_equal(const fwp_planner__msg__FusedTeammate * lhs, const fwp_planner__msg__FusedTeammate * rhs);

/// Copy a msg/FusedTeammate message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__FusedTeammate__copy(
  const fwp_planner__msg__FusedTeammate * input,
  fwp_planner__msg__FusedTeammate * output);

/// Initialize array of msg/FusedTeammate messages.
/**
 * It allocates the memory for the number of elements and calls
 * fwp_planner__msg__FusedTeammate__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__FusedTeammate__Sequence__init(fwp_planner__msg__FusedTeammate__Sequence * array, size_t size);

/// Finalize array of msg/FusedTeammate messages.
/**
 * It calls
 * fwp_planner__msg__FusedTeammate__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
void
fwp_planner__msg__FusedTeammate__Sequence__fini(fwp_planner__msg__FusedTeammate__Sequence * array);

/// Create array of msg/FusedTeammate messages.
/**
 * It allocates the memory for the array and calls
 * fwp_planner__msg__FusedTeammate__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
fwp_planner__msg__FusedTeammate__Sequence *
fwp_planner__msg__FusedTeammate__Sequence__create(size_t size);

/// Destroy array of msg/FusedTeammate messages.
/**
 * It calls
 * fwp_planner__msg__FusedTeammate__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
void
fwp_planner__msg__FusedTeammate__Sequence__destroy(fwp_planner__msg__FusedTeammate__Sequence * array);

/// Check for msg/FusedTeammate message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__FusedTeammate__Sequence__are_equal(const fwp_planner__msg__FusedTeammate__Sequence * lhs, const fwp_planner__msg__FusedTeammate__Sequence * rhs);

/// Copy an array of msg/FusedTeammate messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__FusedTeammate__Sequence__copy(
  const fwp_planner__msg__FusedTeammate__Sequence * input,
  fwp_planner__msg__FusedTeammate__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FWP_PLANNER__MSG__DETAIL__FUSED_TEAMMATE__FUNCTIONS_H_
