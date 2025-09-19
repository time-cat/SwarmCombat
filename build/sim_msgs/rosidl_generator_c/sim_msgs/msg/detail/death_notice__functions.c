// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sim_msgs:msg/DeathNotice.idl
// generated code does not contain a copyright notice
#include "sim_msgs/msg/detail/death_notice__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
sim_msgs__msg__DeathNotice__init(sim_msgs__msg__DeathNotice * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    sim_msgs__msg__DeathNotice__fini(msg);
    return false;
  }
  // death
  return true;
}

void
sim_msgs__msg__DeathNotice__fini(sim_msgs__msg__DeathNotice * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // death
}

bool
sim_msgs__msg__DeathNotice__are_equal(const sim_msgs__msg__DeathNotice * lhs, const sim_msgs__msg__DeathNotice * rhs)
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
  // death
  if (lhs->death != rhs->death) {
    return false;
  }
  return true;
}

bool
sim_msgs__msg__DeathNotice__copy(
  const sim_msgs__msg__DeathNotice * input,
  sim_msgs__msg__DeathNotice * output)
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
  // death
  output->death = input->death;
  return true;
}

sim_msgs__msg__DeathNotice *
sim_msgs__msg__DeathNotice__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sim_msgs__msg__DeathNotice * msg = (sim_msgs__msg__DeathNotice *)allocator.allocate(sizeof(sim_msgs__msg__DeathNotice), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sim_msgs__msg__DeathNotice));
  bool success = sim_msgs__msg__DeathNotice__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sim_msgs__msg__DeathNotice__destroy(sim_msgs__msg__DeathNotice * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sim_msgs__msg__DeathNotice__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sim_msgs__msg__DeathNotice__Sequence__init(sim_msgs__msg__DeathNotice__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sim_msgs__msg__DeathNotice * data = NULL;

  if (size) {
    data = (sim_msgs__msg__DeathNotice *)allocator.zero_allocate(size, sizeof(sim_msgs__msg__DeathNotice), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sim_msgs__msg__DeathNotice__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sim_msgs__msg__DeathNotice__fini(&data[i - 1]);
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
sim_msgs__msg__DeathNotice__Sequence__fini(sim_msgs__msg__DeathNotice__Sequence * array)
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
      sim_msgs__msg__DeathNotice__fini(&array->data[i]);
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

sim_msgs__msg__DeathNotice__Sequence *
sim_msgs__msg__DeathNotice__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sim_msgs__msg__DeathNotice__Sequence * array = (sim_msgs__msg__DeathNotice__Sequence *)allocator.allocate(sizeof(sim_msgs__msg__DeathNotice__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sim_msgs__msg__DeathNotice__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sim_msgs__msg__DeathNotice__Sequence__destroy(sim_msgs__msg__DeathNotice__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sim_msgs__msg__DeathNotice__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sim_msgs__msg__DeathNotice__Sequence__are_equal(const sim_msgs__msg__DeathNotice__Sequence * lhs, const sim_msgs__msg__DeathNotice__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sim_msgs__msg__DeathNotice__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sim_msgs__msg__DeathNotice__Sequence__copy(
  const sim_msgs__msg__DeathNotice__Sequence * input,
  sim_msgs__msg__DeathNotice__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sim_msgs__msg__DeathNotice);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sim_msgs__msg__DeathNotice * data =
      (sim_msgs__msg__DeathNotice *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sim_msgs__msg__DeathNotice__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sim_msgs__msg__DeathNotice__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sim_msgs__msg__DeathNotice__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
