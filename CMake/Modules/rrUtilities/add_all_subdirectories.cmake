#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___                2017-12-18 – 2018-1-4
# | '__| '__| | | | __| | | | __| |/ _ / __|                     The MIT License
# | |  | |  | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   \___/ \__|_|_|_|\__|_|\___|___/ rrUtilities by FIGlet
#             _     _           _         _ _               _
#    __ _  __| | __|  ___ _   _| |__   __| (_)_ __ ___  ___| |_ ___  _ __ _   _
#   / _` |/ _` |/ _` / __| | | | '_ \ / _` | | '__/ _ \/ __| __/ _ \| '__| | | |
#  | (_| | (_| | (_| \__ | |_| | |_) | (_| | | | |  __| (__| || (_) | |  | |_| |
#   \__,_|\__,_|\__,_|___/\__,_|_.__/ \__,_|_|_|  \___|\___|\__\___/|_|   \__, |
#                                              add_subdirectory by FIGlet |___/

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

# .rst
# .. command:: add_all_subdirectories
#
#    将目录下所有子目录添加到构建 ::
#
#       add_all_subdirectories(
#         [parent_directory_of_source_directories]
#         [parent_directory_of_binary_directories]
#         [EXCLUDE_FROM_ALL]
#       )
#
#    参见
#
#    + `add_subdirectory <https://cmake.org/cmake/help/latest/command/add_subdirectory>`_
#
function(add_all_subdirectories)
  set(options "EXCLUDE_FROM_ALL")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${options}" "" "")

  list(LENGTH _UNPARSED_ARGUMENTS unparsedArgumentsCount)
  set(_SOURCE_PARENT_DIRECTORY)
  set(_BINARY_PARENT_DIRECTORY)

  if(unparsedArgumentsCount GREATER 0)
    list(GET _UNPARSED_ARGUMENTS 0 _SOURCE_PARENT_DIRECTORY)
  endif()
  if(unparsedArgumentsCount GREATER 1)
    list(GET _UNPARSED_ARGUMENTS 1 _BINARY_PARENT_DIRECTORY)
  endif()
  if(unparsedArgumentsCount GREATER 2)
    message(SEND_ERROR "Incorrect number of arguments.")
    return()
  endif()

  if(DEFINED _SOURCE_PARENT_DIRECTORY)
    set(sourceParentDirectory "${_SOURCE_PARENT_DIRECTORY}")
  else()
    set(sourceParentDirectory "${CMAKE_CURRENT_LIST_DIR}")
  endif()
  file(GLOB directories
    LIST_DIRECTORIES TRUE RELATIVE "${sourceParentDirectory}"
    "${sourceParentDirectory}/*")

  if(_EXCLUDE_FROM_ALL)
    set(excludeFromAll "EXCLUDE_FROM_ALL")
  else()
    set(excludeFromAll)
  endif()

  foreach(directory IN LISTS directories)
    if(IS_DIRECTORY "${sourceParentDirectory}/${directory}")
      if(DEFINED _SOURCE_PARENT_DIRECTORY)
        set(sourceDirectory "${_SOURCE_PARENT_DIRECTORY}/${directory}")
      else()
        set(sourceDirectory "${directory}")
      endif()

      if(DEFINED _BINARY_PARENT_DIRECTORY)
        set(binaryDirectory "${_BINARY_PARENT_DIRECTORY}/${directory}")
      else()
        set(binaryDirectory)
      endif()

      add_subdirectory("${sourceDirectory}" ${binaryDirectory} ${excludeFromAll})
    endif()
  endforeach()
endfunction()
