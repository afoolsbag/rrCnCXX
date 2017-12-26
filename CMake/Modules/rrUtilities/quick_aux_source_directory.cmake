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

include("${CMAKE_CURRENT_LIST_DIR}/aux_source_directory_with_group.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/aux_source_directory_with_group_and_config.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/aux_source_directory_with_install.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/check_name_with_cmake_recommend_variable_rules.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/check_name_with_file_extension_rules.cmake")

# .rst
# .. command:: quick_aux_source_directory
#
#  简便查找、分组、配置、安装源文件::
#
#   quick_aux_source_directory(
#     [SRCDIR    "<source directory>"                  ]
#     [SRCEXTS   "<source extensions>"...              ]
#     [RECURSE                                         ]
#     [GRPDIR     <group directory>                    ]
#     [CONFIGURE                                       ]
#     [CFGEXTS   "<source and configure extensions>"...]
#     [GENDIR     <generate directory>                 ]
#     [INSTALL                                         ]
#     [INSEXTS   "<install extensions>"...             ]
#     [INSDIR     <install directory>                  ]
#      SRCVAR     <source variable>
#     [C] [CXX] [QT]
#   )
function(quick_aux_source_directory)

  set(opts "RECURSE" "CONFIGURE" "INSTALL" "C" "CXX" "QT")
  set(ovks "SRCDIR" "GRPDIR" "GENDIR" "INSDIR" "SRCVAR")
  set(mvks "SRCEXTS" "CFGEXTS" "INSEXTS")
  cmake_parse_arguments("" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  set(prjsrcdir "${PROJECT_SOURCE_DIR}")
  set(cursrcdir "${CMAKE_CURRENT_LIST_DIR}")
  string(REGEX REPLACE "^${prjsrcdir}" "" relpath "${cursrcdir}")
  set(prjbindir "${PROJECT_BINARY_DIR}")
  set(curbindir "${prjbindir}${relpath}")
  string(TOLOWER "${PROJECT_NAME}" prjlower)
  set(prjinsdir "${CMAKE_INSTALL_PREFIX}")
  set(curinsdir "${prjinsdir}/include/${prjlower}")

  if(NOT DEFINED _SRCDIR)
    set(srcdir "${cursrcdir}")
  elseif(NOT IS_DIRECTORY "${_SRCDIR}")
    set(srcdir "${cursrcdir}/${_SRCDIR}")
  else()
    set(srcdir "${_SRCDIR}")
  endif()
  if(NOT IS_DIRECTORY "${srcdir}")
    message(SEND_ERROR "Undesirable SRCDIR(${_SRCDIR}).")
    return()
  endif()

  set(srcexts "${_SRCEXTS}")
  if(_C)
    list(APPEND srcexts ".h" ".c")
  endif()
  if(_CXX)
    list(APPEND srcexts ".H" ".hh" ".hpp" ".hxx" ".inl" ".C" ".cc" ".cpp" ".cxx")
  endif()
  if(_QT)
    list(APPEND srcexts ".ui" ".qml" ".qrc" ".ts")
  endif()
  list(REMOVE_DUPLICATES srcexts)
  foreach(ext ${srcexts})
    check_name_with_file_extension_rules("${ext}" conformed)
    if(NOT conformed)
      message(SEND_ERROR "Undesirable extension(${ext}).")
      return()
    endif()
  endforeach()

  if(_RECURSE)
    set(recurse "RECURSE")
  else()
    unset(recurse)
  endif()

  if(DEFINED _GRPDIR)
    set(grpdir "${_GRPDIR}")
  else()
    set(grpdir "${relpath}")
  endif()

  if(DEFINED _CFGEXTS)
    set(cfgexts ${_CFGEXTS})
  else()
    set(cfgexts ".in")
  endif()
  foreach(ext ${cfgexts})
    check_name_with_file_extension_rules("${ext}" conformed)
    if(NOT conformed)
      message(SEND_ERROR "Undesirable extension(${ext}).")
      return()
    endif()
  endforeach()

  if(NOT DEFINED _GENDIR)
    set(gendir "${curbindir}")
  elseif(NOT IS_ABSOLUTE "${_GENDIR}")
    set(gendir "${curbindir}/${_GENDIR}")
  else()
    set(gendir "${_GENDIR}")
  endif()
  if(NOT IS_ABSOLUTE "${gendir}")
    message(SEND_ERROR "Undesirable GENDIR(${_GENDIR}).")
    return()
  endif()

  set(insexts ${_INSEXTS})
  if(_C)
    list(APPEND insexts ".h")
  endif()
  if(_CXX)
    list(APPEND insexts ".H" ".hh" ".hpp" ".hxx" ".inl")
  endif()
  foreach(ext ${insexts})
    check_name_with_file_extension_rules("${ext}" conformed)
    if(NOT conformed)
      message(SEND_ERROR "Undesirable extension(${ext}).")
      return()
    endif()
  endforeach()

  if(NOT DEFINED _INSDIR)
    set(insdir "${curinsdir}")
  elseif(NOT IS_ABSOLUTE "${_INSDIR}")
    set(insdir "${curinsdir}/${_INSDIR}")
  else()
    set(insdir "${_INSDIR}")
  endif()
  if(NOT IS_ABSOLUTE "${insdir}")
    message(SEND_ERROR "Undesirable INSDIR(${_INSDIR}).")
    return()
  endif()

  if(NOT DEFINED _SRCVAR)
    message(SEND_ERROR "Missing SRCVAR.")
    return()
  endif()
  check_name_with_cmake_recommend_variable_rules("${_SRCVAR}" conformed)
  if(NOT conformed)
    message(SEND_ERROR "Undesirable SRCVAR(${_SRCVAR}).")
    return()
  endif()

  aux_source_directory_with_group(
    SRCDIR     "${srcdir}"
    SRCEXTS     ${srcexts}
    ${recurse}
    GRPDIR     "${grpdir}"
    SRCVAR      srcfiles1
  )

  if(_CONFIGURE)
    aux_source_directory_with_group_and_config(
      SRCDIR     "${srcdir}"
      SRCEXTS     ${cfgexts}
      ${recurse}
      GRPDIR     "${grpdir}"
      GENDIR     "${gendir}"
      SRCVAR      srcfiles2
    )
  endif()

  if(_INSTALL)
    aux_source_directory_with_install(
      SRCDIR     "${srcdir}"
      SRCEXTS     ${insexts}
      ${recurse}
      INSDIR     "${insdir}"
    )
  endif()

  if(_INSTALL AND _CONFIGURE)
    aux_source_directory_with_install(
      SRCDIR     "${gendir}"
      SRCEXTS     ${insexts}
      ${recurse}
      INSDIR     "${insdir}"
    )
  endif()

  set(${_SRCVAR} "${srcfiles1}" "${srcfiles2}" PARENT_SCOPE)

endfunction()
