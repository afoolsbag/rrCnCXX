#            _____ __   ____   __
#           /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/ \ V /  \ V /
# | '__| '__| |     /   \  /   \
# | |  | |  | \__/\/ /^\ \/ /^\ \
# |_|  |_|   \____/\/   \/\/   \/ rrCxx by FIGlet doom
# zhengrr
# 2016-08-01 – 2018-10-13
# The Unlicense

cmake_policy(SET CMP0074 NEW) #3.12+

project(rrCXX VERSION 2018.10.13 LANGUAGES CXX)
project_extra()
compile_option(MULTIPLE_PROCESSES UTF-8)

facile_add_doxygen()

find_package(CCGSL)

configure_file("src/project.hxx.in" "src/project.hxx" @ONLY)
aux_source_directory_ex(
  zInclude
  DIRECTORY  "include/"
  RECURSE
  GROUP_ROOT "include/")
aux_source_directory_ex(
  zSrc
  DIRECTORY  "src/"
  RECURSE
  GROUP_ROOT "src/")
aux_source_directory_ex(
  zGenerate
  DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/src/"
  RECURSE
  GROUP_ROOT "generate/")
add_library_ex(
  SHARED
  ${zInclude} ${zSrc} ${zGenerate}
  TARGET_NAME_VARIABLE sRrcxxLib
  CXX17
  COMPILE_DEFINITIONS  PUBLIC  "-DRRCXX_SHARED"
  INCLUDE_DIRECTORIES  PUBLIC  "include/"
                       PRIVATE "src/"
                               "${CMAKE_CURRENT_BINARY_DIR}/src/"
                               ${CCGSL_INCLUDE_DIRS})

aux_source_directory_ex(
  zTest
  DIRECTORY  "test/"
  RECURSE
  GROUP_ROOT "test/")
facile_add_gtest_executable(
  NAME                "test"
  ${zTest} "ygen.dox"
  CXX17
  INCLUDE_DIRECTORIES PRIVATE "test/"
                              ${CCGSL_INCLUDE_DIRS}
  LINK_LIBRARIES      PRIVATE ${sRrcxxLib}
  POST_COPIES         ${sRrcxxLib})
