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
# .. command:: set_project_extra_variables
#
#  设置若干变量::
#
#   set_project_extra_variables(
#     [AUTHORS   "<authors>"...]
#     [COPYRIGHT "<copyright>" ]
#   )
#
#  变量列表::
#
#   PROJECT_NAME_UPPER
#   PROJECT_NAME_LOWER
#   PROJECT_AUTHORS
#   PROJECT_COPYRIGHT
function(set_project_extra_variables)

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

  if(NOT DEFINED _AUTHORS)
    set(_AUTHORS "${PRODUCT_AUTHORS}")
  endif()

  if(NOT DEFINED _COPYRIGHT)
    set(_COPYRIGHT "${PRODUCT_COPYRIGHT}")
  endif()

  set(PROJECT_NAME_UPPER "${nameupper}"  PARENT_SCOPE)
  set(PROJECT_NAME_LOWER "${namelower}"  PARENT_SCOPE)
  set(PROJECT_AUTHORS    "${_AUTHORS}"   PARENT_SCOPE)
  set(PROJECT_COPYRIGHT  "${_COPYRIGHT}" PARENT_SCOPE)

endfunction()
