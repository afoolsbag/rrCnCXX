#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-10-13
# The Unlicense

project(rrWindows VERSION 2018.10.13 LANGUAGES C)
project_extra()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

add_definitions("-D_UNICODE")
remove_definitions("-D_MBCS")

configure_file("src/cfg.h.in" "src/cfg.h" @ONLY)
aux_source_directory_ex(
  zInclude
  DIRECTORY  "include/"
  RECURSE
  GROUP_ROOT "include/")
aux_source_directory_ex(
  zSrc
  DIRECTORY  "src/"
  RECURSE
  EXTENSIONS ".rc"
  GROUP_ROOT "src/")
aux_source_directory_ex(
  zGenerate
  DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/src/"
  RECURSE
  GROUP_ROOT "generate/")
add_library_ex(
  SHARED
  ${zInclude} ${zSrc} ${zGenerate}
  TARGET_NAME_VARIABLE sRrwindowsLib
  COMPILE_DEFINITIONS  PUBLIC  "-DRRWINDOWS_SHARED"
  INCLUDE_DIRECTORIES  PUBLIC  "include/"
                       PRIVATE "src/"
                               "${CMAKE_CURRENT_BINARY_DIR}/src/")

configure_file("test/cfg.h.in" "test/cfg.h" @ONLY)
aux_source_directory_ex(
  zTest
  DIRECTORY  "test/"
  RECURSE
  EXTENSIONS ".rc"
  GROUP_ROOT "test/")
aux_source_directory_ex(
  zGenerate
  DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/test/"
  RECURSE
  GROUP_ROOT "generate/")
facile_add_check_executable(
  NAME "test"
  ${zTest} ${zGenerate} "ygen.dox"
  INCLUDE_DIRECTORIES PRIVATE "test/"
                              "${CMAKE_CURRENT_BINARY_DIR}/test/"
  LINK_LIBRARIES      PRIVATE ${sRrwindowsLib}
  POST_COPIES         ${sRrwindowsLib})
