#===========================================================================
# rrC-OpenGL
# zhengrr
# 2016-10-12 – 2017-7-24
# The MIT License
#---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)
project("${PRODUCT_NAME}-OpenGL" LANGUAGES C)
make_project_extra_variables()

adjust_compiler_warning_level_to_highest()

find_package(OpenGL)
find_package(GLUT)
if(OPENGL_FOUND AND GLUT_FOUND)
  add_subdirectory("src")
endif()
