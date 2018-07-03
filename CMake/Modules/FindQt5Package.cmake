#  _____ _           _  ___  _   ____  ____            _
# |  ___(_)_ __   __| |/ _ \| |_| ___||  _ \ __ _  ___| | ____ _  __ _  ___
# | |_  | | '_ \ / _` | | | | __|___ \| |_) / _` |/ __| |/ / _` |/ _` |/ _ \
# |  _| | | | | | (_| | |_| | |_ ___) |  __| (_| | (__|   | (_| | (_| |  __/
# |_|   |_|_| |_|\__,_|\__\_\\__|____/|_|   \__,_|\___|_|\_\__,_|\__, |\___|
# zhengrr                               FindQt5Package by FIGlet |___/
# 2016-10-21 – 2018-07-03
# The MIT License

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

#.rst:
# FindQt5Package
# --------------
#
# 寻找Qt5包。
#
# 缓存：
# ::
#
#    Qt5_ROOT_DIR
#    ENV QTDIR[32|64]
#
# 影响：
# ::
#
#    Qt5Package_FOUND
#    Qt5Package_PREFIX_PATH
#
# 预期：
# ::
#
#    v qt5_root_dir
#       v lib
#          v cmake
#             v Qt5
#                  Qt5Config.cmake
#                  ...
#
# 参见：
#
# + `"Find Modules" <https://cmake.org/cmake/help/latest/manual/cmake-developer.7#find-modules>`_. *CMake Documentation*.
# + `"find_path" <https://cmake.org/cmake/help/latest/command/find_path>`_. *CMake Documentation*.
# + `"ENV" <https://cmake.org/cmake/help/latest/variable/ENV>`_. *CMake Documentation*.
# + `"FindPackageHandleStandardArgs" <https://cmake.org/cmake/help/latest/module/FindPackageHandleStandardArgs>`_. *CMake Documentation*.
# + `"mark_as_advanced" <https://cmake.org/cmake/help/latest/command/mark_as_advanced>`_. *CMake Documentation*.
#
if(Qt5Package_FOUND)
  return()
endif()

if(NOT COMMAND get_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrUtilities/LibTag.cmake")
endif()
get_address_model_tag(sAddr)

set(zHints "${Qt5_ROOT_DIR}"
           "$ENV{QTDIR${sAddr}}"
           "$ENV{QTDIR}")

find_path(Qt5_ROOT_DIR
    NAMES "lib/cmake/Qt5/Qt5Config.cmake"
    HINTS ${zHints}
          NO_DEFAULT_PATH)
mark_as_advanced(Qt_ROOT_DIR)

find_path(Qt5Package_PREFIX_PATH
          NAMES "Qt5/Qt5Config.cmake"
          HINTS ${zHints}
  PATH_SUFFIXES "lib/cmake"
                NO_DEFAULT_PATH)
mark_as_advanced(Qt5Package_PREFIX_PATH)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Qt5Package
                      DEFAULT_MSG Qt5_ROOT_DIR
                                  Qt5Package_PREFIX_PATH)

if(Qt5Package_FOUND)
  if(NOT Qt5Package_PREFIX_PATH IN_LIST CMAKE_PREFIX_PATH)
    list(APPEND CMAKE_PREFIX_PATH "${Qt5Package_PREFIX_PATH}")
  endif()
else()
  set(Qt5_ROOT_DIR "${Qt5_ROOT_DIR}" CACHE PATH "The root directory of the Qt5 installation.")
  mark_as_advanced(CLEAR Qt5_ROOT_DIR)
endif()
