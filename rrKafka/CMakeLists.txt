#            _   __       __ _
#           | | / /      / _| |
#  _ __ _ __| |/ /  __ _| |_| | ____ _
# | '__| '__|    \ / _` |  _| |/ / _` | zhengrr
# | |  | |  | |\  \ (_| | | |   < (_| | 2019-07-29 – 2019-11-20
# |_|  |_|  \_| \_/\__,_|_| |_|\_\__,_| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrKafka
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

find_package(RdKafka REQUIRED)
aux_source_directory_con("../include/rrkafka" zWrapper RECURSE PREFIX "/include/rrkafka")
add_library_ex(
  rrKafka             INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_17
  INCLUDE_DIRECTORIES INTERFACE "../include"
  LINK_LIBRARIES      INTERFACE RdKafka::rdkafka++
  SOURCES             INTERFACE ${zWrapper})

aux_source_directory_ex("." zTest RECURSE)
add_executable_con(
  rrKafkaTest         ${zTest}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      PRIVATE               rrKafka
                                            CONAN_PKG::gtest)

add_test(NAME rrKafkaTest COMMAND rrKafkaTest)
