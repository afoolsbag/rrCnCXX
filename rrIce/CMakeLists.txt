#          _____
#         |_   _|
#  _ __ _ __| |  ___ ___
# | '__| '__| | / __/ _ \
# | |  | | _| || (_|  __/
# |_|  |_| \___/\___\___| rrIce by FIGlet doom
# zhengrr
# 2018-03-21 – 2018-10-16
# The MIT License

project(rrIce VERSION 2018.10.16 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

facile_add_doxygen()

find_package(
  Ice
  COMPONENTS Ice++11
             IceDiscovery++11
             IceLocatorDiscovery++11
             IceSSL++11)
if(NOT Ice_FOUND)
  set(Ice_HOME "${Ice_HOME}" CACHE PATH "The root directory of the ICE installation.")
endif()

aux_add_subdirectories(
  WITH_OPTION
  OPTION_NAME_PREFIX "${PROJECT_NAME_UPPER}_")
