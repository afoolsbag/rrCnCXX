#            _____ __   ____   __
#           /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/ \ V /  \ V /
# | '__| '__| |     /   \  /   \  zhengrr
# | |  | |  | \__/\/ /^\ \/ /^\ \ 2016-08-01 – 2019-01-28
# |_|  |_|   \____/\/   \/\/   \/ Unlicense

project(rrCXX VERSION 2019.01.28 LANGUAGES CXX)
project_more()
compile_option(RECOMMENDED_WARNING_LEVEL MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen(WITH_OPTION)

conan_cmake_run(
  REQUIRES gsl_microsoft/2.0.0@bincrafters/stable
           gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)

aux_source_directory_ex(zSource RECURSE)
add_executable_ex(
  ${zSource} ${zGenerated} CXX17
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gsl_microsoft
                              CONAN_PKG::gtest)
