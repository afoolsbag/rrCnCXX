set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_library(SUBNAME "DynamicLink"
      TARGET_NAME_VARIABLE  sDlLib
                    SHARED "lib.h" "lib.c")

facile_add_executable(SUBNAME "DynamicLink"
                              "lib.h" "exe.c"
               LINK_LIBRARIES  ${sDlLib})
