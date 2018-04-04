# zhengrr
# 2016-10-08 – 2018-04-04
# The MIT License

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

# .rst
# .. command:: facile_add_doxygen
#
#    便捷加入Doxygen目标：
#    ::
#
#       facile_add_doxygen(
#         [JAVADOC_AUTOBRIEF]
#         [OPTIMIZE_OUTPUT_FOR_C]
#       )
#
#    缓存：
#    ::
#
#       DOXYGEN_DOT_PATH
#       DOXYGEN_PLANTUML_JAR_PATH
#
#    约定：
#
#    :NAME:             ``<PROJECT_NAME>``
#    :option:           ``<NAME_UPPER>_GENERATE_DOCUMENTATION``
#    :doxygen_add_docs: ``<NAME_LOWER>_documentation``
#    :input:            ``<PROJECT_SOURCE_DIR>`` and ``<PROJECT_BINARY_DIR>``
#    :output:           ``<PROJECT_BINARY_DIR>/doxygen``
#    :more doxygen cfg: see code
#    :install:          to ``docs/<NAME>``
#
#    参见：
#
#    + `"FindDoxygen" <https://cmake.org/cmake/help/latest/module/FindDoxygen>`_. *CMake Documentation*.
#    + `"Configuration" <http://doxygen.org/manual/config.html>`_. *Doxygen Manual*.
#
function(facile_add_doxygen)
  set(zOptKws "JAVADOC_AUTOBRIEF"
              "OPTIMIZE_OUTPUT_FOR_C")
  set(zOneValKws)
  set(zMutValKws)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments \"${_UNPARSED_ARGUMENTS}\".")
    return()
  endif()

  set(sName "${PROJECT_NAME}")
  string(TOUPPER "${sName}" sNameUpr)
  string(TOLOWER "${sName}" sNameLwr)

  # option
  set(vOptName "${sNameUpr}_GENERATE_DOCUMENTATION")

  if(NOT DOXYGEN_FOUND)
    find_package(Doxygen OPTIONAL_COMPONENTS dot)
  endif()
  if(NOT DOXYGEN_FOUND)
    message(WARNING "Doxygen is needed to generate doxygen documentation.")
  endif()

  option(${vOptName} "Generate documentation (requires Doxygen)." ${DOXYGEN_FOUND})
  if(NOT ${vOptName})
    return()
  endif()

  # Doxygen Configuration

  # Project related configuration options
  # YES       FULL_PATH_NAMES       http://doxygen.org/manual/config.html#cfg_full_path_names
  #           STRIP_FROM_PATH       http://doxygen.org/manual/config.html#cfg_strip_from_path
  set(DOXYGEN_STRIP_FROM_PATH       "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
  # NO        JAVADOC_AUTOBRIEF     http://doxygen.org/manual/config.html#cfg_javadoc_autobrief
  set(DOXYGEN_JAVADOC_AUTOBRIEF     "${_JAVADOC_AUTOBRIEF}")
  # NO        OPTIMIZE_OUTPUT_FOR_C http://doxygen.org/manual/config.html#cfg_optimize_output_for_c
  set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C "${_OPTIMIZE_OUTPUT_FOR_C}")

  # Build related configuration options
  # NO        EXTRACT_ALL           http://doxygen.org/manual/config.html#cfg_extract_all
  set(DOXYGEN_EXTRACT_ALL           YES)

  # Configuration options related to warning and progress messages

  # Configuration options related to the input files

  # Configuration options related to source browsing

  # Configuration options related to the alphabetical class index

  # Configuration options related to the HTML output
  # html      HTML_OUTPUT           http://doxygen.org/manual/config.html#cfg_html_output
  set(DOXYGEN_HTML_OUTPUT           "doxygen")
  # NO        USE_MATHJAX           http://doxygen.org/manual/config.html#cfg_use_mathjax
  set(DOXYGEN_USE_MATHJAX           YES)

  # Configuration options related to the LaTeX output

  # Configuration options related to the RTF output

  # Configuration options related to the man page output

  # Configuration options related to the XML output

  # Configuration options related to the DOCBOOK output

  # Configuration options for the AutoGen Definitions output

  # Configuration options related to the Perl module output

  # Configuration options related to the preprocessor

  # Configuration options related to external references

  # Configuration options related to the dot tool
  #           DOT_PATH              http://doxygen.org/manual/config.html#cfg_dot_path
  set(DOXYGEN_DOT_PATH              "" CACHE FILEPATH "The path where the dot tool can be found.")
  # NO        UML_LOOK              http://doxygen.org/manual/config.html#cfg_uml_look
  set(DOXYGEN_UML_LOOK              YES)
  #           PLANTUML_JAR_PATH     http://doxygen.org/manual/config.html#cfg_plantuml_jar_path
  set(DOXYGEN_PLANTUML_JAR_PATH     "" CACHE FILEPATH "The path where java can find the plantuml.jar file.")

  # doxygen
  set(sTgtName "${sNameLwr}_documentation")

  doxygen_add_docs("${sTgtName}"
      "${PROJECT_SOURCE_DIR}"
      "${PROJECT_BINARY_DIR}"
    WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
    COMMENT           "Generating documentation with Doxygen.")

  # install
  install(DIRECTORY "${PROJECT_BINARY_DIR}/doxygen" DESTINATION "docs/${sName}")
endfunction()
