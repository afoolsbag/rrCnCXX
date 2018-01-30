# zhengrr
# 2017-12-17 – 2018-1-30
# The MIT License

# .rst
# .. command:: quick_add_googletest_with_option
#
#    轻快生成GoogleTest测试：
#    ::
#
#       quick_add_googletest_with_option(
#         <source>...
#       )
#
#    缓存变量：
#    ::
#
#       GTEST_ROOT
#
#    影响：
#
#    :option:                ``<PROJECT_NAME_UPPER>_COMPILE_TEST``
#    :add_executable:        ``<PROJECT_NAME_LOWER>_test``
#    :set_target_properties: ``OUTPUT_NAME <PROJECT_NAME>Test``
#    :add_test:              ``<PROJECT_NAME>Test``
#
#    参见：
#
#    + `"enable_testing" <https://cmake.org/cmake/help/latest/command/enable_testing>`_. *CMake Documentation*.
#
function(quick_add_googletest_with_option)
  string(TOUPPER "${PROJECT_NAME}" sPrjNameUpr)
  string(TOLOWER "${PROJECT_NAME}" sPrjNameLwr)
  set(vOptName "${sPrjNameUpr}_COMPILE_TEST")
  set(vTgtName "${sPrjNameLwr}_test")
  set(vTesName "${PROJECT_NAME}Test")

  set(GTEST_ROOT "${GTEST_ROOT}" CACHE PATH "The root directory of the Google Test installation.")
  find_package(GTest)
  option(${vOptName} "Build test executable file (requires GoogleTest)." ${GTEST_FOUND})
  if(NOT ${vOptName})
    return()
  endif()
  if(NOT GTEST_FOUND)
    message(SEND_ERROR "GoogleTest is needed to build the test.")
    return()
  endif()

  include_directories(${GTEST_INCLUDE_DIRS})
  add_executable(${vTgtName} ${ARGN})
  set_target_properties(${vTgtName} PROPERTIES
    OUTPUT_NAME "${vTesName}" CLEAN_DIRECT_OUTPUT ON)
  target_link_libraries(${vTgtName} GTest::GTest GTest::Main)

  add_test(NAME ${vTesName} COMMAND ${vTgtName})
endfunction()
