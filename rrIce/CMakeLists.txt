#          _____
#         |_   _|
#  _ __ _ __| |  ___ ___
# | '__| '__| | / __/ _ \ zhengrr
# | |  | | _| || (_|  __/ 2018-03-21 – 2019-07-10
# |_|  |_| \___/\___\___| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrIce
  VERSION   2019.07.10
  LANGUAGES CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen_con(
  rrIceDoc)

find_package(
  Ice
  COMPONENTS Ice++11
             IceDiscovery++11
             IceLocatorDiscovery++11
             IceSSL++11)

aux_add_subdirectories(
  WITH_OPTION
  OPTION_NAME_PREFIX "${PROJECT_NAME_UPPER}_")
