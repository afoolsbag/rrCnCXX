#                          _ _
#                         | | |
#  _ __ _ __ ___ _ __   __| | | ___   __ _
# | '__| '__/ __| '_ \ / _` | |/ _ \ / _` |
# | |  | |  \__ \ |_) | (_| | | (_) | (_| |
# |_|  |_|  |___/ .__/ \__,_|_|\___/ \__, |
#               | |                   __/ |
# zhengrr       |_|                  |___/  rrspdlog by FIGlet doom
# 2018-08-04 – 2018-11-06
# The Unlicense

cmake_policy(SET CMP0074 NEW) #3.12+

project(rrspdlog VERSION 2108.11.06 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8)

add_doxygen()

conan_cmake_run(
  REQUIRES spdlog/1.2.1@bincrafters/stable
           gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
aux_source_directory_ex(zTest)
add_executable_ex(
  NAME "test" ${zTest} CXX17
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::spdlog
                              CONAN_PKG::gtest)
