# zhengrr
# 2017-12-17 – 2018-04-11
# The MIT License

if(NOT COMMAND facile_add_executable)
  include("${CMAKE_CURRENT_LIST_DIR}/FacileAddExe.cmake")
endif()

# .rst
# .. command:: facile_add_gtest_executable
#
#    以``facile_add_executable``命令为基础，额外约定了若干缺省参数：
#
#    额外约定：
#
#    :OPTION_DESCRIPTION: see code
#    :LINK_LIBRARIES:     ``GTest::GTest``
#
function(facile_add_gtest_executable)
  set(zOptKws)
  set(zOneValKws "OPTION_DESCRIPTION" "TARGET_NAME_VARIABLE")
  set(zMutValKws "LINK_LIBRARIES")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  # OPTION_DESCRIPTION
  if(DEFINED _OPTION_DESCRIPTION)
    set(sOptDesc ${_OPTION_DESCRIPTION})
  else()
    set(sOptDesc "Build executable with GTest (requires GTest).")
  endif()

  # LINK_LIBRARIES
  set(zLinkLibs ${_LINK_LIBRARIES})

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
    if(NOT GTest::GTest IN_LIST zLinkLibs)
      list(APPEND zLinkLibs GTest::GTest)
    endif()
  endif()

  # facile_add_executable
  enable_testing()
  facile_add_executable(
    OPTION_DESCRIPTION     "${sOptDesc}"
    TARGET_NAME_VARIABLE    sTgtName
    ${_UNPARSED_ARGUMENTS}
    LINK_LIBRARIES          ${zLinkLibs})
  add_test(NAME "${sTgtName}" COMMAND "${sTgtName}")

  if(DEFINED _TARGET_NAME_VARIABLE)
    set(${_TARGET_NAME_VARIABLE} "${sTgtName}" PARENT_SCOPE)
  endif()
endfunction()
