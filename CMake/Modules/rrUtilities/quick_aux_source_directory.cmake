#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___               2016-10-8 – 2017-12-27
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
#     <source_variable>
#     [SOURCE_DIRECTORY     source_directory]
#     [SOURCE_EXTENSIONS    source_extensions...]
#     [GROUP_DIRECTORY      group_directory]
#     [CONFIGURE]
#     [CONFIGURE_EXTENSIONS configure_extensions...]
#     [GENERATED_DIRECTORY  generated_directory]
#     [INSTALL]
#     [INSTALL_EXTENSIONS   install_extensions...]
#     [INSTALL_DIRECTORY    install_directory]
#     [RECURSE] [C] [CXX] [QT]
#   )
function(quick_aux_source_directory _SOURCE_VARIABLE)
  set(options "CONFIGURE" "INSTALL" "RECURSE" "C" "CXX" "QT")
  set(oneValueKeywords "SOURCE_DIRECTORY" "GROUP_DIRECTORY" "GENERATED_DIRECTORY" "INSTALL_DIRECTORY")
  set(multiValueKeywords "SOURCE_EXTENSIONS" "CONFIGURE_EXTENSIONS" "INSTALL_EXTENSIONS")
  cmake_parse_arguments(PARSE_ARGV 1 "" "${options}" "${oneValueKeywords}" "${multiValueKeywords}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  set(projectSourceDirectory "${PROJECT_SOURCE_DIR}")
  set(currentSourceDirectory "${CMAKE_CURRENT_LIST_DIR}")
  string(REGEX REPLACE "^${projectSourceDirectory}" "" relativePath "${currentSourceDirectory}")
  set(projectBinaryDirectory "${PROJECT_BINARY_DIR}")
  set(currentBinaryDirectory "${projectBinaryDirectory}${relativePath}")
  string(TOLOWER "${PROJECT_NAME}" projectNameLower)
  set(projectInstallDirectory "${CMAKE_INSTALL_PREFIX}")
  set(currentInstallDirectory "${projectInstallDirectory}/include/${projectNameLower}")

  check_name_with_cmake_recommend_variable_rules("${_SOURCE_VARIABLE}" checkPassed)
  if(NOT checkPassed)
    message(SEND_ERROR "Undesirable argument SOURCE_VARIABLE(${_SOURCE_VARIABLE}).")
    return()
  endif()

  if(NOT DEFINED _SOURCE_DIRECTORY)
    set(sourceDirectory "${currentSourceDirectory}")
  elseif(NOT IS_DIRECTORY "${_SOURCE_DIRECTORY}")
    set(sourceDirectory "${currentSourceDirectory}/${_SOURCE_DIRECTORY}")
  else()
    set(sourceDirectory "${_SOURCE_DIRECTORY}")
  endif()
  if(NOT IS_DIRECTORY "${sourceDirectory}")
    message(SEND_ERROR "Undesirable SOURCE_DIRECTORY(${_SOURCE_DIRECTORY}).")
    return()
  endif()

  set(sourceExtensions "${_SOURCE_EXTENSIONS}")
  if(_C)
    list(APPEND sourceExtensions ".h" ".c")
  endif()
  if(_CXX)
    list(APPEND sourceExtensions ".H" ".hh" ".hpp" ".hxx" ".inl" ".C" ".cc" ".cpp" ".cxx")
  endif()
  if(_QT)
    list(APPEND sourceExtensions ".ui" ".qml" ".qrc" ".ts")
  endif()
  list(REMOVE_DUPLICATES sourceExtensions)
  foreach(extension ${sourceExtensions})
    check_name_with_file_extension_rules("${extension}" checkPassed)
    if(NOT checkPassed)
      message(SEND_ERROR "Undesirable extension(${extension}).")
      return()
    endif()
  endforeach()

  if(DEFINED _GROUP_DIRECTORY)
    set(groupDirectory "${_GROUP_DIRECTORY}")
  else()
    set(groupDirectory "${relativePath}")
  endif()

  if(_RECURSE)
    set(recurse "RECURSE")
  else()
    unset(recurse)
  endif()

  if(DEFINED _CONFIGURE_EXTENSIONS)
    set(configureExtensions ${_CONFIGURE_EXTENSIONS})
  else()
    set(configureExtensions ".in")
  endif()
  foreach(extension ${configureExtensions})
    check_name_with_file_extension_rules("${extension}" checkPassed)
    if(NOT checkPassed)
      message(SEND_ERROR "Undesirable extension(${extension}).")
      return()
    endif()
  endforeach()

  if(NOT DEFINED _GENERATED_DIRECTORY)
    set(generatedDirectory "${currentBinaryDirectory}")
  elseif(NOT IS_ABSOLUTE "${_GENERATED_DIRECTORY}")
    set(generatedDirectory "${currentBinaryDirectory}/${_GENERATED_DIRECTORY}")
  else()
    set(generatedDirectory "${_GENERATED_DIRECTORY}")
  endif()
  if(NOT IS_ABSOLUTE "${generatedDirectory}")
    message(SEND_ERROR "Undesirable GENERATED_DIRECTORY(${_GENERATED_DIRECTORY}).")
    return()
  endif()

  set(installExtensions ${_INSTALL_EXTENSIONS})
  if(_C)
    list(APPEND installExtensions ".h")
  endif()
  if(_CXX)
    list(APPEND installExtensions ".H" ".hh" ".hpp" ".hxx" ".inl")
  endif()
  foreach(extension ${installExtensions})
    check_name_with_file_extension_rules("${extension}" checkPassed)
    if(NOT checkPassed)
      message(SEND_ERROR "Undesirable extension(${extension}).")
      return()
    endif()
  endforeach()

  if(NOT DEFINED _INSTALL_DIRECTORY)
    set(installDirectory "${currentInstallDirectory}")
  elseif(NOT IS_ABSOLUTE "${_INSTALL_DIRECTORY}")
    set(installDirectory "${currentInstallDirectory}/${_INSTALL_DIRECTORY}")
  else()
    set(installDirectory "${_INSTALL_DIRECTORY}")
  endif()
  if(NOT IS_ABSOLUTE "${installDirectory}")
    message(SEND_ERROR "Undesirable INSTALL_DIRECTORY(${_INSTALL_DIRECTORY}).")
    return()
  endif()

  aux_source_directory_with_group(
    SOURCE_VARIABLE   ${_SOURCE_VARIABLE}
    SOURCE_DIRECTORY "${sourceDirectory}"
    SOURCE_EXTENSIONS ${sourceExtensions}
    GROUP_DIRECTORY  "${groupDirectory}"
    ${recurse}
  )

  if(_CONFIGURE)
    aux_source_directory_with_group_and_config(
      SOURCE_VARIABLE      ${_SOURCE_VARIABLE}
      SOURCE_DIRECTORY    "${sourceDirectory}"
      SOURCE_EXTENSIONS    ${configureExtensions}
      GROUP_DIRECTORY     "${groupDirectory}"
      GENERATED_DIRECTORY "${generatedDirectory}"
      ${recurse}
    )
  endif()

  if(_INSTALL)
    aux_source_directory_with_install(
      SOURCE_DIRECTORY  "${sourceDirectory}"
      SOURCE_EXTENSIONS  ${installExtensions}
      INSTALL_DIRECTORY "${installDirectory}"
      ${recurse}
    )
  endif()

  if( _CONFIGURE AND _INSTALL)
    aux_source_directory_with_install(
      SOURCE_DIRECTORY  "${generatedDirectory}"
      SOURCE_EXTENSIONS  ${installExtensions}
      INSTALL_DIRECTORY "${installDirectory}"
      ${recurse}
    )
  endif()

  list(REMOVE_DUPLICATES ${_SOURCE_VARIABLE})
  set(${_SOURCE_VARIABLE} ${${_SOURCE_VARIABLE}} PARENT_SCOPE)
endfunction()
