#            ____                  _
#  _ __ _ __| __ )  ___   ___  ___| |_
# | '__| '__|  _ \ / _ \ / _ \/ __| __|
# | |  | |  | |_) | (_) | (_) \__ | |_
# |_|  |_|  |____/ \___/ \___/|___/\__| rrBoost by FIGlet
# zhengrr
# 2016-10-27 – 2018-10-31
# The Unlicense

cmake_policy(SET CMP0074 NEW) #3.12+

project(rrBoost VERSION 2018.10.31 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8)

add_doxygen()

conan_cmake_run(
  REQUIRES boost/1.68.0@conan/stable
           gsl_microsoft/2.0.0@bincrafters/stable
           gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
aux_source_directory_ex(zSource RECURSE)
add_executable_ex(
  NAME "test" ${zSource} CXX17
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gsl_microsoft)
                              CONAN_PKG::gtest
                              CONAN_PKG::boost
