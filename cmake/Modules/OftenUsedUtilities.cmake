# zhengrr
# 2017-12-13
# The MIT License

#.rst:
# OftenUsedUtilities
# ------------------
#
# 此模块提供了若干指令，用于简化常用操作。

# .rst
# .. command:: add_project_directory
#
#   add_project_directory(
#     [NAME "<project name>"]
#     [DIRECTORY "<sub directory>"]
#   )
#
#  注意::
#
#   此指令假定 NAME 参数仅由拉丁字母组成；
#   此指令假定 DIRECTORY 参数是合法的；
#   此指令假定"PRODUCT"相关变量已设置。
macro(add_project_directory)
  set(one_value_keywords "NAME" "DIRECTORY")
  cmake_parse_arguments("TEMP" "" "${one_value_keywords}" "" ${ARGN})
  if(PRODUCT_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments '${PRODUCT_UNPARSED_ARGUMENTS}'.")
  endif()

  string(TOUPPER "${TEMP_NAME}" TEMP_NAME_UPPER)

  option(${PRODUCT_NAME_UPPER}-${TEMP_NAME_UPPER} "Project ${PRODUCT_NAME}-${TEMP_NAME}." OFF)
  if(${PRODUCT_NAME_UPPER}-${TEMP_NAME_UPPER})
    add_subdirectory("${TEMP_DIRECTORY}")
  endif()
endmacro()
