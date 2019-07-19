#           ______                 _
#           | ___ \               | |
#  _ __ _ __| |_/ / ___   ___  ___| |_
# | '__| '__| ___ \/ _ \ / _ \/ __| __| zhengrr
# | |  | |  | |_/ / (_) | (_) \__ \ |_  2016-10-27 – 2019-07-18
# |_|  |_|  \____/ \___/ \___/|___/\__| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

string(TIMESTAMP sYear       "%Y")
string(TIMESTAMP sMonth      "%m")
string(TIMESTAMP sDay        "%d")
string(TIMESTAMP sHourMinute "%H%M")

project_ex(
  rrBoost
  VERSION   ${sYear}.${sMonth}.${sDay}.${sHourMinute}
  LANGUAGES CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen_con(
  rrBoostDoc)

hunter_add_package(Boost)
find_package(Boost CONFIG REQUIRED)
hunter_add_package(Microsoft.GSL)
find_package(Microsoft.GSL CONFIG REQUIRED)
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

conan_cmake_run(
  REQUIRES    boost/1.70.0@conan/stable
              gsl_microsoft/2.0.0@bincrafters/stable
              gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("." zSrc)
add_executable_con(
  rrBoostTest         ${zSrc}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE Microsoft.GSL
                              GTest::main
                              Boost::boost)
