#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___                2017-12-27 – 2018-1-2
# | '__| '__| | | | __| | | | __| |/ _ / __|                     The MIT License
# | |  | |  | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   \___/ \__|_|_|_|\__|_|\___|___/ rrUtilities by FIGlet
#            _     _                _                  _                       _
#   __ _  __| | __| | ___ _   _ ___| |_ ___  _ __ ___ | |_ __ _ _ __ __ _  ___| |_
#  / _` |/ _` |/ _` |/ __| | | / __| __/ _ \| '_ ` _ \| __/ _` | '__/ _` |/ _ | __|
# | (_| | (_| | (_| | (__| |_| \__ | || (_) | | | | | | || (_| | | | (_| |  __| |_
#  \__,_|\__,_|\__,_|\___|\__,_|___/\__\___/|_| |_| |_|\__\__,_|_|  \__, |\___|\__|
#                                       add_custom_target by FIGlet |___/

# .rst
# .. command:: quick_add_googletest_with_option
#
#  简便生成ＧｏｏｇｌｅＴｅｓｔ测试::
#
#   quick_add_googletest_with_option(
#     <source_variable>
#   )
function(quick_add_googletest_with_option _SOURCE_VARIABLE)
  cmake_parse_arguments(PARSE_ARGV 1 "" "" "" "")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  string(TOUPPER "${PROJECT_NAME}" projectNameUpper)
  string(TOLOWER "${PROJECT_NAME}" projectNameLower)
  set(optionName "${projectNameUpper}_COMPILE_TEST")
  set(targetName "${projectNameLower}_test")
  set(testName "${PROJECT_NAME}_GoogleTest")

  set(GTEST_ROOT "" CACHE PATH "The root directory of the Google Test installation.")
  find_package(GTest)
  option(${optionName} "Build test file (requires GoogleTest)." ${GTEST_FOUND})
  if(NOT ${optionName})
    return()
  endif()
  if(NOT GTEST_FOUND)
    message(SEND_ERROR "GoogleTest is needed to build test.")
    return()
  endif()

  include_directories(${GTEST_INCLUDE_DIRS})
  add_executable(${targetName} ${${_SOURCE_VARIABLE}})
  target_link_libraries(${targetName} GTest::GTest GTest::Main)

  add_test(NAME ${testName} COMMAND ${targetName})
endfunction()
