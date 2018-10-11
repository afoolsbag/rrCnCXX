# zhengrr
# 2017-12-18 – 2018-10-11
# The Unlicense

include_guard()

if(NOT COMMAND check_name_with_cmake_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CkName.cmake")
endif()

# .rst
# .. command:: add_subdirectory_ex
#
#   添加子目录到构建（附加功能）::
#
#     add_subdirectory_ex(<source-directory>
#                         [binary-directory]
#                         [EXCLUDE_FROM_ALL]
#                         [WITH_OPTION]
#                         [OPTION_INITIAL_ON]
#     )
function(add_subdirectory_ex _SOURCE_DIRECTORY)
  set(zOptKws    EXCLUDE_FROM_ALL
                 WITH_OPTION
                 OPTION_INITIAL_ON)
  set(zOneValKws)
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
    check_name_with_cmake_rules("${_SOURCE_DIRECTORY}" sPassed)
    if(NOT sPassed)
      message(WARNING "The directory name isn't meet CMake recommend variable rules: ${_SOURCE_DIRECTORY}.")
    endif()
    string(TOUPPER "${_SOURCE_DIRECTORY}" vOptName)
    option(${vOptName} "Sub-directory ${_SOURCE_DIRECTORY}." ${_OPTION_INITIAL_ON})
  else()
    set(vOptName sOptVal)
    set(sOptVal TRUE)
  endif()

  if(${vOptName})
    add_subdirectory("${_SOURCE_DIRECTORY}" ${_BINARY_DIRECTORY} ${_EXCLUDE_FROM_ALL})
  endif()
endfunction()
