#            _____            _     
#           /  __ \          | |    
#  _ __ _ __| /  \/ ___ _ __ | |__  
# | '__| '__| |    / _ \ '_ \| '_ \ 
# | |  | |  | \__/\  __/ |_) | | | |
# |_|  |_|   \____/\___| .__/|_| |_| zhengrr
#                      | |           2019-07-29 – 2019-11-20
#                      |_|           Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrCeph
  TIME_AS_VERSION
  LANGUAGES CXX)

include_conan_script()

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

conan_cmake_run(
  REQUIRES    gtest/1.10.0
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

find_package(S3 REQUIRED)
aux_source_directory_ex("../include/rrceph" zWrapper RECURSE PREFIX "include/rrceph")
add_library_ex(
  rrCeph              INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_11
  INCLUDE_DIRECTORIES INTERFACE "../include"
  LINK_LIBRARIES      INTERFACE S3::s3
  SOURCES             INTERFACE ${zWrapper})

aux_source_directory_ex("." zTest RECURSE)
add_executable_con(
  rrCephTest          ${zTest}
  PROPERTIES          CXX_STANDARD          11
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      PRIVATE               rrCeph
                                            CONAN_PKG::gtest)

add_test(NAME rrCephTest COMMAND rrCephTest)
