set(CMAKE_INCLUDE_CURRENT_DIR ON)
aux_source_directory_enhanced(zSrc RECURSE)
facile_add_executable(SUBNAME "HelloWorldServer"
                              ${zSrc}
                              "${CMAKE_CURRENT_LIST_DIR}/../HelloWorld.ice"
                              "${CMAKE_CURRENT_BINARY_DIR}/HelloWorld.h"
                              "${CMAKE_CURRENT_BINARY_DIR}/HelloWorld.cpp"
               LINK_LIBRARIES Ice::Ice
                              Ice::IceDiscovery
                              Ice::IceLocatorDiscovery
                              Ice::IceSSL)
