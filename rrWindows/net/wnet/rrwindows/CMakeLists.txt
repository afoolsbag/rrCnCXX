set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_library(SUBNAME "AccessSharedFolder"
      TARGET_NAME_VARIABLE  sAcsShrFlrLib
                    STATIC "acsshrflr.h" "acsshrflr.c"
                PROPERTIES  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/..")

facile_add_executable(SUBNAME "AccessSharedFolderTest"
                              "acsshrflrtest.c"
               LINK_LIBRARIES "${sAcsShrFlrLib}"
                               rrwindows_errorhandling_static_library)
