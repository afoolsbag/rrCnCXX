# ______ _           _ _    _      _     _____            _        _  ____________
# |  ___(_)         | | |  | |    | |   /  ___|          | |      | | | ___ \ ___ \
# | |_   _ _ __   __| | |  | | ___| |__ \ `--.  ___   ___| | _____| |_| |_/ / |_/ /
# |  _| | | '_ \ / _` | |/\| |/ _ \ '_ \ `--. \/ _ \ / __| |/ / _ \ __|  __/|  __/
# | |   | | | | | (_| \  /\  /  __/ |_) /\__/ / (_) | (__|   <  __/ |_| |   | |
# \_|   |_|_| |_|\__,_|\/  \/ \___|_.__/\____/ \___/ \___|_|\_\___|\__\_|   \_|
# zhengrr
# 2019-04-22 – 2019-04-22
# Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_guard()

if(NOT COMMAND find_package_handle_standard_args)
  include(FindPackageHandleStandardArgs)
endif()

if(NOT COMMAND add_library_ex)
  include("${CMAKE_CURRENT_LIST_DIR}/rrCMake/AddLibrary.cmake")
endif()

#.rst:
# FindWebSocketPP
# ---------------
#
# Find the `WebSocket++ <https://www.zaphoyd.com/websocketpp>`_ headers as libraries.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``WebSocketPP::websocketpp``
#   The WebSocket++ library, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``WebSocketPP_FOUND``
#   Found the WebSocketPP.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``WebSocketPP_ROOT``
#   The root directory of the WebSocketPP installation (may also be set as an environment variable)::
#
#     v WebSocketPP_ROOT
#       v include
#         v websocketpp
#             clinet.h
#             server.h
#             ...

if(WebSocketPP_FOUND)
  return()
endif()

# <prefix>/include
find_path(
  WebSocketPP_INCLUDE_DIR
  NAMES         "websocketpp/client.hpp"
                "websocketpp/server.hpp")
mark_as_advanced(WebSocketPP_INCLUDE_DIR)

# package
find_package_handle_standard_args(
  WebSocketPP
  DEFAULT_MSG
  WebSocketPP_INCLUDE_DIR)

if(WebSocketPP_FOUND)
  # targets
  if(NOT TARGET WebSocketPP::websocketpp)
    add_library_ex(
      WebSocketPP::websocketpp INTERFACE IMPORTED
      COMPILE_FEATURES         INTERFACE cxx_std_14
      INCLUDE_DIRECTORIES      INTERFACE "${WebSocketPP_INCLUDE_DIR}")
  endif()

  mark_as_advanced(WebSocketPP_ROOT)

else()
  # hints
  set(WebSocketPP_ROOT "${WebSocketPP_ROOT}" CACHE PATH "The root directory of the WebSocketPP installation.")
  mark_as_advanced(CLEAR WebSocketPP_ROOT)

endif()
