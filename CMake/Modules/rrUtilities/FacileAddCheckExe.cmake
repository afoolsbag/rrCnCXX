# zhengrr
# 2018-02-02 – 2018-07-05
# The MIT License

if(NOT COMMAND facile_add_executable)
  include("${CMAKE_CURRENT_LIST_DIR}/FacileAddExe.cmake")
endif()

# .rst
# .. command:: facile_add_check_executable
#
#    以``facile_add_executable``命令为基础，额外约定了若干缺省参数，并启用测试。
#
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
  facile_add_executable(
     OPTION_DESCRIPTION "Build executable with Check (requires Check)."
   TARGET_NAME_VARIABLE sTgtName
                        ${_UNPARSED_ARGUMENTS}
         LINK_LIBRARIES Check::Check Check::Compat)
  add_test(NAME "${sTgtName}" COMMAND "${sTgtName}")

  if(DEFINED _TARGET_NAME_VARIABLE)
    set(${_TARGET_NAME_VARIABLE} "${sTgtName}" PARENT_SCOPE)
  endif()
endfunction()
