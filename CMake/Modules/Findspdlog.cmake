# ______ _           _               _ _
# |  ___(_)         | |             | | |
# | |_   _ _ __   __| |___ _ __   __| | | ___   __ _
# |  _| | | '_ \ / _` / __| '_ \ / _` | |/ _ \ / _` |
# | |   | | | | | (_| \__ \ |_) | (_| | | (_) | (_| |
# \_|   |_|_| |_|\__,_|___/ .__/ \__,_|_|\___/ \__, |
# zhengrr                 | |                   __/ |
# 2018-08-04 – 2018-10-22 |_|                  |___/  Findspdlog by FIGlet doom
# The Unlicense

#.rst:
# Findspdlog
# ----------
#
# Find the `spdlog <https://github.com/gabime/spdlog>`_ headers.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``spdlog::spdlog``
#   The spdlog library, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``spdlog_FOUND``
#   Found the spdlog.
#
# ``spdlog_INCLUDE_DIRS``
#   The directory containing the spdlog headers.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``spdlog_ROOT_DIR``
#   The root directory of the spdlog installation (may also be set as an environment variable)::
#
#     v spdlog_ROOT_DIR
#       v include
#         v spdlog
#             spdlog.h
#             ...

if(spdlog_FOUND)
  return()
endif()

# hints
set(zHints "${spdlog_ROOT_DIR}" "$ENV{spdlog_ROOT_DIR}")

# include
find_path(
  spdlog_INCLUDE_DIR
  NAMES         "spdlog/spdlog.h"
  HINTS         ${zHints}
  PATH_SUFFIXES "include"
  NO_DEFAULT_PATH)
mark_as_advanced(spdlog_INCLUDE_DIR)

set(spdlog_INCLUDE_DIRS ${spdlog_INCLUDE_DIR})

# package
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  spdlog
  DEFAULT_MSG
  spdlog_INCLUDE_DIR)

if(spdlog_FOUND)
  # target
  if(NOT TARGET spdlog::spdlog)
    add_library(spdlog::spdlog INTERFACE IMPORTED)
    set_target_properties(
      spdlog::spdlog
      PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${spdlog_INCLUDE_DIRS}")
  endif()
  mark_as_advanced(spdlog_ROOT_DIR)

else()
  # hints
  set(spdlog_ROOT_DIR "${spdlog_ROOT_DIR}" CACHE PATH "The root directory of the spdlog installation.")
  mark_as_advanced(CLEAR spdlog_ROOT_DIR)

endif()
