# zhengrr
# 2017-12-18 – 2018-1-30
# The MIT License

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 NEW) #3.1+

# .rst
# .. command:: check_name_with_cmake_recommend_variable_rules
#
#    检查输入是否符合CMake推荐变量（命名）规则::
#
#       仅包含拉丁字母、阿拉伯数字、下划线和连字符。
#
#       check_name_with_cmake_recommend_variable_rules(
#         <name>
#         <result>
#       )
#
#    参见
#
#    + `Variables <https://cmake.org/cmake/help/latest/manual/cmake-language.7.html#id31>`_
#
function(check_name_with_cmake_recommend_variable_rules _NAME _RESULT_VARIABLE)
  if(NOT ${ARGC} EQUAL 2)
    message(SEND_ERROR "Incorrect number of arguments (${ARGN}).")
    return()
  endif()

  if("${_NAME}" MATCHES "^[-0-9A-Z_a-z]+$")
    set(${_RESULT_VARIABLE} TRUE  PARENT_SCOPE)
  else()
    set(${_RESULT_VARIABLE} FALSE PARENT_SCOPE)
  endif()
endfunction()
