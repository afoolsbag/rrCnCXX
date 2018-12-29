# zhengrr
# 2017-12-18 – 2018-12-29
# Unlicense

include_guard()

cmake_minimum_required(VERSION 3.1)
cmake_policy(SET CMP0054 NEW) #3.1+

# .rst
# .. command:: check_name_with_c_rules
#
#   检查输入是否符合 C 语言标识符命名规则（C identifier rules），
#   仅包含拉丁字母、阿拉伯数字和下划线，且首字符不为数字::
#
#     check_name_with_c_rules(<name> <STATUS|WARNING|AUTHOR_WARNING|SEND_ERROR|FATAL_ERROR|DEPRECATION>)
function(check_name_with_c_rules _NAME _MODE)
  if(NOT ${ARGC} EQUAL 2)
    message(FATAL_ERROR "Incorrect number of arguments: ${ARGN}.")
  endif()

  if(NOT "${_NAME}" MATCHES "^[A-Z_a-z]+[0-9A-Z_a-z]*$")
    message(${_MODE} "The name isn't meet C identifier rules: ${_NAME}.")
  endif()
endfunction()

# .rst
# .. command:: check_name_with_cmake_rules
#
#   检查输入是否符合 CMake 推荐变量命名规则（CMake recommend variable rules），
#   仅包含拉丁字母、阿拉伯数字、下划线和连字符::
#
#     check_name_with_cmake_rules(<name> <STATUS|WARNING|AUTHOR_WARNING|SEND_ERROR|FATAL_ERROR|DEPRECATION>)
function(check_name_with_cmake_rules _NAME _MODE)
  if(NOT ${ARGC} EQUAL 2)
    message(FATAL_ERROR "Incorrect number of arguments: ${ARGN}.")
  endif()

  if(NOT "${_NAME}" MATCHES "^[-0-9A-Z_a-z]+$")
    message(${_MODE} "The name isn't meet CMake recommend variable rules: ${_NAME}.")
  endif()
endfunction()

# .rst
# .. command:: check_name_with_fext_rules
#
#   检查输入是否符合文件扩展名命名规则（file extension rules），
#   首字符为下脚点，扩展名仅包含拉丁字母和阿拉伯数字，可以串接::
#
#     check_name_with_fext_rules(<name> <STATUS|WARNING|AUTHOR_WARNING|SEND_ERROR|FATAL_ERROR|DEPRECATION>)
function(check_name_with_fext_rules _NAME _MODE)
  if(NOT ${ARGC} EQUAL 2)
    message(FATAL_ERROR "Incorrect number of arguments: ${ARGN}.")
  endif()

  if(NOT "${_NAME}" MATCHES "^([.][0-9A-Za-z]+)+$")
    message(${_MODE} "The name isn't meet file extension rules: ${_NAME}.")
  endif()
endfunction()
