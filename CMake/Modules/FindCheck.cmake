#  _____ _           _  ____ _               _
# |  ___(_)_ __   __| |/ ___| |__   ___  ___| | __
# | |_  | | '_ \ / _` | |   | '_ \ / _ \/ __| |/ /
# |  _| | | | | | (_| | |___| | | |  __| (__|   <
# |_|   |_|_| |_|\__,_|\____|_| |_|\___|\___|_|\_\ FindCheck by FIGlet
# zhengrr
# 2018-02-02 – 2018-10-22
# The Unlicense

if(NOT COMMAND get_toolset_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrUtilities/LibTag.cmake")
endif()

#.rst:
# FindCheck
# ---------
#
# Find the `Check <https://libcheck.github.io/check/>`_ headers and libraries.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# ``Check::Check``
#   The Check library, if found.
#
# ``Check::Compat``
#   The Compat library, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``Check_FOUND``
#   Found the Check.
#
# ``Check_INCLUDE_DIRS``
#   The directory containing the Check headers.
#
# ``Check_LIBRARIES_RELEASE``
#   The Check release build libraries.
#   
# ``Check_LIBRARIES_DEBUG``
#   The Check debug build libraries.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``Check_ROOT_DIR``
#   The root directory of the Check installation (may also be set as an environment variable)::
#
#     v Check_ROOT_DIR
#       v include
#         v check
#             check.h
#             check_stdint.h
#             libcompat.h
#       v lib
#         > vc141x32d
#         > ...
#           check.lib
#           compat.lib

if(Check_FOUND)
  return()
endif()

# hints
set(zHints "${Check_ROOT_DIR}" "$ENV{Check_ROOT_DIR}")

# include
find_path(
  Check_INCLUDE_DIR
  NAMES         "check/check.h"
  HINTS         ${zHints}
  PATH_SUFFIXES "include"
  NO_DEFAULT_PATH)
mark_as_advanced(Check_INCLUDE_DIR)

set(Check_INCLUDE_DIRS ${Check_INCLUDE_DIR})

# lib
get_toolset_architecture_address_model_tag(sTag)
set(zRelPathSufs "lib/${sTag}")
set(zDbgPathSufs "lib/${sTag}d" ${zRelPathSufs})

find_library(
  Check_Check_LIBRARY_RELEASE
  NAMES         "check"
  HINTS         ${zHints}
  PATH_SUFFIXES ${zRelPathSufs}
  NO_DEFAULT_PATH)
mark_as_advanced(Check_Check_LIBRARY_RELEASE)
find_library(
  Check_Check_LIBRARY_DEBUG
  NAMES         "check"
  HINTS         ${zHints}
  PATH_SUFFIXES ${zDbgPathSufs}
  NO_DEFAULT_PATH)
mark_as_advanced(Check_Check_LIBRARY_DEBUG)

find_library(
  Check_Compat_LIBRARY_RELEASE
  NAMES         "compat"
  HINTS         ${zHints}
  PATH_SUFFIXES ${zRelPathSufs}
  NO_DEFAULT_PATH)
mark_as_advanced(Check_Compat_LIBRARY_RELEASE)
find_library(
  Check_Compat_LIBRARY_DEBUG
  NAMES         "compat"
  HINTS         ${zHints}
  PATH_SUFFIXES ${zDbgPathSufs}
  NO_DEFAULT_PATH)
mark_as_advanced(Check_Compat_LIBRARY_DEBUG)

set(Check_LIBRARIES_RELEASE ${Check_Check_LIBRARY_RELEASE}
                            ${Check_Compat_LIBRARY_RELEASE})
set(Check_LIBRARIES_DEBUG ${Check_Check_LIBRARY_DEBUG}
                          ${Check_Compat_LIBRARY_DEBUG})

# package
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  Check
  DEFAULT_MSG
  Check_Check_LIBRARY_RELEASE
  Check_INCLUDE_DIR
  Check_Check_LIBRARY_DEBUG
  Check_Compat_LIBRARY_RELEASE
  Check_Compat_LIBRARY_DEBUG)

if(Check_FOUND)
  # targets
  if(NOT TARGET Check::Check)
    add_library(Check::Check STATIC IMPORTED)
    set_target_properties(
      Check::Check
      PROPERTIES IMPORTED_LOCATION_RELEASE     "${Check_Check_LIBRARY_RELEASE}"
                 IMPORTED_LOCATION_DEBUG       "${Check_Check_LIBRARY_DEBUG}"
                 INTERFACE_INCLUDE_DIRECTORIES "${Check_INCLUDE_DIRS}")
  endif()
  if(NOT TARGET Check::Compat)
    add_library(Check::Compat STATIC IMPORTED)
    set_target_properties(
      Check::Compat
      PROPERTIES IMPORTED_LOCATION_RELEASE     "${Check_Compat_LIBRARY_RELEASE}"
                 IMPORTED_LOCATION_DEBUG       "${Check_Compat_LIBRARY_DEBUG}"
                 INTERFACE_INCLUDE_DIRECTORIES "${Check_INCLUDE_DIR}")
  endif()
  mark_as_advanced(Check_ROOT_DIR)

else()
  # hints
  set(Check_ROOT_DIR "${Check_ROOT_DIR}" CACHE PATH "The root directory of the Check installation.")
  mark_as_advanced(CLEAR Check_ROOT_DIR)

endif()
