# zhengrr
# 2017-12-18 – 2018-1-30
# The MIT License

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 NEW) #3.1+

# .rst
# .. command:: check_name_with_c_identifier_rules
#
#    检查输入是否符合C语言标识符（命名）规则::
#
#       仅包含拉丁字母、阿拉伯数字和下划线，且首字符不为数字。
#
#       check_name_with_c_identifier_rules(
#         <name>
#         <result>
#       )
#
function(check_name_with_c_identifier_rules _NAME _RESULT_VARIABLE)
  if(NOT ${ARGC} EQUAL 2)
    message(SEND_ERROR "Incorrect number of arguments (${ARGN}).")
    return()
  endif()

  if("${_NAME}" MATCHES "^[A-Z_a-z]+[0-9A-Z_a-z]*$")
    set(${_RESULT_VARIABLE} TRUE  PARENT_SCOPE)
  else()
    set(${_RESULT_VARIABLE} FALSE PARENT_SCOPE)
  endif()
endfunction()
