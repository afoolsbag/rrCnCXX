#          ______            _
#         |___  /           | |
#  _ __ _ __ / /  ___   ___ | | _____  ___ _ __   ___ _ __
# | '__| '__/ /  / _ \ / _ \| |/ / _ \/ _ \ '_ \ / _ \ '__|
# | |  | |./ /__| (_) | (_) |   <  __/  __/ |_) |  __/ |
# |_|  |_|\_____/\___/ \___/|_|\_\___|\___| .__/ \___|_|
# zhengrr                                 | |
# 2018-12-29 – 2019-07-18                 |_|
# Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

string(TIMESTAMP sYear       "%Y")
string(TIMESTAMP sMonth      "%m")
string(TIMESTAMP sDay        "%d")
string(TIMESTAMP sHourMinute "%H%M")

project_ex(
  rrZooKeeper
  VERSION   ${sYear}.${sMonth}.${sDay}.${sHourMinute}
  LANGUAGES CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

hunter_add_package(zookeeper)
find_package(zookeeper CONFIG REQUIRED)
aux_source_directory_ex("wrapper" zWrapper RECURSE PREFIX "wrapper")
add_library_ex(
  rrZookeeperWraper   INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_17
  INCLUDE_DIRECTORIES INTERFACE "wrapper"
  LINK_LIBRARIES      INTERFACE zookeeper::zookeeper_mt
  SOURCES             INTERFACE ${zWrapper})

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
aux_source_directory_ex("test" zTest RECURSE PREFIX "test")
add_executable_ex(
  rrZookeeperTest     ${zTest}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "test"
  LINK_LIBRARIES      PRIVATE rrZookeeperWraper
                              GTest::main)
