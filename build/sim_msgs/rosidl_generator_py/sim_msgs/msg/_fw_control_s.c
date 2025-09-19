// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from sim_msgs:msg/FwControl.idl
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
#include "sim_msgs/msg/detail/fw_control__struct.h"
#include "sim_msgs/msg/detail/fw_control__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool sim_msgs__msg__fw_control__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[35];
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
    assert(strncmp("sim_msgs.msg._fw_control.FwControl", full_classname_dest, 34) == 0);
  }
  sim_msgs__msg__FwControl * ros_message = _ros_message;
  {  // desired_roll
    PyObject * field = PyObject_GetAttrString(_pymsg, "desired_roll");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->desired_roll = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // desired_pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "desired_pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->desired_pitch = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // desired_yaw_rate
    PyObject * field = PyObject_GetAttrString(_pymsg, "desired_yaw_rate");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->desired_yaw_rate = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // desired_airspeed
    PyObject * field = PyObject_GetAttrString(_pymsg, "desired_airspeed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->desired_airspeed = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * sim_msgs__msg__fw_control__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FwControl */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("sim_msgs.msg._fw_control");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FwControl");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  sim_msgs__msg__FwControl * ros_message = (sim_msgs__msg__FwControl *)raw_ros_message;
  {  // desired_roll
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->desired_roll);
    {
      int rc = PyObject_SetAttrString(_pymessage, "desired_roll", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // desired_pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->desired_pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "desired_pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // desired_yaw_rate
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->desired_yaw_rate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "desired_yaw_rate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // desired_airspeed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->desired_airspeed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "desired_airspeed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
