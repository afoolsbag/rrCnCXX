# zhengrr
# 2016-10-08 – 2018-10-25
# The Unlicense

include_guard()

if(NOT COMMAND check_name_with_cmake_rules OR
   NOT COMMAND check_name_with_fext_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CkName.cmake")
endif()

# .rst
# .. command:: aux_source_directory_ex
#
#   查找目录中的所有源文件（附加功能）::
#
#     aux_source_directory_ex(
#       <results-variable>
#       [DIRECTORY    <directory>]     default: "${CMAKE_CURRENT_LIST_DIR}"
#
#       [RECURES]
#
#       [EXPLICIT]
#       [C] [CXX] [MFC] [QT] [CFG]
#       [EXTENSIONS   <extension>...]
#
#       [BASE_MATCHES <regex>]
#       [BASE_CLASHES <regex>]
#
#       [GROUP_ROOT   <group-root>]
#
#       [PROPERTIES   <property-key property-value>...]
#       [PCH_NAME     <pch-name>]      default: MFC ? "mfc" : NULL
#       [PCH_HEADER]  <pch-header>]    default: MFC ? "stdafx.h" : NULL
#       [PCH_SOURCE]  <pch-source>]    default: MFC ? "stdafx.cpp" : NULL
#     )
function(aux_source_directory_ex _RESULTS_VARIABLE)
  set(zOptKws    RECURSE
                 EXPLICIT
                 C CXX MFC QT CFG)
  set(zOneValKws DIRECTORY
                 BASE_MATCHES
                 BASE_CLASHES
                 GROUP_ROOT
                 PCH_NAME
                 PCH_HEADER
                 PCH_SOURCE)
  set(zMutValKws EXTENSIONS
                 PROPERTIES)
  cmake_parse_arguments(PARSE_ARGV 1 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
  endif()

  check_name_with_cmake_rules("${_RESULTS_VARIABLE}" WARNING)

  if(NOT DEFINED _DIRECTORY)
    set(_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")
  elseif(NOT IS_ABSOLUTE "${_DIRECTORY}")
    set(_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/${_DIRECTORY}")
  endif()
  if(NOT IS_DIRECTORY "${_DIRECTORY}")
    message(WARNING "The path isn't directory: ${_DIRECTORY}.")
  endif()

  if(_RECURSE)
    set(_RECURSE GLOB_RECURSE)
  else()
    set(_RECURSE GLOB)
  endif()

  get_property(zLangs GLOBAL PROPERTY ENABLED_LANGUAGES)
  set(zExts)
  if(_C OR ((NOT _EXPLICIT) AND (C IN_LIST zLangs)))
    list(APPEND zExts ".h"   ".c"   ".inl")
  endif()
  if(_CXX OR ((NOT _EXPLICIT) AND (CXX IN_LIST zLangs)))
    list(APPEND zExts ".hpp" ".cpp" ".hh"  ".cc"  ".hxx" ".cxx" ".hp"  ".cp"
                      ".HPP" ".CPP" ".H"   ".C"   ".h++" ".c++" ".h"   ".inl")
  endif()
  if(_MFC)
    list(APPEND zExts ".h"   ".cpp"
                      ".rc"  ".rc2" ".bmp" ".cur" ".ico")
    if(NOT DEFINED _PCH_NAME)
      set(_PCH_NAME "mfc")
    endif()
    if(NOT DEFINED _PCH_HEADER)
      set(_PCH_HEADER "stdafx.h")
    endif()
    if(NOT DEFINED _PCH_SOURCE)
      set(_PCH_SOURCE "stdafx.cpp")
    endif()
  endif()
  if(_QT)
    list(APPEND zExts ".h"   ".cpp"
                      ".qml" ".qrc" ".ui")
  endif()
  if(_CFG OR (NOT _EXPLICIT))
    list(APPEND zExts ".in"  ".dox")
  endif()
  if(DEFINED _EXTENSIONS)
    foreach(sExt ${_EXTENSIONS})
      check_name_with_fext_rules("${sExt}" SEND_ERROR)
      list(APPEND zExts "${sExt}")
    endforeach()
  endif()
  list(REMOVE_DUPLICATES zExts)

  set(zResults)
  foreach(sExt ${zExts})
    file(${_RECURSE} zExtFiles "${_DIRECTORY}/*${sExt}")
    foreach(sExtFile ${zExtFiles})

      if (DEFINED _BASE_MATCHES OR DEFINED _BASE_CLASHES)
        get_filename_component(sExtFileName "${sExtFile}" NAME)
        string(REGEX REPLACE "${sExt}$" "" sExtFileBase "${sExtFileName}")
        if(DEFINED _BASE_MATCHES AND (NOT sExtFileBase MATCHES "${_BASE_MATCHES}"))
          continue()
        endif()
        if(DEFINED _BASE_CLASHES AND sExtFileBase MATCHES "${_BASE_CLASHES}")
          continue()
        endif()
      endif()

      get_filename_component(sExtFileDir "${sExtFile}" DIRECTORY)
      file(RELATIVE_PATH sExtFileRelDir "${_DIRECTORY}" "${sExtFileDir}")
      string(REPLACE "/" "\\\\" sExtFileGrp "${_GROUP_ROOT}${sExtFileRelDir}")

      list(APPEND zResults "${sExtFile}")
      source_group("${sExtFileGrp}" FILES "${sExtFile}")

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

  if(_PCH_NAME AND _PCH_HEADER AND _PCH_SOURCE)
    set(sPchFile "${CMAKE_CURRENT_BINARY_DIR}/${_PCH_NAME}$<$<CONFIG:Debug>:d>.pch")
    foreach(sFile ${zResults})
      if(NOT sFile MATCHES ".*\\.(c|cpp|cc|cxx|cp|CPP|C|c\\+\\+)$")
        continue()
      endif()
      get_filename_component(sFileName "${sFile}" NAME)
      if(sFileName STREQUAL _PCH_SOURCE)
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

  set(${_RESULTS_VARIABLE} ${zResults} PARENT_SCOPE)
endfunction()
