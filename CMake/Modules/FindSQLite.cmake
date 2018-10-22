# ______ _           _ _____  _____ _     _ _
# |  ___(_)         | /  ___||  _  | |   (_) |
# | |_   _ _ __   __| \ `--. | | | | |    _| |_ ___
# |  _| | | '_ \ / _` |`--. \| | | | |   | | __/ _ \
# | |   | | | | | (_| /\__/ /\ \/' / |___| | ||  __/
# \_|   |_|_| |_|\__,_\____/  \_/\_\_____/_|\__\___| FindSQLite by FIGlet doom
# zhengrr
# 2018-05-23 – 2018-10-22
# The Unlicense

if(NOT COMMAND get_toolset_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrUtilities/LibTag.cmake")
endif()

#.rst:
# FindSQLite
# ----------
#
# Find the `SQLite <https://sqlite.org/>`_ headers and libraries.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines the following :prop_tgt:`IMPORTED` targets:
#
# ``SQLite::SQLite``
#   The SQLite library, if found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ``SQLite_FOUND``
#   Found the SQLite.
#
# ``SQLite_INCLUDE_DIRS``
#   The directory containing the SQLite headers.
#
# ``SQLite_LIBRARIES``
#   The SQLite libraries.
#
# Cache variables
# ^^^^^^^^^^^^^^^
#
# The following cache variables may also be set:
#
# ``SQLite_ROOT_DIR``
#   The root directory of the SQLite installation (may also be set as an environment variable)::
#
#   v SQLite_ROOT_DIR
#     v include
#       v sqlite3
#           sqlite3.h
#           sqlite3ext.h
#     v lib
#       > x32
#       v x64
#         v vc141
#             sqlite3.exp
#             sqlite3.lib
#           sqlite3.def
#           sqlite3.dll

if(SQLite_FOUND)
  return()
endif()

# hints
set(zHints "${SQLite_ROOT_DIR}" "$ENV{SQLite_DIR_DIR}")

# include
find_path(
  SQLite_INCLUDE_DIR
  NAMES         "sqlite3/sqlite3.h"
  HINTS         ${zHints}
  PATH_SUFFIXES "include"
  NO_DEFAULT_PATH)
mark_as_advanced(SQLite_INCLUDE_DIR)

set(SQLite_INCLUDE_DIRS ${SQLite_INCLUDE_DIR})

# lib
get_toolset_tag(sTool)
get_architecture_address_model_tag(sArAd)

find_library(
  SQLite_LIBRARY
  NAMES         "sqlite3"
  HINTS         ${zHints}
  PATH_SUFFIXES "lib/${sArAd}/${sTool}"
                "lib/${sArAd}"
  NO_DEFAULT_PATH)
mark_as_advanced(SQLite_LIBRARY)
find_file(
  SQLite_LIBRARY_DLL
  NAMES         "sqlite3.dll"
  HINTS         ${zHints}
  PATH_SUFFIXES "lib/${sArAd}"
  NO_DEFAULT_PATH)
mark_as_advanced(SQLite_LIBRARY_DLL)

set(SQLite_LIBRARIES ${SQLite_LIBRARY})

# package
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  SQLite
  DEFAULT_MSG
  SQLite_LIBRARY
  SQLite_INCLUDE_DIR
  SQLite_LIBRARY_DLL)

if(SQLite_FOUND)
  # target
  if(NOT TARGET SQLite::SQLite)
    add_library(SQLite::SQLite SHARED IMPORTED)
    set_target_properties(
      SQLite::SQLite
      PROPERTIES IMPORTED_IMPLIB               "${SQLite_LIBRARY}"
                 IMPORTED_LOCATION             "${SQLite_LIBRARY_DLL}"
                 INTERFACE_INCLUDE_DIRECTORIES "${SQLite_INCLUDE_DIRS}")
  endif()
  mark_as_advanced(SQLite_ROOT_DIR)

else()
  # hints
  set(SQLite_ROOT_DIR "${SQLite_ROOT_DIR}" CACHE PATH "The root directory of the SQLite installation.")
  mark_as_advanced(CLEAR SQLite_ROOT_DIR)

endif()
