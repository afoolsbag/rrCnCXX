# zhengrr
# 2017-12-18 – 2018-1-30
# The MIT License

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 NEW) #3.1+

# .rst
# .. command:: check_name_with_file_extension_rules
#
#    检查输入是否符合文件扩展名（命名）规则::
#
#       首字符为下脚点，扩展名仅包含拉丁字母和阿拉伯数字。
#       允许串接，如 .tar.gz
#
#       check_name_with_file_extension_rules(
#         <name>
#         <result>
#       )
#
function(check_name_with_file_extension_rules _NAME _RESULT_VARIABLE)
  if(NOT ${ARGC} EQUAL 2)
    message(SEND_ERROR "Incorrect number of arguments (${ARGN}).")
    return()
  endif()

  if("${_NAME}" MATCHES "^([.][0-9A-Za-z]+)+$")
    set(${_RESULT_VARIABLE} TRUE  PARENT_SCOPE)
  else()
    set(${_RESULT_VARIABLE} FALSE PARENT_SCOPE)
  endif()
endfunction()
