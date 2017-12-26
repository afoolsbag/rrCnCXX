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
# .. command:: quick_add_executable_with_option
#
#  简便生成可执行文件::
#
#   quick_add_executable_with_option(
#      SRCVAR  <source variable>
#     [CSTD    <90|99|11>       ]
#     [CXXSTD  <98|11|14|17>    ]
#   )
function(quick_add_executable_with_option)

  set(opts)
  set(ovks "SRCVAR" "CSTD" "CXXSTD")
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

  string(TOUPPER "${PROJECT_NAME}" upper)
  string(TOLOWER "${PROJECT_NAME}" lower)

  option(${upper}_COMPILE_EXE "Build executable file." ON)
  if(${upper}_COMPILE_EXE)
    add_executable(${lower}_exe ${${_SRCVAR}})
    set_target_properties(${lower}_exe PROPERTIES
      cstd
      cxxstd
      OUTPUT_NAME "${PROJECT_NAME}" CLEAN_DIRECT_OUTPUT ON)
    install(TARGETS ${lower}_exe DESTINATION "bin")
  endif()

endfunction()
