// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pivot_msg:msg/Pivot.idl
// generated code does not contain a copyright notice

#ifndef PIVOT_MSG__MSG__DETAIL__PIVOT__STRUCT_H_
#define PIVOT_MSG__MSG__DETAIL__PIVOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Pivot in the package pivot_msg.
typedef struct pivot_msg__msg__Pivot
{
  double pan;
  double tilt;
  double spin;
  double depth;
} pivot_msg__msg__Pivot;

// Struct for a sequence of pivot_msg__msg__Pivot.
typedef struct pivot_msg__msg__Pivot__Sequence
{
  pivot_msg__msg__Pivot * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pivot_msg__msg__Pivot__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PIVOT_MSG__MSG__DETAIL__PIVOT__STRUCT_H_
