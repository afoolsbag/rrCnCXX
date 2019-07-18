#            _____ __   ____   __
#           /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/ \ V /  \ V /
# | '__| '__| |     /   \  /   \  zhengrr
# | |  | |  | \__/\/ /^\ \/ /^\ \ 2016-08-01 – 2019-07-18
# |_|  |_|   \____/\/   \/\/   \/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

string(TIMESTAMP sYear       "%Y")
string(TIMESTAMP sMonth      "%m")
string(TIMESTAMP sDay        "%d")
string(TIMESTAMP sHourMinute "%H%M")

project_ex(
  rrCXX
  VERSION   ${sYear}.${sMonth}.${sDay}.${sHourMinute}
  LANGUAGES CXX)

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen_con(
  rrCXXdoc)

hunter_add_package(Microsoft.GSL)
find_package(Microsoft.GSL CONFIG REQUIRED)
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

aux_source_directory_con("." zSrc RECURSE)
add_executable_con(
  rrCXXtest           ${zSrc}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      Microsoft.GSL::GSL
                      GTest::main)
