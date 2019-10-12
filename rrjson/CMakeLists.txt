#            _                 
#           (_)                
#  _ __ _ __ _ ___  ___  _ __  
# | '__| '__| / __|/ _ \| '_ \ 
# | |  | |  | \__ \ (_) | | | |
# |_|  |_|  | |___/\___/|_| |_| zhengrr
#          _/ |                 2019-09-23 – 2019-09-23
#         |__/                  Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrjson
  TIME_AS_VERSION
  LANGUAGES CXX)

include_conan_script()

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

conan_cmake_run(
  REQUIRES    gtest/1.8.1@bincrafters/stable
              jsonformoderncpp/3.7.0@vthiery/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("." zTest)
add_executable_con(
  rrjsonTest          ${zTest}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gtest
                              CONAN_PKG::jsonformoderncpp)

add_test(NAME rrjsonTest COMMAND rrjsonTest)