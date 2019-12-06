#           ______ _____ _____ _______   __
#           | ___ \  _  /  ___|_   _\ \ / /
#  _ __ _ __| |_/ / | | \ `--.  | |  \ V /
# | '__| '__|  __/| | | |`--. \ | |  /   \  zhengrr
# | |  | |  | |   \ \_/ /\__/ /_| |_/ /^\ \ 2019-02-15 – 2019-12-05
# |_|  |_|  \_|    \___/\____/ \___/\/   \/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

if(NOT UNIX)
  message(WARNING "The project is just supposed to work with Unix-like.")
endif()

project_ex(
  rrPOSIX
  TIME_AS_VERSION
  LANGUAGES C CXX)

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

include_conan_script()
conan_cmake_run(
  REQUIRES    gtest/1.10.0
              ms-gsl/2.0.0
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

add_doxygen_con(
  rrPOSIXdoc)

aux_source_directory_con("../include/rrposix" zWrapper RECURSE PREFIX "include/rrposix")
add_library_ex(
  rrPOSIX             INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_17
  INCLUDE_DIRECTORIES INTERFACE "../include"
                                "../include/linux/usr/linux"
                                "../include/linux/usr/linux/x86_64-linux-gnu"
  LINK_LIBRARIES      INTERFACE CONAN_PKG::ms-gsl
  SOURCES             INTERFACE ${zWrapper})

aux_source_directory_ex("." zTest RECURSE)
add_executable_con(
  rrPosixTest         ${zTest}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gtest
                              rrPOSIX)

add_test(NAME rrPosixTest COMMAND rrPosixTest)
