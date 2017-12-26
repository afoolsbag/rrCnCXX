#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___               2016-10-8 – 2017-12-26
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
#  简便生成库::
#
#   quick_add_library_with_option(
#      SRCVAR  <source variable>
#     [TYPE    <STATIC|SHARED|MODULE>]
#     [CSTD    <90|99|11>            ]
#     [CXXSTD  <98|11|14|17>         ]
#   )
function(quick_add_library_with_option)

  set(opts)
  set(ovks "SRCVAR" "TYPE" "CSTD" "CXXSTD")
  set(mvks)
  cmake_parse_arguments("" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED _SRCVAR)
    message(SEND_ERROR "Missing SRCVAR.")
    return()
  endif()

  if(NOT DEFINED _TYPE)
    set(typetext "library")
    set(typeupper "LIBRARY")
    set(typelower "library")
  elseif("${_TYPE}" STREQUAL "STATIC")
    set(typetext "static library")
    set(typeupper "STATIC")
    set(typelower "static")
  elseif("${_TYPE}" STREQUAL "SHARED")
    set(typetext "shared library")
    set(typeupper "SHARED")
    set(typelower "shared")
  elseif("${_TYPE}" STREQUAL "MODULE")
    set(typetext "module library")
    set(typeupper "MODULE")
    set(typelower "module")
  else()
    message(SEND_ERROR "Undesirable TYPE(${_TYPE}).")
    return()
  endif()

  if(DEFINED _CSTD)
    set(cstd "C_STANDARD ${_CSTD} C_STANDARD_REQUIRED ON")
  else()
    unset(cstd)
  endif()

  if(DEFINED _CXXSTD)
    set(cxxstd "CXX_STANDARD ${_CXXSTD} CXX_STANDARD_REQUIRED ON")
  else()
    unset(cxxstd)
  endif()

  string(TOUPPER "${PROJECT_NAME}" nameupper)
  string(TOLOWER "${PROJECT_NAME}" namelower)

  option(${nameupper}_COMPILE_${typeupper} "Build ${typetext}." ON)
  if(${nameupper}_COMPILE_${typeupper})
    add_library(${namelower}_${typelower} ${_TYPE} ${${_SRCVAR}})
    set_target_properties(${namelower}_${typelower} PROPERTIES
      cstd
      cxxstd
      OUTPUT_NAME "${PROJECT_NAME}" CLEAN_DIRECT_OUTPUT ON)
    install(TARGETS ${namelower}_${typelower} DESTINATION "lib")
  endif()

endfunction()
