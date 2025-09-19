// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from fwp_planner:msg/TeamMulticast.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "fwp_planner/msg/detail/team_multicast__struct.h"
#include "fwp_planner/msg/detail/team_multicast__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "fwp_planner/msg/detail/fused_enemy__functions.h"
#include "fwp_planner/msg/detail/fused_teammate__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool fwp_planner__msg__fused_teammate__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * fwp_planner__msg__fused_teammate__convert_to_py(void * raw_ros_message);
bool fwp_planner__msg__fused_enemy__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * fwp_planner__msg__fused_enemy__convert_to_py(void * raw_ros_message);
bool fwp_planner__msg__dynamic_state__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * fwp_planner__msg__dynamic_state__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool fwp_planner__msg__team_multicast__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("fwp_planner.msg._team_multicast.TeamMulticast", full_classname_dest, 45) == 0);
  }
  fwp_planner__msg__TeamMulticast * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // sender_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "sender_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sender_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // multicast_range
    PyObject * field = PyObject_GetAttrString(_pymsg, "multicast_range");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->multicast_range = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // known_teammates
    PyObject * field = PyObject_GetAttrString(_pymsg, "known_teammates");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'known_teammates'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!fwp_planner__msg__FusedTeammate__Sequence__init(&(ros_message->known_teammates), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create fwp_planner__msg__FusedTeammate__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    fwp_planner__msg__FusedTeammate * dest = ros_message->known_teammates.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!fwp_planner__msg__fused_teammate__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // known_enemies
    PyObject * field = PyObject_GetAttrString(_pymsg, "known_enemies");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'known_enemies'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!fwp_planner__msg__FusedEnemy__Sequence__init(&(ros_message->known_enemies), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create fwp_planner__msg__FusedEnemy__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    fwp_planner__msg__FusedEnemy * dest = ros_message->known_enemies.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!fwp_planner__msg__fused_enemy__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // dynamic_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "dynamic_state");
    if (!field) {
      return false;
    }
    if (!fwp_planner__msg__dynamic_state__convert_from_py(field, &ros_message->dynamic_state)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // is_alive
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_alive");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_alive = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * fwp_planner__msg__team_multicast__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TeamMulticast */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("fwp_planner.msg._team_multicast");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TeamMulticast");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  fwp_planner__msg__TeamMulticast * ros_message = (fwp_planner__msg__TeamMulticast *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sender_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->sender_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sender_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // multicast_range
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->multicast_range);
    {
      int rc = PyObject_SetAttrString(_pymessage, "multicast_range", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // known_teammates
    PyObject * field = NULL;
    size_t size = ros_message->known_teammates.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    fwp_planner__msg__FusedTeammate * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->known_teammates.data[i]);
      PyObject * pyitem = fwp_planner__msg__fused_teammate__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "known_teammates", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // known_enemies
    PyObject * field = NULL;
    size_t size = ros_message->known_enemies.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    fwp_planner__msg__FusedEnemy * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->known_enemies.data[i]);
      PyObject * pyitem = fwp_planner__msg__fused_enemy__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "known_enemies", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dynamic_state
    PyObject * field = NULL;
    field = fwp_planner__msg__dynamic_state__convert_to_py(&ros_message->dynamic_state);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "dynamic_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_alive
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_alive ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_alive", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
