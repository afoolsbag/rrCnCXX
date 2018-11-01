#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____| rrMFC by FIGlet
# zhengrr
# 2017-12-08 – 2018-10-31
# The Unlicense

project(rrMFC VERSION 2018.10.31 LANGUAGES CXX)
project_more()
compile_option(UTF-8 WARNING_AS_ERROR)

add_doxygen()

add_definitions("-D_AFXDLL")
set(CMAKE_MFC_FLAG 2)
add_definitions("-D_UNICODE")
remove_definitions("-D_MBCS")

conan_cmake_run(
  REQUIRES gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
aux_source_directory_ex(zTest DIRECTORY "test/" RECURSE MFC GROUP_ROOT "test/")
add_executable_ex(
  NAME "test" "ygen.dox" ${zTest} CXX17
  INCLUDE_DIRECTORIES PRIVATE "test/"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gtest)

aux_add_subdirectories(WITH_OPTION OPTION_NAME_PREFIX "${PROJECT_NAME_UPPER}_")
