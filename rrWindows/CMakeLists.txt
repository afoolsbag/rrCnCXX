#            _    _ _           _
#           | |  | (_)         | |
#  _ __ _ __| |  | |_ _ __   __| | _____      _____
# | '__| '__| |/\| | | '_ \ / _` |/ _ \ \ /\ / / __| zhengrr
# | |  | |  \  /\  / | | | | (_| | (_) \ V  V /\__ \ 2016-10-12 – 2020-20-30
# |_|  |_|   \/  \/|_|_| |_|\__,_|\___/ \_/\_/ |___/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

if(NOT WIN32)
  message(WARNING "The project is just supposed to work with Windows.")
endif()

project_ex(
  rrWindows
  TIME_AS_VERSION
  LANGUAGES C CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

include_conan_script()
conan_cmake_run(
  REQUIRES    gtest/1.10.0
              ms-gsl/2.0.0
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

add_doxygen_con(
  rrWindowsDoc)

aux_source_directory_con("../include/rrwindows" zWrapper RECURSE PREFIX "include/rrwindows")
add_library_ex(
  rrWindows           INTERFACE
  COMPILE_DEFINITIONS INTERFACE "_WIN32_WINNT=0x0A00"  # Windows 10
  COMPILE_FEATURES    INTERFACE cxx_std_11
  INCLUDE_DIRECTORIES INTERFACE "../include"
  LINK_LIBRARIES      INTERFACE CONAN_PKG::ms-gsl
  SOURCES             INTERFACE ${zWrapper})

aux_source_directory_ex("." zTest RECURSE)
add_executable_con(
  rrWindowsTest       ${zTest}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gtest
                              rrWindows)

add_test(NAME rrWindowsTest COMMAND rrWindowsTest)
