# zhengrr
# 2017-12-18 – 2018-1-31
# The MIT License

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

# .rst
# .. command:: add_all_subdirectories
#
#    将目录下所有子目录添加到构建：
#    ::
#
#       add_all_subdirectories(
#         [parent_directory_of_source_directories]
#         [parent_directory_of_binary_directories]
#         [EXCLUDE_FROM_ALL]
#       )
#
#    参见：
#
#    + `"list" <https://cmake.org/cmake/help/latest/command/list>`_. *CMake Documentation*.
#    + `"add_subdirectory" <https://cmake.org/cmake/help/latest/command/add_subdirectory>`_. *CMake Documentation*.
#
function(add_all_subdirectories)
  unset(_SOURCE_PARRENT_DIRECTORY)
  unset(_BINARY_PARRENT_DIRECTORY)
  set(zOptKws "EXCLUDE_FROM_ALL")
  set(zOneValKws)
  set(zMutValKws)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  list(LENGTH _UNPARSED_ARGUMENTS sUArgCnt)
  if(sUArgCnt GREATER 0)
    list(GET _UNPARSED_ARGUMENTS 0 _SOURCE_PARRENT_DIRECTORY)
  endif()
  if(sUArgCnt GREATER 1)
    list(GET _UNPARSED_ARGUMENTS 1 _BINARY_PARRENT_DIRECTORY)
  endif()
  if(sUArgCnt GREATER 2)
    message(SEND_ERROR "Incorrect number of arguments \"${ARGN}\".")
    return()
  endif()

  if(DEFINED _SOURCE_PARRENT_DIRECTORY)
    set(sDir "${_SOURCE_PARRENT_DIRECTORY}")
  else()
    set(sDir "${CMAKE_CURRENT_LIST_DIR}")
  endif()
  file(GLOB zRelFiles RELATIVE "${sDir}" "${sDir}/*")

  if(_EXCLUDE_FROM_ALL)
    set(sExcludeFromAll "EXCLUDE_FROM_ALL")
  else()
    set(sExcludeFromAll)
  endif()

  foreach(sRelDir IN LISTS zRelFiles)
    if(NOT IS_DIRECTORY "${sDir}/${sRelDir}")
      continue()
    endif()

    if(DEFINED _SOURCE_PARENT_DIRECTORY)
      set(sSrcDir "${_SOURCE_PARENT_DIRECTORY}/${sRelDir}")
    else()
      set(sSrcDir "${sRelDir}")
    endif()

    if(DEFINED _BINARY_PARENT_DIRECTORY)
      set(sBinDir "${_BINARY_PARENT_DIRECTORY}/${sRelDir}")
    else()
      set(sBinDir)
    endif()

    add_subdirectory("${sSrcDir}" ${sBinDir} ${sExcludeFromAll})
  endforeach()
endfunction()
