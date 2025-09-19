// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fwp_planner:msg/TeamMulticast.idl
// generated code does not contain a copyright notice
#include "fwp_planner/msg/detail/team_multicast__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `known_teammates`
#include "fwp_planner/msg/detail/fused_teammate__functions.h"
// Member `known_enemies`
#include "fwp_planner/msg/detail/fused_enemy__functions.h"
// Member `dynamic_state`
#include "fwp_planner/msg/detail/dynamic_state__functions.h"

bool
fwp_planner__msg__TeamMulticast__init(fwp_planner__msg__TeamMulticast * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    fwp_planner__msg__TeamMulticast__fini(msg);
    return false;
  }
  // sender_id
  // multicast_range
  // known_teammates
  if (!fwp_planner__msg__FusedTeammate__Sequence__init(&msg->known_teammates, 0)) {
    fwp_planner__msg__TeamMulticast__fini(msg);
    return false;
  }
  // known_enemies
  if (!fwp_planner__msg__FusedEnemy__Sequence__init(&msg->known_enemies, 0)) {
    fwp_planner__msg__TeamMulticast__fini(msg);
    return false;
  }
  // dynamic_state
  if (!fwp_planner__msg__DynamicState__init(&msg->dynamic_state)) {
    fwp_planner__msg__TeamMulticast__fini(msg);
    return false;
  }
  // is_alive
  return true;
}

void
fwp_planner__msg__TeamMulticast__fini(fwp_planner__msg__TeamMulticast * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // sender_id
  // multicast_range
  // known_teammates
  fwp_planner__msg__FusedTeammate__Sequence__fini(&msg->known_teammates);
  // known_enemies
  fwp_planner__msg__FusedEnemy__Sequence__fini(&msg->known_enemies);
  // dynamic_state
  fwp_planner__msg__DynamicState__fini(&msg->dynamic_state);
  // is_alive
}

bool
fwp_planner__msg__TeamMulticast__are_equal(const fwp_planner__msg__TeamMulticast * lhs, const fwp_planner__msg__TeamMulticast * rhs)
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
  // multicast_range
  if (lhs->multicast_range != rhs->multicast_range) {
    return false;
  }
  // known_teammates
  if (!fwp_planner__msg__FusedTeammate__Sequence__are_equal(
      &(lhs->known_teammates), &(rhs->known_teammates)))
  {
    return false;
  }
  // known_enemies
  if (!fwp_planner__msg__FusedEnemy__Sequence__are_equal(
      &(lhs->known_enemies), &(rhs->known_enemies)))
  {
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
fwp_planner__msg__TeamMulticast__copy(
  const fwp_planner__msg__TeamMulticast * input,
  fwp_planner__msg__TeamMulticast * output)
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
  // multicast_range
  output->multicast_range = input->multicast_range;
  // known_teammates
  if (!fwp_planner__msg__FusedTeammate__Sequence__copy(
      &(input->known_teammates), &(output->known_teammates)))
  {
    return false;
  }
  // known_enemies
  if (!fwp_planner__msg__FusedEnemy__Sequence__copy(
      &(input->known_enemies), &(output->known_enemies)))
  {
    return false;
  }
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

fwp_planner__msg__TeamMulticast *
fwp_planner__msg__TeamMulticast__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__TeamMulticast * msg = (fwp_planner__msg__TeamMulticast *)allocator.allocate(sizeof(fwp_planner__msg__TeamMulticast), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fwp_planner__msg__TeamMulticast));
  bool success = fwp_planner__msg__TeamMulticast__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fwp_planner__msg__TeamMulticast__destroy(fwp_planner__msg__TeamMulticast * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fwp_planner__msg__TeamMulticast__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fwp_planner__msg__TeamMulticast__Sequence__init(fwp_planner__msg__TeamMulticast__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__TeamMulticast * data = NULL;

  if (size) {
    data = (fwp_planner__msg__TeamMulticast *)allocator.zero_allocate(size, sizeof(fwp_planner__msg__TeamMulticast), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fwp_planner__msg__TeamMulticast__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fwp_planner__msg__TeamMulticast__fini(&data[i - 1]);
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
fwp_planner__msg__TeamMulticast__Sequence__fini(fwp_planner__msg__TeamMulticast__Sequence * array)
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
      fwp_planner__msg__TeamMulticast__fini(&array->data[i]);
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

fwp_planner__msg__TeamMulticast__Sequence *
fwp_planner__msg__TeamMulticast__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fwp_planner__msg__TeamMulticast__Sequence * array = (fwp_planner__msg__TeamMulticast__Sequence *)allocator.allocate(sizeof(fwp_planner__msg__TeamMulticast__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fwp_planner__msg__TeamMulticast__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fwp_planner__msg__TeamMulticast__Sequence__destroy(fwp_planner__msg__TeamMulticast__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fwp_planner__msg__TeamMulticast__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fwp_planner__msg__TeamMulticast__Sequence__are_equal(const fwp_planner__msg__TeamMulticast__Sequence * lhs, const fwp_planner__msg__TeamMulticast__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fwp_planner__msg__TeamMulticast__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fwp_planner__msg__TeamMulticast__Sequence__copy(
  const fwp_planner__msg__TeamMulticast__Sequence * input,
  fwp_planner__msg__TeamMulticast__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fwp_planner__msg__TeamMulticast);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fwp_planner__msg__TeamMulticast * data =
      (fwp_planner__msg__TeamMulticast *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fwp_planner__msg__TeamMulticast__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fwp_planner__msg__TeamMulticast__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fwp_planner__msg__TeamMulticast__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
