#             ______  ___  __
#  _ __ _ __ / ___\ \/ \ \/ /
# | '__| '__| |    \  / \  /
# | |  | |  | |___ /  \ /  \
# |_|  |_|   \____/_/\_/_/\_\ rrCxx by FIGlet
# zhengrr
# 2016-08-01 – 2018-07-03
# The MIT License

project(rrCXX VERSION 2018.7.3 LANGUAGES CXX)
project_extra()
compiler_warning_level(HIGHEST AS_ERROR)

facile_add_doxygen()

facile_add_library(    OPTION_INITIAL_ON
  TARGET_NAME_VARIABLE sRrcxxLib
                       STATIC)

aux_source_directory_enhanced(zSrc RECURSE SOURCE_PREFIXS "gt")
facile_add_gtest_executable(SUBNAME "Test"
                                    OPTION_INITIAL_ON
                                    "cxxver.hxx" "cxxdef.hxx" ${zSrc}
                INCLUDE_DIRECTORIES PRIVATE "."
                     LINK_LIBRARIES "${sRrcxxLib}")

aux_add_subdirectories()
