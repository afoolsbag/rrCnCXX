#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___                 2016-10-8 – 2018-1-8
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
#    简便生成库文件::
#
#       quick_add_library_with_option(
#         [SUBNAME subname]
#         [STATIC] [SHARED] [MODULE]
#         [C90 | C99 | C11]
#         [CXX98 | CXX11 | CXX14 | CXX17]
#         <source>...
#       )
#
#    参见
#
#    + `add_executable <https://cmake.org/cmake/help/latest/command/add_library>`_
#    + `set_target_properties <https://cmake.org/cmake/help/latest/command/set_target_properties>`_
#    + `C_STANDARD <https://cmake.org/cmake/help/latest/prop_tgt/C_STANDARD>`_
#    + `CXX_STANDARD <https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD>`_
#
function(quick_add_library_with_option _SOURCE_VARIABLE)
  set(options "STATIC" "SHARED" "MODULE" "C90" "C99" "C11" "CXX98" "CXX11" "CXX14" "CXX17")
  set(oneValueKeywords "SUBNAME")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${options}" "${oneValueKeywords}" "")

  if(DEFINED _SUBNAME)
    set(name "${PROJECT_NAME}_${_SUBNAME}")
  else()
    set(name "${PROJECT_NAME}")
  endif()
  string(TOUPPER "${name}" nameUpper)
  string(TOLOWER "${name}" nameLower)

  if(_C11)
    set(cStandardProperty C_STANDARD 11 C_STANDARD_REQUIRED ON)
  elseif(_C99)
    set(cStandardProperty C_STANDARD 99 C_STANDARD_REQUIRED ON)
  elseif(_C90)
    set(cStandardProperty C_STANDARD 90 C_STANDARD_REQUIRED ON)
  else()
    set(cStandardProperty)
  endif()

  if(_CXX17)
    set(cxxStandardProperty CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX14)
    set(cxxStandardProperty CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX11)
    set(cxxStandardProperty CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX98)
    set(cxxStandardProperty CXX_STANDARD 98 CXX_STANDARD_REQUIRED ON)
  else()
    set(cxxStandardProperty)
  endif()

  if(_STATIC OR ((NOT _STATIC) AND (NOT _SHARED) AND (NOT _MODULE) AND (NOT BUILD_SHARED_LIBS)))
    set(optionName "${nameUpper}_COMPILE_STATIC")
    set(targetName "${nameLower}_static")
    option(${optionName} "Build static library." ON)
    if(NOT ${optionName})
      return()
    endif()
    add_library(${targetName} STATIC ${_UNPARSED_ARGUMENTS})
    set_target_properties(${targetName} PROPERTIES
      ${cStandardProperty}
      ${cxxStandardProperty}
      OUTPUT_NAME "${name}" CLEAN_DIRECT_OUTPUT ON)
    install(TARGETS ${targetName} DESTINATION "lib")
  endif()

  if(_SHARED OR ((NOT _STATIC) AND (NOT _SHARED) AND (NOT _MODULE) AND (BUILD_SHARED_LIBS)))
    set(optionName "${nameUpper}_COMPILE_SHARED")
    set(targetName "${nameLower}_shared")
    option(${optionName} "Build shared library." ON)
    if(NOT ${optionName})
      return()
    endif()
    add_library(${targetName} SHARED ${_UNPARSED_ARGUMENTS})
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
    add_library(${targetName} MODULE ${_UNPARSED_ARGUMENTS})
    set_target_properties(${targetName} PROPERTIES
      ${cStandardProperty}
      ${cxxStandardProperty}
      OUTPUT_NAME "${name}" CLEAN_DIRECT_OUTPUT ON)
    install(TARGETS ${targetName} DESTINATION "lib")
  endif()
endfunction()
