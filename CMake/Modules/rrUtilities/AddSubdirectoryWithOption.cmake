# zhengrr
# 2017-12-18 – 2018-1-31
# The MIT License

include("${CMAKE_CURRENT_LIST_DIR}/CheckNameWithCmakeRecommendVariableRules.cmake")

# .rst
# .. command:: add_subdirectory_with_option
#
#    提供选项，可选地将子目录添加到构建：
#    ::
#
#       add_subdirectory_with_option(
#         <source_directory>
#         [binary_directory]
#         [EXCLUDE_FROM_ALL]
#         [OPTION_INITIAL_VALUE <ON|OFF>]
#       )
#
#    缺陷：
#    ::
#
#       此命令的实现，强制要求源目录为直接子目录。
#
function(add_subdirectory_with_option _SOURCE_DIRECTORY)
  unset(_BINARY_DIRECTORY)
  set(zOptKws "EXCLUDE_FROM_ALL")
  set(zOneValKws "OPTION_INITIAL_VALUE")
  set(zMutValKws)
  cmake_parse_arguments(PARSE_ARGV 1 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  list(LENGTH _UNPARSED_ARGUMENTS sUArgCnt)
  if(sUArgCnt GREATER 0)
    list(GET _UNPARSED_ARGUMENTS 0 _BINARY_DIRECTORY)
  endif()
  if(sUArgCnt GREATER 1)
    message(SEND_ERROR "Incorrect number of arguments \"${ARGN}\".")
    return()
  endif()

  check_name_with_cmake_recommend_variable_rules("${_SOURCE_DIRECTORY}" sCkPassed)
  if(NOT sCkPassed)
    message(SEND_ERROR "Undesirable argument \"${_SOURCE_DIRECTORY}\".")
    return()
  endif()
  string(TOUPPER "${_SOURCE_DIRECTORY}" vOptName)

  if(_EXCLUDE_FROM_ALL)
    set(sExcludeFromAll "EXCLUDE_FROM_ALL")
  else()
    set(sExcludeFromAll)
  endif()

  if(NOT DEFINED _OPTION_INITIAL_VALUE)
    set(sOptInitVal)
  elseif(_OPTION_INITIAL_VALUE STREQUAL "ON")
    set(sOptInitVal ON)
  elseif(_OPTION_INITIAL_VALUE STREQUAL "OFF")
    set(sOptInitVal OFF)
  else()
    message(SEND_ERROR "Undesirable arguments \"OPTION_INITIAL_VALUE ${_OPTION_INITIAL_VALUE}\".")
    return()
  endif()

  option(${vOptName} "Subdirectory ${_SOURCE_DIRECTORY}." ${sOptInitVal})
  if(${vOptName})
    add_subdirectory("${_SOURCE_DIRECTORY}" ${_BINARY_DIRECTORY} ${sExcludeFromAll})
  endif()
endfunction()
