"""autogenerated by genmsg_py from Pose.msg. Do not edit."""
import roslib.message
import struct

import roslib.msg

class Pose(roslib.message.Message):
  _md5sum = "6912a6eb81006b68b259c9bf26039f96"
  _type = "harlie_base/Pose"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """Header header
float32 x
float32 y
float32 theta
float32 x_var
float32 y_var
float32 theta_var
float32 x_vel
float32 y_vel
float32 theta_vel

================================================================================
MSG: roslib/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.secs: seconds (stamp_secs) since epoch
# * stamp.nsecs: nanoseconds since stamp_secs
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

"""
  __slots__ = ['header','x','y','theta','x_var','y_var','theta_var','x_vel','y_vel','theta_vel']
  _slot_types = ['Header','float32','float32','float32','float32','float32','float32','float32','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.
    
    The available fields are:
       header,x,y,theta,x_var,y_var,theta_var,x_vel,y_vel,theta_vel
    
    @param args: complete set of field values, in .msg order
    @param kwds: use keyword arguments corresponding to message field names
    to set specific fields. 
    """
    if args or kwds:
      super(Pose, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = roslib.msg._Header.Header()
      if self.x is None:
        self.x = 0.
      if self.y is None:
        self.y = 0.
      if self.theta is None:
        self.theta = 0.
      if self.x_var is None:
        self.x_var = 0.
      if self.y_var is None:
        self.y_var = 0.
      if self.theta_var is None:
        self.theta_var = 0.
      if self.x_vel is None:
        self.x_vel = 0.
      if self.y_vel is None:
        self.y_vel = 0.
      if self.theta_vel is None:
        self.theta_vel = 0.
    else:
      self.header = roslib.msg._Header.Header()
      self.x = 0.
      self.y = 0.
      self.theta = 0.
      self.x_var = 0.
      self.y_var = 0.
      self.theta_var = 0.
      self.x_vel = 0.
      self.y_vel = 0.
      self.theta_vel = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    @param buff: buffer
    @type  buff: StringIO
    """
    try:
      _x = self
      buff.write(_struct_3I.pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_9f.pack(_x.x, _x.y, _x.theta, _x.x_var, _x.y_var, _x.theta_var, _x.x_vel, _x.y_vel, _x.theta_vel))
    except struct.error, se: self._check_types(se)
    except TypeError, te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    @param str: byte array of serialized message
    @type  str: str
    """
    try:
      if self.header is None:
        self.header = roslib.msg._Header.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 36
      (_x.x, _x.y, _x.theta, _x.x_var, _x.y_var, _x.theta_var, _x.x_vel, _x.y_vel, _x.theta_vel,) = _struct_9f.unpack(str[start:end])
      return self
    except struct.error, e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    @param buff: buffer
    @type  buff: StringIO
    @param numpy: numpy python module
    @type  numpy module
    """
    try:
      _x = self
      buff.write(_struct_3I.pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_9f.pack(_x.x, _x.y, _x.theta, _x.x_var, _x.y_var, _x.theta_var, _x.x_vel, _x.y_vel, _x.theta_vel))
    except struct.error, se: self._check_types(se)
    except TypeError, te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    @param str: byte array of serialized message
    @type  str: str
    @param numpy: numpy python module
    @type  numpy: module
    """
    try:
      if self.header is None:
        self.header = roslib.msg._Header.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 36
      (_x.x, _x.y, _x.theta, _x.x_var, _x.y_var, _x.theta_var, _x.x_vel, _x.y_vel, _x.theta_vel,) = _struct_9f.unpack(str[start:end])
      return self
    except struct.error, e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill

_struct_I = roslib.message.struct_I
_struct_3I = struct.Struct("<3I")
_struct_9f = struct.Struct("<9f")
