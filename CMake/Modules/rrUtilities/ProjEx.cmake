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
# .. command:: project_extra
#
#    额外设置若干变量：
#    ::
#
#       project_extra(
#         [AUTHORS <author>...]
#         [LICENSE license]
#       )
#
#    影响：
#    ::
#
#       PROJECT_NAME_UPPER
#       PROJECT_NAME_LOWER
#       PROJECT_AUTHORS
#       PROJECT_LICENSE
#
function(project_extra)
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

  if(DEFINED _AUTHORS)
    set(zAuthors ${_AUTHORS})
  else()
    set(zAuthors ${PRODUCT_AUTHORS})
  endif()

  if(DEFINED _LICENSE)
    set(sLicense "${_LICENSE}")
  else()
    set(sLicense "${PRODUCT_LICENSE}")
  endif()

  set(PROJECT_NAME_UPPER      "${projNameUpr}" PARENT_SCOPE)
  set(PROJECT_NAME_LOWER      "${projNameLwr}" PARENT_SCOPE)
  if(NOT "${PROJECT_VERSION_MAJOR}")
    set(PROJECT_VERSION_MAJOR 0                PARENT_SCOPE)
  endif()
  if(NOT "${PROJECT_VERSION_MINOR}")
    set(PROJECT_VERSION_MINOR 0                PARENT_SCOPE)
  endif()
  if(NOT "${PROJECT_VERSION_PATCH}")
    set(PROJECT_VERSION_PATCH 0                PARENT_SCOPE)
  endif()
  if(NOT "${PROJECT_VERSION_TWEAK}")
    set(PROJECT_VERSION_TWEAK 0                PARENT_SCOPE)
  endif()
  set(PROJECT_AUTHORS         ${zAuthors}      PARENT_SCOPE)
  set(PROJECT_LICENSE         "${sLicense}"    PARENT_SCOPE)

  check_name_with_cmake_recommend_variable_rules("${PROJECT_NAME}" sCkPassed)
  if(NOT sCkPassed)
    message(WARNING "PROJECT_NAME isn't meet CMake recommend variable rules: ${PROJECT_NAME}.")
  endif()

  check_name_with_c_identifier_rules("${PROJECT_NAME}" sCkPassed)
  if(NOT sCkPassed)
    message(WARNING "PROJECT_NAME isn't meet C identifier rules: ${PROJECT_NAME}.")
  endif()
endfunction()
