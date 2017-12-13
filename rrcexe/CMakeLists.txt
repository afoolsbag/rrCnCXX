#===========================================================================
# rrC-executable
# zhengrr
# 2016-8-1 – 2017-7-24
# The MIT License
#---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)
project("${PRODUCT_NAME}-executable" VERSION 0.0.0.0 LANGUAGES C)
make_project_extra_variables()

adjust_compiler_warning_level_to_highest()

add_subdirectory("src")
add_subdirectory("test")
add_subdirectory("doxygen")
