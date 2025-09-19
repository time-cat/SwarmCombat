// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fwp_planner:msg/FusedTeammate.idl
// generated code does not contain a copyright notice
#include "fwp_planner/msg/detail/fused_teammate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
fwp_planner__msg__FusedTeammate__init(fwp_planner__msg__FusedTeammate * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // target_id
  // timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->timestamp)) {
    fwp_planner__msg__FusedTeammate__fini(msg);
    return false;
  }
  return true;
}

void
fwp_planner__msg__FusedTeammate__fini(fwp_planner__msg__FusedTeammate * msg)
{
  if (!msg) {
    return;
  }
  // id
  // target_id
  // timestamp
  builtin_interfaces__msg__Time__fini(&msg->timestamp);
}

bool
fwp_planner__msg__FusedTeammate__are_equal(const fwp_planner__msg__FusedTeammate * lhs, const fwp_planner__msg__FusedTeammate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // target_id
  if (lhs->target_id != rhs->target_id) {
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
fwp_planner__msg__FusedTeammate__copy(
  const fwp_planner__msg__FusedTeammate * input,
  fwp_planner__msg__FusedTeammate * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // target_id
  output->target_id = input->target_id;
  // timestamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->timestamp), &(output->timestamp)))
  {
    return false;
  }
  return true;
}

fwp_planner__msg__FusedTeammate *
fwp_planner__msg__FusedTeammate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__FusedTeammate * msg = (fwp_planner__msg__FusedTeammate *)allocator.allocate(sizeof(fwp_planner__msg__FusedTeammate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fwp_planner__msg__FusedTeammate));
  bool success = fwp_planner__msg__FusedTeammate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fwp_planner__msg__FusedTeammate__destroy(fwp_planner__msg__FusedTeammate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fwp_planner__msg__FusedTeammate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fwp_planner__msg__FusedTeammate__Sequence__init(fwp_planner__msg__FusedTeammate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__FusedTeammate * data = NULL;

  if (size) {
    data = (fwp_planner__msg__FusedTeammate *)allocator.zero_allocate(size, sizeof(fwp_planner__msg__FusedTeammate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fwp_planner__msg__FusedTeammate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fwp_planner__msg__FusedTeammate__fini(&data[i - 1]);
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
fwp_planner__msg__FusedTeammate__Sequence__fini(fwp_planner__msg__FusedTeammate__Sequence * array)
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
      fwp_planner__msg__FusedTeammate__fini(&array->data[i]);
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

fwp_planner__msg__FusedTeammate__Sequence *
fwp_planner__msg__FusedTeammate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__FusedTeammate__Sequence * array = (fwp_planner__msg__FusedTeammate__Sequence *)allocator.allocate(sizeof(fwp_planner__msg__FusedTeammate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fwp_planner__msg__FusedTeammate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fwp_planner__msg__FusedTeammate__Sequence__destroy(fwp_planner__msg__FusedTeammate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fwp_planner__msg__FusedTeammate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fwp_planner__msg__FusedTeammate__Sequence__are_equal(const fwp_planner__msg__FusedTeammate__Sequence * lhs, const fwp_planner__msg__FusedTeammate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fwp_planner__msg__FusedTeammate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fwp_planner__msg__FusedTeammate__Sequence__copy(
  const fwp_planner__msg__FusedTeammate__Sequence * input,
  fwp_planner__msg__FusedTeammate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fwp_planner__msg__FusedTeammate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fwp_planner__msg__FusedTeammate * data =
      (fwp_planner__msg__FusedTeammate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fwp_planner__msg__FusedTeammate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fwp_planner__msg__FusedTeammate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fwp_planner__msg__FusedTeammate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
