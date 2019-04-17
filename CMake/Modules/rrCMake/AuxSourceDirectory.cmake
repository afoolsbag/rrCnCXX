# zhengrr
# 2016-10-08 – 2019-04-16
# Unlicense

cmake_minimum_required(VERSION 3.14)
cmake_policy(VERSION 3.14)

include_guard()

if(NOT COMMAND check_name_with_fext_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CheckName.cmake")
endif()

#-------------------------------------------------------------------------------
# FUNCTIONS

#.rst
# .. command:: aux_source_directory_ex
#
#   搜集目录中的源文件（auxiliary source directory），扩展功能（extend）。
#
#   .. code-block:: cmake
#
#     aux_source_directory_ex(
#       <directory> <variable>
#
#       [RECURES]
#
#       [MATCHES    <regex>...]
#       [CLASHES    <regex>...]
#
#       [EXPLICIT]
#       [EXTENSIONS <extensions...>]
#
#       [FLAT]
#       [PREFIX     <group-prefix>]
#
#       [PROPERTIES <property-key> <property-value> ...]
#     )
#
#   参见：
#
#   - `aux_source_directory <https://cmake.org/cmake/help/latest/command/aux_source_directory.html>`_
#   - `file <https://cmake.org/cmake/help/latest/command/file.html>`_
#   - `source_group <https://cmake.org/cmake/help/latest/command/source_group.html>`_
#   - `set_source_files_properties <https://cmake.org/cmake/help/latest/command/set_source_files_properties.html>`_
function(aux_source_directory_ex _DIRECTORY _VARIABLE)
  set(zOptKws    RECURSE
                 EXPLICIT
                 FLAT)
  set(zOneValKws PREFIX)
  set(zMutValKws MATCHES
                 CLASHES
                 EXTENSIONS
                 PROPERTIES)
  cmake_parse_arguments(PARSE_ARGV 2 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
  endif()

  if(NOT IS_ABSOLUTE "${_DIRECTORY}")
    set(_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/${_DIRECTORY}")
  endif()
  if(NOT IS_DIRECTORY "${_DIRECTORY}")
    message(WARNING "The path isn't a directory: ${_DIRECTORY}.")
  endif()

  if(_RECURSE)
    set(_RECURSE GLOB_RECURSE)
  else()
    set(_RECURSE GLOB)
  endif()

  set(zExts)
  if(NOT _EXPLICIT)
    list(APPEND zExts ".in"  ".dox")
    get_property(zLangs GLOBAL PROPERTY ENABLED_LANGUAGES)
    if(C IN_LIST zLangs)
      list(APPEND zExts ".h"   ".c"   ".inl")
    endif()
    if(CXX IN_LIST zLangs)
      list(APPEND zExts ".hpp" ".cpp" ".hh"  ".cc"  ".hxx" ".cxx" ".hp"  ".cp"
                        ".HPP" ".CPP" ".H"   ".C"   ".h++" ".c++" ".h"   ".inl")
    endif()
  endif()
  if(DEFINED _EXTENSIONS)
    foreach(sExt ${_EXTENSIONS})
      check_name_with_fext_rules("${sExt}" SEND_ERROR)
      list(APPEND zExts "${sExt}")
    endforeach()
  endif()
  list(REMOVE_DUPLICATES zExts)

  if(NOT DEFINED _PREFIX)
    set(_PREFIX "/")
  endif()

  set(zResults)
  foreach(sExt ${zExts})
    file(${_RECURSE} zFiles CONFIGURE_DEPENDS "${_DIRECTORY}/*${sExt}")
    foreach(sFile IN LISTS zFiles)
      if(DEFINED _MATCHES OR DEFINED _CLASHES)
        get_filename_component(sBase "${sFile}" NAME_WLE)

        if(DEFINED _MATCHES)
          set(sPass FALSE)
          foreach(sRegex IN LISTS _MATCHES)
            if(sBase MATCHES "${sRegex}")
              set(sPass TRUE)
              break()
            endif()
          endforeach()
          if(NOT sPass)
            continue()
          endif()
        endif()

        if(DEFINED _CLASHES)
          set(sPass TRUE)
          foreach(sRegex IN LISTS _CLASHES)
            if(sBase MATCHES "${sRegex}")
              set(sPass FALSE)
              break()
            endif()
          endforeach()
          if(NOT sPass)
            continue()
          endif()
        endif()
      endif()

      if(_FLAT)
        source_group("${_PREFIX}" FILES "${sFile}")
      else()
        source_group(TREE "${_DIRECTORY}" PREFIX "${_PREFIX}" FILES "${sFile}")
      endif()

      list(APPEND zResults "${sFile}")

    endforeach()
  endforeach()
  if(zResults)
    list(REMOVE_DUPLICATES zResults)
  endif()

  if(DEFINED _PROPERTIES)
    list(LENGTH _PROPERTIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword PROPERTIES is used, but without value.")
    endif()
    set_source_files_properties(${zResults} PROPERTIES ${_PROPERTIES})
  endif()

  set(${_VARIABLE} ${zResults} PARENT_SCOPE)
endfunction()

#.rst
# .. command:: aux_source_directory_con
#
#   搜集目录中的源文件（aux source directory），遵循惯例（convention）。
#
#   .. code-block:: cmake
#
#     aux_source_directory_con(
#       <arguments...>
#       [C] [CXX] [MFC] [QT] [CFG]
#       [PCH_NAME   <pch-name>}]
#       [PCH_HEADER <pch-header>]
#       [PCH_SOURCE <pch-source>]
#     )
#
#   参见：
#
#   - :command:`aux_source_directory_con`
function(aux_source_directory_con _DIRECTORY _VARIABLE)
  set(zOptKws    C CXX MFC QT CFG)
  set(zMutValKws EXTENSIONS)
  cmake_parse_arguments(PARSE_ARGV 2 "" "${zOptKws}" "" "${zMutValKws}")

  list(INSERT _EXTENSIONS 0 EXTENSIONS)
  if(_C)
    list(APPEND _EXTENSIONS ".h"   ".c"   ".inl")
  endif()
  if(_CXX)
    list(APPEND _EXTENSIONS ".hpp" ".cpp" ".hh"  ".cc"  ".hxx" ".cxx" ".hp"  ".cp"
                            ".HPP" ".CPP" ".H"   ".C"   ".h++" ".c++" ".h"   ".inl")
  endif()
  if(_MFC)
    list(APPEND _EXTENSIONS ".h"   ".cpp"
                            ".rc"  ".rc2" ".bmp" ".cur" ".ico")
  endif()
  if(_QT)
    list(APPEND _EXTENSIONS ".h"   ".cpp" ".ui"
                            ".qrc" ".qml" ".ts")
  endif()
  if(_CFG)
    list(APPEND _EXTENSIONS ".in"  ".dox")
  endif()
  list(REMOVE_DUPLICATES _EXTENSIONS)

  # aux_source_directory_ex
  aux_source_directory_ex(
    ${_DIRECTORY} ${_VARIABLE} ${_UNPARSED_ARGUMENTS}
    ${_EXPLICIT}
    ${_EXTENSIONS}
  )
  set(${_VARIABLE} ${${_VARIABLE}} PARENT_SCOPE)

  if(_MFC)
    if(NOT DEFINED _PCH_NAME)
      set(_PCH_NAME ${PROJECT_NAME})
    endif()
    if(NOT DEFINED _PCH_HEADER)
      set(_PCH_HEADER "stdafx.h")
    endif()
    if(NOT DEFINED _PCH_SOURCE)
      set(_PCH_SOURCE "stdafx.cpp")
    endif()
  endif()

  if(_PCH_NAME AND _PCH_HEADER AND _PCH_SOURCE)
    set(sPchFile "${CMAKE_CURRENT_BINARY_DIR}/${_PCH_NAME}$<$<CONFIG:Debug>:d>.pch")
    foreach(sFile ${${_VARIABLE}})
      if(NOT sFile MATCHES ".*\\.(c|cpp|cc|cxx|cp|CPP|C|c\\+\\+)$")
        continue()
      endif()
      get_filename_component(sName "${sFile}" NAME)
      if(sName STREQUAL _PCH_SOURCE)
        set_source_files_properties(
          ${sFile}
          PROPERTIES COMPILE_FLAGS  "/Yc\"${_PCH_HEADER}\" /Fp\"${sPchFile}\""
                     OBJECT_OUTPUTS "${sPchFile}")
      else()
        set_source_files_properties(
          ${sFile}
          PROPERTIES COMPILE_FLAGS  "/Yu\"${_PCH_HEADER}\" /FI\"${_PCH_HEADER}\" /Fp\"${sPchFile}\""
                     OBJECT_DEPENDS "${sPchFile}")
      endif()
    endforeach()
  endif()
endfunction()
