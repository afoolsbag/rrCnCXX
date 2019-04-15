# zhengrr
# 2016-10-08 – 2019-04-15
# Unlicense

cmake_minimum_required(VERSION 3.10)
cmake_policy(VERSION 3.10)

include_guard()

#-------------------------------------------------------------------------------
# MACROS

#.rst
# .. command:: arguments_to_doxygen
macro(arguments_to_doxygen)
  foreach(sCfgName IN ITEMS ${ARGV})
    if(DEFINED _${sCfgName})
      set(DOXYGEN_${sCfgName} ${_${sCfgName}})
    endif()
  endforeach()
endmacro()

#-------------------------------------------------------------------------------
# FUNCTIONS

#.rst
# .. command:: add_doxygen
#
#   添加 Doxygen 目标到项目。
#
#   .. code-block:: cmake
#
#     add_doxygen(                                                       default
#       <arguments...>
#       [FULL_PATH_NAMES       <YES|NO>]                                     YES
#       [STRIP_FROM_PATH       path]
#       [JAVADOC_AUTOBRIEF     <YES|NO>]                                      NO
#       [OPTIMIZE_OUTPUT_FOR_C <YES|NO>]                                      NO
#       [EXTRACT_ALL           <YES|NO>]                                      NO
#       [HTML_OUTPUT           directory]                                   html
#       [USE_MATHJAX           <YES|NO>]                                      NO
#       [DOT_PATH              path]
#       [UML_LOOK              <YES|NO>]                                      NO
#       [PLANTUML_JAR_PATH     path]
#     )
#
#   参见：
#
#   - `FindDoxygen <https://cmake.org/cmake/help/latest/module/FindDoxygen.html>`_
#   - `Configuration <http://doxygen.org/manual/config.html>`_
function(add_doxygen)
  set(zOneValKws)
  set(zMutValKws)
  list(APPEND zOneValKws FULL_PATH_NAMES
                         STRIP_FROM_PATH
                         JAVADOC_AUTOBRIEF
                         OPTIMIZE_OUTPUT_FOR_C
                         EXTRACT_ALL
                         HTML_OUTPUT
                         USE_MATHJAX
                         DOT_PATH
                         UML_LOOK
                         PLANTUML_JAR_PATH)
  cmake_parse_arguments(PARSE_ARGV 0 "" "" "${zOneValKws}" "${zMutValKws}")

  find_package(Doxygen)
  if(NOT DOXYGEN_FOUND)
    message(WARNING "Doxygen is needed to generate doxygen documentation.")
  endif()

  arguments_to_doxygen(
    ${zOneValKws}
    ${zMutValKws}
  )

  doxygen_add_docs(${_UNPARSED_ARGUMENTS})
endfunction()

#.rst
# .. command:: add_doxygen_con
#
#   添加 Doxygen 目标到项目，遵循惯例（convention）。
#
#   .. code-block:: cmake
#
#     add_doxygen_con(
#       <arguments...>
#     )
#
#   参见：
#
#   - `option <https://cmake.org/cmake/help/latest/command/option.html>`_
#   - :command:`add_doxygen`
#   - `install <https://cmake.org/cmake/help/latest/command/install.html>`_
function(add_doxygen_con _NAME)
  set(zOptKws    ALL EXCLUDE_FROM_ALL)
  set(zOneValKws WORKING_DIRECTORY
                 COMMENT)
  set(zMutValKws)
  list(APPEND zOneValKws STRIP_FROM_PATH
                         EXTRACT_ALL
                         HTML_OUTPUT
                         USE_MATHJAX
                         DOT_PATH
                         PLANTUML_JAR_PATH)
  cmake_parse_arguments(PARSE_ARGV 1 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  string(TOUPPER ${PROJECT_NAME} _PROJECT_NAME_UPPER)
  string(TOUPPER ${_NAME}        _NAME_UPPER)

  # option
  set(vOptVar ${_PROJECT_NAME_UPPER}_${_NAME_UPPER}_DOCUMENTATION)
  option(${vOptVar} "Build ${_NAME} documentation." ${DOXYGEN_FOUND})
  if(NOT ${vOptVar})
    return()
  endif()

  # arguments
  if(DEFINED _EXCLUDE_FROM_ALL)
    set(_ALL)
  else()
    set(_ALL ALL)
  endif()
  if(NOT DEFINED _WORKING_DIRECTORY)
    set(_WORKING_DIRECTORY WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")
  endif()
  if(NOT DEFINED _COMMENT)
    set(_COMMENT COMMENT "Generating documentation with Doxygen.")
  endif()

  # configurations
  if(NOT DEFINED _STRIP_FROM_PATH)
    set(_STRIP_FROM_PATH   STRIP_FROM_PATH   "${PROJECT_SOURCE_DIR}")
  endif()
  if(NOT DEFINED _EXTRACT_ALL)
    set(_EXTRACT_ALL       EXTRACT_ALL       YES)
  endif()
  if(NOT DEFINED _HTML_OUTPUT)
    set(_HTML_OUTPUT       HTML_OUTPUT       "doxygen")
  endif()
  if(NOT DEFINED _USE_MATHJAX)
    set(_USE_MATHJAX       USE_MATHJAX       YES)
  endif()
  if(NOT DEFINED _DOT_PATH)
    set(_DOT_PATH          DOT_PATH          "$ENV{GRAPHVIZ_DOT}")
  endif()
  if(NOT DEFINED _PLANTUML_JAR_PATH)
    set(_PLANTUML_JAR_PATH PLANTUML_JAR_PATH "$ENV{PLANTUML}")
  endif()

  # 调用 add_doxygen
  add_doxygen(
    ${_NAME} ${_UNPARSED_ARGUMENTS} ${_ALL} ${WORKING_DIRECTORY} ${_COMMENT}
    ${_STRIP_FROM_PATH}
    ${_EXTRACT_ALL}
    ${_HTML_OUTPUT}
    ${_USE_MATHJAX}
    ${_DOT_PATH}
    ${_PLANTUML_JAR_PATH}
  )

  # 安装
  install(
    DIRECTORY   "${PROJECT_BINARY_DIR}/doxygen/"
    DESTINATION "doc/${_NAME}")
endfunction()
