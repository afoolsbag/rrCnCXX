#           ___  _________ _____ 
#           |  \/  ||  ___/  __ \
#  _ __ _ __| .  . || |_  | /  \/
# | '__| '__| |\/| ||  _| | |     zhengrr
# | |  | |  | |  | || |   | \__/\ 2017-12-08 – 2019-04-16
# |_|  |_|  \_|  |_/\_|    \____/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project(rrMFC VERSION 2019.04.16 LANGUAGES CXX)
project_more()

compile_option(
  RECOMMENDED_WARNING_LEVEL
  UTF-8
  WARNING_AS_ERROR)

add_doxygen_con(
  rrMFCdoc)

add_definitions("-D_AFXDLL")
set(CMAKE_MFC_FLAG 2)
add_definitions("-D_UNICODE")
remove_definitions("-D_MBCS")

conan_cmake_run(
  REQUIRES    gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
aux_source_directory_con("test" zTest RECURSE MFC PREFIX "test")
add_executable_con(
  rrMFCtest           "ygen.dox" ${zTest}
  INCLUDE_DIRECTORIES PRIVATE "test"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gtest)

aux_add_subdirectories(WITH_OPTION OPTION_NAME_PREFIX "${PROJECT_NAME_UPPER}_")
