#             ___                    ______     __
#  _ __ _ __ / _ \ _ __   ___ _ __  / ___\ \   / /
# | '__| '__| | | | '_ \ / _ | '_ \| |    \ \ / /
# | |  | |  | |_| | |_) |  __| | | | |___  \ V /
# |_|  |_|   \___/| .__/ \___|_| |_|\____|  \_/ rrOpenCV by FIGlet
# zhengrr         |_|
# 2018-01-22 – 2018-10-31
# The Unlicense

project(rrOpenCV VERSION 2018.10.31 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen()

find_package(OpenCVPackage)
find_package(OpenCV)

conan_cmake_run(
  REQUIRES gsl_microsoft/2.0.0@bincrafters/stable
           gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
aux_source_directory_ex(zTest DIRECTORY "test/" RECURSE GROUP_ROOT "test/")
add_executable_ex(
  NAME "test" "ygen.dox" ${zTest} CXX17
  INCLUDE_DIRECTORIES PRIVATE "test/"
                              ${OpenCV_INCLUDE_DIRS}
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gsl_microsoft
                              CONAN_PKG::gtest
                              opencv_core
  POST_COPIES                 opencv_core)

aux_add_subdirectories(WITH_OPTION OPTION_NAME_PREFIX "${PROJECT_NAME_UPPER}_")
