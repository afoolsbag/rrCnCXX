# ______ _           _  ______            _   __                          _____
# |  ___(_)         | ||___  /           | | / /                         /  __ \
# | |_   _ _ __   __| |   / /  ___   ___ | |/ /  ___  ___ _ __   ___ _ __| /  \/
# |  _| | | '_ \ / _` |  / /  / _ \ / _ \|    \ / _ \/ _ \ '_ \ / _ \ '__| |
# | |   | | | | | (_| |./ /__| (_) | (_) | |\  \  __/  __/ |_) |  __/ |  | \__/\
# \_|   |_|_| |_|\__,_|\_____/\___/ \___/\_| \_/\___|\___| .__/ \___|_|   \____/
# zhengrr                                                | |
# 2018-12-29 – 2019-01-02                                |_|
# Unlicense

if(NOT COMMAND get_toolset_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrCMake/LibraryTag.cmake")
endif()

#.rst:
# FindZooKeeperC
# --------------
#
# Find the `Apache ZooKeeper <https://zookeeper.apache.org/>`_ C client headers, libraries and executables.
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
#   Found the ZooKeeper C client.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``ZooKeeperC_ROOT_DIR``
#   The root directory of the ZooKeeper C client installation (may also be set as an environment variable)::
#
#     v ZooKeeperC_ROOT_DIR
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

# hints
set(zHints "${ZooKeeperC_ROOT_DIR}" "$ENV{ZooKeeperC_ROOT_DIR}")

# bin
find_program(
  ZooKeeperC_cli_EXECUTABLE
  NAMES         "cli"
  HINTS         ${zHints}
  PATH_SUFFIXES "bin"
  NO_DEFAULT_PATH)
mark_as_advanced(ZooKeeperC_cli_EXECUTABLE)

# include
find_path(
  ZooKeeperC_INCLUDE_DIR
  NAMES         "zookeeper/zookeeper.h"
  HINTS         ${zHints}
  PATH_SUFFIXES "include"
  NO_DEFAULT_PATH)
mark_as_advanced(ZooKeeperC_INCLUDE_DIR)

# lib
get_toolset_architecture_address_model_tag(sTag)
set(zDbgPathSufs "lib/${sTag}d" "lib/${sTag}" "lib")
set(zRelPathSufs                "lib/${sTag}" "lib")

find_library(
  ZooKeeperC_hashtable_LIBRARY_DEBUG
  NAMES         "hashtable"
  HINTS         ${zHints}
  PATH_SUFFIXES ${zDbgPathSufs}
  NO_DEFAULT_PATH)
mark_as_advanced(ZooKeeperC_hashtable_LIBRARY_DEBUG)
find_library(
  ZooKeeperC_hashtable_LIBRARY_RELEASE
  NAMES         "hashtable"
  HINTS         ${zHints}
  PATH_SUFFIXES ${zRelPathSufs}
  NO_DEFAULT_PATH)
mark_as_advanced(ZooKeeperC_hashtable_LIBRARY_RELEASE)

find_library(
  ZooKeeperC_zookeeper_LIBRARY_DEBUG
  NAMES         "zookeeper"
  HINTS         ${zHints}
  PATH_SUFFIXES ${zDbgPathSufs}
  NO_DEFAULT_PATH)
mark_as_advanced(ZooKeeperC_zookeeper_LIBRARY_DEBUG)
find_library(
  ZooKeeperC_zookeeper_LIBRARY_RELEASE
  NAMES         "zookeeper"
  HINTS         ${zHints}
  PATH_SUFFIXES ${zRelPathSufs}
  NO_DEFAULT_PATH)
mark_as_advanced(ZooKeeperC_zookeeper_LIBRARY_RELEASE)

# package
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  ZooKeeperC
  DEFAULT_MSG
  ZooKeeperC_ROOT_DIR
  ZooKeeperC_INCLUDE_DIR
  ZooKeeperC_hashtable_LIBRARY_DEBUG
  ZooKeeperC_hashtable_LIBRARY_RELEASE
  ZooKeeperC_zookeeper_LIBRARY_DEBUG
  ZooKeeperC_zookeeper_LIBRARY_RELEASE)

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
    target_compile_options(
      ZooKeeperC::zookeeper
      INTERFACE $<IF:$<CONFIG:Debug>,/MTd,/MT>)
    target_link_libraries(
      ZooKeeperC::zookeeper
      INTERFACE WS2_32
                ZooKeeperC::hashtable)
  endif()

  mark_as_advanced(ZooKeeperC_ROOT_DIR)

else()
  # hints
  set(ZooKeeperC_ROOT_DIR "${ZooKeeperC_ROOT_DIR}" CACHE PATH "The root directory of the ZooKeeper C client installation.")
  mark_as_advanced(CLEAR ZooKeeperC_ROOT_DIR)

endif()
