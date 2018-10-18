#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/ rrWindows by FIGlet
# zhengrr
# 2016-10-12 – 2018-10-18
# The Unlicense

project(rrWindows VERSION 2018.10.18 LANGUAGES C)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

add_definitions("-D_UNICODE")
remove_definitions("-D_MBCS")

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
configure_file("src/project.h.in" "src/project.h" @ONLY)
aux_source_directory_ex(
  zGenerated
  DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/src/"
  GROUP_ROOT "generated/")
add_library_ex(
  SHARED
  ${zInclude} ${zSrc} ${zGenerated}
  TARGET_NAME_VARIABLE sRrwindowsLib
  COMPILE_DEFINITIONS  PUBLIC  "-DRRWINDOWS_SHARED"
  INCLUDE_DIRECTORIES  PUBLIC  "include/"
                       PRIVATE "src/"
                               "${CMAKE_CURRENT_BINARY_DIR}/src/")

configure_file("test/project.h.in" "test/project.h" @ONLY)
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
