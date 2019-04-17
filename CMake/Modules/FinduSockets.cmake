# ______ _           _       _____            _        _
# |  ___(_)         | |     /  ___|          | |      | |
# | |_   _ _ __   __| |_   _\ `--.  ___   ___| | _____| |_ ___
# |  _| | | '_ \ / _` | | | |`--. \/ _ \ / __| |/ / _ \ __/ __| zhengrr
# | |   | | | | | (_| | |_| /\__/ / (_) | (__|   <  __/ |_\__ \ 2019-04-11 – 2019-04-16
# \_|   |_|_| |_|\__,_|\__,_\____/ \___/ \___|_|\_\___|\__|___/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_guard()

if(NOT COMMAND find_package_handle_standard_args)
  include(FindPackageHandleStandardArgs)
endif()

if(NOT COMMAND add_library_ex)
  include("${CMAKE_CURRENT_LIST_DIR}/rrCMake/AddLibrary.cmake")
endif()

if(NOT COMMAND get_toolset_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrCMake/LibraryTag.cmake")
endif()

#.rst:
# FinduSockets
# ------------
#
# Find the `uSockets <https://github.com/uNetworking/uSockets>`_ headers and libraries.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``uSockets::uSockets``
#   The uSockets library, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``uSockets_FOUND``
#   Found the uSockets.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``uSockets_ROOT``
#   The root directory of the uSockets installation (may also be set as an environment variable)::
#
#     v uSockets_ROOT
#       v include
#         v usockets
#             libusockets.h
#       v lib
#         > vc141x32d
#         > ...
#           uSockets.lib
#
# CMakeLists.txt
# ^^^^^^^^^^^^^^
#
# ``CMakeLists.txt``::
#
#   cmake_minimum_required(VERSION 3.9.6)
#   project(uSockets VERSION 0.1.2 LANGUAGES C CXX)
#   
#   if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
#     file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.13/conan.cmake"
#                   "${CMAKE_BINARY_DIR}/conan.cmake")
#   endif()
#   include("${CMAKE_BINARY_DIR}/conan.cmake")
#   
#   conan_cmake_run(
#     REQUIRES libuv/1.25.0@bincrafters/stable
#              OpenSSL/1.1.1b@conan/stable
#     BASIC_SETUP CMAKE_TARGETS)
#   
#   add_library(
#     uSockets
#     STATIC src/context.c
#            src/loop.c
#            src/socket.c
#            src/ssl.c
#            src/eventing/epoll.c
#            src/eventing/libuv.c
#   )
#   
#   set_target_properties(
#     uSockets
#     PROPERTIES C_STANDARD 11
#                C_STANDARD_REQUIRED ON
#   )
#   
#   target_link_libraries(
#     uSockets
#     PRIVATE CONAN_PKG::libuv
#             CONAN_PKG::OpenSSL
#   )
#   
#   target_include_directories(
#     uSockets
#     PRIVATE "src/"
#   )

if(uSockets_FOUND)
  return()
endif()

#-------------------------------------------------------------------------------
# Windows

if(WIN32)
  # <prefix>/include
  find_path(
    uSockets_INCLUDE_DIR
    NAMES         "usockets/libusockets.h")
  mark_as_advanced(uSockets_INCLUDE_DIR)

  # <prefix>/lib
  get_toolset_architecture_address_model_tag(sTag)

  find_library(
    uSockets_uSockets_LIBRARY_DEBUG
    NAMES         "uSockets"
    PATH_SUFFIXES "${sTag}d" "${sTag}")
  mark_as_advanced(uSockets_uSockets_LIBRARY_DEBUG)
  find_library(
    uSockets_uSockets_LIBRARY_RELEASE
    NAMES         "uSockets"
    PATH_SUFFIXES "${sTag}")
  mark_as_advanced(uSockets_uSockets_LIBRARY_RELEASE)

  # package
  find_package_handle_standard_args(
    uSockets
    DEFAULT_MSG
    uSockets_uSockets_LIBRARY_RELEASE
    uSockets_INCLUDE_DIR
    uSockets_uSockets_LIBRARY_DEBUG)

  if(uSockets_FOUND)
    # targets
    if(NOT TARGET uSockets::uSockets)
      add_library_ex(
        uSockets::uSockets  STATIC IMPORTED
        PROPERTIES          IMPORTED_LOCATION_DEBUG       "${uSockets_uSockets_LIBRARY_DEBUG}"
                            IMPORTED_LOCATION_RELEASE     "${uSockets_uSockets_LIBRARY_RELEASE}"
        INCLUDE_DIRECTORIES INTERFACE                     "${uSockets_INCLUDE_DIR}")
    endif()

    mark_as_advanced(uSockets_ROOT)

  else()
    # hints
    set(uSockets_ROOT "${uSockets_ROOT}" CACHE PATH "The root directory of the uSockets installation.")
    mark_as_advanced(CLEAR uSockets_ROOT)

  endif()

endif()
