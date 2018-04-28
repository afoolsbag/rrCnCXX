facile_add_library(SUBNAME "StringTranscode"
                    STATIC "rrwindows/strxc.h" "rrwindows/strxc.c"
                PROPERTIES  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}")
