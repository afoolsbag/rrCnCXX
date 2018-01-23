#             ____ _
#  _ __ _ __ / ___| |    __ _ _ __   __ _ _   _  __ _  __ _  ___
# | '__| '__| |   | |   / _` | '_ \ / _` | | | |/ _` |/ _` |/ _ \
# | |  | |  | |___| |__| (_| | | | | (_| | |_| | (_| | (_| |  __/
# |_|  |_|   \____|_____\__,_|_| |_|\__, |\__,_|\__,_|\__, |\___|
# zhengrr                           |___/             |___/
# 2016-8-1 – 2018-1-23                      rrCLanguage by FIGlet
# The MIT License

project("rrCLanguage" VERSION 2018.1.23 LANGUAGES C)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("cfg.h.in" "cfg.h" @ONLY)

quick_add_executable_with_option(SUBNAME "DateTime" "date_time_utils/date_time_utils.c" "c_std_ver.h")

quick_add_executable_with_option(SUBNAME "IO" "io_supt/file_io.c")

quick_add_executable_with_option(SUBNAME "Main" "lang/main.c")

quick_add_executable_with_option(SUBNAME "Memery" "dyn_mem_mgmt/c_mem_mgmt_lib.c")

quick_add_executable_with_option(SUBNAME "StringCopy" "strs_lib/str_cpy.c" "c_std_ver.h")
quick_add_executable_with_option(SUBNAME "StringCatenate" "strs_lib/str_cat.c" "c_std_ver.h")

quick_add_executable_with_option(SUBNAME "Array" "type_supt/array.c" "c_std_ver.h")
quick_add_executable_with_option(SUBNAME "Character" "type_supt/char.c" "c_std_ver.h")
quick_add_executable_with_option(SUBNAME "Structure" "type_supt/struct.c" "c_std_ver.h")

quick_add_library_with_option(SUBNAME "Library" "${PROJECT_BINARY_DIR}/cfg.h" "api.h" "lib.h" "lib.c")
