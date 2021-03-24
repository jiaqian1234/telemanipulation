// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pivot_msg:msg/Pivot.idl
// generated code does not contain a copyright notice
#include "pivot_msg/msg/detail/pivot__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
pivot_msg__msg__Pivot__init(pivot_msg__msg__Pivot * msg)
{
  if (!msg) {
    return false;
  }
  // pan
  // tilt
  // spin
  // depth
  return true;
}

void
pivot_msg__msg__Pivot__fini(pivot_msg__msg__Pivot * msg)
{
  if (!msg) {
    return;
  }
  // pan
  // tilt
  // spin
  // depth
}

pivot_msg__msg__Pivot *
pivot_msg__msg__Pivot__create()
{
  pivot_msg__msg__Pivot * msg = (pivot_msg__msg__Pivot *)malloc(sizeof(pivot_msg__msg__Pivot));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pivot_msg__msg__Pivot));
  bool success = pivot_msg__msg__Pivot__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
pivot_msg__msg__Pivot__destroy(pivot_msg__msg__Pivot * msg)
{
  if (msg) {
    pivot_msg__msg__Pivot__fini(msg);
  }
  free(msg);
}


bool
pivot_msg__msg__Pivot__Sequence__init(pivot_msg__msg__Pivot__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  pivot_msg__msg__Pivot * data = NULL;
  if (size) {
    data = (pivot_msg__msg__Pivot *)calloc(size, sizeof(pivot_msg__msg__Pivot));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pivot_msg__msg__Pivot__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pivot_msg__msg__Pivot__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pivot_msg__msg__Pivot__Sequence__fini(pivot_msg__msg__Pivot__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pivot_msg__msg__Pivot__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pivot_msg__msg__Pivot__Sequence *
pivot_msg__msg__Pivot__Sequence__create(size_t size)
{
  pivot_msg__msg__Pivot__Sequence * array = (pivot_msg__msg__Pivot__Sequence *)malloc(sizeof(pivot_msg__msg__Pivot__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = pivot_msg__msg__Pivot__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
pivot_msg__msg__Pivot__Sequence__destroy(pivot_msg__msg__Pivot__Sequence * array)
{
  if (array) {
    pivot_msg__msg__Pivot__Sequence__fini(array);
  }
  free(array);
}
