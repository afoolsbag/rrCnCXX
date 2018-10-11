#             ____
#  _ __ _ __ / ___|
# | '__| '__| |
# | |  | |  | |___
# |_|  |_|   \____| rrC by FIGlet
# zhengrr
# 2016-08-01 – 2018-10-11
# The Unlicense

project(rrC VERSION 2018.10.11 LANGUAGES C)
project_extra()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

configure_file("src/cfg.h.in" "src/cfg.h" @ONLY)
aux_source_directory_ex(zInclude
                        RECURSE
       SOURCE_DIRECTORY "include/"
           SOURCE_GROUP "include/")
aux_source_directory_ex(zSrc
                        RECURSE
       SOURCE_DIRECTORY "src/"
           SOURCE_GROUP "src/")
aux_source_directory_ex(zGenerate
                        RECURSE
       SOURCE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/src/"
           SOURCE_GROUP "generate/")
add_library_ex(        OPTION_INITIAL_ON
  TARGET_NAME_VARIABLE sRrcLib
                       SHARED
                       ${zInclude} ${zSrc} ${zGenerate}
   COMPILE_DEFINITIONS PUBLIC  "-DRRC_SHARED"
   INCLUDE_DIRECTORIES PUBLIC  "include/"
                       PRIVATE "src/"
                               "${CMAKE_CURRENT_BINARY_DIR}/src/")

aux_source_directory_ex(zTest
                        RECURSE
       SOURCE_DIRECTORY "test/"
           SOURCE_GROUP "test/")
facile_add_check_executable(SUBNAME "test"
                                    OPTION_INITIAL_ON
                                    ${zTest} "ygen.dox"
                INCLUDE_DIRECTORIES PRIVATE "test/"
                     LINK_LIBRARIES ${sRrcLib}
                        POST_COPIES ${sRrcLib})
