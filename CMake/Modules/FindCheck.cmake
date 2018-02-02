#  _____ _           _  ____ _               _
# |  ___(_)_ __   __| |/ ___| |__   ___  ___| | __
# | |_  | | '_ \ / _` | |   | '_ \ / _ \/ __| |/ /
# |  _| | | | | | (_| | |___| | | |  __| (__|   <
# |_|   |_|_| |_|\__,_|\____|_| |_|\___|\___|_|\_\
# zhengrr                      FindCheck by FIGlet
# 2018-2-2
# The MIT License

#.rst:
# FindCheck
# ---------
#
# 寻找CMocka包。
#
# 缓存变量：
# ::
#
#    CHECK_ROOT
#
# 结果变量：
# ::
#
#    CHECK_FOUND
#    CHECK_INCLUDE_DIRS
#    CHECK_LIBRARIES
#
find_path(CHECK_INCLUDE_DIRS
  NAMES
    "check.h"
    "check_stdint.h"
    "libcompat.h"
  HINTS
    "${CHECK_ROOT}/include"
    "$ENV{CHECK_ROOT}/include"
  NO_DEFAULT_PATH)
mark_as_advanced(CHECK_INCLUDE_DIRS)

find_library(CHECK_LIBRARY_check
  NAMES
    "check"
  HINTS
    "${CHECK_ROOT}/lib"
    "$ENV{CHECK_ROOT}/lib"
  NO_DEFAULT_PATH)
find_library(CHECK_LIBRARY_compat
  NAMES
    "compat"
  HINTS
    "${CHECK_ROOT}/lib"
    "$ENV{CHECK_ROOT}/lib"
  NO_DEFAULT_PATH)
set(CHECK_LIBRARIES "${CHECK_LIBRARY_check}" "${CHECK_LIBRARY_compat}")
mark_as_advanced(CHECK_LIBRARIES)

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("CHECK"
  DEFAULT_MSG
    Check_INCLUDE_DIRS
    CHECK_LIBRARY_check
    CHECK_LIBRARY_compat)
