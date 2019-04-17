#            _____ __   ____   __
#           /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/ \ V /  \ V /
# | '__| '__| |     /   \  /   \  zhengrr
# | |  | |  | \__/\/ /^\ \/ /^\ \ 2016-08-01 – 2019-04-17
# |_|  |_|   \____/\/   \/\/   \/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrCXX
  VERSION   2019.04.17
  LANGUAGES CXX)

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen_con(
  rrCXXdoc)

conan_cmake_run(
  REQUIRES    gsl_microsoft/2.0.0@bincrafters/stable
              gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
aux_source_directory_con("." zSrc RECURSE)
add_executable_con(
  rrCXXtest           ${zSrc}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gsl_microsoft
                              CONAN_PKG::gtest)
