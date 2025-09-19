// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fwp_planner:msg/FusedEnemy.idl
// generated code does not contain a copyright notice
#include "fwp_planner/msg/detail/fused_enemy__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
fwp_planner__msg__FusedEnemy__init(fwp_planner__msg__FusedEnemy * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    fwp_planner__msg__FusedEnemy__fini(msg);
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->timestamp)) {
    fwp_planner__msg__FusedEnemy__fini(msg);
    return false;
  }
  return true;
}

void
fwp_planner__msg__FusedEnemy__fini(fwp_planner__msg__FusedEnemy * msg)
{
  if (!msg) {
    return;
  }
  // id
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // timestamp
  builtin_interfaces__msg__Time__fini(&msg->timestamp);
}

bool
fwp_planner__msg__FusedEnemy__are_equal(const fwp_planner__msg__FusedEnemy * lhs, const fwp_planner__msg__FusedEnemy * rhs)
{
  if (!lhs || !rhs) {
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
  // timestamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->timestamp), &(rhs->timestamp)))
  {
    return false;
  }
  return true;
}

bool
fwp_planner__msg__FusedEnemy__copy(
  const fwp_planner__msg__FusedEnemy * input,
  fwp_planner__msg__FusedEnemy * output)
{
  if (!input || !output) {
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
  // timestamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->timestamp), &(output->timestamp)))
  {
    return false;
  }
  return true;
}

fwp_planner__msg__FusedEnemy *
fwp_planner__msg__FusedEnemy__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__FusedEnemy * msg = (fwp_planner__msg__FusedEnemy *)allocator.allocate(sizeof(fwp_planner__msg__FusedEnemy), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fwp_planner__msg__FusedEnemy));
  bool success = fwp_planner__msg__FusedEnemy__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fwp_planner__msg__FusedEnemy__destroy(fwp_planner__msg__FusedEnemy * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fwp_planner__msg__FusedEnemy__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fwp_planner__msg__FusedEnemy__Sequence__init(fwp_planner__msg__FusedEnemy__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__FusedEnemy * data = NULL;

  if (size) {
    data = (fwp_planner__msg__FusedEnemy *)allocator.zero_allocate(size, sizeof(fwp_planner__msg__FusedEnemy), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fwp_planner__msg__FusedEnemy__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fwp_planner__msg__FusedEnemy__fini(&data[i - 1]);
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
fwp_planner__msg__FusedEnemy__Sequence__fini(fwp_planner__msg__FusedEnemy__Sequence * array)
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
      fwp_planner__msg__FusedEnemy__fini(&array->data[i]);
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

fwp_planner__msg__FusedEnemy__Sequence *
fwp_planner__msg__FusedEnemy__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__FusedEnemy__Sequence * array = (fwp_planner__msg__FusedEnemy__Sequence *)allocator.allocate(sizeof(fwp_planner__msg__FusedEnemy__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fwp_planner__msg__FusedEnemy__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fwp_planner__msg__FusedEnemy__Sequence__destroy(fwp_planner__msg__FusedEnemy__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fwp_planner__msg__FusedEnemy__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fwp_planner__msg__FusedEnemy__Sequence__are_equal(const fwp_planner__msg__FusedEnemy__Sequence * lhs, const fwp_planner__msg__FusedEnemy__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fwp_planner__msg__FusedEnemy__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fwp_planner__msg__FusedEnemy__Sequence__copy(
  const fwp_planner__msg__FusedEnemy__Sequence * input,
  fwp_planner__msg__FusedEnemy__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fwp_planner__msg__FusedEnemy);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fwp_planner__msg__FusedEnemy * data =
      (fwp_planner__msg__FusedEnemy *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fwp_planner__msg__FusedEnemy__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fwp_planner__msg__FusedEnemy__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fwp_planner__msg__FusedEnemy__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
