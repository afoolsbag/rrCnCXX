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

include("${CMAKE_CURRENT_LIST_DIR}/check_name_with_cmake_recommend_variable_rules.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/check_name_with_file_extension_rules.cmake")

# .rst
# .. command:: aux_source_directory_with_group
#
#  查找目录下所有指定文件并分组::
#
#   aux_source_directory_with_group(
#     <SOURCE_VARIABLE   source_variable>
#     <SOURCE_DIRECTORY  source_directory>
#     <SOURCE_EXTENSIONS source_extensions...>
#     <GROUP_DIRECTORY   group_directory>
#     [RECURSE]
#   )
function(aux_source_directory_with_group)
  set(options "RECURSE")
  set(oneValueKeywords "SOURCE_VARIABLE" "SOURCE_DIRECTORY" "GROUP_DIRECTORY")
  set(multiValueKeywords "SOURCE_EXTENSIONS")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${options}" "${oneValueKeywords}" "${multiValueKeywords}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED _SOURCE_VARIABLE)
    message(SEND_ERROR "Missing argument SOURCE_VARIABLE.")
    return()
  endif()
  check_name_with_cmake_recommend_variable_rules("${_SOURCE_VARIABLE}" checkPassed)
  if(NOT checkPassed)
    message(SEND_ERROR "Undesirable argument SOURCE_VARIABLE(${_SOURCE_VARIABLE}).")
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

  if(_RECURSE)
    set(recurse "GLOB_RECURSE")
  else()
    set(recurse "GLOB")
  endif()

  foreach(extension ${_SOURCE_EXTENSIONS})
    file(${recurse} files "${_SOURCE_DIRECTORY}/*${extension}")
    foreach(file ${files})
      # append file
      list(APPEND ${_SOURCE_VARIABLE} "${file}")
      # group file
      get_filename_component(fileDirectory "${file}" DIRECTORY)
      string(REGEX REPLACE "^${_SOURCE_DIRECTORY}" "" relativePath "${fileDirectory}")
      string(REPLACE "/" "\\\\" fileGroupDirectory "${_GROUP_DIRECTORY}${relativePath}")
      source_group("${fileGroupDirectory}" FILES "${file}")
    endforeach()
  endforeach()

  list(REMOVE_DUPLICATES ${_SOURCE_VARIABLE})
  set(${_SOURCE_VARIABLE} ${${_SOURCE_VARIABLE}} PARENT_SCOPE)
endfunction()
