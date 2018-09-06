# ______ _           _ _
# |  ___(_)         | | |
# | |_   _ _ __   __| | |    _   _  __ _
# |  _| | | '_ \ / _` | |   | | | |/ _` |
# | |   | | | | | (_| | |___| |_| | (_| |
# \_|   |_|_| |_|\__,_\_____/\__,_|\__,_|
# zhengrr          FindLua by FIGlet doom
# 2018-07-09 – 2018-09-06
# The Unlicense

if(NOT COMMAND get_toolset_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/rrUtilities/LibTag.cmake")
endif()

#.rst:
# FindLua
# -------
#
# 寻找 Lua。
#
# 导入目标：
# ::
#
#    Lua::Lua
#
# 结果变量：
# ::
#
#    Lua_FOUND
#    Lua_INCLUDE_DIRS
#    Lua_LIBRARIES
#
# 提示变量：
# ::
#
#    Lua_ROOT
#    ENV Lua_ROOT
#
# 预期：
# ::
#
#    v lua_root
#       v include
#          v lua
#               lua.h
#               lualib.h
#               lauxlib.h
#               ...
#       v lib
#          > vc141x32
#          v vc141x64
#               lua53.dll
#               lua53.lib
#
if(Lua_FOUND)
  return()
endif()

# hints

set(zHints "${Lua_ROOT}" "$ENV{Lua_DIR}")

get_toolset_architecture_address_model_tag(sTag)

# include

find_path(Lua_INCLUDE_DIR
          NAMES "lua/lua.h"
          HINTS ${zHints}
  PATH_SUFFIXES "include"
                NO_DEFAULT_PATH)
mark_as_advanced(Lua_INCLUDE_DIR)

set(Lua_INCLUDE_DIRS ${Lua_INCLUDE_DIR})
mark_as_advanced(Lua_INCLUDE_DIRS)

# lib

set(zPathSufs "lib/${sTag}")

find_library(Lua_LIBRARY
          NAMES "lua" "lua53"
          HINTS ${zHints}
  PATH_SUFFIXES ${zPathSufs}
                NO_DEFAULT_PATH)
mark_as_advanced(Lua_LIBRARY)

find_file(Lua_LIBRARY_DLL
          NAMES "lua.dll" "lua53.dll"
          HINTS ${zHints}
  PATH_SUFFIXES ${zPathSufs}
                NO_DEFAULT_PATH)
mark_as_advanced(Lua_LIBRARY_DLL)

set(Lua_LIBRARIES ${Lua_LIBRARY})
mark_as_advanced(Lua_LIBRARIES)

# package

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Lua
                      DEFAULT_MSG Lua_LIBRARY
                                  Lua_INCLUDE_DIR
                                  Lua_LIBRARY_DLL)

if(Lua_FOUND)

  # target

  if(NOT TARGET Lua::Lua)
    add_library(Lua::Lua SHARED IMPORTED)
    set_target_properties(Lua::Lua
               PROPERTIES IMPORTED_IMPLIB "${Lua_LIBRARY}"
                          IMPORTED_LOCATION "${Lua_LIBRARY_DLL}"
                          INTERFACE_INCLUDE_DIRECTORIES "${Lua_INCLUDE_DIRS}")
  endif()

  mark_as_advanced(Lua_ROOT)

else()

  # hints

  set(Lua_ROOT "${Lua_ROOT}" CACHE PATH "The root directory of the Lua installation.")
  mark_as_advanced(CLEAR Lua_ROOT)

endif()
