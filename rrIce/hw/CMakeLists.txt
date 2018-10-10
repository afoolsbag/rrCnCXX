execute_process(COMMAND "${Ice_SLICE2CPP_EXECUTABLE}"
                        "--output-dir=${CMAKE_CURRENT_BINARY_DIR}"
                        "service.ice"
      WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_executable(SUBNAME "hw_client"
                              OPTION_INITIAL_ON
                              "client.cpp"
                              "service.ice"
                              "${CMAKE_CURRENT_BINARY_DIR}/service.h"
                              "${CMAKE_CURRENT_BINARY_DIR}/service.cpp"
          COMPILE_DEFINITIONS PRIVATE "-DICE_CPP11_MAPPING"
               LINK_LIBRARIES Ice::Ice++11
                              Ice::IceDiscovery++11
                              Ice::IceLocatorDiscovery++11
                              Ice::IceSSL++11)

facile_add_executable(SUBNAME "hw_server"
                              OPTION_INITIAL_ON
                              "server.cpp"
                              "service.ice"
                              "${CMAKE_CURRENT_BINARY_DIR}/service.h"
                              "${CMAKE_CURRENT_BINARY_DIR}/service.cpp"
          COMPILE_DEFINITIONS PRIVATE "-DICE_CPP11_MAPPING"
               LINK_LIBRARIES Ice::Ice++11
                              Ice::IceDiscovery++11
                              Ice::IceLocatorDiscovery++11
                              Ice::IceSSL++11)
