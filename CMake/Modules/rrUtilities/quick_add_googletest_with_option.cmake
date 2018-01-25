#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___               2017-12-27 – 2018-1-25
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
#    简便生成 Google Test::
#
#       quick_add_googletest_with_option(
#         <source>...
#       )
#
#    选项名形如 ``<PROJECT_NAME_UPPER>_COMPILE_TEST``
#
#    目标名形如 ``<PROJECT_NAME_LOWER>_test``
#
#    测试名形如 ``<PROJECT_NAME>_GoogleTest``
#
#    参见
#
#    + `enable_testing <https://cmake.org/cmake/help/latest/command/enable_testing>`_
#
function(quick_add_googletest_with_option)
  string(TOUPPER "${PROJECT_NAME}" sProjectNameUpper)
  string(TOLOWER "${PROJECT_NAME}" sProjectNameLower)
  set(vOption "${sProjectNameUpper}_COMPILE_TEST")
  set(vTarget "${sProjectNameLower}_test")
  set(vGoogleTest "${PROJECT_NAME}_Test")

  set(GTEST_ROOT "${GTEST_ROOT}" CACHE PATH "The root directory of the Google Test installation.")
  find_package(GTest)
  option(${vOption} "Build test file (requires GoogleTest)." ${GTEST_FOUND})
  if(NOT ${vOption})
    return()
  endif()
  if(NOT GTEST_FOUND)
    message(SEND_ERROR "GoogleTest is needed to build test.")
    return()
  endif()

  include_directories(${GTEST_INCLUDE_DIRS})
  add_executable(${vTarget} ${ARGN})
  target_link_libraries(${vTarget} GTest::GTest GTest::Main)

  add_test(NAME ${vGoogleTest} COMMAND ${vTarget})
endfunction()
