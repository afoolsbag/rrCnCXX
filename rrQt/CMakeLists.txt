#===========================================================================
# rrCPlusPlus-Boost
# zhengrr
# 2016-6-28 – 2017-7-26
# The MIT License
#---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)
project("${PRODUCT_NAME}-Qt" LANGUAGES CXX)
make_project_extra_variables()

adjust_compiler_warning_level_to_highest()

find_package(Qt5Package)
if(Qt5Package_FOUND)
  add_subdirectory("src")
endif()
