#===========================================================================
# rrCPlusPlus-LIVE555
# zhengrr
# 2016-10-18 – 2017-7-26
# The MIT License
#---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)
project("${PRODUCT_NAME}-LIVE555" LANGUAGES CXX)
make_project_extra_variables()

adjust_compiler_warning_level_to_highest()

find_package(LIVE555)
if(LIVE555_FOUND)
  add_subdirectory("src")
endif()
