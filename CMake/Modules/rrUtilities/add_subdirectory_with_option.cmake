#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___               2016-10-8 – 2017-12-26
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
#      SRCDIR           "<source directory>"
#     [BINDIR           "<binary directory>"]
#     [EXCLUDE_FROM_ALL                     ]
#     [INITIAL_OPTION    <OFF|ON>           ]
#   )
function(add_subdirectory_with_option)

  set(opts "EXCLUDE_FROM_ALL")
  set(ovks "SRCDIR" "BINDIR" "INITIAL_OPTION")
  set(mvks)
  cmake_parse_arguments("" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED _SRCDIR)
    message(SEND_ERROR "Missing SRCDIR.")
    return()
  endif()
  check_name_with_cmake_recommend_variable_rules("${_SRCDIR}" conformed)
  if(NOT conformed)
    message(SEND_ERROR "Undesirable SRCDIR(${_SRCDIR}).")
    return()
  endif()

  string(TOUPPER "${_SRCDIR}" optionname)

  if(DEFINED _INITIAL_OPTION)
    set(initialoption "${_INITIAL_OPTION}")
  else()
    set(initialoption OFF)
  endif()

  if(DEFINED _BINDIR)
    set(bindir "${_BINDIR}")
  else()
    unset(bindir)
  endif()

  if(_EXCLUDE_FROM_ALL)
    set(exclude_from_all "EXCLUDE_FROM_ALL")
  else()
    unset(exclude_from_all)
  endif()

  option(${optionname} "Subdirectory ${_SRCDIR}." ${initialoption})
  if(${optionname})
    add_subdirectory("${_SRCDIR}" ${bindir} ${exclude_from_all})
  endif()

endfunction()
