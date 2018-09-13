#  _____ _           _  ___  _   ____  ____            _
# |  ___(_)_ __   __| |/ _ \| |_| ___||  _ \ __ _  ___| | ____ _  __ _  ___
# | |_  | | '_ \ / _` | | | | __|___ \| |_) / _` |/ __| |/ / _` |/ _` |/ _ \
# |  _| | | | | | (_| | |_| | |_ ___) |  __| (_| | (__|   | (_| | (_| |  __/
# |_|   |_|_| |_|\__,_|\__\_\\__|____/|_|   \__,_|\___|_|\_\__,_|\__, |\___|
# zhengrr                               FindQt5Package by FIGlet |___/
# 2016-10-21 – 2018-09-13
# The Unlicense

cmake_policy(SET CMP0057 NEW) #3.3+

if(NOT COMMAND get_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrUtilities/LibTag.cmake")
endif()

#.rst:
# FindQt5Package
# --------------
#
# 寻找 Qt5 包。
#
# 结果变量：
# ::
#
#    Qt5Package_FOUND
#    Qt5Package_PREFIX_PATH
#
# 提示变量：
# ::
#
#    Qt5_ROOT
#    ENV QTDIR[32|64]
#
# 预期：
# ::
#
#    v qt5_root
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

# hints

get_address_model_tag(sAddr)

set(zHints "${Qt5_ROOT}"
           "$ENV{QTDIR${sAddr}}"
           "$ENV{QTDIR}")

# prefix

find_path(Qt5Package_PREFIX_PATH
          NAMES "Qt5/Qt5Config.cmake"
          HINTS ${zHints}
  PATH_SUFFIXES "lib/cmake"
                NO_DEFAULT_PATH)
mark_as_advanced(Qt5Package_PREFIX_PATH)

# package

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Qt5Package
                      DEFAULT_MSG Qt5Package_PREFIX_PATH)

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
