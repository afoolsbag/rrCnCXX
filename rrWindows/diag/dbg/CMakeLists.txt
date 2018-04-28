facile_add_library(SUBNAME "ErrorHandling"
                    STATIC "rrwindows/errhdl.h" "rrwindows/errhdl.c"
                PROPERTIES  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}")
