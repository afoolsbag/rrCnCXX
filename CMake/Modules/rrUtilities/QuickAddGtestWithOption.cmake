# zhengrr
# 2017-12-17 – 2018-2-2
# The MIT License

# .rst
# .. command:: quick_add_gtest_with_option
#
#    轻快生成GTest测试：
#    ::
#
#       quick_add_gtest_with_option(
#         <source>...
#       )
#
#    缓存变量：
#    ::
#
#       GTEST_ROOT
#
#    作用：
#
#    :option:         ``<PROJECT_NAME_UPPER>_COMPILE_TEST``
#    :add_executable: ``<PROJECT_NAME_LOWER>_test``
#    :output:         ``<PROJECT_NAME>_Test``
#    :add_test:       ``<PROJECT_NAME>_Test``
#
#    参见：
#
#    + `"enable_testing" <https://cmake.org/cmake/help/latest/command/enable_testing>`_. *CMake Documentation*.
#
function(quick_add_gtest_with_option)
  string(TOUPPER "${PROJECT_NAME}" sPrjNameUpr)
  string(TOLOWER "${PROJECT_NAME}" sPrjNameLwr)
  set(vOptName "${sPrjNameUpr}_COMPILE_TEST")
  set(sTgtName "${sPrjNameLwr}_test")
  set(sTesName "${PROJECT_NAME}_Test")

  set(GTEST_ROOT "${GTEST_ROOT}" CACHE PATH "The root directory of the GTest installation.")
  find_package(GTest)
  option(${vOptName} "Build test executable file (requires GTest)." ${GTEST_FOUND})
  if(NOT ${vOptName})
    return()
  endif()
  if(NOT GTEST_FOUND)
    message(SEND_ERROR "GTest is needed to build the test.")
    return()
  endif()

  include_directories(${GTEST_INCLUDE_DIRS})
  add_executable("${sTgtName}" ${ARGN})
  set_target_properties("${sTgtName}" PROPERTIES
    OUTPUT_NAME "${sTesName}" CLEAN_DIRECT_OUTPUT ON)
  target_link_libraries("${sTgtName}" GTest::GTest GTest::Main)

  add_test(NAME "${sTesName}" COMMAND "${sTgtName}")
endfunction()

# .rst
# .. command:: quick_gtest
#
#    同``quick_add_gtest_with_option``。
#
macro(quick_gtest)
  quick_add_gtest_with_option(${ARGN})
endmacro()
