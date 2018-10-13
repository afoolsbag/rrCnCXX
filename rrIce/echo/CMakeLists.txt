execute_process(
  COMMAND           "${Ice_SLICE2CPP_EXECUTABLE}"
                    "--output-dir=${CMAKE_CURRENT_BINARY_DIR}"
                    "service.ice"
  WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable_ex(
  NAME_PREFIX                 "echo_"
  NAME                        "client"
  "client.cpp"
  "service.ice"
  "${CMAKE_CURRENT_BINARY_DIR}/service.h"
  "${CMAKE_CURRENT_BINARY_DIR}/service.cpp"
  FLAT_GROUP
  COMPILE_DEFINITIONS PRIVATE "-DICE_CPP11_MAPPING"
  LINK_LIBRARIES      PRIVATE Ice::Ice++11
                              Ice::IceDiscovery++11
                              Ice::IceLocatorDiscovery++11
                              Ice::IceSSL++11)

add_executable_ex(
  NAME_PREFIX                 "echo_"
  NAME                        "server"
  "server.cpp"
  "service.ice"
  "${CMAKE_CURRENT_BINARY_DIR}/service.h"
  "${CMAKE_CURRENT_BINARY_DIR}/service.cpp"
  FLAT_GROUP
  COMPILE_DEFINITIONS PRIVATE "-DICE_CPP11_MAPPING"
  LINK_LIBRARIES      PRIVATE Ice::Ice++11
                              Ice::IceDiscovery++11
                              Ice::IceLocatorDiscovery++11
                              Ice::IceSSL++11)
