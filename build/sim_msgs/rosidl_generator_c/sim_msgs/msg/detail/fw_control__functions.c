// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sim_msgs:msg/FwControl.idl
// generated code does not contain a copyright notice
#include "sim_msgs/msg/detail/fw_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
sim_msgs__msg__FwControl__init(sim_msgs__msg__FwControl * msg)
{
  if (!msg) {
    return false;
  }
  // desired_roll
  // desired_pitch
  // desired_yaw_rate
  // desired_airspeed
  return true;
}

void
sim_msgs__msg__FwControl__fini(sim_msgs__msg__FwControl * msg)
{
  if (!msg) {
    return;
  }
  // desired_roll
  // desired_pitch
  // desired_yaw_rate
  // desired_airspeed
}

bool
sim_msgs__msg__FwControl__are_equal(const sim_msgs__msg__FwControl * lhs, const sim_msgs__msg__FwControl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // desired_roll
  if (lhs->desired_roll != rhs->desired_roll) {
    return false;
  }
  // desired_pitch
  if (lhs->desired_pitch != rhs->desired_pitch) {
    return false;
  }
  // desired_yaw_rate
  if (lhs->desired_yaw_rate != rhs->desired_yaw_rate) {
    return false;
  }
  // desired_airspeed
  if (lhs->desired_airspeed != rhs->desired_airspeed) {
    return false;
  }
  return true;
}

bool
sim_msgs__msg__FwControl__copy(
  const sim_msgs__msg__FwControl * input,
  sim_msgs__msg__FwControl * output)
{
  if (!input || !output) {
    return false;
  }
  // desired_roll
  output->desired_roll = input->desired_roll;
  // desired_pitch
  output->desired_pitch = input->desired_pitch;
  // desired_yaw_rate
  output->desired_yaw_rate = input->desired_yaw_rate;
  // desired_airspeed
  output->desired_airspeed = input->desired_airspeed;
  return true;
}

sim_msgs__msg__FwControl *
sim_msgs__msg__FwControl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sim_msgs__msg__FwControl * msg = (sim_msgs__msg__FwControl *)allocator.allocate(sizeof(sim_msgs__msg__FwControl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sim_msgs__msg__FwControl));
  bool success = sim_msgs__msg__FwControl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sim_msgs__msg__FwControl__destroy(sim_msgs__msg__FwControl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sim_msgs__msg__FwControl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sim_msgs__msg__FwControl__Sequence__init(sim_msgs__msg__FwControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sim_msgs__msg__FwControl * data = NULL;

  if (size) {
    data = (sim_msgs__msg__FwControl *)allocator.zero_allocate(size, sizeof(sim_msgs__msg__FwControl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sim_msgs__msg__FwControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sim_msgs__msg__FwControl__fini(&data[i - 1]);
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
sim_msgs__msg__FwControl__Sequence__fini(sim_msgs__msg__FwControl__Sequence * array)
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
      sim_msgs__msg__FwControl__fini(&array->data[i]);
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

sim_msgs__msg__FwControl__Sequence *
sim_msgs__msg__FwControl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sim_msgs__msg__FwControl__Sequence * array = (sim_msgs__msg__FwControl__Sequence *)allocator.allocate(sizeof(sim_msgs__msg__FwControl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sim_msgs__msg__FwControl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sim_msgs__msg__FwControl__Sequence__destroy(sim_msgs__msg__FwControl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sim_msgs__msg__FwControl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sim_msgs__msg__FwControl__Sequence__are_equal(const sim_msgs__msg__FwControl__Sequence * lhs, const sim_msgs__msg__FwControl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sim_msgs__msg__FwControl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sim_msgs__msg__FwControl__Sequence__copy(
  const sim_msgs__msg__FwControl__Sequence * input,
  sim_msgs__msg__FwControl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sim_msgs__msg__FwControl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sim_msgs__msg__FwControl * data =
      (sim_msgs__msg__FwControl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sim_msgs__msg__FwControl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sim_msgs__msg__FwControl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sim_msgs__msg__FwControl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
