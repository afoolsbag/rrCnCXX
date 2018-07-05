#  _____ _           _  ____ _               _
# |  ___(_)_ __   __| |/ ___| |__   ___  ___| | __
# | |_  | | '_ \ / _` | |   | '_ \ / _ \/ __| |/ /
# |  _| | | | | | (_| | |___| | | |  __| (__|   <
# |_|   |_|_| |_|\__,_|\____|_| |_|\___|\___|_|\_\
# zhengrr                      FindCheck by FIGlet
# 2018-02-02 – 2018-07-05
# The MIT License

#.rst:
# FindCheck
# ---------
#
# 寻找Check。
#
# 导入目标：
# ::
#
#    Check::Check
#    Check::Compat
#
# 结果变量：
# ::
#
#    Check_FOUND
#    Check_INCLUDE_DIRS
#    Check_LIBRARIES_RELEASE
#    Check_LIBRARIES_DEBUG
#
# 提示变量：
# ::
#
#    Check_ROOT_DIR
#    ENV CHECKROOT
#
# 预期：
# ::
#
#    v check_root_dir
#       v include
#          v check
#               check.h
#               check_stdint.h
#               libcompat.h
#       v lib
#          > vc141x32d
#          > ...
#            check.lib
#            compat.lib
#
if(Check_FOUND)
  return()
endif()

# hints

set(zHints "${Check_ROOT_DIR}" "$ENV{CHECKROOT}")

if(NOT COMMAND get_toolset_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrUtilities/LibTag.cmake")
endif()
get_toolset_tag(sTool)
get_architecture_address_model_tag(sArAd)

# include

find_path(Check_INCLUDE_DIR
          NAMES "check/check.h"
          HINTS ${zHints}
  PATH_SUFFIXES "include"
                NO_DEFAULT_PATH)
mark_as_advanced(Check_INCLUDE_DIR)

set(Check_INCLUDE_DIRS ${Check_INCLUDE_DIR})
mark_as_advanced(Check_INCLUDE_DIRS)

# lib

set(zRelPathSufs "lib/${sTool}${sArAd}"
                 "lib/${sArAd}"
                 "lib")
set(zDbgPathSufs "lib/${sTool}${sArAd}d"
                 "lib/${sArAd}d"
                 ${zRelPathSufs})

find_library(Check_check_LIBRARY_RELEASE
          NAMES "check"
          HINTS ${zHints}
  PATH_SUFFIXES ${zRelPathSufs}
                NO_DEFAULT_PATH)
mark_as_advanced(Check_check_LIBRARY_RELEASE)
find_library(Check_check_LIBRARY_DEBUG
          NAMES "check"
          HINTS ${zHints}
  PATH_SUFFIXES ${zDbgPathSufs}
                NO_DEFAULT_PATH)
mark_as_advanced(Check_check_LIBRARY_DEBUG)

find_library(Check_compat_LIBRARY_RELEASE
          NAMES "compat"
          HINTS ${zHints}
  PATH_SUFFIXES ${zRelPathSufs}
                NO_DEFAULT_PATH)
mark_as_advanced(Check_compat_LIBRARY_RELEASE)
find_library(Check_compat_LIBRARY_DEBUG
          NAMES "compat"
          HINTS ${zHints}
  PATH_SUFFIXES ${zDbgPathSufs}
                NO_DEFAULT_PATH)
mark_as_advanced(Check_compat_LIBRARY_DEBUG)

set(Check_LIBRARIES_RELEASE ${Check_check_LIBRARY_RELEASE}
                            ${Check_compat_LIBRARY_RELEASE})
mark_as_advanced(Check_LIBRARIES_RELEASE)
set(Check_LIBRARIES_DEBUG ${Check_check_LIBRARY_DEBUG}
                          ${Check_compat_LIBRARY_DEBUG})
mark_as_advanced(Check_LIBRARIES_DEBUG)

# package

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Check
                      DEFAULT_MSG Check_ROOT_DIR
                                  Check_INCLUDE_DIR
                                  Check_check_LIBRARY_RELEASE
                                  Check_check_LIBRARY_DEBUG
                                  Check_compat_LIBRARY_RELEASE
                                  Check_compat_LIBRARY_DEBUG)

if(Check_FOUND)

  # targets

  if(NOT TARGET Check::Compat)
    add_library(Check::Compat STATIC IMPORTED)
    set_target_properties(Check::Compat
               PROPERTIES IMPORTED_LOCATION_RELEASE "${Check_compat_LIBRARY_RELEASE}"
                          IMPORTED_LOCATION_DEBUG "${Check_compat_LIBRARY_DEBUG}"
                          INTERFACE_INCLUDE_DIRECTORIES "${Check_INCLUDE_DIR}")
  endif()

  if(NOT TARGET Check::Check)
    add_library(Check::Check STATIC IMPORTED)
    set_target_properties(Check::Check
               PROPERTIES IMPORTED_LOCATION_RELEASE "${Check_check_LIBRARY_RELEASE}"
                          IMPORTED_LOCATION_DEBUG "${Check_check_LIBRARY_DEBUG}"
                          INTERFACE_INCLUDE_DIRECTORIES "${Check_INCLUDE_DIRS}")
  endif()

else()

  # hints

  set(Check_ROOT_DIR "${Check_ROOT_DIR}" CACHE PATH "The root directory of the Check installation.")
  mark_as_advanced(CLEAR Check_ROOT_DIR)

endif()
