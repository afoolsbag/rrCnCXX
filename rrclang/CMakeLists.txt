# zhengrr
# 2016-10-12 – 2017-12-13
# The MIT License

cmake_minimum_required(VERSION 3.0)

project("rrCLanguage" LANGUAGES C)
make_project_extra_variables()

adjust_compiler_warning_level_to_highest()

add_subdirectory("src")
