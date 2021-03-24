// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from telemanipulator:msg/Pivot.idl
// generated code does not contain a copyright notice

#ifndef TELEMANIPULATOR__MSG__DETAIL__PIVOT__STRUCT_H_
#define TELEMANIPULATOR__MSG__DETAIL__PIVOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Pivot in the package telemanipulator.
typedef struct telemanipulator__msg__Pivot
{
  double pan;
  double tilt;
  double spin;
  double depth;
} telemanipulator__msg__Pivot;

// Struct for a sequence of telemanipulator__msg__Pivot.
typedef struct telemanipulator__msg__Pivot__Sequence
{
  telemanipulator__msg__Pivot * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} telemanipulator__msg__Pivot__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TELEMANIPULATOR__MSG__DETAIL__PIVOT__STRUCT_H_
