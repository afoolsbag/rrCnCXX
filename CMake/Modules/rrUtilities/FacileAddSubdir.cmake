# zhengrr
# 2017-12-18 – 2018-04-11
# The MIT License

if(NOT COMMAND check_name_with_cmake_recommend_variable_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CkNameCmakeVar.cmake")
endif()

# .rst
# .. command:: facile_add_subdirectory
#
#    便捷加入子目录（构建）：
#    ::
#
#       facile_add_subdirectory(
#         <source-directory>
#         [binary-directory]
#         [EXCLUDE_FROM_ALL]
#         [WITHOUT_OPTION]
#         [OPTION_INITIAL_VALUE <ON|OFF>]
#       )
#
function(facile_add_subdirectory _SOURCE_DIRECTORY)
  set(zOptKws    "EXCLUDE_FROM_ALL" "WITHOUT_OPTION")
  set(zOneValKws "OPTION_INITIAL_VALUE")
  set(zMutValKws)
  cmake_parse_arguments(PARSE_ARGV 1 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  list(LENGTH _UNPARSED_ARGUMENTS sUnpArgCnt)
  if(sUnpArgCnt EQUAL 0)
    set(_BINARY_DIRECTORY)
  elseif(sUnpArgCnt EQUAL 1)
    list(GET _UNPARSED_ARGUMENTS 0 _BINARY_DIRECTORY)
  elseif(sUnpArgCnt GREATER 1)
    message(FATAL_ERROR "Incorrect number of arguments: ${ARGN}.")
    return()
  endif()

  if(_EXCLUDE_FROM_ALL)
    set(sExcludeFromAll "EXCLUDE_FROM_ALL")
  else()
    set(sExcludeFromAll)
  endif()

  if(_WITHOUT_OPTION)
    set(vOptName sOptName)
    set(sOptName ON)
  else()
    check_name_with_cmake_recommend_variable_rules("${_SOURCE_DIRECTORY}" sCkPassed)
    if(NOT sCkPassed)
      message(WARNING "The directory name not meet CMake recommend variable rules: ${_SOURCE_DIRECTORY}.")
    endif()
    string(TOUPPER "${_SOURCE_DIRECTORY}" vOptName)
    option(${vOptName} "Subdirectory ${_SOURCE_DIRECTORY}." ${_OPTION_INITIAL_VALUE})
  endif()
  if(${vOptName})
    add_subdirectory("${_SOURCE_DIRECTORY}" ${_BINARY_DIRECTORY} ${sExcludeFromAll})
  endif()
endfunction()