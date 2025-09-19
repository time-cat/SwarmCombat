// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from fwp_planner:msg/DynamicState.idl
// generated code does not contain a copyright notice

#ifndef FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__FUNCTIONS_H_
#define FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "fwp_planner/msg/rosidl_generator_c__visibility_control.h"

#include "fwp_planner/msg/detail/dynamic_state__struct.h"

/// Initialize msg/DynamicState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * fwp_planner__msg__DynamicState
 * )) before or use
 * fwp_planner__msg__DynamicState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__DynamicState__init(fwp_planner__msg__DynamicState * msg);

/// Finalize msg/DynamicState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
void
fwp_planner__msg__DynamicState__fini(fwp_planner__msg__DynamicState * msg);

/// Create msg/DynamicState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * fwp_planner__msg__DynamicState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
fwp_planner__msg__DynamicState *
fwp_planner__msg__DynamicState__create();

/// Destroy msg/DynamicState message.
/**
 * It calls
 * fwp_planner__msg__DynamicState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
void
fwp_planner__msg__DynamicState__destroy(fwp_planner__msg__DynamicState * msg);

/// Check for msg/DynamicState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__DynamicState__are_equal(const fwp_planner__msg__DynamicState * lhs, const fwp_planner__msg__DynamicState * rhs);

/// Copy a msg/DynamicState message.
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
fwp_planner__msg__DynamicState__copy(
  const fwp_planner__msg__DynamicState * input,
  fwp_planner__msg__DynamicState * output);

/// Initialize array of msg/DynamicState messages.
/**
 * It allocates the memory for the number of elements and calls
 * fwp_planner__msg__DynamicState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__DynamicState__Sequence__init(fwp_planner__msg__DynamicState__Sequence * array, size_t size);

/// Finalize array of msg/DynamicState messages.
/**
 * It calls
 * fwp_planner__msg__DynamicState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
void
fwp_planner__msg__DynamicState__Sequence__fini(fwp_planner__msg__DynamicState__Sequence * array);

/// Create array of msg/DynamicState messages.
/**
 * It allocates the memory for the array and calls
 * fwp_planner__msg__DynamicState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
fwp_planner__msg__DynamicState__Sequence *
fwp_planner__msg__DynamicState__Sequence__create(size_t size);

/// Destroy array of msg/DynamicState messages.
/**
 * It calls
 * fwp_planner__msg__DynamicState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
void
fwp_planner__msg__DynamicState__Sequence__destroy(fwp_planner__msg__DynamicState__Sequence * array);

/// Check for msg/DynamicState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fwp_planner
bool
fwp_planner__msg__DynamicState__Sequence__are_equal(const fwp_planner__msg__DynamicState__Sequence * lhs, const fwp_planner__msg__DynamicState__Sequence * rhs);

/// Copy an array of msg/DynamicState messages.
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
fwp_planner__msg__DynamicState__Sequence__copy(
  const fwp_planner__msg__DynamicState__Sequence * input,
  fwp_planner__msg__DynamicState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FWP_PLANNER__MSG__DETAIL__DYNAMIC_STATE__FUNCTIONS_H_
