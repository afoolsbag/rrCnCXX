# zhengrr
# 2017-12-18 – 2018-06-04
# The MIT License

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

if(NOT COMMAND facile_add_subdirectory)
  include("${CMAKE_CURRENT_LIST_DIR}/FacileAddSubdir.cmake")
endif()

# .rst
# .. command:: aux_add_subdirectories
#
#    搜寻并加入子目录到构建：
#    ::
#
#       aux_add_subdirectories(
#         [WITH_OPTION]
#       )
#
function(aux_add_subdirectories)
  set(zOptKws    WITH_OPTION)
  set(zOneValKws)
  set(zMutValKws)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
    return()
  endif()

  if(_WITH_OPTION)
    set(sOpt)
  else()
    set(sOpt WITHOUT_OPTION)
  endif()

  set(sDir "${CMAKE_CURRENT_LIST_DIR}")
  file(GLOB zRelFiles RELATIVE "${sDir}" "${sDir}/*")

  foreach(sRelDir IN LISTS zRelFiles)
    if(NOT IS_DIRECTORY "${sDir}/${sRelDir}")
      continue()
    endif()
    if(NOT EXISTS "${sDir}/${sRelDir}/CMakeLists.txt")
      continue()
    endif()
    facile_add_subdirectory("${sRelDir}" ${sOpt})
  endforeach()
endfunction()
