# zhengrr
# 2016-10-08 – 2018-10-13
# The Unlicense

include_guard()

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

# .rst
# .. command:: facile_add_doxygen
#
#   便捷添加 Doxygen 目标到项目::
#
#     facile_add_doxygen(
#       [WITH_OPTION]
#       [OPTION_NAME_PREFIX <option-name-prefix>]
#       [OPTION_NAME        <option-name>]           default: "${PROJECT_NAME_UPPER}"
#       [OPTION_NAME_SUFFUX <option-name-suffix>]    default: "_GENERATE_DOCUMENTATION"
#       [OPTION_DESCRIPTION <option-description>]    default: "Generate documentation (requires Doxygen)."
#       [OPTION_INITIAL_ON]
#
#       [TARGET_NAME_PREFIX   <target-name-prefix>]
#       [TARGET_NAME          <target-name>]         default: "${PROJECT_NAME_LOWER}"
#       [TARGET_NAME_SUFFIX   <target-name-suffix>]  default: "_documentation"
#
#       [JAVADOC_AUTOBRIEF]
#       [OPTIMIZE_OUTPUT_FOR_C]
#     )
#
#   缓存：
#
#   ``DOXYGEN_DOT_PATH``
#
#   ``DOXYGEN_PLANTUML_JAR_PATH``
#
#   参见：
#
#   - `"FindDoxygen" <https://cmake.org/cmake/help/latest/module/FindDoxygen>`_. *CMake Documentation*.
#   - `"Configuration" <http://doxygen.org/manual/config.html>`_. *Doxygen Manual*.
function(facile_add_doxygen)
  set(zOptKws    WITH_OPTION
                 OPTION_INITIAL_ON
                 JAVADOC_AUTOBRIEF
                 OPTIMIZE_OUTPUT_FOR_C)
  set(zOneValKws OPTION_NAME_PREFIX
                 OPTION_NAME
                 OPTION_NAME_SUFFUX
                 OPTION_DESCRIPTION
                 TARGET_NAME_PREFIX
                 TARGET_NAME
                 TARGET_NAME_SUFFIX)
  set(zMutValKws)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
  endif()

  if(_WITH_OPTION)
    if(NOT DEFINED _OPTION_NAME)
      string(TOUPPER "${PROJECT_NAME}" _OPTION_NAME)
    endif()
    if(NOT DEFINED _OPTION_NAME_SUFFIX)
      set(_OPTION_NAME_SUFFIX "_GENERATE_DOCUMENTATION")
    endif()
    set(vOptName "${_OPTION_NAME_PREFIX}${_OPTION_NAME}${_OPTION_NAME_SUFFIX}")
    check_name_with_cmake_rules("${vOptName}" WARNING)
    if(NOT DEFINED _OPTION_DESCRIPTION)
      set(_OPTION_DESCRIPTION "Generate documentation (requires Doxygen).")
    endif()
    option(${vOptName} "${_OPTION_DESCRIPTION}" ${_OPTION_INITIAL_ON})
    if(NOT ${vOptName})
      return()
    endif()
  endif()

  if(NOT DEFINED _TARGET_NAME)
    string(TOLOWER "${PROJECT_NAME}" _TARGET_NAME)
  endif()
  if(NOT DEFINED _TARGET_NAME_SUFFIX)
    set(_TARGET_NAME_SUFFIX "_documentation")
  endif()
  set(sTgtName "${_TARGET_NAME_PREFIX}${_TARGET_NAME}${_TARGET_NAME_SUFFIX}")
  check_name_with_cmake_rules("${sTgtName}" WARNING)

  find_package(Doxygen OPTIONAL_COMPONENTS dot)
  if(NOT DOXYGEN_FOUND)
    message(WARNING "Doxygen is needed to generate doxygen documentation.")
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

  doxygen_add_docs(
    "${sTgtName}"
    "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}"
    WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
    COMMENT           "Generating documentation with Doxygen.")

  install(DIRECTORY "${PROJECT_BINARY_DIR}/doxygen" DESTINATION "docs/${PROJECT_NAME}")
endfunction()
