# zhengrr
# 2017-12-17 – 2018-10-13
# The Unlicense

include_guard()

cmake_policy(SET CMP0074 NEW) #3.12+

if(NOT COMMAND add_executable_ex)
  include("${CMAKE_CURRENT_LIST_DIR}/AddExeEx.cmake")
endif()

# .rst
# .. command:: facile_add_gtest_executable
#
#   便捷添加 GTest 目标到项目，
#   以 ``add_executable_ex`` 命令为基础，额外约定了若干缺省参数，并启用测试。
function(facile_add_gtest_executable)
  set(zOptKws)
  set(zOneValKws TARGET_NAME_VARIABLE)
  set(zMutValKws)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  find_package(GTest)
  if(NOT GTEST_FOUND)
    set(GTEST_ROOT "${GTEST_ROOT}" CACHE PATH "The root directory of the GTest installation.")
    message(WARNING "GTest is needed to build executable with GTest.")
  endif()

  enable_testing()
  add_executable_ex(
    OPTION_DESCRIPTION   "Build executable with GTest (requires GTest)."
    TARGET_NAME_VARIABLE sTgtName
    ${_UNPARSED_ARGUMENTS}
    LINK_LIBRARIES       GTest::GTest)
  add_test(NAME "${sTgtName}" COMMAND "${sTgtName}")

  if(DEFINED _TARGET_NAME_VARIABLE)
    set(${_TARGET_NAME_VARIABLE} "${sTgtName}" PARENT_SCOPE)
  endif()
endfunction()
