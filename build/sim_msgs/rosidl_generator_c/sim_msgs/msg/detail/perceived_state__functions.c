// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sim_msgs:msg/PerceivedState.idl
// generated code does not contain a copyright notice
#include "sim_msgs/msg/detail/perceived_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
sim_msgs__msg__PerceivedState__init(sim_msgs__msg__PerceivedState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    sim_msgs__msg__PerceivedState__fini(msg);
    return false;
  }
  // id
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    sim_msgs__msg__PerceivedState__fini(msg);
    return false;
  }
  // is_alive
  return true;
}

void
sim_msgs__msg__PerceivedState__fini(sim_msgs__msg__PerceivedState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // id
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // is_alive
}

bool
sim_msgs__msg__PerceivedState__are_equal(const sim_msgs__msg__PerceivedState * lhs, const sim_msgs__msg__PerceivedState * rhs)
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
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
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
sim_msgs__msg__PerceivedState__copy(
  const sim_msgs__msg__PerceivedState * input,
  sim_msgs__msg__PerceivedState * output)
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
  // id
  output->id = input->id;
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // is_alive
  output->is_alive = input->is_alive;
  return true;
}

sim_msgs__msg__PerceivedState *
sim_msgs__msg__PerceivedState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sim_msgs__msg__PerceivedState * msg = (sim_msgs__msg__PerceivedState *)allocator.allocate(sizeof(sim_msgs__msg__PerceivedState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sim_msgs__msg__PerceivedState));
  bool success = sim_msgs__msg__PerceivedState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sim_msgs__msg__PerceivedState__destroy(sim_msgs__msg__PerceivedState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sim_msgs__msg__PerceivedState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sim_msgs__msg__PerceivedState__Sequence__init(sim_msgs__msg__PerceivedState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sim_msgs__msg__PerceivedState * data = NULL;

  if (size) {
    data = (sim_msgs__msg__PerceivedState *)allocator.zero_allocate(size, sizeof(sim_msgs__msg__PerceivedState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sim_msgs__msg__PerceivedState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sim_msgs__msg__PerceivedState__fini(&data[i - 1]);
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
sim_msgs__msg__PerceivedState__Sequence__fini(sim_msgs__msg__PerceivedState__Sequence * array)
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
      sim_msgs__msg__PerceivedState__fini(&array->data[i]);
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

sim_msgs__msg__PerceivedState__Sequence *
sim_msgs__msg__PerceivedState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sim_msgs__msg__PerceivedState__Sequence * array = (sim_msgs__msg__PerceivedState__Sequence *)allocator.allocate(sizeof(sim_msgs__msg__PerceivedState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sim_msgs__msg__PerceivedState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sim_msgs__msg__PerceivedState__Sequence__destroy(sim_msgs__msg__PerceivedState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sim_msgs__msg__PerceivedState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sim_msgs__msg__PerceivedState__Sequence__are_equal(const sim_msgs__msg__PerceivedState__Sequence * lhs, const sim_msgs__msg__PerceivedState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sim_msgs__msg__PerceivedState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sim_msgs__msg__PerceivedState__Sequence__copy(
  const sim_msgs__msg__PerceivedState__Sequence * input,
  sim_msgs__msg__PerceivedState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sim_msgs__msg__PerceivedState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sim_msgs__msg__PerceivedState * data =
      (sim_msgs__msg__PerceivedState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sim_msgs__msg__PerceivedState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sim_msgs__msg__PerceivedState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sim_msgs__msg__PerceivedState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
