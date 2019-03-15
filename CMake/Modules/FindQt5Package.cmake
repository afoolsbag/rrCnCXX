#  _____ _           _  ___  _   ____  ____            _
# |  ___(_)_ __   __| |/ _ \| |_| ___||  _ \ __ _  ___| | ____ _  __ _  ___
# | |_  | | '_ \ / _` | | | | __|___ \| |_) / _` |/ __| |/ / _` |/ _` |/ _ \
# |  _| | | | | | (_| | |_| | |_ ___) |  __| (_| | (__|   | (_| | (_| |  __/
# |_|   |_|_| |_|\__,_|\__\_\\__|____/|_|   \__,_|\___|_|\_\__,_|\__, |\___|
# zhengrr                               FindQt5Package by FIGlet |___/
# 2016-10-21 – 2019-03-15
# Unlicense

cmake_minimum_required(VERSION 3.3)
cmake_policy(SET CMP0057 NEW) #3.3+

if(NOT COMMAND find_package_handle_standard_args)
  include(FindPackageHandleStandardArgs)
endif()

#.rst:
# FindQt5Package
# --------------
#
# Find the `Qt5 <https://qt.io/>`_ CMake Packages.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``Qt5Package_FOUND``
#   Found the Qt5 CMake Packages.
#
# ``Qt5Package_PREFIX_PATH``
#   The directory containing the Qt5 CMake Packages.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``Qt5_ROOT``
#   The root directory of the Qt5 installation (may also be set as an environment variable)::
#
#     v Qt5_ROOT
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
set(zHints "${Qt5_ROOT}" "$ENV{Qt5_ROOT}" "$ENV{QTDIR}")

# prefix
find_path(Qt5Package_PREFIX_PATH
  NAMES         "Qt5/Qt5Config.cmake"
  HINTS         ${zHints}
  PATH_SUFFIXES "lib/cmake"
  NO_DEFAULT_PATH)
mark_as_advanced(Qt5Package_PREFIX_PATH)

# package
find_package_handle_standard_args(
  Qt5Package
  DEFAULT_MSG
  Qt5Package_PREFIX_PATH)

if(Qt5Package_FOUND)
  # append
  if(NOT Qt5Package_PREFIX_PATH IN_LIST CMAKE_PREFIX_PATH)
    list(APPEND CMAKE_PREFIX_PATH "${Qt5Package_PREFIX_PATH}")
  endif()
  mark_as_advanced(Qt5_ROOT)

else()
  # hints
  set(Qt5_ROOT "${Qt5_ROOT}" CACHE PATH "The root directory of the Qt5 installation.")
  mark_as_advanced(CLEAR Qt5_ROOT)

endif()
