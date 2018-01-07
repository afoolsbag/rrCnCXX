#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___                 2016-10-8 – 2018-1-3
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
#     [ORIGINAL_NAME original_name]  // not target name
#     [STATIC] [SHARED] [MODULE]
#     [C_STANDARD 90|99|11]
#     [CXX_STANDARD 98|11|14|17]
#   )
function(quick_add_library_with_option _SOURCE_VARIABLE)
  set(options "STATIC" "SHARED" "MODULE")
  set(oneValueKeywords "ORIGINAL_NAME" "SPECIAL" "C_STANDARD" "CXX_STANDARD")
  cmake_parse_arguments(PARSE_ARGV 1 "" "" "${oneValueKeywords}" "")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(DEFINED _ORIGINAL_NAME)
    set(name "${_ORIGINAL_NAME}")
    string(TOUPPER "${_ORIGINAL_NAME}" nameUpper)
    string(TOLOWER "${_ORIGINAL_NAME}" nameLower)
  else()
    set(name "${PROJECT_NAME}")
    string(TOUPPER "${PROJECT_NAME}" nameUpper)
    string(TOLOWER "${PROJECT_NAME}" nameLower)
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

  if(_STATIC OR (NOT _STATIC AND NOT _SHARED AND NOT _MODULE AND NOT BUILD_SHARED_LIBS))
    set(optionName "${nameUpper}_COMPILE_STATIC")
    set(targetName "${nameLower}_static")
    option(${optionName} "Build static library." ON)
    if(NOT ${optionName})
      return()
    endif()
    add_library(${targetName} STATIC ${${_SOURCE_VARIABLE}})
    set_target_properties(${targetName} PROPERTIES
      ${cStandardProperty}
      ${cxxStandardProperty}
      OUTPUT_NAME "${name}" CLEAN_DIRECT_OUTPUT ON)
    install(TARGETS ${targetName} DESTINATION "lib")
  endif()

  if(_SHARED OR (NOT _STATIC AND NOT _SHARED AND NOT _MODULE AND BUILD_SHARED_LIBS))
    set(optionName "${nameUpper}_COMPILE_SHARED")
    set(targetName "${nameLower}_shared")
    option(${optionName} "Build shared library." ON)
    if(NOT ${optionName})
      return()
    endif()
    add_library(${targetName} SHARED ${${_SOURCE_VARIABLE}})
    set_target_properties(${targetName} PROPERTIES
      ${cStandardProperty}
      ${cxxStandardProperty}
      OUTPUT_NAME "${name}" CLEAN_DIRECT_OUTPUT ON)
    install(TARGETS ${targetName} DESTINATION "lib")
  endif()

  if(_MODULE)
    set(optionName "${nameUpper}_COMPILE_MODULE")
    set(targetName "${nameLower}_module")
    option(${optionName} "Build module library." ON)
    if(NOT ${optionName})
      return()
    endif()
    add_library(${targetName} MODULE ${${_SOURCE_VARIABLE}})
    set_target_properties(${targetName} PROPERTIES
      ${cStandardProperty}
      ${cxxStandardProperty}
      OUTPUT_NAME "${name}" CLEAN_DIRECT_OUTPUT ON)
    install(TARGETS ${targetName} DESTINATION "lib")
  endif()
endfunction()
