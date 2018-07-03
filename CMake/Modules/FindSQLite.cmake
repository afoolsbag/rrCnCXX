# ______ _           _ _____  _____ _     _ _
# |  ___(_)         | /  ___||  _  | |   (_) |
# | |_   _ _ __   __| \ `--. | | | | |    _| |_ ___
# |  _| | | '_ \ / _` |`--. \| | | | |   | | __/ _ \
# | |   | | | | | (_| /\__/ /\ \/' / |___| | ||  __/
# \_|   |_|_| |_|\__,_\____/  \_/\_\_____/_|\__\___|
# zhengrr                  FindSQLite by FIGlet doom
# 2018-05-23 – 2018-07-03
# The MIT License

#.rst:
# FindSQLite
# ----------
#
# 寻找SQLite包。
#
# 缓存：
# ::
#
#    SQLite_ROOT_DIR
#    ENV SQLITEROOT
#
# 影响：
# ::
#
#    SQLite_FOUND
#    SQLite_INCLUDE_DIRS
#    SQLite_LIBRARIES
#
#    SQLite
#
# 预期：
# ::
#
#    v sqlite_root_dir
#       v include
#          v sqlite3
#               sqlite3.h
#               sqlite3ext.h
#       v bin
#          > x32
#          v x64
#               sqlite3.def
#               sqlite3.dll
#       v lib
#          > vc141x32
#          v vc141x64
#               sqlite3.exp
#               sqlite3.lib
#
if(SQLite_FOUND)
  return()
endif()

if(NOT COMMAND get_toolset_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrUtilities/LibTag.cmake")
endif()
get_toolset_tag(sTool)
get_architecture_address_model_tag(sArAd)

set(zHints "${SQLite_ROOT_DIR}" "$ENV{SQLITEROOT}")

set(zPathSufs "lib/${sTool}${sArAd}"
              "lib/${sArAd}"
              "lib")

find_path(SQLite_INCLUDE_DIRS
          NAMES "sqlite3/sqlite3.h"
          HINTS ${zHints}
  PATH_SUFFIXES "include"
                NO_DEFAULT_PATH)
mark_as_advanced(SQLite_INCLUDE_DIRS)

find_library(SQLite_LIBRARY
          NAMES "sqlite3"
          HINTS ${zHints}
  PATH_SUFFIXES ${zPathSufs}
                NO_DEFAULT_PATH)
mark_as_advanced(SQLite_LIBRARY)

set(SQLite_LIBRARIES ${SQLite_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SQLite
                      DEFAULT_MSG SQLite_INCLUDE_DIRS
                                  SQLite_LIBRARY)

if(SQLite_FOUND)
  if(NOT TARGET SQLite)
  add_library(SQLite UNKNOWN IMPORTED)
  set_target_properties(SQLite    PROPERTIES
                IMPORTED_LOCATION "${SQLite_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${SQLite_INCLUDE_DIRS}")
  endif()
else()
  set(SQLite_ROOT_DIR "${SQLite_ROOT_DIR}" CACHE PATH "The root directory of the SQLite installation.")
  mark_as_advanced(CLEAR SQLite_ROOT_DIR)
endif()
