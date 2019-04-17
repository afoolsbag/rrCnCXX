# zhengrr
# 2017-12-18 – 2019-04-17
# Unlicense

cmake_minimum_required(VERSION 3.10)
cmake_policy(VERSION 3.10)

include_guard()

#.rst:
# .. command:: check_name_with_c_rules
#
#   检查输入是否符合 C 语言标识符命名规则：
#   仅包含拉丁字母、阿拉伯数字和下划线，且首字符不为数字。
#
#   .. code-block:: cmake
#
#     check_name_with_c_rules(
#       <name>
#       <STATUS|WARNING|AUTHOR_WARNING|SEND_ERROR|FATAL_ERROR|DEPRECATION>
#     )
function(check_name_with_c_rules _NAME _MODE)
  if(NOT ${ARGC} EQUAL 2)
    message(FATAL_ERROR "Incorrect number of arguments: ${ARGN}.")
  endif()

  if(NOT "${_NAME}" MATCHES "^[A-Z_a-z]+[0-9A-Z_a-z]*$")
    message(${_MODE} "The name isn't meet C identifier rules: ${_NAME}.")
  endif()
endfunction()

#.rst:
# .. command:: check_name_with_cmake_rules
#
#   检查输入是否符合 CMake 推荐变量命名规则：
#   仅包含拉丁字母、阿拉伯数字、下划线和连字符。
#
#   .. code-block:: cmake
#
#     check_name_with_cmake_rules(
#       <name>
#       <STATUS|WARNING|AUTHOR_WARNING|SEND_ERROR|FATAL_ERROR|DEPRECATION>
#     )
function(check_name_with_cmake_rules _NAME _MODE)
  if(NOT ${ARGC} EQUAL 2)
    message(FATAL_ERROR "Incorrect number of arguments: ${ARGN}.")
  endif()

  if(NOT "${_NAME}" MATCHES "^[-0-9A-Z_a-z]+$")
    message(${_MODE} "The name isn't meet CMake recommend variable rules: ${_NAME}.")
  endif()
endfunction()

#.rst:
# .. command:: check_name_with_fext_rules
#
#   检查输入是否符合文件扩展名命名规则：
#   首字符为下脚点，扩展名仅包含拉丁字母和阿拉伯数字，可以串接。
#
#   .. code-block:: cmake
#
#     check_name_with_fext_rules(
#       <name>
#       <STATUS|WARNING|AUTHOR_WARNING|SEND_ERROR|FATAL_ERROR|DEPRECATION>
#     )
function(check_name_with_fext_rules _NAME _MODE)
  if(NOT ${ARGC} EQUAL 2)
    message(FATAL_ERROR "Incorrect number of arguments: ${ARGN}.")
  endif()

  if(NOT "${_NAME}" MATCHES "^([.][0-9A-Za-z]+)+$")
    message(${_MODE} "The name isn't meet file extension rules: ${_NAME}.")
  endif()
endfunction()
