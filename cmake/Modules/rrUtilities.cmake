# zhengrr
# 2016-10-8 – 2017-12-14
# The MIT License

#.rst:
# rrUtilities
# -----------
#
# zhengrr's CMake Utilities.
#
# 此模块提供了若干指令，用于简化操作。
#
# 须 CMake 3.3 及以上版本。

# --------------------------------------------------------------------------

# .rst
# .. command:: check_name_with_c_identifier_rules
#
#  此指令检查输入是否符合 C语言标识符规则::
#
#   check_name_with_c_identifier_rules("<name>" <result>)
function(check_name_with_c_identifier_rules)
  if(NOT ${ARGC} EQUAL 2)
    message(SEND_ERROR "Incorrect number of arguments (${ARGN}).")
    return()
  endif()
  if("${ARGV0}" MATCHES "^[A-Z_a-z]+[0-9A-Z_a-z]*$")
    set(${ARGV1} TRUE PARENT_SCOPE)
  else()
    set(${ARGV1} FALSE PARENT_SCOPE)
  endif()
endfunction()

# .rst
# .. command:: make_product_variables
#
#  此指令设置若干 PRODUCT 变量::
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
#   此指令假定 PROJECT_NAME 符合 C语言标识符规则。
macro(make_product_variables)
  set(once TRUE)
  while(once)
    set(once FALSE)

    check_name_with_c_identifier_rules("${PROJECT_NAME}" conformed)
    if(NOT conformed)
      message(SEND_ERROR "The current PROJECT_NAME(${PROJECT_NAME}) doesn't conform to the c identifier rules.")
      break()
    endif()

    set(opts)
    set(ovks "COPYRIGHT")
    set(mvks "AUTHORS")
    cmake_parse_arguments("PRODUCT" "${opts}" "${ovks}" "${mvks}" ${ARGN})
    if(PRODUCT_UNPARSED_ARGUMENTS)
      message(SEND_ERROR "Unexpected arguments(${PRODUCT_UNPARSED_ARGUMENTS}).")
      break()
    endif()

    set(PRODUCT_NAME "${PROJECT_NAME}")
    string(TOUPPER "${PROJECT_NAME}" PRODUCT_NAME_UPPER)
    string(TOLOWER "${PROJECT_NAME}" PRODUCT_NAME_LOWER)
    set(PRODUCT_SOURCE_DIR "${PROJECT_SOURCE_DIR}")
    set(PRODUCT_BINARY_DIR "${PROJECT_BINARY_DIR}")
    set(PRODUCT_VERSION "${PROJECT_VERSION}")
    set(PRODUCT_VERSION_MAJRO "${PROJECT_VERSION_MAJOR}")
    set(PRODUCT_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
    set(PRODUCT_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
    set(PRODUCT_VERSION_TWEAK "${PROJECT_VERSION_TWEAK}")
    # PRODUCT_AUTHORS 与 PRODUCT_COPYRIGHT 由 cmake_parse_arguments 设置。

  endwhile(once)
endmacro()

# .rst
# .. command:: make_project_extra_variables
#
#  此指令设置若干 PROJECT 额外变量::
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
#   PROJECT_AUTHORS
#   PROJECT_COPYRIGHT
#
#  注意::
#
#   此指令假定 PROJECT_NAME 符合 C语言标识符规则。
macro(make_project_extra_variables)
  set(once TRUE)
  while(once)
    set(once FALSE)

    check_name_with_c_identifier_rules("${PROJECT_NAME}" conformed)
    if(NOT conformed)
      message(SEND_ERROR "The current PROJECT_NAME(${PROJECT_NAME}) doesn't conform to the c identifier rules.")
      break()
    endif()

    set(opts)
    set(ovks "COPYRIGHT")
    set(mvks "AUTHORS")
    cmake_parse_arguments("PROJECT" "${opts}" "${ovks}" "${mvks}" ${ARGN})
    if(PROJECT_UNPARSED_ARGUMENTS)
      message(SEND_ERROR "Unexpected arguments:(${PROJECT_UNPARSED_ARGUMENTS}).")
      break()
    endif()

    string(TOUPPER "${PROJECT_NAME}" PROJECT_NAME_UPPER)
    string(TOLOWER "${PROJECT_NAME}" PROJECT_NAME_LOWER)

    # PROJECT_AUTHORS 与 PROJECT_COPYRIGHT 由 cmake_parse_arguments 设置。

    if(NOT DEFINED PROJECT_AUTHORS)
      set(PROJECT_AUTHORS ${PRODUCT_AUTHORS})
    endif()

    if(NOT DEFINED PROJECT_COPYRIGHT)
      set(PROJECT_COPYRIGHT "${PRODUCT_COPYRIGHT}")
    endif()

  endwhile(once)
endmacro()

# --------------------------------------------------------------------------

# .rst
# .. command:: add_subdirectories_all
#
#  ``add_subdirectory``的变体，将目录下的所有子目录添加到构建::
#
#   add_subdirectories_all(
#     [<parent directory of source directories>]
#     [<parent directory of binary directories>]
#     [EXCLUDE_FROM_ALL]
#   )
#
#  参数::
#
#   <parent directory of source directories> 默认为当前目录；
#   其余参数参见 add_subdirectory 指令。
macro(add_subdirectories_all)
  # TODO:
  # 判断传入参数：
  #  0 个：采用默认值；
  #  1 个：判断 ARGV0 为 <parent ... source ...> 或 EXCLUDE_FROM_ALL；
  #  2 个：判断 ARGV1 为 <parent ... binary ...> 或 EXCLUDE_FROM_ALL；
  #  3 个：略；
  # 以及健壮性处理。
endmacro()

# .rst
# .. command:: add_subdirectory_with_option
#
#  ``add_subdirectory``的变体，提供选项选择是否将子目录添加到构建::
#
#   add_subdirectory_with_option(
#     <source directory>
#     [<binary directory>]
#     [EXCLUDE_FROM_ALL]
#     [INITIAL_OPTION <OFF|ON>]
#   )
#  参数::
#
#   <initial option> 默认为 "OFF"；
#   其余参数参见 add_subdirectory 指令。
macro(add_subdirectory_with_option)
  # TODO:
  # 判断传入参数：
  #  1 个：采用默认值；
  #  2 个：判断 ARGV1 为 <binary directory> 或 EXCLUDE_FROM_ALL；
  #  3 个：判断为 <binary directory> EXCLUDE_FROM_ALL 或 INITIAL_OPTION <OFF|ON>；
  #  5 个：略；
  # 以及健壮性处理。
endmacro()
