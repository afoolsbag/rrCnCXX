#===========================================================================
# rrCPlusPlus-DirectX
# zhengrr
# 2016-10-13 – 2017-7-26
# The MIT License
#---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)
project("${PRODUCT_NAME}-DirectX" LANGUAGES CXX)
make_project_extra_variables()

adjust_compiler_warning_level_to_highest()

add_subdirectory("src")
