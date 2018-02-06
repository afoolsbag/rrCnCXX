# zhengrr
# 2018-2-2 – 6
# The MIT License

# .rst
# .. command:: quick_add_check_with_option
#
#    轻快生成Check测试：
#    ::
#
#       quick_add_check_with_option(
#         <source>...
#       )
#
#    缓存变量：
#    ::
#
#       CHECK_ROOT
#
#    作用：
#
#    :option:         ``<PROJECT_NAME_UPPER>_COMPILE_TEST``
#    :add_executable: ``<PROJECT_NAME_LOWER>_test``
#    :output:         ``<PROJECT_NAME>_Test``
#    :add_test:       ``<PROJECT_NAME>_Test``
#
#    参见
#
function(quick_add_check_with_option)
  string(TOUPPER "${PROJECT_NAME}" sPrjNameUpr)
  string(TOLOWER "${PROJECT_NAME}" sPrjNameLwr)
  set(vOptName "${sPrjNameUpr}_COMPILE_TEST")
  set(sTgtName "${sPrjNameLwr}_test")
  set(sTesName "${PROJECT_NAME}_Test")

  set(CHECK_ROOT "${CHECK_ROOT}" CACHE PATH "The root directory of the Check installation.")
  list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/../")
  find_package(Check)
  option(${vOptName} "Build test executable file (requires Check)." ${CHECK_FOUND})
  if(NOT ${vOptName})
    return()
  endif()
  if(NOT CHECK_FOUND)
    message(SEND_ERROR "Check is needed to build the test.")
    return()
  endif()

  include_directories(${CHECK_INCLUDE_DIRS})
  source_group("" FILES ${ARGN})
  add_executable("${sTgtName}" ${ARGN})
  set_target_properties("${sTgtName}" PROPERTIES
    OUTPUT_NAME "${sTesName}" CLEAN_DIRECT_OUTPUT ON)
  target_link_libraries("${sTgtName}" ${CHECK_LIBRARIES})

  add_test(NAME "${sTesName}" COMMAND "${sTgtName}")
endfunction()

# .rst
# .. command:: quick_check
#
#    同``quick_add_check_with_option``。
#
macro(quick_check)
  quick_add_check_with_option(${ARGN})
endmacro()
