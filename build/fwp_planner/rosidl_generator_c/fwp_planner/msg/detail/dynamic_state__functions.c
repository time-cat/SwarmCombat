// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fwp_planner:msg/DynamicState.idl
// generated code does not contain a copyright notice
#include "fwp_planner/msg/detail/dynamic_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
fwp_planner__msg__DynamicState__init(fwp_planner__msg__DynamicState * msg)
{
  if (!msg) {
    return false;
  }
  // posi_n
  // posi_e
  // posi_d
  // orient_x
  // orient_y
  // orient_z
  // orient_w
  // vel
  // vel_alpha
  // vel_bete
  // angle_alpha
  // abgle_bete
  return true;
}

void
fwp_planner__msg__DynamicState__fini(fwp_planner__msg__DynamicState * msg)
{
  if (!msg) {
    return;
  }
  // posi_n
  // posi_e
  // posi_d
  // orient_x
  // orient_y
  // orient_z
  // orient_w
  // vel
  // vel_alpha
  // vel_bete
  // angle_alpha
  // abgle_bete
}

bool
fwp_planner__msg__DynamicState__are_equal(const fwp_planner__msg__DynamicState * lhs, const fwp_planner__msg__DynamicState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // posi_n
  if (lhs->posi_n != rhs->posi_n) {
    return false;
  }
  // posi_e
  if (lhs->posi_e != rhs->posi_e) {
    return false;
  }
  // posi_d
  if (lhs->posi_d != rhs->posi_d) {
    return false;
  }
  // orient_x
  if (lhs->orient_x != rhs->orient_x) {
    return false;
  }
  // orient_y
  if (lhs->orient_y != rhs->orient_y) {
    return false;
  }
  // orient_z
  if (lhs->orient_z != rhs->orient_z) {
    return false;
  }
  // orient_w
  if (lhs->orient_w != rhs->orient_w) {
    return false;
  }
  // vel
  if (lhs->vel != rhs->vel) {
    return false;
  }
  // vel_alpha
  if (lhs->vel_alpha != rhs->vel_alpha) {
    return false;
  }
  // vel_bete
  if (lhs->vel_bete != rhs->vel_bete) {
    return false;
  }
  // angle_alpha
  if (lhs->angle_alpha != rhs->angle_alpha) {
    return false;
  }
  // abgle_bete
  if (lhs->abgle_bete != rhs->abgle_bete) {
    return false;
  }
  return true;
}

bool
fwp_planner__msg__DynamicState__copy(
  const fwp_planner__msg__DynamicState * input,
  fwp_planner__msg__DynamicState * output)
{
  if (!input || !output) {
    return false;
  }
  // posi_n
  output->posi_n = input->posi_n;
  // posi_e
  output->posi_e = input->posi_e;
  // posi_d
  output->posi_d = input->posi_d;
  // orient_x
  output->orient_x = input->orient_x;
  // orient_y
  output->orient_y = input->orient_y;
  // orient_z
  output->orient_z = input->orient_z;
  // orient_w
  output->orient_w = input->orient_w;
  // vel
  output->vel = input->vel;
  // vel_alpha
  output->vel_alpha = input->vel_alpha;
  // vel_bete
  output->vel_bete = input->vel_bete;
  // angle_alpha
  output->angle_alpha = input->angle_alpha;
  // abgle_bete
  output->abgle_bete = input->abgle_bete;
  return true;
}

fwp_planner__msg__DynamicState *
fwp_planner__msg__DynamicState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__DynamicState * msg = (fwp_planner__msg__DynamicState *)allocator.allocate(sizeof(fwp_planner__msg__DynamicState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fwp_planner__msg__DynamicState));
  bool success = fwp_planner__msg__DynamicState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fwp_planner__msg__DynamicState__destroy(fwp_planner__msg__DynamicState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fwp_planner__msg__DynamicState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fwp_planner__msg__DynamicState__Sequence__init(fwp_planner__msg__DynamicState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__DynamicState * data = NULL;

  if (size) {
    data = (fwp_planner__msg__DynamicState *)allocator.zero_allocate(size, sizeof(fwp_planner__msg__DynamicState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fwp_planner__msg__DynamicState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fwp_planner__msg__DynamicState__fini(&data[i - 1]);
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
fwp_planner__msg__DynamicState__Sequence__fini(fwp_planner__msg__DynamicState__Sequence * array)
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
      fwp_planner__msg__DynamicState__fini(&array->data[i]);
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

fwp_planner__msg__DynamicState__Sequence *
fwp_planner__msg__DynamicState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__DynamicState__Sequence * array = (fwp_planner__msg__DynamicState__Sequence *)allocator.allocate(sizeof(fwp_planner__msg__DynamicState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fwp_planner__msg__DynamicState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fwp_planner__msg__DynamicState__Sequence__destroy(fwp_planner__msg__DynamicState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fwp_planner__msg__DynamicState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fwp_planner__msg__DynamicState__Sequence__are_equal(const fwp_planner__msg__DynamicState__Sequence * lhs, const fwp_planner__msg__DynamicState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fwp_planner__msg__DynamicState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fwp_planner__msg__DynamicState__Sequence__copy(
  const fwp_planner__msg__DynamicState__Sequence * input,
  fwp_planner__msg__DynamicState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fwp_planner__msg__DynamicState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fwp_planner__msg__DynamicState * data =
      (fwp_planner__msg__DynamicState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fwp_planner__msg__DynamicState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fwp_planner__msg__DynamicState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fwp_planner__msg__DynamicState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
