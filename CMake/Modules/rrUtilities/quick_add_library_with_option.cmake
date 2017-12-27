#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___               2016-10-8 – 2017-12-27
# | '__| '__| | | | __| | | | __| |/ _ / __|                     The MIT License
# | |  | |  | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   \___/ \__|_|_|_|\__|_|\___|___/ rrUtilities by FIGlet
#            _     _                _                  _                       _
#   __ _  __| | __| | ___ _   _ ___| |_ ___  _ __ ___ | |_ __ _ _ __ __ _  ___| |_
#  / _` |/ _` |/ _` |/ __| | | / __| __/ _ \| '_ ` _ \| __/ _` | '__/ _` |/ _ | __|
# | (_| | (_| | (_| | (__| |_| \__ | || (_) | | | | | | || (_| | | | (_| |  __| |_
#  \__,_|\__,_|\__,_|\___|\__,_|___/\__\___/|_| |_| |_|\__\__,_|_|  \__, |\___|\__|
#                                       add_custom_target by FIGlet |___/

# .rst
# .. command:: quick_add_library_with_option
#
#  简便生成库文件::
#
#   quick_add_library_with_option(
#     <source_variable>
#     [SPECIAL STATIC|SHARED|MODULE]
#     [C_STANDARD 90|99|11]
#     [CXX_STANDARD 98|11|14|17]
#   )
function(quick_add_library_with_option _SOURCE_VARIABLE)
  set(oneValueKeywords "SPECIAL" "C_STANDARD" "CXX_STANDARD")
  cmake_parse_arguments(PARSE_ARGV 1 "" "" "${oneValueKeywords}" "")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  string(TOUPPER "${PROJECT_NAME}" projectNameUpper)
  string(TOLOWER "${PROJECT_NAME}" projectNameLower)

  if(NOT DEFINED _SPECIAL)
    set(textName "library")
    set(optionName "${projectNameUpper}_COMPILE_LIBRARY")
    set(targetName "${projectNameLower}_library")
  elseif(_SPECIAL STREQUAL "STATIC")
    set(textName "static library")
    set(optionName "${projectNameUpper}_COMPILE_STATIC")
    set(targetName "${projectNameLower}_static")
  elseif(_SPECIAL STREQUAL "SHARED")
    set(textName "shared library")
    set(optionName "${projectNameUpper}_COMPILE_SHARED")
    set(targetName "${projectNameLower}_shared")
  elseif(_SPECIAL STREQUAL "MODULE")
    set(textName "module library")
    set(optionName "${projectNameUpper}_COMPILE_MODULE")
    set(targetName "${projectNameLower}_module")
  else()
    message(SEND_ERROR "Undesirable SPECIAL(${_SPECIAL}).")
    return()
  endif()

  if(DEFINED _C_STANDARD)
    set(cStandardProperty C_STANDARD ${_C_STANDARD} C_STANDARD_REQUIRED ON)
  else()
    set(cStandardProperty)
  endif()

  if(DEFINED _CXX_STANDARD)
    set(cxxStandardProperty CXX_STANDARD ${_CXX_STANDARD} CXX_STANDARD_REQUIRED ON)
  else()
    set(cxxStandardProperty)
  endif()

  option(${optionName} "Build ${typetext}." ON)
  if(NOT ${optionName})
    return()
  endif()

  add_library(${targetName} ${_TYPE} ${${_SOURCE_VARIABLE}})
  set_target_properties(${targetName} PROPERTIES
    ${cStandardProperty}
    ${cxxStandardProperty}
    OUTPUT_NAME "${PROJECT_NAME}" CLEAN_DIRECT_OUTPUT ON)
  install(TARGETS ${targetName} DESTINATION "lib")
endfunction()
