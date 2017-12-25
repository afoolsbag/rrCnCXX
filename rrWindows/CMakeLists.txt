#===========================================================================
# rrC-Windows
# zhengrr
# 2016-10-12 – 2017-7-27
# The MIT License
#---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)
project("${PRODUCT_NAME}-Windows" LANGUAGES C)
make_project_extra_variables()

adjust_compiler_warning_level_to_highest()

add_subdirectory("src")
