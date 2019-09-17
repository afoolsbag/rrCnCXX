#                          _ _
#                         | | |
#  _ __ _ __ ___ _ __   __| | | ___   __ _
# | '__| '__/ __| '_ \ / _` | |/ _ \ / _` |
# | |  | |  \__ \ |_) | (_| | | (_) | (_| |
# |_|  |_|  |___/ .__/ \__,_|_|\___/ \__, | zhengrr
#               | |                   __/ | 2018-08-04 – 2019-09-17
#               |_|                  |___/  Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrspdlog
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
  REQUIRES    boost/1.71.0@conan/stable
              gtest/1.8.1@bincrafters/stable
              spdlog/1.3.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("wrapper" zWrapper RECURSE PREFIX "wrapper")
add_library_ex(
  rrspdlogWrapper     INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_17
  INCLUDE_DIRECTORIES INTERFACE "wrapper"
  LINK_LIBRARIES      INTERFACE CONAN_PKG::spdlog
  SOURCES             INTERFACE ${zWrapper})

aux_source_directory_con("test" zTest RECURSE PREFIX "test")
add_executable_con(
  rrspdlogTest        ${zTest}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "test"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gtest
                              CONAN_PKG::boost
                              rrspdlogWrapper)

add_test(NAME rrspdlogTest COMMAND rrspdlogTest)
