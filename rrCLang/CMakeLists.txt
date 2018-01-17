#             ____ _
#  _ __ _ __ / ___| |    __ _ _ __   __ _ _   _  __ _  __ _  ___
# | '__| '__| |   | |   / _` | '_ \ / _` | | | |/ _` |/ _` |/ _ \
# | |  | |  | |___| |__| (_| | | | | (_| | |_| | (_| | (_| |  __/
# |_|  |_|   \____|_____\__,_|_| |_|\__, |\__,_|\__,_|\__, |\___|
# zhengrr                           |___/             |___/
# 2016-8-1 – 2018-1-16                      rrCLanguage by FIGlet
# The MIT License

project("rrCLanguage" VERSION 2018.1.16 LANGUAGES C)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("config.h.in" "config.h" @ONLY)

quick_add_library_with_option(SUBNAME "Library" "${PROJECT_BINARY_DIR}/config.h" "api.h" "library.h" "library.c")

quick_add_executable_with_option(SUBNAME "Array" "type_array.c" "c_standard_version.h")
quick_add_executable_with_option(SUBNAME "Character" "type_character.c" "c_standard_version.h")
quick_add_executable_with_option(SUBNAME "IO" "input_output_support.c")
quick_add_executable_with_option(SUBNAME "Main" "lang_main.c")
quick_add_executable_with_option(SUBNAME "Memery" "dynamic_memory_management.c")
quick_add_executable_with_option(SUBNAME "String" "strings_library.c" "c_standard_version.h")
quick_add_executable_with_option(SUBNAME "Structure" "type_structure.c" "c_standard_version.h")
quick_add_executable_with_option(SUBNAME "Time" "date_and_time_utilities.c" "c_standard_version.h")
