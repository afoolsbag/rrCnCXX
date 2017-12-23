#             ____ _     _ _
#  _ __ _ __ / ___| |   (_| |__  _ __ __ _ _ __ _   _
# | '__| '__| |   | |   | | '_ \| '__/ _` | '__| | | |
# | |  | |  | |___| |___| | |_) | | | (_| | |  | |_| |
# |_|  |_|   \____|_____|_|_.__/|_|  \__,_|_|   \__, |
#                                               |___/
#                                 rrCLibrary by FIGlet

# zhengrr
# 2016-8-1 – 2017-12-21
# The MIT License

cmake_minimum_required(VERSION 3.0)
project("rrCLibrary" VERSION 0.0.0.0 LANGUAGES C)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

add_all_subdirectories()
