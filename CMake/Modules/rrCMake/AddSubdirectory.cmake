# zhengrr
# 2017-12-18 – 2019-04-17
# Unlicense

cmake_minimum_required(VERSION 3.10)
cmake_policy(VERSION 3.10)

include_guard()

if(NOT COMMAND check_name_with_cmake_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CheckName.cmake")
endif()

#.rst:
# .. command:: add_subdirectory_con
#
#   添加子目录到构建（add subdirectory），遵循惯例（convention）。
#
#   .. code-block:: cmake
#
#     add_subdirectory_con(
#       <argument>...
#       [PREFIX <option-prefix>]
#     )
#
#   参见：
#
#   - `add_subdirectory <https://cmake.org/cmake/help/latest/command/add_subdirectory.html>`_
function(add_subdirectory_con _SOURCE_DIRECTORY)
  set(zOneValKws PREFIX)
  cmake_parse_arguments(PARSE_ARGV 1 "" "" "${zOneValKws}" "")

  string(TOUPPER ${_SOURCE_DIRECTORY} _SOURCE_DIRECTORY_UPPER)

  set(vOptName ${_SOURCE_DIRECTORY_UPPER})
  if(DEFINED _PREFIX)
    set(vOptName ${_PREFIX}_${vOptName})
  endif()

  check_name_with_cmake_rules("${vOptName}" WARNING)

  option(${vOptName} "Sub-directory ${_SOURCE_DIRECTORY}." OFF)
  if(NOT ${vOptName})
    return()
  endif()

  add_subdirectory(${_SOURCE_DIRECTORY} ${_UNPARSED_ARGUMENTS})
endfunction()

# .rst
# .. command:: add_aux_subdirectories_con
#
#   搜集当前目录的子目录并加入构建（add auxiliary subdirectories），遵循惯例（convention）。
#
#   .. code-block:: cmake
#
#     add_aux_subdirectories_con(
#       <argument>...
#     )
function(add_aux_subdirectories_con)
  file(
    GLOB     zSubDirs
    RELATIVE "${CMAKE_CURRENT_LIST_DIR}"
             "${CMAKE_CURRENT_LIST_DIR}/*"
  )

  foreach(sSubDir IN LISTS zSubDirs)
    if(NOT IS_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/${sSubDir}")
      continue()
    endif()
    if(NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/${sSubDir}/CMakeLists.txt")
      continue()
    endif()
    add_subdirectory_con("${sSubDir}" ${ARGV})
  endforeach()
endfunction()
