#             ____
#  _ __ _ __ / ___|
# | '__| '__| |
# | |  | |  | |___
# |_|  |_|   \____| rrC by FIGlet
# zhengrr
# 2016-08-01 – 2018-10-13
# The Unlicense

project(rrC VERSION 2018.10.13 LANGUAGES C)
project_extra()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

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
  GROUP_ROOT "src/")
aux_source_directory_ex(
  zGenerate
  DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/src/"
  RECURSE
  GROUP_ROOT "generate/")
add_library_ex(
  SHARED
  ${zInclude} ${zSrc} ${zGenerate}
  TARGET_NAME_VARIABLE sRrcLib
  COMPILE_DEFINITIONS  PUBLIC  "-DRRC_SHARED"
  INCLUDE_DIRECTORIES  PUBLIC  "include/"
                       PRIVATE "src/"
                               "${CMAKE_CURRENT_BINARY_DIR}/src/")

aux_source_directory_ex(
  zTest
  DIRECTORY  "test/"
  RECURSE
  GROUP_ROOT "test/")
facile_add_check_executable(
  NAME                "test"
  ${zTest} "ygen.dox"
  INCLUDE_DIRECTORIES PRIVATE "test/"
  LINK_LIBRARIES      PRIVATE ${sRrcLib}
  POST_COPIES         ${sRrcLib})
