#            _____ __   ____   __
#           /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/ \ V /  \ V /
# | '__| '__| |     /   \  /   \
# | |  | |  | \__/\/ /^\ \/ /^\ \
# |_|  |_|   \____/\/   \/\/   \/ rrCxx by FIGlet doom
# zhengrr
# 2016-08-01 – 2018-08-07
# The MIT License

project(rrCXX VERSION 2018.8.7 LANGUAGES CXX)
project_extra()
compiler_warning_level(UTF-8)

facile_add_doxygen()

configure_file("rrcxx/rrcxxcfg.hxx.in" "rrcxx/rrcxxcfg.hxx" @ONLY)
aux_source_directory_enhanced(zSrc
                              RECURSE
             SOURCE_DIRECTORY "rrcxx"
          SOURCE_BASE_CLASHES "^.*_test$")
facile_add_library(    OPTION_INITIAL_ON
  TARGET_NAME_VARIABLE sRrcxxLib
                       SHARED
                       ${zSrc}
   COMPILE_DEFINITIONS PUBLIC  "-DRRCXX_SHARED"
   INCLUDE_DIRECTORIES PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
                       PUBLIC  ".")

aux_source_directory_enhanced(zSrc
                              RECURSE
          SOURCE_BASE_MATCHES "^.*_test$|^ygen$")
facile_add_gtest_executable(OPTION_INITIAL_ON
                            ${zSrc}
        INCLUDE_DIRECTORIES PRIVATE "."
             LINK_LIBRARIES "${sRrcxxLib}"
                POST_COPIES "${sRrcxxLib}")
