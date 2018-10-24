#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____| rrMFC by FIGlet
# zhengrr
# 2017-12-08 – 2018-10-24
# The Unlicense

project(rrMFC VERSION 2018.10.24 LANGUAGES CXX)
project_more()
compile_option(UTF-8 WARNING_AS_ERROR)

facile_add_doxygen()

add_definitions("-D_AFXDLL")
set(CMAKE_MFC_FLAG 2)
add_definitions("-D_UNICODE")
remove_definitions("-D_MBCS")

aux_source_directory_ex(
  zTest
  DIRECTORY  "test/"
  RECURSE
  MFC
  GROUP_ROOT "test/")
facile_add_gtest_executable(
  NAME "test"
  "ygen.dox" ${zTest}
  CXX17
  INCLUDE_DIRECTORIES PRIVATE "test/")

aux_add_subdirectories(
  WITH_OPTION
  OPTION_NAME_PREFIX "${PROJECT_NAME_UPPER}_")
