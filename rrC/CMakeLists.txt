#             ____
#  _ __ _ __ / ___|
# | '__| '__| |
# | |  | |  | |___
# |_|  |_|   \____| rrC by FIGlet
# zhengrr
# 2016-08-01 – 2018-05-02
# The MIT License

project("rrC" VERSION 2018.5.2 LANGUAGES C)
project_extra()
compiler_warning_level(HIGHEST AS_ERROR)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("config.h.in" "config.h" @ONLY)

aux_source_directory_enhanced(zSrc RECURSE SOURCE_PREFIXS "tmain" "tsuite" "tcase")
facile_add_check_executable(SUBNAME "Test" ${zSrc})
