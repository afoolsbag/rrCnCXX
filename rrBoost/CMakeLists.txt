#            ____                  _
#  _ __ _ __| __ )  ___   ___  ___| |_
# | '__| '__|  _ \ / _ \ / _ \/ __| __|
# | |  | |  | |_) | (_) | (_) \__ | |_
# |_|  |_|  |____/ \___/ \___/|___/\__|
# zhengrr             rrBoost by FIGlet
# 2016-10-27 – 2018-1-24
# The MIT License

find_package(Boost 1.66 COMPONENTS program_options REQUIRED)

project("rrBoost" VERSION 2018.1.24 LANGUAGES CXX)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory("src")
