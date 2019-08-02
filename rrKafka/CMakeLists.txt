#            _   __       __ _
#           | | / /      / _| |
#  _ __ _ __| |/ /  __ _| |_| | ____ _
# | '__| '__|    \ / _` |  _| |/ / _` | zhengrr
# | |  | |  | |\  \ (_| | | |   < (_| | 2019-07-29 – 2019-07-29
# |_|  |_|  \_| \_/\__,_|_| |_|\_\__,_| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

string(TIMESTAMP sYear       "%Y")
string(TIMESTAMP sMonth      "%m")
string(TIMESTAMP sDay        "%d")
string(TIMESTAMP sHourMinute "%H%M")

project_ex(
  rrKafka
  VERSION   ${sYear}.${sMonth}.${sDay}.${sHourMinute}
  LANGUAGES CXX)

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

find_package(RdKafka)
aux_source_directory_con("wrapper" zWrapper RECURSE PREFIX "wrapper")
add_library_ex(
  rrKafkaWraper       INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_17
  INCLUDE_DIRECTORIES INTERFACE "wrapper"
                                "linux/usr/include"
                                "linux/usr/include/x86_64-linux-gnu"
  LINK_LIBRARIES      INTERFACE RdKafka::rdkafka++
  SOURCES             INTERFACE ${zWrapper})

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
aux_source_directory_ex("test" zTest RECURSE PREFIX "test")
add_executable_con(
  rrKafkaTest         ${zTest}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "test"
  LINK_LIBRARIES      PRIVATE rrKafkaWraper
                              GTest::main)

add_test(NAME rrKafkaTest COMMAND rrKafkaTest)
