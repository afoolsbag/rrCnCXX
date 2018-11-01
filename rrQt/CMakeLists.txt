#             ___  _
#  _ __ _ __ / _ \| |_
# | '__| '__| | | | __|
# | |  | |  | |_| | |_
# |_|  |_|   \__\_\\__| rrQt by FIGlet
# zhengrr
# 2016-06-28 – 2018-10-31
# The Unlicense

project(rrQt VERSION 2018.10.31 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8)

add_doxygen()

find_package(Qt5Package)
find_package(Qt5 COMPONENTS Core Gui Widgets Quick Test)

conan_cmake_run(
  REQUIRES gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
aux_source_directory_ex(zTest DIRECTORY "test/" RECURSE QT GROUP_ROOT "test/")
add_executable_ex(
  NAME "test" "ygen.dox" ${zTest} CXX17
  INCLUDE_DIRECTORIES PRIVATE "test/"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gtest)

aux_add_subdirectories(WITH_OPTION OPTION_NAME_PREFIX "${PROJECT_NAME_UPPER}_")
