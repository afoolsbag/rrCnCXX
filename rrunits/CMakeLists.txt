#                        _ _
#                       (_) |
#  _ __ _ __ _   _ _ __  _| |_ ___
# | '__| '__| | | | '_ \| | __/ __| zhengrr
# | |  | |  | |_| | | | | | |_\__ \ 2019-12-06 – 2019-12-06
# |_|  |_|   \__,_|_| |_|_|\__|___/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

project_ex(
  rrunits
  TIME_AS_VERSION
  LANGUAGES CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

hunter_add_package(units)
find_package(units CONFIG REQUIRED)

include_conan_script()
conan_cmake_run(
  REQUIRES    boost/1.71.0@conan/stable
              gtest/1.10.0
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("." zTest RECURSE)
add_executable_con(
  rrunitsTest         ${zTest}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gtest
                              units::units)

add_test(NAME rrunitsTest COMMAND rrunitsTest)
