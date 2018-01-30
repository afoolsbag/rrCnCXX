# zhengrr
# 2016-10-8 – 2018-1-30
# The MIT License

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

# .rst
# .. command:: quick_add_doxygen_with_option
#
#    轻快生成Doxygen文档：
#    ::
#
#       quick_add_doxygen_with_option(
#          [API | DEV]
#          [OPTIMIZE_OUTPUT_FOR_C]
#       )
#
#    缓存变量：
#    ::
#
#       DOXYGEN_DOT_PATH
#       DOXYGEN_PLANTUML_JAR_PATH
#
#    影响：
#
#    :option:           ``<PROJECT_NAME_UPPER>_GENERATE_[DEV|API]DOC``
#    :doxygen_add_docs: ``<PROJECT_NAME_LOWER>_[dev|api]doc``
#    :install:          ``<PROJECT_BINARY_DIR>/doxygen`` to ``docs/<PROJECT_NAME>``
#
#    参见：
#
#    + `"FindDoxygen" <https://cmake.org/cmake/help/latest/module/FindDoxygen>`_. *CMake Documentation*.
#    + `"Configuration" <http://doxygen.org/manual/config.html>`_. *Doxygen Manual*.
#    + `"install" <https://cmake.org/cmake/help/latest/command/install>`_. *CMake Documentation*.
#
function(quick_add_doxygen_with_option)
  set(zOpts "API" "DEV" "OPTIMIZE_OUTPUT_FOR_C")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOpts}" "" "")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments \"${_UNPARSED_ARGUMENTS}\".")
    return()
  endif()

  string(TOUPPER "${PROJECT_NAME}" sPrjNameUpr)
  string(TOLOWER "${PROJECT_NAME}" sPrjNameLwr)

  if(_DEV)
    set(sTxtName "developing documentation")
    set(vOptName "${sPrjNameUpr}_GENERATE_DEVDOC")
    set(vTgtName "${sPrjNameLwr}_devdoc")
  elseif(_API)
    set(sTxtName "API documentation")
    set(vOptName "${sPrjNameUpr}_GENERATE_APIDOC")
    set(vTgtName "${sPrjNameLwr}_apidoc")
  else()
    set(sTxtName "documentation")
    set(vOptName "${sPrjNameUpr}_GENERATE_DOC")
    set(vTgtName "${sPrjNameLwr}_doc")
  endif()

  find_package(Doxygen OPTIONAL_COMPONENTS dot)
  option(${vOptName} "Generate ${sTxtName} (requires Doxygen)." ${DOXYGEN_FOUND})
  if(NOT ${vOptName})
    return()
  endif()
  if(NOT DOXYGEN_FOUND)
    message(SEND_ERROR "Doxygen is needed to generate the ${sTxtName}.")
    return()
  endif()

  set(DOXYGEN_STRIP_FROM_PATH "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
  if(_OPTIMIZE_OUTPUT_FOR_C)
    set(OPTIMIZE_OUTPUT_FOR_C YES)
  endif()
  set(DOXYGEN_HTML_OUTPUT "doxygen")
  set(DOXYGEN_DOT_PATH "" CACHE FILEPATH "The path where the dot tool can be found.")
  set(DOXYGEN_PLANTUML_JAR_PATH "" CACHE FILEPATH "The path where java can find the plantuml.jar file.")
  doxygen_add_docs(${vTgtName}
    "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}"
    WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
    COMMENT "Generating ${sTxtName} with Doxygen.")

  install(DIRECTORY "${PROJECT_BINARY_DIR}/doxygen" DESTINATION "docs/${PROJECT_NAME}")
endfunction()
