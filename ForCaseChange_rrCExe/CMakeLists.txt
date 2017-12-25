#             ____ _____                     _        _     _
#  _ __ _ __ / ___| ______  _____  ___ _   _| |_ __ _| |__ | | ___
# | '__| '__| |   |  _| \ \/ / _ \/ __| | | | __/ _` | '_ \| |/ _ \
# | |  | |  | |___| |___ >  |  __| (__| |_| | || (_| | |_) | |  __/
# |_|  |_|   \____|_____/_/\_\___|\___|\__,_|\__\__,_|_.__/|_|\___|
#                                           rrCExecutable by FIGlet

# zhengrr
# 2016-8-1 – 2017-12-21
# The MIT License

cmake_minimum_required(VERSION 3.0)
project("rrCExecutable" VERSION 0.0.0.0 LANGUAGES C)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

add_all_subdirectories()
