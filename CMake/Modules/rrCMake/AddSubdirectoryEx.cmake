# zhengrr
# 2017-12-18 – 2018-12-29
# Unlicense

include_guard()

if(NOT COMMAND check_name_with_cmake_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CheckName.cmake")
endif()

# .rst
# .. command:: add_subdirectory_ex
#
#   添加子目录到构建（附加功能）::
#
#     add_subdirectory_ex(
#       <source-directory>
#       [<binary-directory>]
#       [EXCLUDE_FROM_ALL]
#
#       [WITH_OPTION]
#       [OPTION_NAME_PREFIX <option-name-prefix>]
#       [OPTION_NAME        <option-name>]         default: "${SOURCE_DIRECTORY_UPPER}"
#       [OPTION_NAME_SUFFIX <option-name-suffix>]
#       [OPTION_INITIAL_ON]
#     )
function(add_subdirectory_ex _SOURCE_DIRECTORY)
  set(zOptKws    EXCLUDE_FROM_ALL
                 WITH_OPTION
                 OPTION_INITIAL_ON)
  set(zOneValKws OPTION_NAME_PREFIX
                 OPTION_NAME
                 OPTION_NAME_SUFFIX)
  set(zMutValKws)
  cmake_parse_arguments(PARSE_ARGV 1 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  list(LENGTH _UNPARSED_ARGUMENTS sUnpArgCnt)
  if(sUnpArgCnt EQUAL 0)
    set(_BINARY_DIRECTORY)
  elseif(sUnpArgCnt EQUAL 1)
    list(GET _UNPARSED_ARGUMENTS 0 _BINARY_DIRECTORY)
  else()
    message(FATAL_ERROR "Incorrect number of arguments: ${ARGN}.")
  endif()

  if(_EXCLUDE_FROM_ALL)
    set(_EXCLUDE_FROM_ALL EXCLUDE_FROM_ALL)
  else()
    set(_EXCLUDE_FROM_ALL)
  endif()

  if(_WITH_OPTION)
    if(NOT DEFINED _OPTION_NAME)
      string(TOUPPER "${_SOURCE_DIRECTORY}" _OPTION_NAME)
    endif()
    set(vOptName "${_OPTION_NAME_PREFIX}${_OPTION_NAME}${_OPTION_NAME_SUFFIX}")
    check_name_with_cmake_rules("${vOptName}" WARNING)
    option(${vOptName} "Sub-directory ${_SOURCE_DIRECTORY}." ${_OPTION_INITIAL_ON})
    if(NOT ${vOptName})
      return()
    endif()
  endif()

  add_subdirectory("${_SOURCE_DIRECTORY}" ${_BINARY_DIRECTORY} ${_EXCLUDE_FROM_ALL})
endfunction()
