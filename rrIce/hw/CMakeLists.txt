execute_process(COMMAND "${Ice_SLICE2CPP_EXECUTABLE}"
                        "--output-dir=${CMAKE_CURRENT_BINARY_DIR}"
                        "service.ice"
      WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable_ex(SUBNAME "hw_client"
                          OPTION_INITIAL_ON
                          FLAT_GROUP
                          "client.cpp"
                          "service.ice"
                          "${CMAKE_CURRENT_BINARY_DIR}/service.h"
                          "${CMAKE_CURRENT_BINARY_DIR}/service.cpp"
      COMPILE_DEFINITIONS PRIVATE "-DICE_CPP11_MAPPING"
           LINK_LIBRARIES Ice::Ice++11
                          Ice::IceDiscovery++11
                          Ice::IceLocatorDiscovery++11
                          Ice::IceSSL++11)

add_executable_ex(SUBNAME "hw_server"
                          OPTION_INITIAL_ON
                          FLAT_GROUP
                          "server.cpp"
                          "service.ice"
                          "${CMAKE_CURRENT_BINARY_DIR}/service.h"
                          "${CMAKE_CURRENT_BINARY_DIR}/service.cpp"
      COMPILE_DEFINITIONS PRIVATE "-DICE_CPP11_MAPPING"
           LINK_LIBRARIES Ice::Ice++11
                          Ice::IceDiscovery++11
                          Ice::IceLocatorDiscovery++11
                          Ice::IceSSL++11)
