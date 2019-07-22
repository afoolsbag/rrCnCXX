#            _
#           | |
#  _ __ _ __| |    _   _  __ _
# | '__| '__| |   | | | |/ _` | zhengrr
# | |  | |  | |___| |_| | (_| | 2016-10-27 – 2019-07-22
# |_|  |_|  \_____/\__,_|\__,_| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

string(TIMESTAMP sYear       "%Y")
string(TIMESTAMP sMonth      "%m")
string(TIMESTAMP sDay        "%d")
string(TIMESTAMP sHourMinute "%H%M")

project_ex(
  rrLua
  VERSION   ${sYear}.${sMonth}.${sDay}.${sHourMinute}
  LANGUAGES CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

add_doxygen_con(
  rrLuaDoc)

hunter_add_package(Boost COMPONENTS filesystem)
find_package(Boost CONFIG REQUIRED COMPONENTS filesystem)
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
hunter_add_package(Lua)
find_package(Lua CONFIG REQUIRED)

aux_source_directory_con("." zTest RECURSE EXTENSIONS ".lua")
add_executable_con(
  rrLuaTest           ${zTest}
  PROPERTIES          CXX_STANDARD                  20
                      CXX_STANDARD_REQUIRED         ON
  INCLUDE_DIRECTORIES PRIVATE                       "."
  LINK_LIBRARIES      PRIVATE                       Boost::boost
                                                    Boost::filesystem
                                                    GTest::main
                                                    Lua::lua_lib)

add_custom_command(
  TARGET rrLuaTest POST_BUILD
  COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
          "${CMAKE_CURRENT_SOURCE_DIR}/test.lua"
          "$<TARGET_FILE_DIR:rrLuaTest>"
  COMMENT "Copy Lua script file to target directory")

add_test(NAME rrLuaTest COMMAND rrLuaTest)
