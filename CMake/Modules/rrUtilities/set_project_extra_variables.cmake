# zhengrr
# 2016-10-8 – 2018-1-30
# The MIT License

include("${CMAKE_CURRENT_LIST_DIR}/check_name_with_c_identifier_rules.cmake")

# .rst
# .. command:: set_project_extra_variables
#
#  设置若干变量::
#
#   set_project_extra_variables(
#     [AUTHORS authors...]
#     [COPYRIGHT copyright]
#   )
#
#  变量列表::
#
#   PROJECT_NAME_UPPER
#   PROJECT_NAME_LOWER
#   PROJECT_AUTHORS
#   PROJECT_COPYRIGHT
function(set_project_extra_variables)
  check_name_with_c_identifier_rules("${PROJECT_NAME}" checkPassed)
  if(NOT checkPassed)
    message(SEND_ERROR "Undesirable variable PROJECT_NAME(${PROJECT_NAME}).")
    return()
  endif()

  set(oneValueKeywords "COPYRIGHT")
  set(multiValueKeywords "AUTHORS")
  cmake_parse_arguments(PARSE_ARGV 0 "" "" "${oneValueKeywords}" "${multiValueKeywords}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  string(TOUPPER "${PROJECT_NAME}" projectNameUpper)
  string(TOLOWER "${PROJECT_NAME}" projectNameLower)

  if(NOT DEFINED _AUTHORS)
    set(_AUTHORS ${PRODUCT_AUTHORS})
  endif()

  if(NOT DEFINED _COPYRIGHT)
    set(_COPYRIGHT "${PRODUCT_COPYRIGHT}")
  endif()

  set(PROJECT_NAME_UPPER "${projectNameUpper}" PARENT_SCOPE)
  set(PROJECT_NAME_LOWER "${projectNameLower}" PARENT_SCOPE)
  set(PROJECT_AUTHORS     ${_AUTHORS}          PARENT_SCOPE)
  set(PROJECT_COPYRIGHT  "${_COPYRIGHT}"       PARENT_SCOPE)
endfunction()
