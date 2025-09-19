// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from sim_msgs:msg/ExplosionReport.idl
// generated code does not contain a copyright notice

#ifndef SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__FUNCTIONS_H_
#define SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "sim_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "sim_msgs/msg/detail/explosion_report__struct.h"

/// Initialize msg/ExplosionReport message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sim_msgs__msg__ExplosionReport
 * )) before or use
 * sim_msgs__msg__ExplosionReport__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__ExplosionReport__init(sim_msgs__msg__ExplosionReport * msg);

/// Finalize msg/ExplosionReport message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
void
sim_msgs__msg__ExplosionReport__fini(sim_msgs__msg__ExplosionReport * msg);

/// Create msg/ExplosionReport message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sim_msgs__msg__ExplosionReport__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
sim_msgs__msg__ExplosionReport *
sim_msgs__msg__ExplosionReport__create();

/// Destroy msg/ExplosionReport message.
/**
 * It calls
 * sim_msgs__msg__ExplosionReport__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
void
sim_msgs__msg__ExplosionReport__destroy(sim_msgs__msg__ExplosionReport * msg);

/// Check for msg/ExplosionReport message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__ExplosionReport__are_equal(const sim_msgs__msg__ExplosionReport * lhs, const sim_msgs__msg__ExplosionReport * rhs);

/// Copy a msg/ExplosionReport message.
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
sim_msgs__msg__ExplosionReport__copy(
  const sim_msgs__msg__ExplosionReport * input,
  sim_msgs__msg__ExplosionReport * output);

/// Initialize array of msg/ExplosionReport messages.
/**
 * It allocates the memory for the number of elements and calls
 * sim_msgs__msg__ExplosionReport__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__ExplosionReport__Sequence__init(sim_msgs__msg__ExplosionReport__Sequence * array, size_t size);

/// Finalize array of msg/ExplosionReport messages.
/**
 * It calls
 * sim_msgs__msg__ExplosionReport__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
void
sim_msgs__msg__ExplosionReport__Sequence__fini(sim_msgs__msg__ExplosionReport__Sequence * array);

/// Create array of msg/ExplosionReport messages.
/**
 * It allocates the memory for the array and calls
 * sim_msgs__msg__ExplosionReport__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
sim_msgs__msg__ExplosionReport__Sequence *
sim_msgs__msg__ExplosionReport__Sequence__create(size_t size);

/// Destroy array of msg/ExplosionReport messages.
/**
 * It calls
 * sim_msgs__msg__ExplosionReport__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
void
sim_msgs__msg__ExplosionReport__Sequence__destroy(sim_msgs__msg__ExplosionReport__Sequence * array);

/// Check for msg/ExplosionReport message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sim_msgs
bool
sim_msgs__msg__ExplosionReport__Sequence__are_equal(const sim_msgs__msg__ExplosionReport__Sequence * lhs, const sim_msgs__msg__ExplosionReport__Sequence * rhs);

/// Copy an array of msg/ExplosionReport messages.
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
sim_msgs__msg__ExplosionReport__Sequence__copy(
  const sim_msgs__msg__ExplosionReport__Sequence * input,
  sim_msgs__msg__ExplosionReport__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SIM_MSGS__MSG__DETAIL__EXPLOSION_REPORT__FUNCTIONS_H_
