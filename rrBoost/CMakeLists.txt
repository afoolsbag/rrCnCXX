#           ______                 _
#           | ___ \               | |
#  _ __ _ __| |_/ / ___   ___  ___| |_
# | '__| '__| ___ \/ _ \ / _ \/ __| __| zhengrr
# | |  | |  | |_/ / (_) | (_) \__ \ |_  2016-10-27 – 2019-02-26
# |_|  |_|  \____/ \___/ \___/|___/\__| Unlicense

project(rrBoost VERSION 2019.02.26 LANGUAGES CXX)
project_more()
compile_option(RECOMMENDED_WARNING_LEVEL MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen(WITH_OPTION)

conan_cmake_run(
  REQUIRES boost/1.69.0@conan/stable
           gsl_microsoft/2.0.0@bincrafters/stable
           gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)

aux_source_directory_ex(zSource RECURSE)

add_executable_ex(
  ${zSource} CXX17
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gsl_microsoft
                              CONAN_PKG::gtest
                              CONAN_PKG::boost)
