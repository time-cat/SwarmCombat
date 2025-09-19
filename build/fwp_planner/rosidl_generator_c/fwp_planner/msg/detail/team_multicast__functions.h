// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from fwp_planner:msg/TeamMulticast.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__FUNCTIONS_H_
#define FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "fwp_planner/msg/rosidl_generator_c__visibility_control.h"

#include "fwp_planner/msg/detail/team_multicast__struct.h"

/// Initialize msg/TeamMulticast message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * fwp_planner__msg__TeamMulticast
 * )) before or use
 * fwp_planner__msg__TeamMulticast__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__TeamMulticast__init(fwp_planner__msg__TeamMulticast * msg);

/// Finalize msg/TeamMulticast message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
void
fwp_planner__msg__TeamMulticast__fini(fwp_planner__msg__TeamMulticast * msg);

/// Create msg/TeamMulticast message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * fwp_planner__msg__TeamMulticast__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
fwp_planner__msg__TeamMulticast *
fwp_planner__msg__TeamMulticast__create();

/// Destroy msg/TeamMulticast message.
/**
 * It calls
 * fwp_planner__msg__TeamMulticast__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
void
fwp_planner__msg__TeamMulticast__destroy(fwp_planner__msg__TeamMulticast * msg);

/// Check for msg/TeamMulticast message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__TeamMulticast__are_equal(const fwp_planner__msg__TeamMulticast * lhs, const fwp_planner__msg__TeamMulticast * rhs);

/// Copy a msg/TeamMulticast message.
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
fwp_planner__msg__TeamMulticast__copy(
  const fwp_planner__msg__TeamMulticast * input,
  fwp_planner__msg__TeamMulticast * output);

/// Initialize array of msg/TeamMulticast messages.
/**
 * It allocates the memory for the number of elements and calls
 * fwp_planner__msg__TeamMulticast__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__TeamMulticast__Sequence__init(fwp_planner__msg__TeamMulticast__Sequence * array, size_t size);

/// Finalize array of msg/TeamMulticast messages.
/**
 * It calls
 * fwp_planner__msg__TeamMulticast__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
void
fwp_planner__msg__TeamMulticast__Sequence__fini(fwp_planner__msg__TeamMulticast__Sequence * array);

/// Create array of msg/TeamMulticast messages.
/**
 * It allocates the memory for the array and calls
 * fwp_planner__msg__TeamMulticast__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
fwp_planner__msg__TeamMulticast__Sequence *
fwp_planner__msg__TeamMulticast__Sequence__create(size_t size);

/// Destroy array of msg/TeamMulticast messages.
/**
 * It calls
 * fwp_planner__msg__TeamMulticast__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
void
fwp_planner__msg__TeamMulticast__Sequence__destroy(fwp_planner__msg__TeamMulticast__Sequence * array);

/// Check for msg/TeamMulticast message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__TeamMulticast__Sequence__are_equal(const fwp_planner__msg__TeamMulticast__Sequence * lhs, const fwp_planner__msg__TeamMulticast__Sequence * rhs);

/// Copy an array of msg/TeamMulticast messages.
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
fwp_planner__msg__TeamMulticast__Sequence__copy(
  const fwp_planner__msg__TeamMulticast__Sequence * input,
  fwp_planner__msg__TeamMulticast__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FWP_PLANNER__MSG__DETAIL__TEAM_MULTICAST__FUNCTIONS_H_
