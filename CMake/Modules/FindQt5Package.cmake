#  _____ _           _  ___  _   ____  ____            _
# |  ___(_)_ __   __| |/ _ \| |_| ___||  _ \ __ _  ___| | ____ _  __ _  ___
# | |_  | | '_ \ / _` | | | | __|___ \| |_) / _` |/ __| |/ / _` |/ _` |/ _ \
# |  _| | | | | | (_| | |_| | |_ ___) |  __| (_| | (__|   | (_| | (_| |  __/
# |_|   |_|_| |_|\__,_|\__\_\\__|____/|_|   \__,_|\___|_|\_\__,_|\__, |\___|
# zhengrr                               FindQt5Package by FIGlet |___/
# 2016-10-21 – 2018-10-22
# The Unlicense

cmake_policy(SET CMP0057 NEW) #3.3+

if(NOT COMMAND get_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrCMake/LibTag.cmake")
endif()

#.rst:
# FindQt5Package
# --------------
#
# Find the `Qt5 <https://qt.io/>`_ CMake packages.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``Qt5Package_FOUND``
#   Found the Qt5 CMake packages.
#
# ``Qt5Package_PREFIX_PATH``
#   The directory containing the Qt5 CMake packages.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``Qt5_ROOT_DIR`` ``ENV QTDIR[32|64]``
#   The root directory of the Qt5 installation::
#
#     v Qt5_ROOT_DIR
#       v lib
#         v cmake
#           v Qt5
#               Qt5Config.cmake
#               Qt5ConfigVersion.cmake
#               Qt5ModuleLocation.cmake
#           > ...

if(Qt5Package_FOUND)
  return()
endif()

# hints
get_address_model_tag(sAddr)
set(zHints "${Qt5_ROOT_DIR}" "$ENV{QTDIR${sAddr}}" "$ENV{QTDIR}")

# prefix
find_path(Qt5Package_PREFIX_PATH
  NAMES         "Qt5/Qt5Config.cmake"
  HINTS         ${zHints}
  PATH_SUFFIXES "lib/cmake"
  NO_DEFAULT_PATH)
mark_as_advanced(Qt5Package_PREFIX_PATH)

# package
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  Qt5Package
  DEFAULT_MSG
  Qt5Package_PREFIX_PATH)

if(Qt5Package_FOUND)
  # append
  if(NOT Qt5Package_PREFIX_PATH IN_LIST CMAKE_PREFIX_PATH)
    list(APPEND CMAKE_PREFIX_PATH "${Qt5Package_PREFIX_PATH}")
  endif()
  mark_as_advanced(Qt5_ROOT_DIR)

else()
  # hints
  set(Qt5_ROOT_DIR "${Qt5_ROOT_DIR}" CACHE PATH "The root directory of the Qt5 installation.")
  mark_as_advanced(CLEAR Qt5_ROOT_DIR)

endif()
