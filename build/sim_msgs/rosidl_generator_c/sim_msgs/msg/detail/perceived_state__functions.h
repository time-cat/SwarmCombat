// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from sim_msgs:msg/PerceivedState.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__PERCEIVED_STATE__FUNCTIONS_H_
#define SIM_MSGS__MSG__DETAIL__PERCEIVED_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "sim_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "sim_msgs/msg/detail/perceived_state__struct.h"

/// Initialize msg/PerceivedState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sim_msgs__msg__PerceivedState
 * )) before or use
 * sim_msgs__msg__PerceivedState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__PerceivedState__init(sim_msgs__msg__PerceivedState * msg);

/// Finalize msg/PerceivedState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
void
sim_msgs__msg__PerceivedState__fini(sim_msgs__msg__PerceivedState * msg);

/// Create msg/PerceivedState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sim_msgs__msg__PerceivedState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
sim_msgs__msg__PerceivedState *
sim_msgs__msg__PerceivedState__create();

/// Destroy msg/PerceivedState message.
/**
 * It calls
 * sim_msgs__msg__PerceivedState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
void
sim_msgs__msg__PerceivedState__destroy(sim_msgs__msg__PerceivedState * msg);

/// Check for msg/PerceivedState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__PerceivedState__are_equal(const sim_msgs__msg__PerceivedState * lhs, const sim_msgs__msg__PerceivedState * rhs);

/// Copy a msg/PerceivedState message.
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
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__PerceivedState__copy(
  const sim_msgs__msg__PerceivedState * input,
  sim_msgs__msg__PerceivedState * output);

/// Initialize array of msg/PerceivedState messages.
/**
 * It allocates the memory for the number of elements and calls
 * sim_msgs__msg__PerceivedState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__PerceivedState__Sequence__init(sim_msgs__msg__PerceivedState__Sequence * array, size_t size);

/// Finalize array of msg/PerceivedState messages.
/**
 * It calls
 * sim_msgs__msg__PerceivedState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
void
sim_msgs__msg__PerceivedState__Sequence__fini(sim_msgs__msg__PerceivedState__Sequence * array);

/// Create array of msg/PerceivedState messages.
/**
 * It allocates the memory for the array and calls
 * sim_msgs__msg__PerceivedState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
sim_msgs__msg__PerceivedState__Sequence *
sim_msgs__msg__PerceivedState__Sequence__create(size_t size);

/// Destroy array of msg/PerceivedState messages.
/**
 * It calls
 * sim_msgs__msg__PerceivedState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
void
sim_msgs__msg__PerceivedState__Sequence__destroy(sim_msgs__msg__PerceivedState__Sequence * array);

/// Check for msg/PerceivedState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__PerceivedState__Sequence__are_equal(const sim_msgs__msg__PerceivedState__Sequence * lhs, const sim_msgs__msg__PerceivedState__Sequence * rhs);

/// Copy an array of msg/PerceivedState messages.
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
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__PerceivedState__Sequence__copy(
  const sim_msgs__msg__PerceivedState__Sequence * input,
  sim_msgs__msg__PerceivedState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SIM_MSGS__MSG__DETAIL__PERCEIVED_STATE__FUNCTIONS_H_
