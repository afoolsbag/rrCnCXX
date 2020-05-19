#            _ _ _
#           | (_) |
#  _ __ _ __| |_| |__  _   ___   __
# | '__| '__| | | '_ \| | | \ \ / / zhengrr
# | |  | |  | | | |_) | |_| |\ V /  2020-05-01 – 2020-05-06
# |_|  |_|  |_|_|_.__/ \__,_| \_/   Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrlibuv
  TIME_AS_VERSION
  LANGUAGES C CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

include_conan_script()
conan_cmake_run(
  REQUIRES    gtest/1.8.1
              libuv/1.34.2
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("." zTest RECURSE)
add_executable_con(
  rrlibuvTest         ${zTest}
  PROPERTIES          C_STANDARD            11
                      C_STANDARD_REQUIRED   ON
                      CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      CONAN_PKG::gtest
                      CONAN_PKG::libuv)

add_test(NAME rrlibuvTest COMMAND rrlibuvTest)
