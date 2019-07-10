#          ______            _
#         |___  /           | |
#  _ __ _ __ / /  ___   ___ | | _____  ___ _ __   ___ _ __
# | '__| '__/ /  / _ \ / _ \| |/ / _ \/ _ \ '_ \ / _ \ '__|
# | |  | |./ /__| (_) | (_) |   <  __/  __/ |_) |  __/ |
# |_|  |_|\_____/\___/ \___/|_|\_\___|\___| .__/ \___|_|
# zhengrr                                 | |
# 2018-12-29 – 2019-05-28                 |_|
# Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrZooKeeper
  VERSION   2019.05.28
  LANGUAGES CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen_con(
  rrZookeeperDoc)

find_package(ZookeeperCClient)
conan_cmake_run(
  REQUIRES    gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)

aux_source_directory_ex("wrapper" zWrapper RECURSE PREFIX "wrapper")
add_library_ex(
  rrZookeeperWraper   INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_17
  INCLUDE_DIRECTORIES INTERFACE "wrapper"
  LINK_LIBRARIES      INTERFACE ZookeeperCClient::zookeeper
  SOURCES             INTERFACE ${zWrapper})

aux_source_directory_ex("test" zTest RECURSE PREFIX "test")
add_executable_ex(
  rrZookeeperTest     ${zTest}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "test"
  LINK_LIBRARIES      PRIVATE rrZookeeperWraper
                              CONAN_PKG::gtest
                              ZookeeperCClient::zookeeper)
