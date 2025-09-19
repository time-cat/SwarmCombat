# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fwp_planner:msg/TeamMulticast.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TeamMulticast(type):
    """Metaclass of message 'TeamMulticast'."""

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
                'fwp_planner.msg.TeamMulticast')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__team_multicast
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__team_multicast
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__team_multicast
            cls._TYPE_SUPPORT = module.type_support_msg__msg__team_multicast
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__team_multicast

            from fwp_planner.msg import DynamicState
            if DynamicState.__class__._TYPE_SUPPORT is None:
                DynamicState.__class__.__import_type_support__()

            from fwp_planner.msg import FusedEnemy
            if FusedEnemy.__class__._TYPE_SUPPORT is None:
                FusedEnemy.__class__.__import_type_support__()

            from fwp_planner.msg import FusedTeammate
            if FusedTeammate.__class__._TYPE_SUPPORT is None:
                FusedTeammate.__class__.__import_type_support__()

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


class TeamMulticast(metaclass=Metaclass_TeamMulticast):
    """Message class 'TeamMulticast'."""

    __slots__ = [
        '_header',
        '_sender_id',
        '_multicast_range',
        '_known_teammates',
        '_known_enemies',
        '_dynamic_state',
        '_is_alive',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'sender_id': 'int32',
        'multicast_range': 'float',
        'known_teammates': 'sequence<fwp_planner/FusedTeammate>',
        'known_enemies': 'sequence<fwp_planner/FusedEnemy>',
        'dynamic_state': 'fwp_planner/DynamicState',
        'is_alive': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['fwp_planner', 'msg'], 'FusedTeammate')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['fwp_planner', 'msg'], 'FusedEnemy')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['fwp_planner', 'msg'], 'DynamicState'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.sender_id = kwargs.get('sender_id', int())
        self.multicast_range = kwargs.get('multicast_range', float())
        self.known_teammates = kwargs.get('known_teammates', [])
        self.known_enemies = kwargs.get('known_enemies', [])
        from fwp_planner.msg import DynamicState
        self.dynamic_state = kwargs.get('dynamic_state', DynamicState())
        self.is_alive = kwargs.get('is_alive', bool())

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
        if self.sender_id != other.sender_id:
            return False
        if self.multicast_range != other.multicast_range:
            return False
        if self.known_teammates != other.known_teammates:
            return False
        if self.known_enemies != other.known_enemies:
            return False
        if self.dynamic_state != other.dynamic_state:
            return False
        if self.is_alive != other.is_alive:
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
    def sender_id(self):
        """Message field 'sender_id'."""
        return self._sender_id

    @sender_id.setter
    def sender_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sender_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'sender_id' field must be an integer in [-2147483648, 2147483647]"
        self._sender_id = value

    @builtins.property
    def multicast_range(self):
        """Message field 'multicast_range'."""
        return self._multicast_range

    @multicast_range.setter
    def multicast_range(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'multicast_range' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'multicast_range' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._multicast_range = value

    @builtins.property
    def known_teammates(self):
        """Message field 'known_teammates'."""
        return self._known_teammates

    @known_teammates.setter
    def known_teammates(self, value):
        if __debug__:
            from fwp_planner.msg import FusedTeammate
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, FusedTeammate) for v in value) and
                 True), \
                "The 'known_teammates' field must be a set or sequence and each value of type 'FusedTeammate'"
        self._known_teammates = value

    @builtins.property
    def known_enemies(self):
        """Message field 'known_enemies'."""
        return self._known_enemies

    @known_enemies.setter
    def known_enemies(self, value):
        if __debug__:
            from fwp_planner.msg import FusedEnemy
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, FusedEnemy) for v in value) and
                 True), \
                "The 'known_enemies' field must be a set or sequence and each value of type 'FusedEnemy'"
        self._known_enemies = value

    @builtins.property
    def dynamic_state(self):
        """Message field 'dynamic_state'."""
        return self._dynamic_state

    @dynamic_state.setter
    def dynamic_state(self, value):
        if __debug__:
            from fwp_planner.msg import DynamicState
            assert \
                isinstance(value, DynamicState), \
                "The 'dynamic_state' field must be a sub message of type 'DynamicState'"
        self._dynamic_state = value

    @builtins.property
    def is_alive(self):
        """Message field 'is_alive'."""
        return self._is_alive

    @is_alive.setter
    def is_alive(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_alive' field must be of type 'bool'"
        self._is_alive = value
