#             ______  ___  __
#  _ __ _ __ / ___\ \/ \ \/ /
# | '__| '__| |    \  / \  /
# | |  | |  | |___ /  \ /  \
# |_|  |_|   \____/_/\_/_/\_\ rrCxx by FIGlet
# zhengrr
# 2016-08-01 – 2018-05-04
# The MIT License

project("rrCXX" VERSION 2018.5.4 LANGUAGES CXX)
project_extra()
compiler_warning_level(HIGHEST AS_ERROR)

facile_add_doxygen()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("config.hxx.in" "config.hxx" @ONLY)

aux_source_directory_enhanced(zSrc RECURSE)
facile_add_gtest_executable(SUBNAME "Test" OPTION_INITIAL_ON ${zSrc})
