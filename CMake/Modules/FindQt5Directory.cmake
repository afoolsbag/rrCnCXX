#===========================================================================
# zhengrr
# 2016-10-21 – 2017-7-27
# The MIT License
#---------------------------------------------------------------------------

#.rst:
# FindQt5Directory
# ----------------
#
# 此模块用于寻找 Qt5 目录。
#
# 须 CMake 3.3 及以上版本。
#
# 此模块定义并设置了以下变量：
#
# ``QT5DIRECTORY_FOUND``
# ``QT5DIRECTORY_BASE_DIR``

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW)  # CMake 3.3+


function(find_qt5_directory)
  set(QT5DIRECTORY_FOUND TRUE)

  if(NOT QT5DIRECTORY_BASE_DIR)
    math(EXPR address_width "8 * ${CMAKE_SIZEOF_VOID_P}")
    if(DEFINED QTDIR${address_width})
      set(QT5DIRECTORY_BASE_DIR "${QTDIR${address_width}}")
    elseif(DEFINED ENV{QTDIR${address_width}})
      set(QT5DIRECTORY_BASE_DIR "$ENV{QTDIR${address_width}}")
    elseif(DEFINED ENV{QTDIR})
      set(QT5DIRECTORY_BASE_DIR "$ENV{QTDIR}")
    else()
      set(QT5DIRECTORY_FOUND FALSE)
    endif()
  elseif(NOT IS_DIRECTORY "${QT5DIRECTORY_BASE_DIR}")
    set(QT5DIRECTORY_FOUND FALSE)
  endif()

  if(QT5DIRECTORY_FOUND)
    find_path(QT5DIRECTORY_BASE_DIR_CHECKED
        NAMES "lib/cmake/Qt5/Qt5Config.cmake"
        PATHS "${QT5DIRECTORY_BASE_DIR}"
        NO_DEFAULT_PATH)
  endif()

  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(Qt5Directory
      FOUND_VAR     QT5DIRECTORY_FOUND
      REQUIRED_VARS QT5DIRECTORY_BASE_DIR_CHECKED)

  set(QT5DIRECTORY_BASE_DIR ${QT5DIRECTORY_BASE_DIR} CACHE PATH "Qt5 base directory.")
  set(QT5DIRECTORY_FOUND ${QT5DIRECTORY_FOUND} PARENT_SCOPE)
  mark_as_advanced(QT5DIRECTORY_BASE_DIR)

  if(QT5DIRECTORY_FOUND)
    if(NOT QT5DIRECTORY_BASE_DIR IN_LIST CMAKE_PREFIX_PATH)
      set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${QT5DIRECTORY_BASE_DIR}" PARENT_SCOPE)
    endif()
  endif()
endfunction()


find_qt5_directory()
