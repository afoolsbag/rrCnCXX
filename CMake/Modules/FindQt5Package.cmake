#  _____ _           _  ___  _   ____  ____            _
# |  ___(_)_ __   __| |/ _ \| |_| ___||  _ \ __ _  ___| | ____ _  __ _  ___
# | |_  | | '_ \ / _` | | | | __|___ \| |_) / _` |/ __| |/ / _` |/ _` |/ _ \
# |  _| | | | | | (_| | |_| | |_ ___) |  __| (_| | (__|   | (_| | (_| |  __/
# |_|   |_|_| |_|\__,_|\__\_\\__|____/|_|   \__,_|\___|_|\_\__,_|\__, |\___|
# zhengrr                               FindQt5Package by FIGlet |___/
# 2016-10-21 – 2018-1-26
# The MIT License

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

#.rst:
# FindQt5Package
# --------------
#
# 寻找 Qt5 包。
#
# 缓存变量::
#
#    QTDIR
#
# 结果变量::
#
#    Qt5Package_FOUND
#    Qt5Package_PREFIX_PATH
#
# 参见
#
# + `ENV <https://cmake.org/cmake/help/latest/variable/ENV>`_
# + `find_path <https://cmake.org/cmake/help/latest/command/find_path>`_
# + `FindPackageHandleStandardArgs <https://cmake.org/cmake/help/latest/module/FindPackageHandleStandardArgs>`_
# + `mark_as_advanced <https://cmake.org/cmake/help/latest/command/mark_as_advanced>`_
#
math(EXPR _sAddressWidth "${CMAKE_SIZEOF_VOID_P} * 8")

find_path(
  Qt5Package_PREFIX_PATH
    "lib/cmake/Qt5/Qt5Config.cmake"
  HINTS
    "${QTDIR${_sAddressWidth}}"
    "${QTDIR}"
    "$ENV{QTDIR${sAddressWidth}}"
    "$ENV{QTDIR}"
  NO_DEFAULT_PATH)
mark_as_advanced(Qt5Package_PREFIX_PATH)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  Qt5Package DEFAULT_MSG
    Qt5Package_PREFIX_PATH)

if((Qt5Package_FOUND) AND (NOT Qt5Package_PREFIX_PATH IN_LIST CMAKE_PREFIX_PATH))
  list(APPEND CMAKE_PREFIX_PATH "${Qt5Package_PREFIX_PATH}")
endif()
