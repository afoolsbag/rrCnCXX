#             ______  ___  __
#  _ __ _ __ / ___\ \/ \ \/ /
# | '__| '__| |    \  / \  /
# | |  | |  | |___ /  \ /  \
# |_|  |_|   \____/_/\_/_/\_\ rrCxx by FIGlet
# zhengrr
# 2016-08-01 – 2018-05-05
# The MIT License

project(rrCXX VERSION 2018.5.5 LANGUAGES CXX)
project_extra()
compiler_warning_level(HIGHEST AS_ERROR)

facile_add_doxygen()

configure_file("rrcxx/cfg.hxx.in" "rrcxx/cfg.hxx" @ONLY)
aux_source_directory_enhanced(zSrc RECURSE SOURCE_DIRECTORY "rrcxx")
facile_add_library(OPTION_INITIAL_ON
                TARGET_NAME_VARIABLE sRrcxxLib
                              STATIC ${zSrc}
                 INCLUDE_DIRECTORIES PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/rrcxx"
                                             "${CMAKE_CURRENT_BINARY_DIR}/rrcxx")

aux_source_directory_enhanced(zSrc RECURSE SOURCE_PREFIXS "gt")
facile_add_gtest_executable(SUBNAME "Test"
                  OPTION_INITIAL_ON
                                    "cxxver.hxx" "cxxdef.hxx" ${zSrc}
                INCLUDE_DIRECTORIES  PRIVATE "."
                     LINK_LIBRARIES "${sRrcxxLib}")
