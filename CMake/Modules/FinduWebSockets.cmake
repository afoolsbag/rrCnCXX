# ______ _           _       _    _      _     _____            _        _
# |  ___(_)         | |     | |  | |    | |   /  ___|          | |      | |
# | |_   _ _ __   __| |_   _| |  | | ___| |__ \ `--.  ___   ___| | _____| |_ ___
# |  _| | | '_ \ / _` | | | | |/\| |/ _ \ '_ \ `--. \/ _ \ / __| |/ / _ \ __/ __|
# | |   | | | | | (_| | |_| \  /\  /  __/ |_) /\__/ / (_) | (__|   <  __/ |_\__ \
# \_|   |_|_| |_|\__,_|\__,_|\/  \/ \___|_.__/\____/ \___/ \___|_|\_\___|\__|___/
# zhengrr
# 2019-04-11 – 2019-04-11
# Unlicense

if(NOT COMMAND find_package_handle_standard_args)
  include(FindPackageHandleStandardArgs)
endif()

#.rst:
# FinduWebSockets
# ---------------
#
# Find the `uWebSockets <https://github.com/uNetworking/uWebSockets>`_ headers as libraries.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``uWebSockets::uWebSockets``
#   The uWebSockets library, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``uWebSockets_FOUND``
#   Found the uWebSockets.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``uWebSockets_ROOT``
#   The root directory of the uWebSockets installation (may also be set as an environment variable)::
#
#     v uWebSockets_ROOT
#       v include
#         v uWebSockets
#             App.h
#             ...

if(uWebSockets_FOUND)
  return()
endif()

find_package(uSockets)

cmake_minimum_required(VERSION 3.12)  # CMP0074

# <prefix>/include
find_path(
  uWebSockets_INCLUDE_DIR
  NAMES         "uWebSockets/App.h")
mark_as_advanced(uWebSockets_INCLUDE_DIR)

# package
find_package_handle_standard_args(
  uWebSockets
  DEFAULT_MSG
  uWebSockets_INCLUDE_DIR)

if(uWebSockets_FOUND)
  # targets
  if(NOT TARGET uWebSockets::uWebSockets)
    add_library(uWebSockets::uWebSockets INTERFACE IMPORTED)
    set_target_properties(
      uWebSockets::uWebSockets
      PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${uWebSockets_INCLUDE_DIR}")
    target_link_libraries(
      uWebSockets::uWebSockets
      INTERFACE uSockets::uSockets)
  endif()

  mark_as_advanced(uWebSockets_ROOT)

else()
  # hints
  set(uWebSockets_ROOT "${uWebSockets_ROOT}" CACHE PATH "The root directory of the uWebSockets installation.")
  mark_as_advanced(CLEAR uWebSockets_ROOT)

endif()
