#            _____ __   ____   __
#           /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/ \ V /  \ V /
# | '__| '__| |     /   \  /   \
# | |  | |  | \__/\/ /^\ \/ /^\ \
# |_|  |_|   \____/\/   \/\/   \/ rrCxx by FIGlet doom
# zhengrr
# 2016-08-01 – 2018-10-15
# The Unlicense

cmake_policy(SET CMP0074 NEW) #3.12+

project(rrCXX VERSION 2018.10.15 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8)

facile_add_doxygen()

find_package(CCGSL)
aux_source_directory_ex(zSource RECURSE)
configure_file("project.hxx.in" "project.hxx" @ONLY)
aux_source_directory_ex(
  zGenerated
  DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/"
  GROUP_ROOT "generated/")
facile_add_gtest_executable(
  NAME "test"
  ${zSource} ${zGenerated}
  CXX17
  INCLUDE_DIRECTORIES PRIVATE "./"
                              "${CMAKE_CURRENT_BINARY_DIR}/"
                              ${CCGSL_INCLUDE_DIRS})
