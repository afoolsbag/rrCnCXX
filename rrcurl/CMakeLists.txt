#                           _
#                          | |
#  _ __ _ __ ___ _   _ _ __| |
# | '__| '__/ __| | | | '__| | zhengrr
# | |  | | | (__| |_| | |  | | 2019-03-20 – 2019-07-22
# |_|  |_|  \___|\__,_|_|  |_| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

string(TIMESTAMP sYear       "%Y")
string(TIMESTAMP sMonth      "%m")
string(TIMESTAMP sDay        "%d")
string(TIMESTAMP sHourMinute "%H%M")

project_ex(
  rrcurl
  VERSION   ${sYear}.${sMonth}.${sDay}.${sHourMinute}
  LANGUAGES CXX)

include_conan_script()

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

add_doxygen_con(
  rrcurlDoc)

conan_cmake_run(
  REQUIRES    gtest/1.8.1@bincrafters/stable
              libcurl/7.64.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("." zSrc RECURSE)
add_executable_con(
  rrcurlTest          ${zSrc}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      PRIVATE               CONAN_PKG::gtest
                                            CONAN_PKG::libcurl)

add_test(NAME rrcurlTest COMMAND rrcurlTest)
