# ______ _           _ _____  _____ _     _ _
# |  ___(_)         | /  ___||  _  | |   (_) |
# | |_   _ _ __   __| \ `--. | | | | |    _| |_ ___
# |  _| | | '_ \ / _` |`--. \| | | | |   | | __/ _ \
# | |   | | | | | (_| /\__/ /\ \/' / |___| | ||  __/
# \_|   |_|_| |_|\__,_\____/  \_/\_\_____/_|\__\___|
# zhengrr                  FindSQLite by FIGlet doom
# 2018-05-23 – 23
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
set(zHints "${SQLite_ROOT_DIR}" "$ENV{SQLITEROOT}")

if(MSVC)
  if(MSVC_VERSION GREATER_EQUAL 1910)
    set(sCompiler "vc141")
  elseif(MSVC14)
    set(sCompiler "vc140")
  elseif(MSVC12)
    set(sCompiler "vc120")
  elseif(MSVC11)
    set(sCompiler "vc110")
  elseif(MSVC10)
    set(sCompiler "vc100")
  elseif(MSVC90)
    set(sCompiler "vc90")
  elseif(MSVC80)
    set(sCompiler "vc80")
  elseif(MSVC71)
    set(sCompiler "vc71")
  elseif(MSVC70)
    set(sCompiler "vc7")
  elseif(MSVC60)
    set(sCompiler "vc6")
  else()
    message(FATAL_ERROR "Unsupported MSVC_VERSION: ${MSVC_VERSION}.")
  endif()
else()
  set(sCompiler)
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
  set(sArchitecture "x32")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(sArchitecture "x64")
else()
  message(FATAL_ERROR "Unsupported CMAKE_SIZEOF_VOID_P: ${CMAKE_SIZEOF_VOID_P}.")
endif()

set(zPathSuffixes "lib/${sCompiler}${sArchitecture}"
                  "lib/${sArchitecture}"
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
  PATH_SUFFIXES ${zPathSuffixes}
                NO_DEFAULT_PATH)
mark_as_advanced(SQLite_LIBRARY)

set(SQLite_LIBRARIES ${SQLite_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SQLite
                      DEFAULT_MSG SQLite_INCLUDE_DIRS
                                  SQLite_LIBRARY)

if(SQLite_FOUND AND NOT TARGET SQLite)
  add_library(SQLite UNKNOWN IMPORTED)
  set_target_properties(SQLite    PROPERTIES
                IMPORTED_LOCATION "${SQLite_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${SQLite_INCLUDE_DIRS}")
endif()
