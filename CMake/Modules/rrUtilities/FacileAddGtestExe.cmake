# zhengrr
# 2017-12-17 – 2018-04-02
# The MIT License

# .rst
# .. command:: facile_add_gtest_executable
#
#    以``facile_add_executable``命令为基础，额外约定了若干缺省参数：
#
#    额外约定：
#
#    :OPTDESC:             see code
#    :LINKS:               ``GTest::GTest``
#
function(facile_add_gtest_executable)
  set(zOptKws)
  set(zOneValKws "TGTNAMEVAR" "OPTDESC")
  set(zMutValKws "LINKS")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  if(DEFINED _OPTDESC)
    set(sOptDesc ${_OPTDESC})
  else()
    set(sOptDesc "Build executable with GTest (requires GTest).")
  endif()

  if(NOT GTEST_FOUND)
    find_package(GTest)
    if(NOT GTEST_FOUND)
      set(GTEST_ROOT "${GTEST_ROOT}" CACHE PATH "The root directory of the GTest installation.")
    endif()
  endif()
  if(NOT GTEST_FOUND)
    message(WARNING "GTest is needed to build executable with GTest.")
  endif()

  if(GTEST_FOUND)
    if(NOT GTest::GTest IN_LIST _LINKS)
      list(APPEND _LINKS GTest::GTest)
    endif()
  endif()

  enable_testing()
  facile_add_executable(
    TGTNAMEVAR sTgtName OPTDESC "${sOptDesc}"
    ${_UNPARSED_ARGUMENTS}
    LINKS ${_LINKS})
  add_test(NAME "${sTgtName}" COMMAND "${sTgtName}")

  if(DEFINED _TGTNAMEVAR)
    set(${_TGTNAMEVAR} "${sTgtName}" PARENT_SCOPE)
  endif()
endfunction()
