# ______ _           _  ______            _   __                          _____
# |  ___(_)         | ||___  /           | | / /                         /  __ \
# | |_   _ _ __   __| |   / /  ___   ___ | |/ /  ___  ___ _ __   ___ _ __| /  \/
# |  _| | | '_ \ / _` |  / /  / _ \ / _ \|    \ / _ \/ _ \ '_ \ / _ \ '__| |
# | |   | | | | | (_| |./ /__| (_) | (_) | |\  \  __/  __/ |_) |  __/ |  | \__/\
# \_|   |_|_| |_|\__,_|\_____/\___/ \___/\_| \_/\___|\___| .__/ \___|_|   \____/
# zhengrr                                                | |
# 2018-12-29 ¨C 2018-12-29                                |_|
# Unlicense

#.rst:
# FindZooKeeperC
# --------------
#
# Find the `Apache ZooKeeper <https://zookeeper.apache.org/>`_ C client headers and libraries.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``ZooKeeperC::cli``
#   The cli executable, if found.
#   (Not yet implemented)
#
# ``ZooKeeperC::hashtable``
#   The hashtable library, if found.
#   (Not yet implemented)
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
# ``ZooKeeperC_INCLUDE_DIRS``
#   The directory containing the ZooKeeper C client headers.
#
# ``ZooKeeperC_LIBRARIES``
#   The ZooKeeper C client libraries.
#
# ``ZooKeeperC_cli_EXECUTABLE``
#   The path to the ZooKeeper C client cli executable.
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
#           zookeeper.lib
#           ...

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

set(ZooKeeperC_INCLUDE_DIRS ${ZooKeeperC_INCLUDE_DIR})

# lib
find_library(
  ZooKeeperC_zookeeper_LIBRARY
  NAMES         "zookeeper"
  HINTS         ${zHints}
  PATH_SUFFIXES "lib"
  NO_DEFAULT_PATH)
mark_as_advanced(ZooKeeperC_zookeeper_LIBRARY)

set(ZooKeeperC_LIBRARIES ${ZooKeeperC_zookeeper_LIBRARY})

# package
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  ZooKeeperC
  DEFAULT_MSG
  ZooKeeperC_ROOT_DIR
  ZooKeeperC_INCLUDE_DIR
  ZooKeeperC_zookeeper_LIBRARY)

if(ZooKeeperC_FOUND)
  # targets
  if(NOT TARGET ZooKeeperC::zookeeper)
    add_library(ZooKeeperC::zookeeper STATIC IMPORTED)
    set_target_properties(
      ZooKeeperC::zookeeper
      PROPERTIES IMPORTED_LOCATION             "${ZooKeeperC_zookeeper_LIBRARY}"
                 INTERFACE_INCLUDE_DIRECTORIES "${ZooKeeperC_INCLUDE_DIRS}")
  endif()
  mark_as_advanced(ZooKeeperC_ROOT_DIR)

else()
  # hints
  set(ZooKeeperC_ROOT_DIR "${ZooKeeperC_ROOT_DIR}" CACHE PATH "The root directory of the ZooKeeper C client installation.")
  mark_as_advanced(CLEAR ZooKeeperC_ROOT_DIR)

endif()
