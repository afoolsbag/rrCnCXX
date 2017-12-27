#            _   _ _   _ _ _ _   _
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___
# | '__| '__| | | | __| | | | __| |/ _ / __|
# | |  | |  | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   \___/ \__|_|_|_|\__|_|\___|___/
#        rrUtilities by FIGlet  _               _
#                           ___| |__   ___  ___| | _ _ __   __ _ _ __ ___   ___
#                          / __| '_ \ / _ \/ __| |/ | '_ \ / _` | '_ ` _ \ / _ \
# zhengrr                 | (__| | | |  __| (__|   <| | | | (_| | | | | | |  __/
# 2017-12-18 – 27          \___|_| |_|\___|\___|_|\_|_| |_|\__,_|_| |_| |_|\___|
# The MIT License                                           check_name by FIGlet

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 NEW) #3.1+

# .rst
# .. command:: check_name_with_file_extension_rules
#
#  检查输入是否符合文件扩展名（命名）规则::
#
#   check_name_with_file_extension_rules(
#     <name>
#     <result>
#   )
function(check_name_with_file_extension_rules _NAME _RESULT)
  if(NOT ${ARGC} EQUAL 2)
    message(SEND_ERROR "Incorrect number of arguments (${ARGN}).")
    return()
  endif()

  if("${_NAME}" MATCHES "^([.][0-9A-Za-z]+)+$")
    set(${_RESULT} TRUE  PARENT_SCOPE)
  else()
    set(${_RESULT} FALSE PARENT_SCOPE)
  endif()
endfunction()
