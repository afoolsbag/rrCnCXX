# zhengrr
# 2016-10-08 – 2018-09-06
# The Unlicense

if(NOT COMMAND check_name_with_cmake_recommend_variable_rules )
  include("${CMAKE_CURRENT_LIST_DIR}/CkNameCmakeVar.cmake")
endif()

if(NOT COMMAND check_name_with_c_identifier_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CkNameCId.cmake")
endif()

# .rst
# .. command:: product_extra
#
#    额外设置若干变量：
#    ::
#
#       product_extra(
#         [AUTHORS <author>...]
#         [LICENSE <license>]
#       )
#
#    影响：
#    ::
#
#       PRODUCT_NAME
#       PRODUCT_NAME_UPPER
#       PRODUCT_NAME_LOWER
#       PRODUCT_SOURCE_DIR
#       PRODUCT_BINARY_DIR
#       PRODUCT_VERSION
#       PRODUCT_VERSION_MAJRO
#       PRODUCT_VERSION_MINOR
#       PRODUCT_VERSION_PATCH
#       PRODUCT_VERSION_TWEAK
#       PRODUCT_DESCRIPTION
#       PRODUCT_AUTHORS
#       PRODUCT_LICENSE
#
function(product_extra)
  set(zOptKws)
  set(zOneValKws LICENSE)
  set(zMutValKws AUTHORS)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
    return()
  endif()

  string(TOUPPER "${PROJECT_NAME}" sProjNameUpr)
  string(TOLOWER "${PROJECT_NAME}" sProjNameLwr)

  set(PRODUCT_NAME            "${PROJECT_NAME}"          PARENT_SCOPE)
  set(PRODUCT_NAME_UPPER      "${sProjNameUpr}"          PARENT_SCOPE)
  set(PRODUCT_NAME_LOWER      "${sProjNameLwr}"          PARENT_SCOPE)
  set(PRODUCT_SOURCE_DIR      "${PROJECT_SOURCE_DIR}"    PARENT_SCOPE)
  set(PRODUCT_BINARY_DIR      "${PROJECT_BINARY_DIR}"    PARENT_SCOPE)
  set(PRODUCT_VERSION         "${PROJECT_VERSION}"       PARENT_SCOPE)
  if("${PROJECT_VERSION_MAJOR}")
    set(PRODUCT_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}" PARENT_SCOPE)
  else()
    set(PRODUCT_VERSION_MAJOR 0                          PARENT_SCOPE)
  endif()
  if("${PROJECT_VERSION_MINOR}")
    set(PRODUCT_VERSION_MINOR "${PROJECT_VERSION_MINOR}" PARENT_SCOPE)
  else()
    set(PRODUCT_VERSION_MINOR 0                          PARENT_SCOPE)
  endif()
  if("${PROJECT_VERSION_PATCH}")
    set(PRODUCT_VERSION_PATCH "${PROJECT_VERSION_PATCH}" PARENT_SCOPE)
  else()
    set(PRODUCT_VERSION_PATCH 0                          PARENT_SCOPE)
  endif()
  if("${PROJECT_VERSION_TWEAK}")
    set(PRODUCT_VERSION_TWEAK "${PROJECT_VERSION_TWEAK}" PARENT_SCOPE)
  else()
    set(PRODUCT_VERSION_TWEAK 0                          PARENT_SCOPE)
  endif()
  set(PRODUCT_DESCRIPTION     "${PROJECT_DESCRIPTION}"   PARENT_SCOPE)
  set(PRODUCT_AUTHORS         ${_AUTHORS}                PARENT_SCOPE)
  set(PRODUCT_LICENSE         "${_LICENSE}"              PARENT_SCOPE)

  check_name_with_cmake_recommend_variable_rules("${PROJECT_NAME}" sCkPassed)
  if(NOT sCkPassed)
    message(WARNING "PRODUCT_NAME isn't meet CMake recommend variable rules: ${PROJECT_NAME}.")
  endif()

  check_name_with_c_identifier_rules("${PROJECT_NAME}" sCkPassed)
  if(NOT sCkPassed)
    message(WARNING "PRODUCT_NAME isn't meet C identifier rules: ${PROJECT_NAME}.")
  endif()
endfunction()
