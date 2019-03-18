# ______ _           _  ______            _   __                          _____
# |  ___(_)         | ||___  /           | | / /                         /  __ \
# | |_   _ _ __   __| |   / /  ___   ___ | |/ /  ___  ___ _ __   ___ _ __| /  \/
# |  _| | | '_ \ / _` |  / /  / _ \ / _ \|    \ / _ \/ _ \ '_ \ / _ \ '__| |
# | |   | | | | | (_| |./ /__| (_) | (_) | |\  \  __/  __/ |_) |  __/ |  | \__/\
# \_|   |_|_| |_|\__,_|\_____/\___/ \___/\_| \_/\___|\___| .__/ \___|_|   \____/
# zhengrr                                                | |
# 2018-12-29 – 2019-03-15                                |_|
# Unlicense

if(NOT COMMAND find_package_handle_standard_args)
  include(FindPackageHandleStandardArgs)
endif()

if(NOT COMMAND get_toolset_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrCMake/LibraryTag.cmake")
endif()

#.rst:
# FindZooKeeperC
# --------------
#
# Find the `Apache ZooKeeper <https://zookeeper.apache.org/>`_ Client-C headers, libraries and executables.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``ZooKeeperC::cli``
#   The cli executable, if found.
#
# ``ZooKeeperC::hashtable``
#   The hashtable library, if found.
#
# ``ZooKeeperC::zookeeper``
#   The zookeeper library, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``ZooKeeperC_FOUND``
#   Found the Apache ZooKeeper Client-C.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``ZooKeeperC_ROOT``
#   The root directory of the Apache ZooKeeper Client-C installation (may also be set as an environment variable)::
#
#     v ZooKeeperC_ROOT
#       v bin
#           cli.exe
#       v include
#         v zookeeper
#             zookeeper.h
#             ...
#       v lib
#         > vc141x32d
#         > ...
#           hashtable.lib
#           zookeeper.lib

if(ZooKeeperC_FOUND)
  return()
endif()

#-------------------------------------------------------------------------------
# UNIX-like

if(UNIX)

  # <prefix>/[s]bin
  find_program(
    ZooKeeperC_cli_EXECUTABLE
    NAMES         "cli_mt")
  mark_as_advanced(ZooKeeperC_cli_EXECUTABLE)

  # <prefix>/include
  find_path(
    ZooKeeperC_INCLUDE_DIR
    NAMES         "zookeeper/zookeeper.h")
  mark_as_advanced(ZooKeeperC_INCLUDE_DIR)

  # <prefix>/lib
  find_library(
    ZooKeeperC_zookeeper_LIBRARY
    NAMES         "zookeeper_mt")
  mark_as_advanced(ZooKeeperC_zookeeper_LIBRARY)

  # package
  find_package_handle_standard_args(
    ZooKeeperC
    DEFAULT_MSG
    ZooKeeperC_zookeeper_LIBRARY
    ZooKeeperC_INCLUDE_DIR)

  if(ZooKeeperC_FOUND)
    # targets
    if(NOT TARGET ZooKeeperC::cli)
      add_executable(ZooKeeperC::cli IMPORTED)
      set_target_properties(
        ZooKeeperC::cli
        PROPERTIES IMPORTED_LOCATION "${ZooKeeperC_cli_EXECUTABLE}")
    endif()

    if(NOT TARGET ZooKeeperC::zookeeper)
      add_library(ZooKeeperC::zookeeper SHARED IMPORTED)
      set_target_properties(
        ZooKeeperC::zookeeper
        PROPERTIES IMPORTED_LOCATION             "${ZooKeeperC_zookeeper_LIBRARY}"
                   INTERFACE_INCLUDE_DIRECTORIES "${ZooKeeperC_INCLUDE_DIR}")
    endif()

    mark_as_advanced(ZooKeeperC_ROOT)

  endif()

endif()

#-------------------------------------------------------------------------------
# Windows

if(WIN32)

  cmake_minimum_required(VERSION 3.12)  # CMP0074

  # <prefix>/[s]bin
  find_program(
    ZooKeeperC_cli_EXECUTABLE
    NAMES         "cli")
  mark_as_advanced(ZooKeeperC_cli_EXECUTABLE)

  # <prefix>/include
  find_path(
    ZooKeeperC_INCLUDE_DIR
    NAMES         "zookeeper/zookeeper.h")
  mark_as_advanced(ZooKeeperC_INCLUDE_DIR)

  # <prefix>/lib
  get_toolset_architecture_address_model_tag(sTag)

  find_library(
    ZooKeeperC_hashtable_LIBRARY_DEBUG
    NAMES         "hashtable"
    PATH_SUFFIXES "${sTag}d" "${sTag}")
  mark_as_advanced(ZooKeeperC_hashtable_LIBRARY_DEBUG)
  find_library(
    ZooKeeperC_hashtable_LIBRARY_RELEASE
    NAMES         "hashtable"
    PATH_SUFFIXES "${sTag}")
  mark_as_advanced(ZooKeeperC_hashtable_LIBRARY_RELEASE)

  find_library(
    ZooKeeperC_zookeeper_LIBRARY_DEBUG
    NAMES         "zookeeper"
    PATH_SUFFIXES "${sTag}d" "${sTag}")
  mark_as_advanced(ZooKeeperC_zookeeper_LIBRARY_DEBUG)
  find_library(
    ZooKeeperC_zookeeper_LIBRARY_RELEASE
    NAMES         "zookeeper"
    PATH_SUFFIXES "${sTag}")
  mark_as_advanced(ZooKeeperC_zookeeper_LIBRARY_RELEASE)

  # package
  find_package_handle_standard_args(
    ZooKeeperC
    DEFAULT_MSG
    ZooKeeperC_zookeeper_LIBRARY_RELEASE
    ZooKeeperC_INCLUDE_DIR
    ZooKeeperC_hashtable_LIBRARY_DEBUG
    ZooKeeperC_hashtable_LIBRARY_RELEASE
    ZooKeeperC_zookeeper_LIBRARY_DEBUG)

  if(ZooKeeperC_FOUND)
    # targets
    if(NOT TARGET ZooKeeperC::cli)
      add_executable(ZooKeeperC::cli IMPORTED)
      set_target_properties(
        ZooKeeperC::cli
        PROPERTIES IMPORTED_LOCATION "${ZooKeeperC_cli_EXECUTABLE}")
    endif()

    if(NOT TARGET ZooKeeperC::hashtable)
      add_library(ZooKeeperC::hashtable STATIC IMPORTED)
      set_target_properties(
        ZooKeeperC::hashtable
        PROPERTIES IMPORTED_LOCATION_DEBUG       "${ZooKeeperC_hashtable_LIBRARY_DEBUG}"
                   IMPORTED_LOCATION_RELEASE     "${ZooKeeperC_hashtable_LIBRARY_RELEASE}"
                   INTERFACE_INCLUDE_DIRECTORIES "${ZooKeeperC_INCLUDE_DIR}")
    endif()

    if(NOT TARGET ZooKeeperC::zookeeper)
      add_library(ZooKeeperC::zookeeper STATIC IMPORTED)
      set_target_properties(
        ZooKeeperC::zookeeper
        PROPERTIES IMPORTED_LOCATION_DEBUG       "${ZooKeeperC_zookeeper_LIBRARY_DEBUG}"
                   IMPORTED_LOCATION_RELEASE     "${ZooKeeperC_zookeeper_LIBRARY_RELEASE}"
                   INTERFACE_INCLUDE_DIRECTORIES "${ZooKeeperC_INCLUDE_DIR}")
      target_compile_definitions(
        ZooKeeperC::zookeeper
        INTERFACE "USE_STATIC_LIB"
      )
      target_link_libraries(
        ZooKeeperC::zookeeper
        INTERFACE WS2_32
                  ZooKeeperC::hashtable)
    endif()

    mark_as_advanced(ZooKeeperC_ROOT)

  else()
    # hints
    set(ZooKeeperC_ROOT "${ZooKeeperC_ROOT}" CACHE PATH "The root directory of the Apache ZooKeeper Client-C installation.")
    mark_as_advanced(CLEAR ZooKeeperC_ROOT)

  endif()

endif()
