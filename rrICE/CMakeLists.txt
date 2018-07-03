#           ___ ____ _____
#  _ __ _ _|_ _/ ___| ____|
# | '__| '__| | |   |  _|
# | |  | |  | | |___| |___
# |_|  |_| |___\____|_____| rrICE by FIGlet
# zhengrr
# 2018-03-21 – 2018-07-03
# The MIT License

project(rrICE VERSION 2018.7.3 LANGUAGES CXX)
project_extra()
compiler_warning_level(AS_ERROR UTF-8)

facile_add_doxygen()

find_package(Ice
  COMPONENTS Ice Ice++11
             IceDiscovery IceDiscovery++11
             IceLocatorDiscovery IceLocatorDiscovery++11
             IceSSL IceSSL++11)
if(NOT Ice_FOUND)
  set(Ice_HOME "${Ice_HOME}" CACHE PATH "The root directory of the ICE installation.")
endif()

execute_process(COMMAND "${Ice_SLICE2CPP_EXECUTABLE}" "HelloSlice.ice"
      WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/ice")
facile_add_executable(SUBNAME HelloServer
                              "hello_server.cxx" "ice/HelloSlice.cpp"
          INCLUDE_DIRECTORIES ${Ice_INCLUDE_DIRS}
               LINK_LIBRARIES ${Ice_LIBRARIES})
facile_add_executable(SUBNAME HelloClient
                              "hello_client.cxx" "ice/HelloSlice.cpp"
          INCLUDE_DIRECTORIES PRIVATE "${Ice_INCLUDE_DIR}"
               LINK_LIBRARIES ${Ice_LIBRARIES})
