# zhengrr
# 2017-12-18 – 2018-10-12
# The Unlicense

include_guard()

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

if(NOT COMMAND add_subdirectory_ex)
  include("${CMAKE_CURRENT_LIST_DIR}/AddSubdirEx.cmake")
endif()

# .rst
# .. command:: aux_add_subdirectories
#
#   查找目录中的所有子目录，并尝试添加到构建::
#
#     aux_add_subdirectories(
#                            [WITH_OPTION]
#                            [OPTION_NAME_PREFIX option-name-prefix]
#                            [OPTION_NAME_SUFFIX option-name-suffix]
#                            [OPTION_INITIAL_ON]
#                [PRIORITIES <sub-directory>...]
#     )
function(aux_add_subdirectories)
  set(zOptKws    WITH_OPTION
                 OPTION_INITIAL_ON)
  set(zOneValKws OPTION_NAME_PREFIX
                 OPTION_NAME_SUFFIX)
  set(zMutValKws PRIORITIES)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
  endif()

  if(_WITH_OPTION)
    set(_WITH_OPTION WITH_OPTION)
  else()
    set(_WITH_OPTION)
  endif()

  if(DEFINED _OPTION_NAME_PREFIX)
    set(_OPTION_NAME_PREFIX OPTION_NAME_PREFIX "${_OPTION_NAME_PREFIX}")
  endif()

  if(DEFINED _OPTION_NAME_SUFFIX)
    set(_OPTION_NAME_SUFFIX OPTION_NAME_SUFFIX "${_OPTION_NAME_SUFFIX}")
  endif()

  if(_OPTION_INITIAL_ON)
    set(_OPTION_INITIAL_ON OPTION_INITIAL_ON)
  else()
    set(_OPTION_INITIAL_ON)
  endif()

  set(sDir "${CMAKE_CURRENT_LIST_DIR}")
  file(GLOB zRelFiles RELATIVE "${sDir}" "${sDir}/*")

  if(DEFINED _PRIORITIES)
    list(LENGTH _PRIORITIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword PRIORITIES is used, but without value.")
    endif()
    foreach(sSubDir ${_PRIORITIES})
      if(NOT sSubDir IN_LIST zRelFiles)
        message(WARNING "A priority-sub-directory doesn't exist: ${sSubDir}.")
      endif()
    endforeach()
    list(INSERT zRelFiles 0 ${_PRIORITIES})
    list(REMOVE_DUPLICATES zRelFiles)
  endif()

  foreach(sRelDir IN LISTS zRelFiles)
    if(NOT IS_DIRECTORY "${sDir}/${sRelDir}")
      continue()
    endif()
    if(NOT EXISTS "${sDir}/${sRelDir}/CMakeLists.txt")
      continue()
    endif()
    add_subdirectory_ex("${sRelDir}" ${_WITH_OPTION} ${_OPTION_NAME_PREFIX} ${_OPTION_NAME_SUFFIX} ${_OPTION_INITIAL_ON})
  endforeach()
endfunction()
