// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from sim_clock:srv/SetRate.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "sim_clock/srv/detail/set_rate__struct.h"
#include "sim_clock/srv/detail/set_rate__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace sim_clock
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SetRate_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetRate_Request_type_support_ids_t;

static const _SetRate_Request_type_support_ids_t _SetRate_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetRate_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetRate_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetRate_Request_type_support_symbol_names_t _SetRate_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sim_clock, srv, SetRate_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sim_clock, srv, SetRate_Request)),
  }
};

typedef struct _SetRate_Request_type_support_data_t
{
  void * data[2];
} _SetRate_Request_type_support_data_t;

static _SetRate_Request_type_support_data_t _SetRate_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetRate_Request_message_typesupport_map = {
  2,
  "sim_clock",
  &_SetRate_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetRate_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetRate_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetRate_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetRate_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace sim_clock

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, sim_clock, srv, SetRate_Request)() {
  return &::sim_clock::srv::rosidl_typesupport_c::SetRate_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "sim_clock/srv/detail/set_rate__struct.h"
// already included above
// #include "sim_clock/srv/detail/set_rate__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sim_clock
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SetRate_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetRate_Response_type_support_ids_t;

static const _SetRate_Response_type_support_ids_t _SetRate_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetRate_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetRate_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetRate_Response_type_support_symbol_names_t _SetRate_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sim_clock, srv, SetRate_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sim_clock, srv, SetRate_Response)),
  }
};

typedef struct _SetRate_Response_type_support_data_t
{
  void * data[2];
} _SetRate_Response_type_support_data_t;

static _SetRate_Response_type_support_data_t _SetRate_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetRate_Response_message_typesupport_map = {
  2,
  "sim_clock",
  &_SetRate_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetRate_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetRate_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetRate_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetRate_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace sim_clock

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, sim_clock, srv, SetRate_Response)() {
  return &::sim_clock::srv::rosidl_typesupport_c::SetRate_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "sim_clock/srv/detail/set_rate__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sim_clock
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SetRate_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetRate_type_support_ids_t;

static const _SetRate_type_support_ids_t _SetRate_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetRate_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetRate_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetRate_type_support_symbol_names_t _SetRate_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sim_clock, srv, SetRate)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sim_clock, srv, SetRate)),
  }
};

typedef struct _SetRate_type_support_data_t
{
  void * data[2];
} _SetRate_type_support_data_t;

static _SetRate_type_support_data_t _SetRate_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetRate_service_typesupport_map = {
  2,
  "sim_clock",
  &_SetRate_service_typesupport_ids.typesupport_identifier[0],
  &_SetRate_service_typesupport_symbol_names.symbol_name[0],
  &_SetRate_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetRate_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetRate_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace sim_clock

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, sim_clock, srv, SetRate)() {
  return &::sim_clock::srv::rosidl_typesupport_c::SetRate_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
