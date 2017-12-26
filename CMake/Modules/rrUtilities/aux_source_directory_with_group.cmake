#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___               2016-10-8 – 2017-12-26
# | '__| '__| | | | __| | | | __| |/ _ / __|                     The MIT License
# | |  | |  | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   \___/ \__|_|_|_|\__|_|\___|___/
#                      rrUtilities by FIGlet         _ _               _
#   __ _ _   ___  _ ___  ___  _   _ _ __ ___ ___  __| (_)_ __ ___  ___| |_ ___  _ __ _   _
#  / _` | | | \ \/ / __|/ _ \| | | | '__/ __/ _  / _` | | '__/ _ \/ __| __/ _ \| '__| | | |
# | (_| | |_| |>  <\__ | (_) | |_| | | | (_|  __| (_| | | | |  __| (__| || (_) | |  | |_| |
#  \__,_|\__,_/_/\_|___/\___/ \__,_|_|  \___\___ \__,_|_|_|  \___|\___|\__\___/|_|   \__, |
#                                                      aux_source_director by FIGlet |___/

include("${CMAKE_CURRENT_LIST_DIR}/check_name_with_cmake_recommend_variable_rules.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/check_name_with_file_extension_rules.cmake")

# .rst
# .. command:: aux_source_directory_with_group
#
#  查找目录下所有指定文件并分组::
#
#   aux_source_directory_with_group(
#      SRCDIR  "<source directory>"
#      SRCEXTS "<source extensions>"...
#     [RECURSE                         ]
#      GRPDIR  "<group directory>"
#      SRCVAR   <source variable>
#   )
function(aux_source_directory_with_group)

  set(opts "RECURSE")
  set(ovks "SRCDIR" "GRPDIR" "SRCVAR")
  set(mvks "SRCEXTS")
  cmake_parse_arguments("" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED _SRCDIR)
    message(SEND_ERROR "Missing SRCDIR.")
    return()
  endif()
  if(NOT IS_DIRECTORY "${_SRCDIR}")
    message(SEND_ERROR "Undesirable SRCDIR(${_SRCDIR}).")
    return()
  endif()

  if(NOT DEFINED _SRCEXTS)
    message(SEND_ERROR "Missing SRCEXTS.")
    return()
  endif()
  list(REMOVE_DUPLICATES _SRCEXTS)
  foreach(ext ${_SRCEXTS})
    check_name_with_file_extension_rules("${ext}" conformed)
    if(NOT conformed)
      message(SEND_ERROR "Undesirable extension(${ext}).")
      return()
    endif()
  endforeach()

  if(_RECURSE)
    set(recurse "GLOB_RECURSE")
  else()
    set(recurse "GLOB")
  endif()

  # GRPDIR

  if(NOT DEFINED _SRCVAR)
    message(SEND_ERROR "Missing SRCVAR.")
    return()
  endif()
  check_name_with_cmake_recommend_variable_rules("${_SRCVAR}" conformed)
  if(NOT conformed)
    message(SEND_ERROR "Undesirable SRCVAR(${_SRCVAR}).")
    return()
  endif()

  unset(srcfiles)
  foreach(ext ${_SRCEXTS})
    file(${recurse} files "${_SRCDIR}/*${ext}")
    foreach(file ${files})

      list(APPEND srcfiles "${file}")

      get_filename_component(filedir "${file}" DIRECTORY)
      string(REGEX REPLACE "^${_SRCDIR}" "" relpath "${filedir}")
      string(REPLACE "/" "\\\\" grpdir "${_GRPDIR}${relpath}")
      source_group("${grpdir}" FILES "${file}")

    endforeach()
  endforeach()

  set(${_SRCVAR} "${srcfiles}" PARENT_SCOPE)

endfunction()
