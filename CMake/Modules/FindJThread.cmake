# ______ _           _   ___ _____ _                        _
# |  ___(_)         | | |_  |_   _| |                      | |
# | |_   _ _ __   __| |   | | | | | |__  _ __ ___  __ _  __| |
# |  _| | | '_ \ / _` |   | | | | | '_ \| '__/ _ \/ _` |/ _` | zhengrr
# | |   | | | | | (_| /\__/ / | | | | | | | |  __/ (_| | (_| | 2019-01-18 – 2019-01-18
# \_|   |_|_| |_|\__,_\____/  \_/ |_| |_|_|  \___|\__,_|\__,_| Unlicense

if(NOT COMMAND get_toolset_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrCMake/LibraryTag.cmake")
endif()

#.rst:
# FindJThread
# -----------
#
# Find the `JThread <https://research.edm.uhasselt.be/jori/page/CS/Jthread.html>`_ headers and libraries.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``JThread::jthread``
#   The jthread library, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``JThread_FOUND``
#   Found the JThread.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``JThread_ROOT_DIR``
#   The root directory of the JThread installation (may also be set as an environment variable)::
#
#     v JThread_ROOT_DIR
#       v include
#         v jthread
#             jmutex.h
#             ...
#       v lib
#         > vc141x32d
#         > ...
#           jthread.lib

if(JThread_FOUND)
  return()
endif()

# hints
set(zHints "${JThread_ROOT_DIR}" "$ENV{JThread_ROOT_DIR}")

# include
find_path(
  JThread_INCLUDE_DIR
  NAMES         "jthread/jthread.h"
  HINTS         ${zHints}
  PATH_SUFFIXES "include"
  NO_DEFAULT_PATH)
mark_as_advanced(JThread_INCLUDE_DIR)

# lib
get_toolset_architecture_address_model_tag(sTag)
set(zDbgPathSufs "lib/${sTag}d" "lib/${sTag}" "lib")
set(zRelPathSufs                "lib/${sTag}" "lib")

find_library(
  JThread_jthread_LIBRARY_DEBUG
  NAMES         "jthread_d"
  HINTS         ${zHints}
  PATH_SUFFIXES ${zDbgPathSufs}
  NO_DEFAULT_PATH)
mark_as_advanced(JThread_jthread_LIBRARY_DEBUG)
find_library(
  JThread_jthread_LIBRARY_RELEASE
  NAMES         "jthread"
  HINTS         ${zHints}
  PATH_SUFFIXES ${zRelPathSufs}
  NO_DEFAULT_PATH)
mark_as_advanced(JThread_jthread_LIBRARY_RELEASE)

# package
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  JThread
  DEFAULT_MSG
  JThread_jthread_LIBRARY_RELEASE
  JThread_INCLUDE_DIR
  JThread_jthread_LIBRARY_DEBUG)

if(JThread_FOUND)
  # targets
  if(NOT TARGET JThread::jthread)
    add_library(JThread::jthread STATIC IMPORTED)
    set_target_properties(
      JThread::jthread
      PROPERTIES IMPORTED_LOCATION_DEBUG       "${JThread_jthread_LIBRARY_DEBUG}"
                 IMPORTED_LOCATION_RELEASE     "${JThread_jthread_LIBRARY_RELEASE}"
                 INTERFACE_INCLUDE_DIRECTORIES "${JThread_INCLUDE_DIR}")
  endif()

  mark_as_advanced(JThread_ROOT_DIR)

else()
  # hints
  set(JThread_ROOT_DIR "${JThread_ROOT_DIR}" CACHE PATH "The root directory of the JThread installation.")
  mark_as_advanced(CLEAR JThread_ROOT_DIR)

endif()
