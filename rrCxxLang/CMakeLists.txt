#             ____           _
#  _ __ _ __ / _____  ___  _| |    __ _ _ __   __ _ _   _  __ _  __ _  ___
# | '__| '__| |   \ \/ \ \/ | |   / _` | '_ \ / _` | | | |/ _` |/ _` |/ _ \
# | |  | |  | |___ >  < >  <| |__| (_| | | | | (_| | |_| | (_| | (_| |  __/
# |_|  |_|   \____/_/\_/_/\_|_____\__,_|_| |_|\__, |\__,_|\__,_|\__, |\___|
# zhengrr                                     |___/             |___/
# 2016-8-1 – 2018-1-8                               rrCxxLanguage by FIGlet
# The MIT License

project("rrCxxLanguage" VERSION 0.0.0.0 LANGUAGES CXX)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("config.hpp.in" "config.hpp" @ONLY)
add_definitions(-DRRCXXLANG_EXPORTS)

quick_add_library_with_option(SUBNAME "Library" "config.hpp.in" "${PROJECT_BINARY_DIR}/config.hpp" "api.hpp" "lib.hpp" "lib.cpp")

#enable_testing()
#quick_aux_source_directory(sourceFiles CXX)
#quick_add_googletest_with_option(sourceFiles)
