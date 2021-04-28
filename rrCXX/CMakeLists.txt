#            _____ __   ____   __
#           /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/ \ V /  \ V /
# | '__| '__| |     /   \  /   \  zhengrr
# | |  | |  | \__/\/ /^\ \/ /^\ \ 2016-08-01 – 2021-04-22
# |_|  |_|   \____/\/   \/\/   \/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

rr_project(
  rrCXX
  TIME_AS_VERSION
  LANGUAGES CXX)

rr_add_compile_options(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

rr_add_doxygen_wcon(
  rrCxxDoc)

rr_include_conan_script()
conan_cmake_run(
  REQUIRES    gtest/1.10.0
              ms-gsl/3.1.0
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

rr_aux_source_directory_with_convention("../include/rrcxx" zWrapper RECURSE PREFIX "include/rrcxx")
rr_add_library(
  rrCXX               INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_17
  INCLUDE_DIRECTORIES INTERFACE "../include"
  LINK_LIBRARIES      INTERFACE CONAN_PKG::ms-gsl
  SOURCES             INTERFACE ${zWrapper})

rr_aux_source_directory_with_convention("." zTest RECURSE)
rr_add_executable_wcon(
  rrCxxTest           ${zTest}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      CONAN_PKG::gtest
                      rrCXX
                      CONAN_PKG::ms-gsl)

add_test(NAME rrCxxTest COMMAND rrCxxTest)
