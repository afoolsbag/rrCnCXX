#            _____                  _____ _   _
#           |  _  |                /  __ \ | | |
#  _ __ _ __| | | |_ __   ___ _ __ | /  \/ | | |
# | '__| '__| | | | '_ \ / _ \ '_ \| |   | | | |
# | |  | |  \ \_/ / |_) |  __/ | | | \__/\ \_/ /
# |_|  |_|   \___/| .__/ \___|_| |_|\____/\___/  zhengrr
#                 | |                            2018-01-22 – 2019-01-06
#                 |_|                            Unlicense

project(rrOpenCV VERSION 2019.1.4 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen()

conan_cmake_run(
  REQUIRES gsl_microsoft/2.0.0@bincrafters/stable
           gtest/1.8.1@bincrafters/stable
           opencv/4.0.0@conan/stable
  BASIC_SETUP CMAKE_TARGETS)

aux_source_directory_ex(zSource RECURSE)

add_executable_ex(
  ${zSource} CXX17
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gsl_microsoft
                              CONAN_PKG::gtest
                              CONAN_PKG::opencv)
