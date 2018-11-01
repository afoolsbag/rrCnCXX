#            _____ __   ____   __
#           /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/ \ V /  \ V /
# | '__| '__| |     /   \  /   \
# | |  | |  | \__/\/ /^\ \/ /^\ \
# |_|  |_|   \____/\/   \/\/   \/ rrCxx by FIGlet doom
# zhengrr
# 2016-08-01 – 2018-10-31
# The Unlicense

cmake_policy(SET CMP0074 NEW) #3.12+

project(rrCXX VERSION 2018.10.31 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8)

add_doxygen()

conan_cmake_run(
  REQUIRES gsl_microsoft/2.0.0@bincrafters/stable
           gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
aux_source_directory_ex(zSource RECURSE)
configure_file("project.hxx.in" "project.hxx" @ONLY)
aux_source_directory_ex(zGenerated DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/" GROUP_ROOT "generated/")
add_executable_ex(
  ${zSource} ${zGenerated} CXX17
  INCLUDE_DIRECTORIES PRIVATE "./"
                              "${CMAKE_CURRENT_BINARY_DIR}/"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gsl_microsoft
                              CONAN_PKG::gtest)
