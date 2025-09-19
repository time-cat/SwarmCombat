# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fwp_planner:msg/DynamicState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DynamicState(type):
    """Metaclass of message 'DynamicState'."""

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
            module = import_type_support('fwp_planner')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fwp_planner.msg.DynamicState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__dynamic_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__dynamic_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__dynamic_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__dynamic_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__dynamic_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DynamicState(metaclass=Metaclass_DynamicState):
    """Message class 'DynamicState'."""

    __slots__ = [
        '_posi_n',
        '_posi_e',
        '_posi_d',
        '_orient_x',
        '_orient_y',
        '_orient_z',
        '_orient_w',
        '_vel',
        '_vel_alpha',
        '_vel_bete',
        '_angle_alpha',
        '_abgle_bete',
    ]

    _fields_and_field_types = {
        'posi_n': 'double',
        'posi_e': 'double',
        'posi_d': 'double',
        'orient_x': 'double',
        'orient_y': 'double',
        'orient_z': 'double',
        'orient_w': 'double',
        'vel': 'double',
        'vel_alpha': 'double',
        'vel_bete': 'double',
        'angle_alpha': 'double',
        'abgle_bete': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.posi_n = kwargs.get('posi_n', float())
        self.posi_e = kwargs.get('posi_e', float())
        self.posi_d = kwargs.get('posi_d', float())
        self.orient_x = kwargs.get('orient_x', float())
        self.orient_y = kwargs.get('orient_y', float())
        self.orient_z = kwargs.get('orient_z', float())
        self.orient_w = kwargs.get('orient_w', float())
        self.vel = kwargs.get('vel', float())
        self.vel_alpha = kwargs.get('vel_alpha', float())
        self.vel_bete = kwargs.get('vel_bete', float())
        self.angle_alpha = kwargs.get('angle_alpha', float())
        self.abgle_bete = kwargs.get('abgle_bete', float())

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
        if self.posi_n != other.posi_n:
            return False
        if self.posi_e != other.posi_e:
            return False
        if self.posi_d != other.posi_d:
            return False
        if self.orient_x != other.orient_x:
            return False
        if self.orient_y != other.orient_y:
            return False
        if self.orient_z != other.orient_z:
            return False
        if self.orient_w != other.orient_w:
            return False
        if self.vel != other.vel:
            return False
        if self.vel_alpha != other.vel_alpha:
            return False
        if self.vel_bete != other.vel_bete:
            return False
        if self.angle_alpha != other.angle_alpha:
            return False
        if self.abgle_bete != other.abgle_bete:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def posi_n(self):
        """Message field 'posi_n'."""
        return self._posi_n

    @posi_n.setter
    def posi_n(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posi_n' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'posi_n' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._posi_n = value

    @builtins.property
    def posi_e(self):
        """Message field 'posi_e'."""
        return self._posi_e

    @posi_e.setter
    def posi_e(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posi_e' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'posi_e' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._posi_e = value

    @builtins.property
    def posi_d(self):
        """Message field 'posi_d'."""
        return self._posi_d

    @posi_d.setter
    def posi_d(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posi_d' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'posi_d' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._posi_d = value

    @builtins.property
    def orient_x(self):
        """Message field 'orient_x'."""
        return self._orient_x

    @orient_x.setter
    def orient_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orient_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orient_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orient_x = value

    @builtins.property
    def orient_y(self):
        """Message field 'orient_y'."""
        return self._orient_y

    @orient_y.setter
    def orient_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orient_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orient_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orient_y = value

    @builtins.property
    def orient_z(self):
        """Message field 'orient_z'."""
        return self._orient_z

    @orient_z.setter
    def orient_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orient_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orient_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orient_z = value

    @builtins.property
    def orient_w(self):
        """Message field 'orient_w'."""
        return self._orient_w

    @orient_w.setter
    def orient_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orient_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orient_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orient_w = value

    @builtins.property
    def vel(self):
        """Message field 'vel'."""
        return self._vel

    @vel.setter
    def vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel = value

    @builtins.property
    def vel_alpha(self):
        """Message field 'vel_alpha'."""
        return self._vel_alpha

    @vel_alpha.setter
    def vel_alpha(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_alpha' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_alpha' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_alpha = value

    @builtins.property
    def vel_bete(self):
        """Message field 'vel_bete'."""
        return self._vel_bete

    @vel_bete.setter
    def vel_bete(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_bete' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_bete' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_bete = value

    @builtins.property
    def angle_alpha(self):
        """Message field 'angle_alpha'."""
        return self._angle_alpha

    @angle_alpha.setter
    def angle_alpha(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'angle_alpha' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'angle_alpha' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._angle_alpha = value

    @builtins.property
    def abgle_bete(self):
        """Message field 'abgle_bete'."""
        return self._abgle_bete

    @abgle_bete.setter
    def abgle_bete(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'abgle_bete' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'abgle_bete' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._abgle_bete = value
