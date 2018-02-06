#  _____ _           _  ____ _               _
# |  ___(_)_ __   __| |/ ___| |__   ___  ___| | __
# | |_  | | '_ \ / _` | |   | '_ \ / _ \/ __| |/ /
# |  _| | | | | | (_| | |___| | | |  __| (__|   <
# |_|   |_|_| |_|\__,_|\____|_| |_|\___|\___|_|\_\
# zhengrr                      FindCheck by FIGlet
# 2018-2-2 – 5
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

find_library(CHECK_check_LIBRARY
  NAMES
    "check"
  HINTS
    "${CHECK_ROOT}/lib"
    "$ENV{CHECK_ROOT}/lib"
  NO_DEFAULT_PATH)
mark_as_advanced(CHECK_check_LIBRARY)
find_library(CHECK_compat_LIBRARY
  NAMES
    "compat"
  HINTS
    "${CHECK_ROOT}/lib"
    "$ENV{CHECK_ROOT}/lib"
  NO_DEFAULT_PATH)
mark_as_advanced(CHECK_compat_LIBRARY)
set(CHECK_LIBRARIES "${CHECK_check_LIBRARY}" "${CHECK_compat_LIBRARY}")

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("Check"
  DEFAULT_MSG
    CHECK_INCLUDE_DIRS
    CHECK_check_LIBRARY
    CHECK_compat_LIBRARY)
