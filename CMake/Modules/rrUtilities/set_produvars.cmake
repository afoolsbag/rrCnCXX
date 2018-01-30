# zhengrr
# 2016-10-8 – 2018-1-30
# The MIT License

include("${CMAKE_CURRENT_LIST_DIR}/ckname_w_cidrul.cmake")

# .rst
# .. command:: set_product_variables
#
#  设置若干变量::
#
#   set_product_variables(
#     [AUTHORS authors...]
#     [COPYRIGHT copyright]
#   )
#
#  变量列表::
#
#   PRODUCT_NAME
#   PRODUCT_NAME_UPPER
#   PRODUCT_NAME_LOWER
#   PRODUCT_SOURCE_DIR
#   PRODUCT_BINARY_DIR
#   PRODUCT_VERSION
#   PRODUCT_VERSION_MAJRO
#   PRODUCT_VERSION_MINOR
#   PRODUCT_VERSION_PATCH
#   PRODUCT_VERSION_TWEAK
#   PRODUCT_DESCRIPTION
#   PRODUCT_AUTHORS
#   PRODUCT_COPYRIGHT
function(set_product_variables)
  check_name_with_c_identifier_rules("${PROJECT_NAME}" checkPassed)
  if(NOT checkPassed)
    message(SEND_ERROR "Undesirable variable PROJECT_NAME(${PROJECT_NAME}).")
    return()
  endif()

  set(zOneValueKeywords "COPYRIGHT")
  set(zMultiValueKeywords "AUTHORS")
  cmake_parse_arguments(PARSE_ARGV 0 "" "" "${zOneValueKeywords}" "${zMultiValueKeywords}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments (${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  string(TOUPPER "${PROJECT_NAME}" sProjectNameUpper)
  string(TOLOWER "${PROJECT_NAME}" sProjectNameLower)

  set(PRODUCT_NAME          "${PROJECT_NAME}"          PARENT_SCOPE)
  set(PRODUCT_NAME_UPPER    "${sProjectNameUpper}"     PARENT_SCOPE)
  set(PRODUCT_NAME_LOWER    "${sProjectNameLower}"     PARENT_SCOPE)
  set(PRODUCT_SOURCE_DIR    "${PROJECT_SOURCE_DIR}"    PARENT_SCOPE)
  set(PRODUCT_BINARY_DIR    "${PROJECT_BINARY_DIR}"    PARENT_SCOPE)
  set(PRODUCT_VERSION       "${PROJECT_VERSION}"       PARENT_SCOPE)
  set(PRODUCT_VERSION_MAJRO "${PROJECT_VERSION_MAJOR}" PARENT_SCOPE)
  set(PRODUCT_VERSION_MINOR "${PROJECT_VERSION_MINOR}" PARENT_SCOPE)
  set(PRODUCT_VERSION_PATCH "${PROJECT_VERSION_PATCH}" PARENT_SCOPE)
  set(PRODUCT_VERSION_TWEAK "${PROJECT_VERSION_TWEAK}" PARENT_SCOPE)
  set(PRODUCT_DESCRIPTION   "${PROJECT_DESCRIPTION}"   PARENT_SCOPE)
  set(PRODUCT_AUTHORS        ${_AUTHORS}               PARENT_SCOPE)
  set(PRODUCT_COPYRIGHT     "${_COPYRIGHT}"            PARENT_SCOPE)
endfunction()
