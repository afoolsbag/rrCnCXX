#             ____ _
#  _ __ _ __ / ___| |    __ _ _ __   __ _ _   _  __ _  __ _  ___
# | '__| '__| |   | |   / _` | '_ \ / _` | | | |/ _` |/ _` |/ _ \
# | |  | |  | |___| |__| (_| | | | | (_| | |_| | (_| | (_| |  __/
# |_|  |_|   \____|_____\__,_|_| |_|\__, |\__,_|\__,_|\__, |\___|
# zhengrr                           |___/             |___/
# 2016-8-1 – 2018-1-22                      rrCLanguage by FIGlet
# The MIT License

project("rrCLanguage" VERSION 2018.1.22 LANGUAGES C)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("cfg.h.in" "cfg.h" @ONLY)

quick_add_executable_with_option(SUBNAME "DateTime" "dt_utils/dt_utils.c" "c_std_ver.h")

quick_add_executable_with_option(SUBNAME "IO" "file_io/file_io.c")

quick_add_executable_with_option(SUBNAME "Main" "c_lang/main.c")

quick_add_executable_with_option(SUBNAME "Memery" "c_mem_mgmt_lib/c_mem_mgmt_lib.c")

quick_add_executable_with_option(SUBNAME "String" "str_lib/str_lib.c" "c_std_ver.h")

quick_add_executable_with_option(SUBNAME "Array" "type_spt/array.c" "c_std_ver.h")
quick_add_executable_with_option(SUBNAME "Character" "type_spt/char.c" "c_std_ver.h")
quick_add_executable_with_option(SUBNAME "Structure" "type_spt/struct.c" "c_std_ver.h")

quick_add_library_with_option(SUBNAME "Library" "${PROJECT_BINARY_DIR}/cfg.h" "api.h" "lib.h" "lib.c")
