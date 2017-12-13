#===========================================================================
# rrCPlusPlus-MicrosoftFoundationClassLibrary
# zhengrr
# 2017-12-8
# The MIT License
#---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)
project("${PRODUCT_NAME}-MicrosoftFoundationClassLibrary" LANGUAGES CXX)
make_project_extra_variables()

adjust_compiler_warning_level_to_highest()

add_subdirectory("src")
