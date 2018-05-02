facile_add_library(SUBNAME "RPC"
                    STATIC "rrwindows/genuuid.h" "rrwindows/genuuid.c"
                PROPERTIES  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}")
