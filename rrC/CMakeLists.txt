#             ____
#  _ __ _ __ / ___|
# | '__| '__| |
# | |  | |  | |___
# |_|  |_|   \____| rrC by FIGlet
# zhengrr
# 2016-08-01 – 2018-08-07
# The MIT License

project(rrC VERSION 2018.8.7 LANGUAGES C)
project_extra()
compiler_warning_level(AS_ERROR UTF-8)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

configure_file("rrc/rrccfg.h.in" "rrc/rrccfg.h" @ONLY)
aux_source_directory_enhanced(zSrc
                              RECURSE
             SOURCE_DIRECTORY "rrc"
          SOURCE_BASE_CLASHES "^.*_test$|^test$")
facile_add_library(    OPTION_INITIAL_ON
  TARGET_NAME_VARIABLE sRrcLib
                       SHARED
                       ${zSrc}
   COMPILE_DEFINITIONS PUBLIC  "-DRRC_SHARED"
   INCLUDE_DIRECTORIES PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
                       PUBLIC  ".")

aux_source_directory_enhanced(zSrc
                              RECURSE
          SOURCE_BASE_MATCHES "^.*_test$|^test$|^ygen$")
facile_add_check_executable(OPTION_INITIAL_ON
                            ${zSrc}
        INCLUDE_DIRECTORIES PRIVATE "."
             LINK_LIBRARIES "${sRrcLib}"
                POST_COPIES "${sRrcLib}")
