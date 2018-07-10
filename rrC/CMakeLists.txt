#             ____
#  _ __ _ __ / ___|
# | '__| '__| |
# | |  | |  | |___
# |_|  |_|   \____| rrC by FIGlet
# zhengrr
# 2016-08-01 – 2018-07-10
# The MIT License

project(rrC VERSION 2018.7.10 LANGUAGES C)
project_extra()
compiler_warning_level(AS_ERROR UTF-8)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

facile_add_library(    OPTION_INITIAL_ON
  TARGET_NAME_VARIABLE sRrcLib
                       SHARED
   COMPILE_DEFINITIONS PUBLIC "-DRRC_SHARED")

aux_source_directory_enhanced(zSrc RECURSE SOURCE_PREFIXS "tmain" "tsuite" "tcase")
facile_add_check_executable(SUBNAME "Test"
                                    OPTION_INITIAL_ON
                                    ${zSrc}
                INCLUDE_DIRECTORIES PRIVATE "."
                     LINK_LIBRARIES "${sRrcLib}"
                        POST_COPIES "${sRrcLib}")

aux_add_subdirectories()
