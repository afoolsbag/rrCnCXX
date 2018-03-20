#  _____ _           _  ___  _   ____  ____            _
# |  ___(_)_ __   __| |/ _ \| |_| ___||  _ \ __ _  ___| | ____ _  __ _  ___
# | |_  | | '_ \ / _` | | | | __|___ \| |_) / _` |/ __| |/ / _` |/ _` |/ _ \
# |  _| | | | | | (_| | |_| | |_ ___) |  __| (_| | (__|   | (_| | (_| |  __/
# |_|   |_|_| |_|\__,_|\__\_\\__|____/|_|   \__,_|\___|_|\_\__,_|\__, |\___|
# zhengrr                               FindQt5Package by FIGlet |___/
# 2016-10-21 – 2018-03-19
# The MIT License

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

#.rst:
# FindQt5Package
# --------------
#
# 寻找Qt5包。
#
# 缓存变量：
# ::
#
#    [ENV] QTDIR[32|64]
#
# 结果变量：
# ::
#
#    QT5_PACKAGE_FOUND
#    QT5_PACKAGE_PREFIX_PATH
#
# 参见：
#
# + `"Find Modules" <https://cmake.org/cmake/help/latest/manual/cmake-developer.7#find-modules>`_. *CMake Documentation*.
# + `"find_path" <https://cmake.org/cmake/help/latest/command/find_path>`_. *CMake Documentation*.
# + `"ENV" <https://cmake.org/cmake/help/latest/variable/ENV>`_. *CMake Documentation*.
# + `"FindPackageHandleStandardArgs" <https://cmake.org/cmake/help/latest/module/FindPackageHandleStandardArgs>`_. *CMake Documentation*.
# + `"mark_as_advanced" <https://cmake.org/cmake/help/latest/command/mark_as_advanced>`_. *CMake Documentation*.
#
if(DEFINED CMAKE_SIZEOF_VOID_P)
  math(EXPR sAddrWidth "${CMAKE_SIZEOF_VOID_P} * 8")
else()
  set(sAddrWidth)
endif()

find_path(QT5PACKAGE_PREFIX_PATH
  NAMES
    "Qt5/Qt5Config.cmake"
  HINTS
    "${QTDIR${sAddrWidth}}"
    "${QTDIR}"
    "$ENV{QTDIR${sAddrWidth}}"
    "$ENV{QTDIR}"
  PATH_SUFFIXES
    "lib/cmake"
  NO_DEFAULT_PATH)
mark_as_advanced(QT5PACKAGE_PREFIX_PATH)

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("Qt5Package"
  DEFAULT_MSG
    QT5PACKAGE_PREFIX_PATH)

if(QT5PACKAGE_FOUND)
  if(NOT QT5PACKAGE_PREFIX_PATH IN_LIST CMAKE_PREFIX_PATH)
    list(APPEND CMAKE_PREFIX_PATH "${QT5PACKAGE_PREFIX_PATH}")
  endif()
endif()
