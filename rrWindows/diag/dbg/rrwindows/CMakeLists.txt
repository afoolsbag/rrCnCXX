set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_library(SUBNAME "ErrorHandling"
      TARGET_NAME_VARIABLE  sErrHdlLib
                    STATIC "errhdl.h" "errhdl.c"
                PROPERTIES  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/..")

facile_add_executable(SUBNAME "ErrorHandlingTest"
                              "errhdltest.c"
               LINK_LIBRARIES "${sErrHdlLib}")
