# zhengrr
# 2016-10-08 – 2018-12-29
# Unlicense

include_guard()

if(NOT COMMAND check_name_with_c_rules OR
   NOT COMMAND check_name_with_cmake_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CheckName.cmake")
endif()

# .rst
# .. command:: product_more
#
#   附加若干变量::
#
#     product_more(
#       [AUTHORS <author>...]
#       [LICENSE <license>]
#     )
#
#   影响::
#
#   ``PRODUCT_NAME``
#
#   ``PRODUCT_NAME_UPPER``
#
#   ``PRODUCT_NAME_LOWER``
#
#   ``PRODUCT_SOURCE_DIR``
#
#   ``PRODUCT_BINARY_DIR``
#
#   ``PRODUCT_VERSION``
#
#   ``PRODUCT_VERSION_MAJRO``
#
#   ``PRODUCT_VERSION_MINOR``
#
#   ``PRODUCT_VERSION_PATCH``
#
#   ``PRODUCT_VERSION_TWEAK``
#
#   ``PRODUCT_DESCRIPTION``
#
#   ``PRODUCT_AUTHORS``
#
#   ``PRODUCT_LICENSE``
function(product_more)
  set(zOptKws)
  set(zOneValKws LICENSE)
  set(zMutValKws AUTHORS)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
  endif()

  check_name_with_c_rules("${PROJECT_NAME}" WARNING)
  check_name_with_cmake_rules("${PROJECT_NAME}" WARNING)
  string(TOUPPER "${PROJECT_NAME}" PROJECT_NAME_UPPER)
  string(TOLOWER "${PROJECT_NAME}" PROJECT_NAME_UPPER)

  set(PRODUCT_NAME            "${PROJECT_NAME}"          PARENT_SCOPE)
  set(PRODUCT_NAME_UPPER      "${PROJECT_NAME_UPPER}"    PARENT_SCOPE)
  set(PRODUCT_NAME_LOWER      "${PROJECT_NAME_UPPER}"    PARENT_SCOPE)
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
endfunction()

# .rst
# .. command:: project_more
#
#   附加若干变量::
#
#     project_more(
#       [AUTHORS <author>...]
#       [LICENSE license]
#     )
#
#   影响::
#
#   ``PROJECT_NAME_UPPER``
#
#   ``PROJECT_NAME_LOWER``
#
#   ``PROJECT_AUTHORS``
#
#   ``PROJECT_LICENSE``
function(project_more)
  set(zOptKws)
  set(zOneValKws LICENSE)
  set(zMutValKws AUTHORS)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
  endif()

  check_name_with_c_rules("${PROJECT_NAME}" WARNING)
  check_name_with_cmake_rules("${PROJECT_NAME}" WARNING)
  string(TOUPPER "${PROJECT_NAME}" PROJECT_NAME_UPPER)
  string(TOLOWER "${PROJECT_NAME}" PROJECT_NAME_LOWER)

  if(NOT DEFINED _AUTHORS)
    set(_AUTHORS ${PRODUCT_AUTHORS})
  endif()

  if(NOT DEFINED _LICENSE)
    set(_LICENSE "${PRODUCT_LICENSE}")
  endif()

  set(PROJECT_NAME_UPPER      "${PROJECT_NAME_UPPER}" PARENT_SCOPE)
  set(PROJECT_NAME_LOWER      "${PROJECT_NAME_LOWER}" PARENT_SCOPE)
  if(NOT "${PROJECT_VERSION_MAJOR}")
    set(PROJECT_VERSION_MAJOR 0                       PARENT_SCOPE)
  endif()
  if(NOT "${PROJECT_VERSION_MINOR}")
    set(PROJECT_VERSION_MINOR 0                       PARENT_SCOPE)
  endif()
  if(NOT "${PROJECT_VERSION_PATCH}")
    set(PROJECT_VERSION_PATCH 0                       PARENT_SCOPE)
  endif()
  if(NOT "${PROJECT_VERSION_TWEAK}")
    set(PROJECT_VERSION_TWEAK 0                       PARENT_SCOPE)
  endif()
  set(PROJECT_AUTHORS         ${_AUTHORS}             PARENT_SCOPE)
  set(PROJECT_LICENSE         "${_LICENSE}"           PARENT_SCOPE)
endfunction()
