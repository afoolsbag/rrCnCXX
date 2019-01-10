#                          _ _
#                         | | |
#  _ __ _ __ ___ _ __   __| | | ___   __ _
# | '__| '__/ __| '_ \ / _` | |/ _ \ / _` |
# | |  | |  \__ \ |_) | (_| | | (_) | (_| |
# |_|  |_|  |___/ .__/ \__,_|_|\___/ \__, | zhengrr
#               | |                   __/ | 2018-08-04 – 2019-01-10
#               |_|                  |___/  Unlicense

cmake_policy(SET CMP0074 NEW) #3.12+

project(rrspdlog VERSION 2019.1.10 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen()

conan_cmake_run(
  REQUIRES spdlog/1.2.1@bincrafters/stable
           gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)

aux_source_directory_ex(zSource)

add_executable_ex(
  ${zSource} CXX17
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::spdlog
                              CONAN_PKG::gtest)
