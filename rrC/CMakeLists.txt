#            _____
#           /  __ \
#  _ __ _ __| /  \/
# | '__| '__| |     zhengrr
# | |  | |  | \__/\ 2016-08-01 – 2019-01-02
# |_|  |_|   \____/ Unlicense

project(rrC VERSION 2019.01.02 LANGUAGES C)
project_more()
compile_option(HIGHEST_WARNING_LEVEL MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

find_package(Check)

aux_source_directory_ex(zSource RECURSE)
configure_file("project.h.in" "project.h" @ONLY)
aux_source_directory_ex(zGenerated DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/" GROUP_ROOT "generated/")

add_executable_ex(
  ${zSource} ${zGenerated} C11
  INCLUDE_DIRECTORIES PRIVATE "./"
                              "${CMAKE_CURRENT_BINARY_DIR}/"
  LINK_LIBRARIES      PRIVATE Check::check)
