#  _____ _           _  ___  _   ____  ____            _
# |  ___(_)_ __   __| |/ _ \| |_| ___||  _ \ __ _  ___| | ____ _  __ _  ___
# | |_  | | '_ \ / _` | | | | __|___ \| |_) / _` |/ __| |/ / _` |/ _` |/ _ \
# |  _| | | | | | (_| | |_| | |_ ___) |  __| (_| | (__|   | (_| | (_| |  __/
# |_|   |_|_| |_|\__,_|\__\_\\__|____/|_|   \__,_|\___|_|\_\__,_|\__, |\___|
# zhengrr                               FindQt5Package by FIGlet |___/
# 2016-10-21 – 2018-2-2
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
#    QTDIR
#
# 结果变量：
# ::
#
#    QT5_PACKAGE_FOUND
#    QT5_PACKAGE_PREFIX_PATH
#
# 参见：
#
# + `"find_path" <https://cmake.org/cmake/help/latest/command/find_path>`_. *CMake Documentation*.
# + `"ENV" <https://cmake.org/cmake/help/latest/variable/ENV>`_. *CMake Documentation*.
# + `"FindPackageHandleStandardArgs" <https://cmake.org/cmake/help/latest/module/FindPackageHandleStandardArgs>`_. *CMake Documentation*.
# + `"mark_as_advanced" <https://cmake.org/cmake/help/latest/command/mark_as_advanced>`_. *CMake Documentation*.
#
if(DEFINED CMAKE_SIZEOF_VOID_P)
  math(EXPR sAddrWitdh "${CMAKE_SIZEOF_VOID_P} * 8")
else()
  set(sAddrWitdh)
endif()

find_path(QT5_PACKAGE_PREFIX_PATH
  NAMES
    "Qt5/Qt5Config.cmake"
  HINTS
    "${QTDIR${sAddrWitdh}}/lib/cmake"
    "${QTDIR}/lib/cmake"
    "$ENV{QTDIR${sAddrWitdh}}/lib/cmake"
    "$ENV{QTDIR}/lib/cmake"
  NO_DEFAULT_PATH)
mark_as_advanced(QT5_PACKAGE_PREFIX_PATH)

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("QT5_PACKAGE"
  DEFAULT_MSG
    QT5_PACKAGE_PREFIX_PATH)

if((QT5_PACKAGE_FOUND) AND (NOT QT5_PACKAGE_PREFIX_PATH IN_LIST CMAKE_PREFIX_PATH))
  list(APPEND CMAKE_PREFIX_PATH "${QT5_PACKAGE_PREFIX_PATH}")
endif()
