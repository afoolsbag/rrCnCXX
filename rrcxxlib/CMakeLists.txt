#             ______  ___  ___     _ _
#  _ __ _ __ / ___\ \/ \ \/ | |   (_| |__  _ __ __ _ _ __ _   _
# | '__| '__| |    \  / \  /| |   | | '_ \| '__/ _` | '__| | | |
# | |  | |  | |___ /  \ /  \| |___| | |_) | | | (_| | |  | |_| |
# |_|  |_|   \____/_/\_/_/\_|_____|_|_.__/|_|  \__,_|_|   \__, |
#                                                         |___/
#                                         rrCXXLibrary by FIGlet

# zhengrr
# 2017-1-12 – 2017-12-21
# The MIT License

cmake_minimum_required(VERSION 3.0)
project("rrCXXLibrary" VERSION 0.0.0.1 LANGUAGES CXX)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

add_all_subdirectories()
