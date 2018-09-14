#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-09-14
# The MIT License

project(rrWindows VERSION 2018.9.14 LANGUAGES C)
project_extra()
compiler_warning_level(AS_ERROR UTF-8)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

add_definitions("-D_UNICODE")
remove_definitions("-D_MBCS")

configure_file("src/cfg.h.in" "src/cfg.h" @ONLY)
aux_source_directory_enhanced(zInclude
                              RECURSE
             SOURCE_DIRECTORY "include/"
                 SOURCE_GROUP "include/")
aux_source_directory_enhanced(zSrc
                              RECURSE
             SOURCE_DIRECTORY "src/"
            SOURCE_EXTENSIONS ".rc"
                 SOURCE_GROUP "src/")
aux_source_directory_enhanced(zGenerate
                              RECURSE
             SOURCE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/src/"
                 SOURCE_GROUP "generate/")
facile_add_library(    OPTION_INITIAL_ON
  TARGET_NAME_VARIABLE sRrwindowsLib
                SHARED ${zInclude} ${zSrc} ${zGenerate}
   COMPILE_DEFINITIONS PUBLIC  "-DRRWINDOWS_SHARED"
   INCLUDE_DIRECTORIES PUBLIC  "include/"
                       PRIVATE "src/"
                               "${CMAKE_CURRENT_BINARY_DIR}/src/")

configure_file("test/cfg.h.in" "test/cfg.h" @ONLY)
aux_source_directory_enhanced(zTest
                              RECURSE
             SOURCE_DIRECTORY "test/"
            SOURCE_EXTENSIONS ".rc"
                 SOURCE_GROUP "test/")
aux_source_directory_enhanced(zGenerate
                              RECURSE
             SOURCE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/test/"
                 SOURCE_GROUP "generate/")
facile_add_check_executable(SUBNAME "test"
                                    OPTION_INITIAL_ON
                                    ${zTest} ${zGenerate} "ygen.dox"
                INCLUDE_DIRECTORIES PRIVATE "test/"
                                            "${CMAKE_CURRENT_BINARY_DIR}/test/"
                     LINK_LIBRARIES ${sRrwindowsLib}
                        POST_COPIES ${sRrwindowsLib})
