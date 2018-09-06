# ______ _           _               _ _
# |  ___(_)         | |             | | |
# | |_   _ _ __   __| |___ _ __   __| | | ___   __ _
# |  _| | | '_ \ / _` / __| '_ \ / _` | |/ _ \ / _` |
# | |   | | | | | (_| \__ \ |_) | (_| | | (_) | (_| |
# \_|   |_|_| |_|\__,_|___/ .__/ \__,_|_|\___/ \__, |
# zhengrr                 | |                   __/ |
# 2018-08-04 – 2018-09-06 |_|                  |___/  Findspdlog by FIGlet doom
# The Unlicense

#.rst:
# Findspdlog
# ----------
#
# 寻找 spdlog。
#
# 结果变量：
# ::
#
#    spdlog_FOUND
#    spdlog_INCLUDE_DIRS
#
# 提示变量：
# ::
#
#    spdlog_ROOT
#    ENV spdlog_ROOT
#
# 预期：
# ::
#
#    v spdlog_ROOT
#       > bench
#       > cmake
#       > example
#       > include
#       > tests
#         ...
#
if(spdlog_FOUND)
  return()
endif()

# hints

set(zHints "${spdlog_ROOT}" "$ENV{spdlog_ROOT}")

# include

find_path(spdlog_INCLUDE_DIR
          NAMES "spdlog/spdlog.h"
          HINTS ${zHints}
  PATH_SUFFIXES "include"
                NO_DEFAULT_PATH)
mark_as_advanced(spdlog_INCLUDE_DIR)

set(spdlog_INCLUDE_DIRS ${spdlog_INCLUDE_DIR})
mark_as_advanced(spdlog_INCLUDE_DIRS)

# package

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(spdlog
                      DEFAULT_MSG spdlog_INCLUDE_DIR)

# hints

if(spdlog_FOUND)

  mark_as_advanced(spdlog_ROOT)

else()

  set(spdlog_ROOT "${spdlog_ROOT}" CACHE PATH "The root directory of the spdlog installation.")
  mark_as_advanced(CLEAR spdlog_ROOT)

endif()
