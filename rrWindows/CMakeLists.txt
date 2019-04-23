#            _    _ _           _
#           | |  | (_)         | |
#  _ __ _ __| |  | |_ _ __   __| | _____      _____
# | '__| '__| |/\| | | '_ \ / _` |/ _ \ \ /\ / / __| zhengrr
# | |  | |  \  /\  / | | | | (_| | (_) \ V  V /\__ \ 2016-10-12 – 2019-04-22
# |_|  |_|   \/  \/|_|_| |_|\__,_|\___/ \_/\_/ |___/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrWindows
  VERSION   2019.04.22
  LANGUAGES C)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen_con(
  rrWindowsDoc
  OPTIMIZE_OUTPUT_FOR_C ON)

configure_file("src/project.h.in" "src/project.h" @ONLY)
aux_source_directory_con("include"                         zInc RECURSE                  PREFIX "include")
aux_source_directory_con("src"                             zSrc RECURSE EXTENSIONS ".rc" PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/src" zGen                          PREFIX "generated")
add_library_con(
  rrWindows
  SHARED              ${zInc} ${zSrc} ${zGen}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PUBLIC  "RRWINDOWS_SHARED"
                              "_WIN32_WINNT=0x0601"
                      PRIVATE "_UNICODE"
  INCLUDE_DIRECTORIES PUBLIC  "include"
                      PRIVATE "src"
                              "${CMAKE_CURRENT_BINARY_DIR}/src")
install(
  DIRECTORY   "include"
  DESTINATION ".")

find_package(Check)
configure_file("test/project.h.in" "test/project.h" @ONLY)
aux_source_directory_ex("test"                             zTest RECURSE EXTENSIONS ".rc" PREFIX "test")
aux_source_directory_ex("${CMAKE_CURRENT_BINARY_DIR}/test" zGen                           PREFIX "generated")
add_executable_con(
  rrWindowsTest       ${zTest} ${zGen} "ygen.dox"
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PRIVATE "_UNICODE"
  INCLUDE_DIRECTORIES PRIVATE "test"
                              "${CMAKE_CURRENT_BINARY_DIR}/test"
  LINK_LIBRARIES      PRIVATE Check::check
                              rrWindows)

configure_file("wdt/project.h.in" "wdt/project.h" @ONLY)
aux_source_directory_con("wdt"                             zWdt RECURSE EXTENSIONS ".rc" PREFIX "wdt")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/wdt" zGen                          PREFIX "generated")
add_executable_con(
  rrWdt               ${zWdt} ${zGen}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PRIVATE "_UNICODE"
  INCLUDE_DIRECTORIES PRIVATE "wdt"
                              "${CMAKE_CURRENT_BINARY_DIR}/wdt"
  LINK_LIBRARIES      PRIVATE rrWindows)

