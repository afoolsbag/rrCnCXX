# zhengrr
# 2016-10-8 – 2017-12-12
# The MIT License

#.rst:
# OftenUsedVariables
# ------------------
#
# 此模块提供了若干指令，用于简化常用变量的处理。
#
# 典型用法形如：
#
# .. code-block:: cmake
#
#  project("<product>" VERSION <version>)
#  make_product_variables(AUTHORS "<authors>"... COPYRIGHT "<copyright>")
#  # ...
#
#  project("<project>" VERSION <version>)
#  make_project_extra_variables(AUTHORS "<authors>"... COPYRIGHT "<copyright>")
#  # ...

# .rst
# .. command:: make_product_variables
#
#  此指令将为"PRODUCT"设置若干变量::
#
#   make_product_variables(
#     [AUTHORS <authors>...]
#     [COPYRIGHT <copyright>]
#   )
#
#  变量列表如下::
#
#   PRODUCT_NAME
#   PRODUCT_NAME_UPPER
#   PRODUCT_NAME_LOWER
#   PRODUCT_NAME_WITHOUT_HYPHEN
#   PRODUCT_NAME_WITHOUT_HYPHEN_UPPER
#   PRODUCT_NAME_WITHOUT_HYPHEN_LOWER
#   PRODUCT_SOURCE_DIR
#   PRODUCT_BINARY_DIR
#   PRODUCT_VERSION
#   PRODUCT_VERSION_MAJRO
#   PRODUCT_VERSION_MINOR
#   PRODUCT_VERSION_PATCH
#   PRODUCT_VERSION_TWEAK
#   PRODUCT_AUTHORS
#   PRODUCT_COPYRIGHT
#
#  注意::
#
#   此指令假定 PRODUCT_NAME 仅由拉丁字母、连字符与下划线组成；
#   此指令通过将连字符替换为双下划线的方式，去除连字符。
macro(make_product_variables)
  set(one_value_keywords "COPYRIGHT")
  set(multi_value_keywords "AUTHORS")
  cmake_parse_arguments("PRODUCT" "" "${one_value_keywords}" "${multi_value_keywords}" ${ARGN})
  if(PRODUCT_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments '${PRODUCT_UNPARSED_ARGUMENTS}'.")
  endif()

  set(PRODUCT_NAME "${PROJECT_NAME}")
  string(TOUPPER "${PROJECT_NAME}" PRODUCT_NAME_UPPER)
  string(TOLOWER "${PROJECT_NAME}" PRODUCT_NAME_LOWER)
  string(REPLACE "-" "__" PRODUCT_NAME_WITHOUT_HYPHEN "${PRODUCT_NAME}")
  string(TOUPPER "${PRODUCT_NAME_WITHOUT_HYPHEN}" PRODUCT_NAME_WITHOUT_HYPHEN_UPPER)
  string(TOLOWER "${PRODUCT_NAME_WITHOUT_HYPHEN}" PRODUCT_NAME_WITHOUT_HYPHEN_LOWER)
  set(PRODUCT_SOURCE_DIR "${PROJECT_SOURCE_DIR}")
  set(PRODUCT_BINARY_DIR "${PROJECT_BINARY_DIR}")
  set(PRODUCT_VERSION "${PROJECT_VERSION}")
  set(PRODUCT_VERSION_MAJRO "${PROJECT_VERSION_MAJOR}")
  set(PRODUCT_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
  set(PRODUCT_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
  set(PRODUCT_VERSION_TWEAK "${PROJECT_VERSION_TWEAK}")
endmacro()

# .rst
# .. command:: make_project_extra_variables
#
#  此指令将为"PROJECT"设置若干额外变量::
#
#   make_project_extra_variables(
#     [AUTHORS <authors>...]
#     [COPYRIGHT <copyright>]
#   )
#
#  额外变量列表如下::
#
#   PROJECT_NAME_UPPER
#   PROJECT_NAME_LOWER
#   PROJECT_NAME_WITHOUT_HYPHEN
#   PROJECT_NAME_WITHOUT_HYPHEN_UPPER
#   PROJECT_NAME_WITHOUT_HYPHEN_LOWER
#   PROJECT_AUTHORS
#   PROJECT_COPYRIGHT
#
#  注意::
#
#   此指令假定 PROJECT_NAME 仅由拉丁字母、连字符与下划线组成；
#   此指令通过将连字符替换为双下划线的方式，去除连字符。
macro(make_project_extra_variables)
  set(one_value_keywords "COPYRIGHT")
  set(multi_value_keywords "AUTHORS")
  cmake_parse_arguments("PROJECT" "" "${one_value_keywords}" "${multi_value_keywords}" ${ARGN})
  if(PROJECT_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments '${PROJECT_UNPARSED_ARGUMENTS}'.")
  endif()

  string(TOUPPER "${PROJECT_NAME}" PROJECT_NAME_UPPER)
  string(TOLOWER "${PROJECT_NAME}" PROJECT_NAME_LOWER)
  string(REPLACE "-" "__" PROJECT_NAME_WITHOUT_HYPHEN "${PROJECT_NAME}")
  string(TOUPPER "${PROJECT_NAME_WITHOUT_HYPHEN}" PROJECT_NAME_WITHOUT_HYPHEN_UPPER)
  string(TOLOWER "${PROJECT_NAME_WITHOUT_HYPHEN}" PROJECT_NAME_WITHOUT_HYPHEN_LOWER)

  if(NOT PROJECT_AUTHORS)
    set(PROJECT_AUTHORS ${PRODUCT_AUTHORS})
  endif()

  if(NOT PROJECT_COPYRIGHT)
    set(PROJECT_COPYRIGHT "${PRODUCT_COPYRIGHT}")
  endif()
endmacro()
