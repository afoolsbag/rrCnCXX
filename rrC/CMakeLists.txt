#             ____
#  _ __ _ __ / ___|
# | '__| '__| |
# | |  | |  | |___
# |_|  |_|   \____| rrC by FIGlet
# zhengrr
# 2016-08-01 – 2018-04-21
# The MIT License

project("rrC" VERSION 2018.4.21 LANGUAGES C)
project_extra()
highest_warning_level(AS_ERROR)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("config.h.in" "config.h" @ONLY)

aux_source_directory_enhanced(zSrc RECURSE)
facile_add_check_executable(SUBNAME "Test" ${zSrc})
