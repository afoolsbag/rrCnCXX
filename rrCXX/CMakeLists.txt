#            _____ __   ____   __
#           /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/ \ V /  \ V /
# | '__| '__| |     /   \  /   \
# | |  | |  | \__/\/ /^\ \/ /^\ \
# |_|  |_|   \____/\/   \/\/   \/ rrCxx by FIGlet doom
# zhengrr
# 2016-08-01 – 2018-08-23
# The MIT License

project(rrCXX VERSION 2018.8.23 LANGUAGES CXX)
project_extra()
compiler_warning_level(UTF-8)

facile_add_doxygen()

configure_file("src/cfg.hxx.in" "src/cfg.hxx" @ONLY)
aux_source_directory_enhanced(zInclude
                              RECURSE
             SOURCE_DIRECTORY "include/"
                 SOURCE_GROUP "include/")
aux_source_directory_enhanced(zSrc
                              RECURSE
             SOURCE_DIRECTORY "src/"
                 SOURCE_GROUP "src/")
aux_source_directory_enhanced(zGenerate
                              RECURSE
             SOURCE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/src/"
                 SOURCE_GROUP "generate/")
facile_add_library(    OPTION_INITIAL_ON
  TARGET_NAME_VARIABLE sRrcxxLib
                       SHARED
                       ${zInclude} ${zSrc} ${zGenerate}
   COMPILE_DEFINITIONS PUBLIC  "-DRRCXX_SHARED"
   INCLUDE_DIRECTORIES PUBLIC  "include/"
                       PRIVATE "src/"
                               "${CMAKE_CURRENT_BINARY_DIR}/src/")

aux_source_directory_enhanced(zTest
                              RECURSE
             SOURCE_DIRECTORY "test/"
                 SOURCE_GROUP "test/")
facile_add_gtest_executable(SUBNAME "test"
                                    OPTION_INITIAL_ON
                                    ${zTest} "ygen.dox"
                INCLUDE_DIRECTORIES PRIVATE "test/"
                     LINK_LIBRARIES ${sRrcxxLib}
                        POST_COPIES ${sRrcxxLib})
