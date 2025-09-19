# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_fw_plane_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED fw_plane_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(fw_plane_FOUND FALSE)
  elseif(NOT fw_plane_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(fw_plane_FOUND FALSE)
  endif()
  return()
endif()
set(_fw_plane_CONFIG_INCLUDED TRUE)

# output package information
if(NOT fw_plane_FIND_QUIETLY)
  message(STATUS "Found fw_plane: 0.0.0 (${fw_plane_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'fw_plane' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${fw_plane_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(fw_plane_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${fw_plane_DIR}/${_extra}")
endforeach()
