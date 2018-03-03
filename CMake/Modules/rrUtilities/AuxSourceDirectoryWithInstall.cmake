# zhengrr
# 2016-10-8 – 2018-1-30
# The MIT License

include("${CMAKE_CURRENT_LIST_DIR}/CkNameFExt.cmake")

# .rst
# .. command:: aux_source_directory_with_install
#
#  查找目录下所有指定文件并安装::
#
#   aux_source_directory_with_install(
#     <SOURCE_DIRECTORY  source_directory>
#     <SOURCE_EXTENSIONS source_extensions...>
#     <INSTALL_DIRECTORY install_directory>
#     [RECURSE]
#   )
function(aux_source_directory_with_install)
  set(options "RECURSE")
  set(oneValueKeywords "SOURCE_DIRECTORY" "INSTALL_DIRECTORY")
  set(multiValueKeywords "SOURCE_EXTENSIONS")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${options}" "${oneValueKeywords}" "${multiValueKeywords}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED _SOURCE_DIRECTORY)
    message(SEND_ERROR "Missing argument SOURCE_DIRECTORY.")
    return()
  endif()
  if(NOT IS_DIRECTORY "${_SOURCE_DIRECTORY}")
    message(SEND_ERROR "Undesirable argument SOURCE_DIRECTORY(${_SOURCE_DIRECTORY}).")
    return()
  endif()

  if(NOT DEFINED _SOURCE_EXTENSIONS)
    message(SEND_ERROR "Missing argument SOURCE_EXTENSIONS.")
    return()
  endif()
  list(REMOVE_DUPLICATES _SOURCE_EXTENSIONS)
  foreach(extension ${_SOURCE_EXTENSIONS})
    check_name_with_file_extension_rules("${extension}" checkPassed)
    if(NOT checkPassed)
      message(SEND_ERROR "Undesirable extension(${extension}).")
      return()
    endif()
  endforeach()

  if(NOT DEFINED _INSTALL_DIRECTORY)
    message(SEND_ERROR "Missing INSTALL_DIRECTORY.")
    return()
  endif()
  if(NOT IS_ABSOLUTE "${_INSTALL_DIRECTORY}")
    message(SEND_ERROR "Undesirable argument INSTALL_DIRECTORY(${_INSTALL_DIRECTORY}).")
    return()
  endif()

  if(_RECURSE)
    set(recurse "GLOB_RECURSE")
  else()
    set(recurse "GLOB")
  endif()

  foreach(extension ${_SOURCE_EXTENSIONS})
    file(${recurse} files "${_SOURCE_DIRECTORY}/*${extension}")
    foreach(file ${files})
      # install file
      get_filename_component(fileDirectory "${file}" DIRECTORY)
      string(REGEX REPLACE "^${_SOURCE_DIRECTORY}" "" relativePath "${fileDirectory}")
      install(FILES "${file}" DESTINATION "${_INSTALL_DIRECTORY}${relativePath}")
    endforeach()
  endforeach()
endfunction()
