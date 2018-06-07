#  _____ _           _  ____ _               _
# |  ___(_)_ __   __| |/ ___| |__   ___  ___| | __
# | |_  | | '_ \ / _` | |   | '_ \ / _ \/ __| |/ /
# |  _| | | | | | (_| | |___| | | |  __| (__|   <
# |_|   |_|_| |_|\__,_|\____|_| |_|\___|\___|_|\_\
# zhengrr                      FindCheck by FIGlet
# 2018-02-02 – 06-06
# The MIT License

#.rst:
# FindCheck
# ---------
#
# 寻找Check包。
#
# 缓存：
# ::
#
#    Check_ROOT_DIR
#    ENV CHECKROOT
#
# 影响：
# ::
#
#    Check_FOUND
#    Check_INCLUDE_DIRS
#    Check_LIBRARIES_RELEASE
#    Check_LIBRARIES_DEBUG
#
#    Check::Check
#    Check::Compat
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
#          > vc141x32
#          > vc141x32d
#          > vc141x64
#          > vc141x64d
#            check.lib
#            compat.lib
#
if(Check_FOUND)
  return()
endif()

if(NOT COMMAND get_toolset_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrUtilities/LibTag.cmake")
endif()
get_toolset_tag(sTool)
get_architecture_address_model_tag(sArAd)

set(zHints "${Check_ROOT_DIR}" "$ENV{CHECKROOT}")

set(zRelPathSufs "lib/${sTool}${sArAd}"
                 "lib/${sArAd}"
                 "lib")
set(zDbgPathSufs "lib/${sTool}${sArAd}d"
                 "lib/${sArAd}"
                 ${zRelPathSufs})

find_path(Check_ROOT_DIR
          NAMES "include/check/check.h"
          HINTS ${zHints}
                NO_DEFAULT_PATH)
mark_as_advanced(Check_ROOT_DIR)

find_path(Check_INCLUDE_DIRS
          NAMES "check/check.h"
          HINTS ${zHints}
  PATH_SUFFIXES "include"
                NO_DEFAULT_PATH)
mark_as_advanced(Check_INCLUDE_DIRS)

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

set(Check_LIBRARIES_RELEASE
  ${Check_check_LIBRARY_RELEASE} ${Check_compat_LIBRARY_RELEASE})
set(Check_LIBRARIES_DEBUG
  ${Check_check_LIBRARY_DEBUG} ${Check_compat_LIBRARY_DEBUG})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Check
                      DEFAULT_MSG Check_ROOT_DIR
                                  Check_INCLUDE_DIRS
                                  Check_check_LIBRARY_RELEASE
                                  Check_check_LIBRARY_DEBUG
                                  Check_compat_LIBRARY_RELEASE
                                  Check_compat_LIBRARY_DEBUG)

if(Check_FOUND)
  if(NOT TARGET Check::Compat)
    add_library(Check::Compat STATIC IMPORTED)
    set_target_properties(Check::Compat PROPERTIES
              IMPORTED_LOCATION_RELEASE "${Check_compat_LIBRARY_RELEASE}"
                IMPORTED_LOCATION_DEBUG "${Check_compat_LIBRARY_DEBUG}"
          INTERFACE_INCLUDE_DIRECTORIES "${Check_INCLUDE_DIRS}")
  endif()

  if(NOT TARGET Check::Check)
    add_library(Check::Check STATIC IMPORTED)
    set_target_properties(Check::Check PROPERTIES
             IMPORTED_LOCATION_RELEASE "${Check_check_LIBRARY_RELEASE}"
               IMPORTED_LOCATION_DEBUG "${Check_check_LIBRARY_DEBUG}"
         INTERFACE_INCLUDE_DIRECTORIES "${Check_INCLUDE_DIRS}")
  endif()

else()
  set(Check_ROOT_DIR "${Check_ROOT_DIR}" CACHE PATH "The root directory of the Check installation.")
  mark_as_advanced(CLEAR Check_ROOT_DIR)

endif()
