#           ___ ____ _____
#  _ __ _ _|_ _/ ___| ____|
# | '__| '__| | |   |  _|
# | |  | |  | | |___| |___
# |_|  |_| |___\____|_____| rrICE by FIGlet
# zhengrr
# 2018-03-21 – 2018-07-16
# The MIT License

project(rrICE VERSION 2018.7.16 LANGUAGES CXX)
project_extra()
compiler_warning_level(AS_ERROR UTF-8)

facile_add_doxygen()

find_package(Ice
  COMPONENTS Ice                 Ice++11
             IceDiscovery        IceDiscovery++11
             IceLocatorDiscovery IceLocatorDiscovery++11
             IceSSL              IceSSL++11)
if(NOT Ice_FOUND)
  set(Ice_HOME "${Ice_HOME}" CACHE PATH "The root directory of the ICE installation.")
endif()

aux_add_subdirectories()
