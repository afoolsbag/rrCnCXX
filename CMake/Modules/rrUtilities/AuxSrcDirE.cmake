# zhengrr
# 2016-10-08 – 2018-04-23
# The MIT License

if(NOT COMMAND check_name_with_cmake_recommend_variable_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CkNameCmakeVar.cmake")
endif()
if(NOT COMMAND check_name_with_file_extension_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CkNameFExt.cmake")
endif()

# .rst
# .. command:: aux_source_directory_enhanced
#
#    搜寻目录下指定文件（增强版）：
#    ::
#
#       aux_source_directory_enhanced(
#         <results-variable>
#         [RECURES] [C] [CXX] [MFC] [QT] [EXPLICIT]
#         [SOURCE_DIRECTORY]
#         [SOURCE_EXTENSIONS <extension>...]
#         [SOURCE_PROPERTIES <property-key property-value>...]
#         [SOURCE_GROUP <group-folder>]
#       )
#
function(aux_source_directory_enhanced _RESULTS_VARIABLE)
  set(zOptKws    "RECURSE"
                 "C" "CXX" "MFC" "QT"
                 "EXPLICIT")
  set(zOneValKws "SOURCE_DIRECTORY" "SOURCE_GROUP")
  set(zMutValKws "SOURCE_EXTENSIONS" "SOURCE_PROPERTIES")
  cmake_parse_arguments(PARSE_ARGV 1 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
    return()
  endif()

  if(NOT DEFINED _SOURCE_DIRECTORY)
    set(sSrcDir "${CMAKE_CURRENT_LIST_DIR}")
  elseif(NOT IS_ABSOLUTE "${_SOURCE_DIRECTORY}")
    set(sSrcDir "${CMAKE_CURRENT_LIST_DIR}/${_SOURCE_DIRECTORY}")
  else()
    set(sSrcDir "${_SOURCE_DIRECTORY}")
  endif()
  if(NOT IS_DIRECTORY "${sSrcDir}")
    message(WARNING "The path isn't directory: ${_SOURCE_DIRECTORY}.")
  endif()

  check_name_with_cmake_recommend_variable_rules("${_RESULTS_VARIABLE}" sCkPassed)
  if(NOT sCkPassed)
    message(WARNING "The variable isn't meet CMake recommend variable rules: ${_RESULTS_VARIABLE}.")
  endif()

  if(_RECURSE)
    set(sRecurse "GLOB_RECURSE")
  else()
    set(sRecurse "GLOB")
  endif()

  if(_EXPLICIT)
    set(zLangs)
  else()
    get_property(zLangs GLOBAL PROPERTY ENABLED_LANGUAGES)
  endif()
  set(zSrcExts)
  if(C IN_LIST zLangs OR _C)
    list(APPEND zSrcExts ".h" ".c" ".inl")
  endif()
  if(CXX IN_LIST zLangs OR _CXX)
    list(APPEND zSrcExts ".hpp" ".cpp" ".hh" ".cc" ".hxx" ".cxx" ".hp" ".cp"
                         ".HPP" ".CPP" ".H"  ".C"  ".h++" ".c++" ".h"  ".inl")
  endif()
  if(_MFC)
    list(APPEND zSrcExts ".h"   ".cpp" ".rc")
  endif()
  if(_QT)
    list(APPEND zSrcExts ".h"   ".cpp" ".ui")
  endif()
  if(DEFINED _SOURCE_EXTENSIONS)
    foreach(sSrcExt ${_SOURCE_EXTENSIONS})
      check_name_with_file_extension_rules("${sSrcExt}" sCkPassed)
      if(NOT sCkPassed)
        message(SEND_ERROR "Undesirable extension: ${sSrcExt}.")
        continue()
      endif()
      list(APPEND zSrcExts "${sSrcExt}")
    endforeach()
  endif()
  list(REMOVE_DUPLICATES zSrcExts)

  if(DEFINED _SOURCE_GROUP)
    set(sSrcGrp "${_SOURCE_GROUP}")
  else()
    set(sSrcGrp)
  endif()

  set(zRsts)
  foreach(sSrcExt ${zSrcExts})
    file(${sRecurse} zSrcFilePaths "${sSrcDir}/*${sSrcExt}")
    foreach(sSrcFilePath ${zSrcFilePaths})
      get_filename_component(sSrcFileDir "${sSrcFilePath}" DIRECTORY)
      file(RELATIVE_PATH sSrcFileRelDir "${sSrcDir}" "${sSrcFileDir}")
      string(REPLACE "/" "\\\\" sSrcFileGrp "${sSrcGrp}${sSrcFileRelDir}")
      list(APPEND zRsts "${sSrcFilePath}")
      source_group("${sSrcFileGrp}" FILES "${sSrcFilePath}")
    endforeach()
  endforeach()
  if(DEFINED _SOURCE_PROPERTIES)
    list(LENGTH _SOURCE_PROPERTIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword SOURCE_PROPERTIES is used, but without value.")
    endif()
    set_source_files_properties(${zRsts} PROPERTIES ${_SOURCE_PROPERTIES})
  endif()

  set(${_RESULTS_VARIABLE} ${zRsts} PARENT_SCOPE)
endfunction()
