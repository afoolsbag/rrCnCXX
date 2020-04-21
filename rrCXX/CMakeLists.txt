#            _____ __   ____   __
#           /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/ \ V /  \ V /
# | '__| '__| |     /   \  /   \  zhengrr
# | |  | |  | \__/\/ /^\ \/ /^\ \ 2016-08-01 – 2020-01-08
# |_|  |_|   \____/\/   \/\/   \/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrCXX
  TIME_AS_VERSION
  LANGUAGES CXX)

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

add_doxygen_con(
  rrCxxDoc)

include_conan_script()
conan_cmake_run(
  REQUIRES    gtest/1.8.1@bincrafters/stable
  #           gtest/1.10.0
              ms-gsl/2.0.0
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("../include/rrcxx" zWrapper RECURSE PREFIX "include/rrcxx")
add_library_ex(
  rrCXX               INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_17
  INCLUDE_DIRECTORIES INTERFACE "../include"
  LINK_LIBRARIES      INTERFACE CONAN_PKG::ms-gsl
  SOURCES             INTERFACE ${zWrapper})

aux_source_directory_con("." zTest RECURSE)
add_executable_con(
  rrCxxTest           ${zTest}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      CONAN_PKG::gtest
                      rrCXX
                      CONAN_PKG::ms-gsl)

add_test(NAME rrCxxTest COMMAND rrCxxTest)
