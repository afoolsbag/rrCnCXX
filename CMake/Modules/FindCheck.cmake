#  _____ _           _  ____ _               _
# |  ___(_)_ __   __| |/ ___| |__   ___  ___| | __
# | |_  | | '_ \ / _` | |   | '_ \ / _ \/ __| |/ /
# |  _| | | | | | (_| | |___| | | |  __| (__|   <
# |_|   |_|_| |_|\__,_|\____|_| |_|\___|\___|_|\_\
# zhengrr                      FindCheck by FIGlet
# 2018-02-02 – 04-11
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
#    Check_LIBRARIES
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
#            check.lib
#            compat.lib
#
set(zHints "${Check_ROOT_DIR}" "$ENV{CHECKROOT}")

find_path(Check_INCLUDE_DIRS
  NAMES
    "check/check.h"
  HINTS
    ${zHints}
  PATH_SUFFIXES
    "include"
  NO_DEFAULT_PATH)
mark_as_advanced(Check_INCLUDE_DIRS)

find_library(Check_check_LIBRARY
  NAMES
    "check"
  HINTS
    ${zHints}
  PATH_SUFFIXES
    "lib"
  NO_DEFAULT_PATH)
mark_as_advanced(Check_check_LIBRARY)
find_library(Check_compat_LIBRARY
  NAMES
    "compat"
  HINTS
    ${zHints}
  PATH_SUFFIXES
    "lib"
  NO_DEFAULT_PATH)
mark_as_advanced(Check_compat_LIBRARY)
set(Check_LIBRARIES ${Check_check_LIBRARY} ${Check_compat_LIBRARY})

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("Check"
  DEFAULT_MSG
    Check_INCLUDE_DIRS
    Check_check_LIBRARY
    Check_compat_LIBRARY)

if(Check_FOUND)
  if(NOT TARGET Check::Compat)
    add_library(Check::Compat UNKNOWN IMPORTED)
  endif()
  set_target_properties(Check::Compat PROPERTIES
    IMPORTED_LOCATION "${Check_compat_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${Check_INCLUDE_DIRS}")

  if(NOT TARGET Check::Check)
    add_library(Check::Check UNKNOWN IMPORTED)
  endif()
  set_target_properties(Check::Check PROPERTIES
    IMPORTED_LOCATION "${Check_check_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${Check_INCLUDE_DIRS}")

endif()
