#             ____
#  _ __ _ __ / ___|
# | '__| '__| |
# | |  | |  | |___
# |_|  |_|   \____| rrC by FIGlet
# zhengrr
# 2016-08-01 – 2018-10-15
# The Unlicense

project(rrC VERSION 2018.10.15 LANGUAGES C)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

aux_source_directory_ex(zSource RECURSE)
configure_file("project.h.in" "project.h" @ONLY)
aux_source_directory_ex(
  zGenerated
  DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/"
  GROUP_ROOT "generated/")
facile_add_check_executable(
  NAME "test"
  ${zSource} ${zGenerated}
  C11
  INCLUDE_DIRECTORIES PRIVATE "./"
                              "${CMAKE_CURRENT_BINARY_DIR}/")
