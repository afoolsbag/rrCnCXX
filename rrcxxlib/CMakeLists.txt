#===========================================================================
# rrCPlusPlus-library
# zhengrr
# 2017-1-12 – 2017-7-24
# The MIT License
#---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)
project("${PRODUCT_NAME}-library" VERSION 0.0.0.1 LANGUAGES CXX)
make_project_extra_variables()

adjust_compiler_warning_level_to_highest()

add_subdirectory("src")
add_subdirectory("test")
add_subdirectory("doxygen")
