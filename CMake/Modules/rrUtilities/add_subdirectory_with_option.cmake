#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___                2017-12-18 – 2018-1-4
# | '__| '__| | | | __| | | | __| |/ _ / __|                     The MIT License
# | |  | |  | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   \___/ \__|_|_|_|\__|_|\___|___/ rrUtilities by FIGlet
#             _     _           _         _ _               _
#    __ _  __| | __|  ___ _   _| |__   __| (_)_ __ ___  ___| |_ ___  _ __ _   _
#   / _` |/ _` |/ _` / __| | | | '_ \ / _` | | '__/ _ \/ __| __/ _ \| '__| | | |
#  | (_| | (_| | (_| \__ | |_| | |_) | (_| | | | |  __| (__| || (_) | |  | |_| |
#   \__,_|\__,_|\__,_|___/\__,_|_.__/ \__,_|_|_|  \___|\___|\__\___/|_|   \__, |
#                                              add_subdirectory by FIGlet |___/

include("${CMAKE_CURRENT_LIST_DIR}/check_name_with_cmake_recommend_variable_rules.cmake")

# .rst
# .. command:: add_subdirectory_with_option
#
#  提供选项，可选地将子目录添加到构建::
#
#   add_subdirectory_with_option(
#     <source_directory>
#     [binary_directory]
#     [EXCLUDE_FROM_ALL]
#     [ON|OFF]            // option initial value
#   )
#
#  BUG::
#
#   此命令的实现，强制要求源目录为直接子目录。
function(add_subdirectory_with_option _SOURCE_DIRECTORY)
  set(_BINARY_DIRECTORY)
  set(options "EXCLUDE_FROM_ALL" "ON" "OFF")
  cmake_parse_arguments(PARSE_ARGV 1 "" "${options}" "" "")
  list(LENGTH _UNPARSED_ARGUMENTS unparsedArgumentsNumber)
  if(unparsedArgumentsNumber GREATER 0)
    list(GET _UNPARSED_ARGUMENTS 0 _BINARY_DIRECTORY)
  endif()
  if(unparsedArgumentsNumber GREATER 1)
    message(SEND_ERROR "Incorrect number of arguments.")
    return()
  endif()

  check_name_with_cmake_recommend_variable_rules("${_SOURCE_DIRECTORY}" checkPassed)
  if(NOT checkPassed)
    message(SEND_ERROR "Undesirable argument(${_SOURCE_DIRECTORY}).")
    return()
  endif()
  string(TOUPPER "${_SOURCE_DIRECTORY}" optionName)

  if(DEFINED _BINARY_DIRECTORY)
    set(binaryDirectory "${_BINARY_DIRECTORY}")
  else()
    set(binaryDirectory)
  endif()

  if(_EXCLUDE_FROM_ALL)
    set(excludeFromAll "EXCLUDE_FROM_ALL")
  else()
    set(excludeFromAll)
  endif()

  if(_ON AND _OFF)
    message(SEND_ERROR "Undesirable arguments(${_ON} & ${_OFF}).")
    return()
  elseif(_ON)
    set(optionInitialValue ON)
  elseif(_OFF)
    set(optionInitialValue OFF)
  else()
    set(optionInitialValue)
  endif()

  option(${optionName} "Subdirectory ${_SOURCE_DIRECTORY}." ${optionInitialValue})
  if(${optionName})
    add_subdirectory("${_SOURCE_DIRECTORY}" ${binaryDirectory} ${excludeFromAll})
  endif()
endfunction()
