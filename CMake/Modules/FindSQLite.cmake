# ______ _           _ _____  _____ _     _ _
# |  ___(_)         | /  ___||  _  | |   (_) |
# | |_   _ _ __   __| \ `--. | | | | |    _| |_ ___
# |  _| | | '_ \ / _` |`--. \| | | | |   | | __/ _ \
# | |   | | | | | (_| /\__/ /\ \/' / |___| | ||  __/
# \_|   |_|_| |_|\__,_\____/  \_/\_\_____/_|\__\___|
# zhengrr                  FindSQLite by FIGlet doom
# 2018-05-23 – 2018-07-05
# The MIT License

#.rst:
# FindSQLite
# ----------
#
# 寻找SQLite。
#
# 导入目标：
# ::
#
#    SQLite
#
# 结果变量：
# ::
#
#    SQLite_FOUND
#    SQLite_INCLUDE_DIRS
#    SQLite_LIBRARIES
#
# 提示变量：
# ::
#
#    SQLite_ROOT_DIR
#    ENV SQLITEROOT
#
# 预期：
# ::
#
#    v sqlite_root_dir
#       v include
#          v sqlite3
#               sqlite3.h
#               sqlite3ext.h
#       v lib
#          > x32
#          v x64
#               sqlite3.def
#               sqlite3.dll
#               sqlite3.exp
#               sqlite3.lib
#
if(SQLite_FOUND)
  return()
endif()

# hints

set(zHints "${SQLite_ROOT_DIR}" "$ENV{SQLITEROOT}")

if(NOT COMMAND get_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrUtilities/LibTag.cmake")
endif()
get_architecture_address_model_tag(sArAd)

# include

find_path(SQLite_INCLUDE_DIR
          NAMES "sqlite3/sqlite3.h"
          HINTS ${zHints}
  PATH_SUFFIXES "include"
                NO_DEFAULT_PATH)
mark_as_advanced(SQLite_INCLUDE_DIR)

set(SQLite_INCLUDE_DIRS ${SQLite_INCLUDE_DIR})
mark_as_advanced(SQLite_INCLUDE_DIRS)

# lib

set(zPathSufs "lib/${sArAd}"
              "lib")

find_library(SQLite_LIBRARY
          NAMES "sqlite3"
          HINTS ${zHints}
  PATH_SUFFIXES ${zPathSufs}
                NO_DEFAULT_PATH)
mark_as_advanced(SQLite_LIBRARY)

find_file(SQLite_LIBRARY_DLL
          NAMES "sqlite3.dll"
          HINTS ${zHints}
  PATH_SUFFIXES ${zPathSufs}
                NO_DEFAULT_PATH)
mark_as_advanced(SQLite_LIBRARY_DLL)

set(SQLite_LIBRARIES ${SQLite_LIBRARY})
mark_as_advanced(SQLite_LIBRARIES)

# package

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SQLite
                      DEFAULT_MSG SQLite_LIBRARY
                                  SQLite_INCLUDE_DIR
                                  SQLite_LIBRARY_DLL)

if(SQLite_FOUND)

  # target

  if(NOT TARGET SQLite)
    add_library(SQLite SHARED IMPORTED)
    set_target_properties(SQLite
               PROPERTIES IMPORTED_IMPLIB "${SQLite_LIBRARY}"
                          IMPORTED_LOCATION "${SQLite_LIBRARY_DLL}"
                          INTERFACE_INCLUDE_DIRECTORIES "${SQLite_INCLUDE_DIRS}")
  endif()

else()

  # hints

  set(SQLite_ROOT_DIR "${SQLite_ROOT_DIR}" CACHE PATH "The root directory of the SQLite installation.")
  mark_as_advanced(CLEAR SQLite_ROOT_DIR)

endif()
