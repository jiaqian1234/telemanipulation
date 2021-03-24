// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from telemanipulator:msg/Pivot.idl
// generated code does not contain a copyright notice
#include "telemanipulator/msg/detail/pivot__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
telemanipulator__msg__Pivot__init(telemanipulator__msg__Pivot * msg)
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
telemanipulator__msg__Pivot__fini(telemanipulator__msg__Pivot * msg)
{
  if (!msg) {
    return;
  }
  // pan
  // tilt
  // spin
  // depth
}

telemanipulator__msg__Pivot *
telemanipulator__msg__Pivot__create()
{
  telemanipulator__msg__Pivot * msg = (telemanipulator__msg__Pivot *)malloc(sizeof(telemanipulator__msg__Pivot));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(telemanipulator__msg__Pivot));
  bool success = telemanipulator__msg__Pivot__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
telemanipulator__msg__Pivot__destroy(telemanipulator__msg__Pivot * msg)
{
  if (msg) {
    telemanipulator__msg__Pivot__fini(msg);
  }
  free(msg);
}


bool
telemanipulator__msg__Pivot__Sequence__init(telemanipulator__msg__Pivot__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  telemanipulator__msg__Pivot * data = NULL;
  if (size) {
    data = (telemanipulator__msg__Pivot *)calloc(size, sizeof(telemanipulator__msg__Pivot));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = telemanipulator__msg__Pivot__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        telemanipulator__msg__Pivot__fini(&data[i - 1]);
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
telemanipulator__msg__Pivot__Sequence__fini(telemanipulator__msg__Pivot__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      telemanipulator__msg__Pivot__fini(&array->data[i]);
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

telemanipulator__msg__Pivot__Sequence *
telemanipulator__msg__Pivot__Sequence__create(size_t size)
{
  telemanipulator__msg__Pivot__Sequence * array = (telemanipulator__msg__Pivot__Sequence *)malloc(sizeof(telemanipulator__msg__Pivot__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = telemanipulator__msg__Pivot__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
telemanipulator__msg__Pivot__Sequence__destroy(telemanipulator__msg__Pivot__Sequence * array)
{
  if (array) {
    telemanipulator__msg__Pivot__Sequence__fini(array);
  }
  free(array);
}
