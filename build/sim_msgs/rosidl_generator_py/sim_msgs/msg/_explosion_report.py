# generated from rosidl_generator_py/resource/_idl.py.em
# with input from sim_msgs:msg/ExplosionReport.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ExplosionReport(type):
    """Metaclass of message 'ExplosionReport'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sim_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sim_msgs.msg.ExplosionReport')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__explosion_report
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__explosion_report
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__explosion_report
            cls._TYPE_SUPPORT = module.type_support_msg__msg__explosion_report
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__explosion_report

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExplosionReport(metaclass=Metaclass_ExplosionReport):
    """Message class 'ExplosionReport'."""

    __slots__ = [
        '_header',
        '_attacker_id',
        '_exp_center',
        '_exp_range',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'attacker_id': 'int32',
        'exp_center': 'geometry_msgs/Point',
        'exp_range': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.attacker_id = kwargs.get('attacker_id', int())
        from geometry_msgs.msg import Point
        self.exp_center = kwargs.get('exp_center', Point())
        self.exp_range = kwargs.get('exp_range', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.attacker_id != other.attacker_id:
            return False
        if self.exp_center != other.exp_center:
            return False
        if self.exp_range != other.exp_range:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def attacker_id(self):
        """Message field 'attacker_id'."""
        return self._attacker_id

    @attacker_id.setter
    def attacker_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'attacker_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'attacker_id' field must be an integer in [-2147483648, 2147483647]"
        self._attacker_id = value

    @builtins.property
    def exp_center(self):
        """Message field 'exp_center'."""
        return self._exp_center

    @exp_center.setter
    def exp_center(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'exp_center' field must be a sub message of type 'Point'"
        self._exp_center = value

    @builtins.property
    def exp_range(self):
        """Message field 'exp_range'."""
        return self._exp_range

    @exp_range.setter
    def exp_range(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'exp_range' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'exp_range' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._exp_range = value
