#             ____ _
#  _ __ _ __ / ___| |    __ _ _ __   __ _ _   _  __ _  __ _  ___
# | '__| '__| |   | |   / _` | '_ \ / _` | | | |/ _` |/ _` |/ _ \
# | |  | |  | |___| |__| (_| | | | | (_| | |_| | (_| | (_| |  __/
# |_|  |_|   \____|_____\__,_|_| |_|\__, |\__,_|\__,_|\__, |\___|
# zhengrr                           |___/             |___/
# 2016-10-12 – 2018-1-6                     rrCLanguage by FIGlet
# The MIT License

project("rrCLanguage" LANGUAGES C)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

quick_add_executable_with_option(SUBNAME "Main" "main.c")
quick_add_executable_with_option(SUBNAME "Type_Array" "type_array.c" "c_standard_version.h")
quick_add_executable_with_option(SUBNAME "Type_String" "type_string.c" "c_standard_version.h")
quick_add_executable_with_option(SUBNAME "Type_Struct" "type_struct.c" "c_standard_version.h")
