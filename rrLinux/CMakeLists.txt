#===========================================================================
# rrC-Linux
# zhengrr
# 2016-10-8 – 2017-7-24
# The MIT License
#---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)
project("${PRODUCT_NAME}-Linux" LANGUAGES C)
make_project_extra_variables()

adjust_compiler_warning_level_to_highest()

add_subdirectory("src")
