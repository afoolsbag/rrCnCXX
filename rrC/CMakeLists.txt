#            _____
#           /  __ \
#  _ __ _ __| /  \/
# | '__| '__| |     zhengrr
# | |  | |  | \__/\ 2016-08-01 – 2019-04-15
# |_|  |_|   \____/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project(rrC VERSION 2019.04.15 LANGUAGES C)
project_more()

compile_option(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen_con(
  rrCdoc
  OPTIMIZE_OUTPUT_FOR_C ON)

find_package(Check)
aux_source_directory_ex(zSrc RECURSE)
add_executable_con(
  rrCtest             ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE             "./"
  LINK_LIBRARIES      PRIVATE             Check::check)
