// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pivot_msg:msg/Pivot.idl
// generated code does not contain a copyright notice

#ifndef PIVOT_MSG__MSG__DETAIL__PIVOT__STRUCT_HPP_
#define PIVOT_MSG__MSG__DETAIL__PIVOT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__pivot_msg__msg__Pivot __attribute__((deprecated))
#else
# define DEPRECATED__pivot_msg__msg__Pivot __declspec(deprecated)
#endif

namespace pivot_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Pivot_
{
  using Type = Pivot_<ContainerAllocator>;

  explicit Pivot_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pan = 0.0;
      this->tilt = 0.0;
      this->spin = 0.0;
      this->depth = 0.0;
    }
  }

  explicit Pivot_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pan = 0.0;
      this->tilt = 0.0;
      this->spin = 0.0;
      this->depth = 0.0;
    }
  }

  // field types and members
  using _pan_type =
    double;
  _pan_type pan;
  using _tilt_type =
    double;
  _tilt_type tilt;
  using _spin_type =
    double;
  _spin_type spin;
  using _depth_type =
    double;
  _depth_type depth;

  // setters for named parameter idiom
  Type & set__pan(
    const double & _arg)
  {
    this->pan = _arg;
    return *this;
  }
  Type & set__tilt(
    const double & _arg)
  {
    this->tilt = _arg;
    return *this;
  }
  Type & set__spin(
    const double & _arg)
  {
    this->spin = _arg;
    return *this;
  }
  Type & set__depth(
    const double & _arg)
  {
    this->depth = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pivot_msg::msg::Pivot_<ContainerAllocator> *;
  using ConstRawPtr =
    const pivot_msg::msg::Pivot_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pivot_msg::msg::Pivot_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pivot_msg::msg::Pivot_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pivot_msg::msg::Pivot_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pivot_msg::msg::Pivot_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pivot_msg::msg::Pivot_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pivot_msg::msg::Pivot_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pivot_msg::msg::Pivot_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pivot_msg::msg::Pivot_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pivot_msg__msg__Pivot
    std::shared_ptr<pivot_msg::msg::Pivot_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pivot_msg__msg__Pivot
    std::shared_ptr<pivot_msg::msg::Pivot_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Pivot_ & other) const
  {
    if (this->pan != other.pan) {
      return false;
    }
    if (this->tilt != other.tilt) {
      return false;
    }
    if (this->spin != other.spin) {
      return false;
    }
    if (this->depth != other.depth) {
      return false;
    }
    return true;
  }
  bool operator!=(const Pivot_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Pivot_

// alias to use template instance with default allocator
using Pivot =
  pivot_msg::msg::Pivot_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pivot_msg

#endif  // PIVOT_MSG__MSG__DETAIL__PIVOT__STRUCT_HPP_
