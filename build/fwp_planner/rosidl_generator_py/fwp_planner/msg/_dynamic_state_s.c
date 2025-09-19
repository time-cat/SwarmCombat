// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from fwp_planner:msg/DynamicState.idl
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
#include "fwp_planner/msg/detail/dynamic_state__struct.h"
#include "fwp_planner/msg/detail/dynamic_state__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool fwp_planner__msg__dynamic_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
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
    assert(strncmp("fwp_planner.msg._dynamic_state.DynamicState", full_classname_dest, 43) == 0);
  }
  fwp_planner__msg__DynamicState * ros_message = _ros_message;
  {  // posi_n
    PyObject * field = PyObject_GetAttrString(_pymsg, "posi_n");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->posi_n = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // posi_e
    PyObject * field = PyObject_GetAttrString(_pymsg, "posi_e");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->posi_e = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // posi_d
    PyObject * field = PyObject_GetAttrString(_pymsg, "posi_d");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->posi_d = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orient_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "orient_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orient_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orient_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "orient_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orient_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orient_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "orient_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orient_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orient_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "orient_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orient_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_alpha
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_alpha");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_alpha = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_bete
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_bete");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_bete = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // angle_alpha
    PyObject * field = PyObject_GetAttrString(_pymsg, "angle_alpha");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->angle_alpha = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // abgle_bete
    PyObject * field = PyObject_GetAttrString(_pymsg, "abgle_bete");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->abgle_bete = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * fwp_planner__msg__dynamic_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DynamicState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("fwp_planner.msg._dynamic_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DynamicState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  fwp_planner__msg__DynamicState * ros_message = (fwp_planner__msg__DynamicState *)raw_ros_message;
  {  // posi_n
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->posi_n);
    {
      int rc = PyObject_SetAttrString(_pymessage, "posi_n", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // posi_e
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->posi_e);
    {
      int rc = PyObject_SetAttrString(_pymessage, "posi_e", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // posi_d
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->posi_d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "posi_d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orient_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orient_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orient_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orient_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orient_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orient_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orient_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orient_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orient_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orient_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orient_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orient_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_alpha
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_alpha);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_alpha", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_bete
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_bete);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_bete", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angle_alpha
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->angle_alpha);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angle_alpha", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // abgle_bete
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->abgle_bete);
    {
      int rc = PyObject_SetAttrString(_pymessage, "abgle_bete", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
