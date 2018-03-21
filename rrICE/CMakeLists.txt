#           ___ ____ _____
#  _ __ _ _|_ _/ ___| ____|
# | '__| '__| | |   |  _|
# | |  | |  | | |___| |___
# |_|  |_| |___\____|_____| rrICE by FIGlet
# zhengrr
# 2018-03-21 – 21
# The MIT License

if(NOT ICE_FOUND)
  find_package(Ice COMPONENTS Ice)
  if(NOT ICE_FOUND)
    set(Ice_HOME "${Ice_HOME}" CACHE PATH "The root directory of the ICE installation.")
  endif()
endif()

project("rrICE" VERSION 2018.3.21 LANGUAGES CXX)
project_variables()
highest_warning_level()

facile_add_doxygen()

facile_add_ice_executable(SUBNAME "server"
  "server.cxx")
facile_add_ice_executable(SUBNAME "client"
  "client.cxx")
