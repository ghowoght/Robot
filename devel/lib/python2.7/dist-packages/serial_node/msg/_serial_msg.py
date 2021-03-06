# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from serial_node/serial_msg.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class serial_msg(genpy.Message):
  _md5sum = "46c11c19de8f979808da3e975b371e2c"
  _type = "serial_node/serial_msg"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """float32 roll
float32 pitch
float32 yaw
float32 linear_x
float32 linear_y
float32 angular_z"""
  __slots__ = ['roll','pitch','yaw','linear_x','linear_y','angular_z']
  _slot_types = ['float32','float32','float32','float32','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       roll,pitch,yaw,linear_x,linear_y,angular_z

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(serial_msg, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.roll is None:
        self.roll = 0.
      if self.pitch is None:
        self.pitch = 0.
      if self.yaw is None:
        self.yaw = 0.
      if self.linear_x is None:
        self.linear_x = 0.
      if self.linear_y is None:
        self.linear_y = 0.
      if self.angular_z is None:
        self.angular_z = 0.
    else:
      self.roll = 0.
      self.pitch = 0.
      self.yaw = 0.
      self.linear_x = 0.
      self.linear_y = 0.
      self.angular_z = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_6f().pack(_x.roll, _x.pitch, _x.yaw, _x.linear_x, _x.linear_y, _x.angular_z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 24
      (_x.roll, _x.pitch, _x.yaw, _x.linear_x, _x.linear_y, _x.angular_z,) = _get_struct_6f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_6f().pack(_x.roll, _x.pitch, _x.yaw, _x.linear_x, _x.linear_y, _x.angular_z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 24
      (_x.roll, _x.pitch, _x.yaw, _x.linear_x, _x.linear_y, _x.angular_z,) = _get_struct_6f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_6f = None
def _get_struct_6f():
    global _struct_6f
    if _struct_6f is None:
        _struct_6f = struct.Struct("<6f")
    return _struct_6f
