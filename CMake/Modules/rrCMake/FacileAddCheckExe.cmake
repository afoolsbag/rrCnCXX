# zhengrr
# 2018-02-02 – 2018-10-13
# The Unlicense

include_guard()

cmake_policy(SET CMP0074 NEW) #3.12+

if(NOT COMMAND add_executable_ex)
  include("${CMAKE_CURRENT_LIST_DIR}/AddExeEx.cmake")
endif()

# .rst
# .. command:: facile_add_check_executable
#
#   便捷添加 Check 目标到项目，
#   以 ``add_executable_ex`` 命令为基础，额外约定了若干缺省参数，并启用测试。
function(facile_add_check_executable)
  set(zOptKws)
  set(zOneValKws TARGET_NAME_VARIABLE)
  set(zMutValKws)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  find_package(Check)
  if(NOT Check_FOUND)
    message(WARNING "Check is needed to build executable with Check.")
  endif()

  enable_testing()
  add_executable_ex(
    OPTION_DESCRIPTION   "Build executable with Check (requires Check)."
    TARGET_NAME_VARIABLE sTgtName
    ${_UNPARSED_ARGUMENTS}
    LINK_LIBRARIES       Check::Check
                         Check::Compat)
  add_test(NAME "${sTgtName}" COMMAND "${sTgtName}")

  if(DEFINED _TARGET_NAME_VARIABLE)
    set(${_TARGET_NAME_VARIABLE} "${sTgtName}" PARENT_SCOPE)
  endif()
endfunction()
