facile_add_library(SUBNAME "CheckProcessRunning"
                    STATIC "rrwindows/ckprocrun.h" "rrwindows/ckprocrun.c"
                PROPERTIES  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}")
