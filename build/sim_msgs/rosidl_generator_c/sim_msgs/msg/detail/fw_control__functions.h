// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from sim_msgs:msg/FwControl.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__FW_CONTROL__FUNCTIONS_H_
#define SIM_MSGS__MSG__DETAIL__FW_CONTROL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "sim_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "sim_msgs/msg/detail/fw_control__struct.h"

/// Initialize msg/FwControl message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sim_msgs__msg__FwControl
 * )) before or use
 * sim_msgs__msg__FwControl__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__FwControl__init(sim_msgs__msg__FwControl * msg);

/// Finalize msg/FwControl message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
void
sim_msgs__msg__FwControl__fini(sim_msgs__msg__FwControl * msg);

/// Create msg/FwControl message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sim_msgs__msg__FwControl__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
sim_msgs__msg__FwControl *
sim_msgs__msg__FwControl__create();

/// Destroy msg/FwControl message.
/**
 * It calls
 * sim_msgs__msg__FwControl__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
void
sim_msgs__msg__FwControl__destroy(sim_msgs__msg__FwControl * msg);

/// Check for msg/FwControl message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__FwControl__are_equal(const sim_msgs__msg__FwControl * lhs, const sim_msgs__msg__FwControl * rhs);

/// Copy a msg/FwControl message.
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
sim_msgs__msg__FwControl__copy(
  const sim_msgs__msg__FwControl * input,
  sim_msgs__msg__FwControl * output);

/// Initialize array of msg/FwControl messages.
/**
 * It allocates the memory for the number of elements and calls
 * sim_msgs__msg__FwControl__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__FwControl__Sequence__init(sim_msgs__msg__FwControl__Sequence * array, size_t size);

/// Finalize array of msg/FwControl messages.
/**
 * It calls
 * sim_msgs__msg__FwControl__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
void
sim_msgs__msg__FwControl__Sequence__fini(sim_msgs__msg__FwControl__Sequence * array);

/// Create array of msg/FwControl messages.
/**
 * It allocates the memory for the array and calls
 * sim_msgs__msg__FwControl__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
sim_msgs__msg__FwControl__Sequence *
sim_msgs__msg__FwControl__Sequence__create(size_t size);

/// Destroy array of msg/FwControl messages.
/**
 * It calls
 * sim_msgs__msg__FwControl__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
void
sim_msgs__msg__FwControl__Sequence__destroy(sim_msgs__msg__FwControl__Sequence * array);

/// Check for msg/FwControl message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__FwControl__Sequence__are_equal(const sim_msgs__msg__FwControl__Sequence * lhs, const sim_msgs__msg__FwControl__Sequence * rhs);

/// Copy an array of msg/FwControl messages.
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
sim_msgs__msg__FwControl__Sequence__copy(
  const sim_msgs__msg__FwControl__Sequence * input,
  sim_msgs__msg__FwControl__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SIM_MSGS__MSG__DETAIL__FW_CONTROL__FUNCTIONS_H_
