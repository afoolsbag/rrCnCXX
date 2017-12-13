#===========================================================================
# rrCPlusPlus-Boost
# zhengrr
# 2016-10-27 – 2017-7-26
# The MIT License
#---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)
project("${PRODUCT_NAME}-Boost" LANGUAGES CXX)
make_project_extra_variables()

adjust_compiler_warning_level_to_highest()

add_subdirectory("src")
