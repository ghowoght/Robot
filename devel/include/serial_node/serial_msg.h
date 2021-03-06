// Generated by gencpp from file serial_node/serial_msg.msg
// DO NOT EDIT!


#ifndef SERIAL_NODE_MESSAGE_SERIAL_MSG_H
#define SERIAL_NODE_MESSAGE_SERIAL_MSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace serial_node
{
template <class ContainerAllocator>
struct serial_msg_
{
  typedef serial_msg_<ContainerAllocator> Type;

  serial_msg_()
    : roll(0.0)
    , pitch(0.0)
    , yaw(0.0)
    , linear_x(0.0)
    , linear_y(0.0)
    , angular_z(0.0)  {
    }
  serial_msg_(const ContainerAllocator& _alloc)
    : roll(0.0)
    , pitch(0.0)
    , yaw(0.0)
    , linear_x(0.0)
    , linear_y(0.0)
    , angular_z(0.0)  {
  (void)_alloc;
    }



   typedef float _roll_type;
  _roll_type roll;

   typedef float _pitch_type;
  _pitch_type pitch;

   typedef float _yaw_type;
  _yaw_type yaw;

   typedef float _linear_x_type;
  _linear_x_type linear_x;

   typedef float _linear_y_type;
  _linear_y_type linear_y;

   typedef float _angular_z_type;
  _angular_z_type angular_z;





  typedef boost::shared_ptr< ::serial_node::serial_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::serial_node::serial_msg_<ContainerAllocator> const> ConstPtr;

}; // struct serial_msg_

typedef ::serial_node::serial_msg_<std::allocator<void> > serial_msg;

typedef boost::shared_ptr< ::serial_node::serial_msg > serial_msgPtr;
typedef boost::shared_ptr< ::serial_node::serial_msg const> serial_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::serial_node::serial_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::serial_node::serial_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::serial_node::serial_msg_<ContainerAllocator1> & lhs, const ::serial_node::serial_msg_<ContainerAllocator2> & rhs)
{
  return lhs.roll == rhs.roll &&
    lhs.pitch == rhs.pitch &&
    lhs.yaw == rhs.yaw &&
    lhs.linear_x == rhs.linear_x &&
    lhs.linear_y == rhs.linear_y &&
    lhs.angular_z == rhs.angular_z;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::serial_node::serial_msg_<ContainerAllocator1> & lhs, const ::serial_node::serial_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace serial_node

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::serial_node::serial_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::serial_node::serial_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::serial_node::serial_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::serial_node::serial_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::serial_node::serial_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::serial_node::serial_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::serial_node::serial_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "46c11c19de8f979808da3e975b371e2c";
  }

  static const char* value(const ::serial_node::serial_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x46c11c19de8f9798ULL;
  static const uint64_t static_value2 = 0x08da3e975b371e2cULL;
};

template<class ContainerAllocator>
struct DataType< ::serial_node::serial_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "serial_node/serial_msg";
  }

  static const char* value(const ::serial_node::serial_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::serial_node::serial_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 roll\n"
"float32 pitch\n"
"float32 yaw\n"
"float32 linear_x\n"
"float32 linear_y\n"
"float32 angular_z\n"
;
  }

  static const char* value(const ::serial_node::serial_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::serial_node::serial_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.roll);
      stream.next(m.pitch);
      stream.next(m.yaw);
      stream.next(m.linear_x);
      stream.next(m.linear_y);
      stream.next(m.angular_z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct serial_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::serial_node::serial_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::serial_node::serial_msg_<ContainerAllocator>& v)
  {
    s << indent << "roll: ";
    Printer<float>::stream(s, indent + "  ", v.roll);
    s << indent << "pitch: ";
    Printer<float>::stream(s, indent + "  ", v.pitch);
    s << indent << "yaw: ";
    Printer<float>::stream(s, indent + "  ", v.yaw);
    s << indent << "linear_x: ";
    Printer<float>::stream(s, indent + "  ", v.linear_x);
    s << indent << "linear_y: ";
    Printer<float>::stream(s, indent + "  ", v.linear_y);
    s << indent << "angular_z: ";
    Printer<float>::stream(s, indent + "  ", v.angular_z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SERIAL_NODE_MESSAGE_SERIAL_MSG_H
