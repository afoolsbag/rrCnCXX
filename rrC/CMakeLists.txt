#            _____
#           /  __ \
#  _ __ _ __| /  \/
# | '__| '__| |     zhengrr
# | |  | |  | \__/\ 2016-08-01 – 2019-01-17
# |_|  |_|   \____/ Unlicense

project(rrC VERSION 2019.01.17 LANGUAGES C)
project_more()
compile_option(HIGHEST_WARNING_LEVEL MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen(WITH_OPTION OPTIMIZE_OUTPUT_FOR_C)

find_package(Check)

aux_source_directory_ex(zSource RECURSE)
add_executable_ex(
  ${zSource} C11
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE Check::check)
