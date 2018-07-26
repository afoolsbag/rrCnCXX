#             ______  ___  __
#  _ __ _ __ / ___\ \/ \ \/ /
# | '__| '__| |    \  / \  /
# | |  | |  | |___ /  \ /  \
# |_|  |_|   \____/_/\_/_/\_\ rrCxx by FIGlet
# zhengrr
# 2016-08-01 – 2018-07-25
# The MIT License

project(rrCXX VERSION 2018.7.25 LANGUAGES CXX)
project_extra()
compiler_warning_level(UTF-8)

facile_add_doxygen()

facile_add_library(    OPTION_INITIAL_ON
  TARGET_NAME_VARIABLE sRrcxxLib
                       SHARED
   COMPILE_DEFINITIONS PUBLIC "-DRRCXX_SHARED")

aux_source_directory_enhanced(zSrc RECURSE SOURCE_PREFIXS "gt")
facile_add_gtest_executable(SUBNAME "Test"
                                    OPTION_INITIAL_ON
                                    ${zSrc}
                INCLUDE_DIRECTORIES PRIVATE "."
                     LINK_LIBRARIES "${sRrcxxLib}"
                        POST_COPIES "${sRrcxxLib}")

aux_add_subdirectories()
