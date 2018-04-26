set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_library(SUBNAME "StringTranscode"
      TARGET_NAME_VARIABLE  sStrxcLib
                    STATIC "strxc.h" "strxc.c"
                PROPERTIES  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/..")

facile_add_executable(SUBNAME "StringTranscodeTest"
                              "strxctest.c"
               LINK_LIBRARIES "${sStrxcLib}")
