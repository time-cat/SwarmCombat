// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fwp_planner:msg/TeamBroadcast.idl
// generated code does not contain a copyright notice
#include "fwp_planner/msg/detail/team_broadcast__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `dynamic_state`
#include "fwp_planner/msg/detail/dynamic_state__functions.h"

bool
fwp_planner__msg__TeamBroadcast__init(fwp_planner__msg__TeamBroadcast * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    fwp_planner__msg__TeamBroadcast__fini(msg);
    return false;
  }
  // sender_id
  // broadcast_range
  // dynamic_state
  if (!fwp_planner__msg__DynamicState__init(&msg->dynamic_state)) {
    fwp_planner__msg__TeamBroadcast__fini(msg);
    return false;
  }
  // is_alive
  return true;
}

void
fwp_planner__msg__TeamBroadcast__fini(fwp_planner__msg__TeamBroadcast * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // sender_id
  // broadcast_range
  // dynamic_state
  fwp_planner__msg__DynamicState__fini(&msg->dynamic_state);
  // is_alive
}

bool
fwp_planner__msg__TeamBroadcast__are_equal(const fwp_planner__msg__TeamBroadcast * lhs, const fwp_planner__msg__TeamBroadcast * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // sender_id
  if (lhs->sender_id != rhs->sender_id) {
    return false;
  }
  // broadcast_range
  if (lhs->broadcast_range != rhs->broadcast_range) {
    return false;
  }
  // dynamic_state
  if (!fwp_planner__msg__DynamicState__are_equal(
      &(lhs->dynamic_state), &(rhs->dynamic_state)))
  {
    return false;
  }
  // is_alive
  if (lhs->is_alive != rhs->is_alive) {
    return false;
  }
  return true;
}

bool
fwp_planner__msg__TeamBroadcast__copy(
  const fwp_planner__msg__TeamBroadcast * input,
  fwp_planner__msg__TeamBroadcast * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // sender_id
  output->sender_id = input->sender_id;
  // broadcast_range
  output->broadcast_range = input->broadcast_range;
  // dynamic_state
  if (!fwp_planner__msg__DynamicState__copy(
      &(input->dynamic_state), &(output->dynamic_state)))
  {
    return false;
  }
  // is_alive
  output->is_alive = input->is_alive;
  return true;
}

fwp_planner__msg__TeamBroadcast *
fwp_planner__msg__TeamBroadcast__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__TeamBroadcast * msg = (fwp_planner__msg__TeamBroadcast *)allocator.allocate(sizeof(fwp_planner__msg__TeamBroadcast), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fwp_planner__msg__TeamBroadcast));
  bool success = fwp_planner__msg__TeamBroadcast__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fwp_planner__msg__TeamBroadcast__destroy(fwp_planner__msg__TeamBroadcast * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fwp_planner__msg__TeamBroadcast__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fwp_planner__msg__TeamBroadcast__Sequence__init(fwp_planner__msg__TeamBroadcast__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__TeamBroadcast * data = NULL;

  if (size) {
    data = (fwp_planner__msg__TeamBroadcast *)allocator.zero_allocate(size, sizeof(fwp_planner__msg__TeamBroadcast), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fwp_planner__msg__TeamBroadcast__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fwp_planner__msg__TeamBroadcast__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fwp_planner__msg__TeamBroadcast__Sequence__fini(fwp_planner__msg__TeamBroadcast__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fwp_planner__msg__TeamBroadcast__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fwp_planner__msg__TeamBroadcast__Sequence *
fwp_planner__msg__TeamBroadcast__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__TeamBroadcast__Sequence * array = (fwp_planner__msg__TeamBroadcast__Sequence *)allocator.allocate(sizeof(fwp_planner__msg__TeamBroadcast__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fwp_planner__msg__TeamBroadcast__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fwp_planner__msg__TeamBroadcast__Sequence__destroy(fwp_planner__msg__TeamBroadcast__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fwp_planner__msg__TeamBroadcast__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fwp_planner__msg__TeamBroadcast__Sequence__are_equal(const fwp_planner__msg__TeamBroadcast__Sequence * lhs, const fwp_planner__msg__TeamBroadcast__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fwp_planner__msg__TeamBroadcast__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fwp_planner__msg__TeamBroadcast__Sequence__copy(
  const fwp_planner__msg__TeamBroadcast__Sequence * input,
  fwp_planner__msg__TeamBroadcast__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fwp_planner__msg__TeamBroadcast);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fwp_planner__msg__TeamBroadcast * data =
      (fwp_planner__msg__TeamBroadcast *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fwp_planner__msg__TeamBroadcast__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fwp_planner__msg__TeamBroadcast__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fwp_planner__msg__TeamBroadcast__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
