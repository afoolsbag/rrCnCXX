#            _________ ___________ _     ___________
#           |_  | ___ \_   _| ___ \ |   |_   _| ___ \
#  _ __ _ __  | | |_/ / | | | |_/ / |     | | | |_/ /
# | '__| '__| | |    /  | | |  __/| |     | | | ___ \ zhengrr
# | |  | |/\__/ / |\ \  | | | |   | |_____| |_| |_/ / 2019-01-17 – 2019-01-18
# |_|  |_|\____/\_| \_| \_/ \_|   \_____/\___/\____/  Unlicense

project(rrJRTPLIB VERSION 2019.01.18 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

conan_cmake_run(
  REQUIRES gsl_microsoft/2.0.0@bincrafters/stable
           gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
find_package(JThread)
find_package(JRTPLIB)

aux_source_directory_ex(zSource RECURSE)
add_executable_ex(
  ${zSource} CXX17
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gsl_microsoft
                              CONAN_PKG::gtest
                              JThread::jthread
                              JRTPLIB::jrtplib)
