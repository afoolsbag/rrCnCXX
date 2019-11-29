#                          _ _
#                         | | |
#  _ __ _ __ ___ _ __   __| | | ___   __ _
# | '__| '__/ __| '_ \ / _` | |/ _ \ / _` |
# | |  | |  \__ \ |_) | (_| | | (_) | (_| |
# |_|  |_|  |___/ .__/ \__,_|_|\___/ \__, | zhengrr
#               | |                   __/ | 2018-08-04 – 2019-11-20
#               |_|                  |___/  Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrspdlog
  TIME_AS_VERSION
  LANGUAGES CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

include_conan_script()
conan_cmake_run(
  REQUIRES    boost/1.71.0@conan/stable
              gtest/1.10.0
              spdlog/1.4.2
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("../include/rrspdlog" zWrapper RECURSE PREFIX "include/rrspdlog")
add_library_ex(
  rrspdlog            INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_17
  INCLUDE_DIRECTORIES INTERFACE "../include"
  LINK_LIBRARIES      INTERFACE CONAN_PKG::spdlog
  SOURCES             INTERFACE ${zWrapper})

aux_source_directory_con("." zTest RECURSE)
add_executable_con(
  rrspdlogTest        ${zTest}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE rrspdlog
                              CONAN_PKG::gtest
                              CONAN_PKG::boost)

add_test(NAME rrspdlogTest COMMAND rrspdlogTest)
