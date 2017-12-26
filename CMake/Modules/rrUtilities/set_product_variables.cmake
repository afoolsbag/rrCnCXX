#            _   _ _   _ _ _ _   _
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___
# | '__| '__| | | | __| | | | __| |/ _ / __|
# | |  | |  | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   \___/ \__|_|_|_|\__|_|\___|___/           _       _     _
#              rrUtilities by FIGlet  __   ____ _ _ __(_) __ _| |__ | | ___ ___
#                                     \ \ / / _` | '__| |/ _` | '_ \| |/ _ / __|
# zhengrr                              \ V | (_| | |  | | (_| | |_) | |  __\__ \
# 2016-10-8 – 2017-12-26                \_/ \__,_|_|  |_|\__,_|_.__/|_|\___|___/
# The MIT License                                            variables by FIGlet

include("${CMAKE_CURRENT_LIST_DIR}/check_name_with_c_identifier_rules.cmake")

# .rst
# .. command:: set_product_variables
#
#  设置若干变量::
#
#   set_product_variables(
#     [AUTHORS   "<authors>"...]
#     [COPYRIGHT "<copyright>" ]
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
#   PRODUCT_AUTHORS
#   PRODUCT_COPYRIGHT
function(set_product_variables)

  check_name_with_c_identifier_rules("${PROJECT_NAME}" conformed)
  if(NOT conformed)
    message(SEND_ERROR "Undesirable PROJECT_NAME(${PROJECT_NAME}).")
    return()
  endif()

  set(opts)
  set(ovks "COPYRIGHT")
  set(mvks "AUTHORS")
  cmake_parse_arguments("" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  string(TOUPPER "${PROJECT_NAME}" nameupper)
  string(TOLOWER "${PROJECT_NAME}" namelower)

  set(PRODUCT_NAME          "${PROJECT_NAME}"          PARENT_SCOPE)
  set(PRODUCT_NAME_UPPER    "${nameupper}"             PARENT_SCOPE)
  set(PRODUCT_NAME_LOWER    "${namelower}"             PARENT_SCOPE)
  set(PRODUCT_SOURCE_DIR    "${PROJECT_SOURCE_DIR}"    PARENT_SCOPE)
  set(PRODUCT_BINARY_DIR    "${PROJECT_BINARY_DIR}"    PARENT_SCOPE)
  set(PRODUCT_VERSION       "${PROJECT_VERSION}"       PARENT_SCOPE)
  set(PRODUCT_VERSION_MAJRO "${PROJECT_VERSION_MAJOR}" PARENT_SCOPE)
  set(PRODUCT_VERSION_MINOR "${PROJECT_VERSION_MINOR}" PARENT_SCOPE)
  set(PRODUCT_VERSION_PATCH "${PROJECT_VERSION_PATCH}" PARENT_SCOPE)
  set(PRODUCT_VERSION_TWEAK "${PROJECT_VERSION_TWEAK}" PARENT_SCOPE)
  set(PRODUCT_AUTHORS       "${_AUTHORS}"              PARENT_SCOPE)
  set(PRODUCT_COPYRIGHT     "${_COPYRIGHT}"            PARENT_SCOPE)

endfunction()
