# zhengrr
# 2016-10-08 – 2019-05-10
# Unlicense

cmake_minimum_required(VERSION 3.10)
cmake_policy(VERSION 3.10)

include_guard()

if(NOT COMMAND get_toolset_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/LibraryTag.cmake")
endif()

if(NOT COMMAND post_build_copy_link_libraries)
  include("${CMAKE_CURRENT_LIST_DIR}/LinkLibraries.cmake")
endif()

#.res:
# .. command:: add_library_ex
#
#   添加库目标到项目（add library），扩展功能（extend）。
#
#   .. code-block:: cmake
#
#     add_library_ex(
#       <name> <argument>...
#       [PROPERTIES          <property-key> <property-value> ...]
#       [COMPILE_DEFINITIONS <INTERFACE|PUBLIC|PRIVATE> <definition>... ...]
#       [COMPILE_FEATURES    <INTERFACE|PUBLIC|PRIVATE> <feature>... ...]
#       [COMPILE_OPTIONS     <INTERFACE|PUBLIC|PRIVATE> <option>... ...]
#       [INCLUDE_DIRECTORIES <INTERFACE|PUBLIC|PRIVATE> <directory>... ...]
#       [LINK_DIRECTORIES    <INTERFACE|PUBLIC|PRIVATE> <directory>... ...]
#       [LINK_LIBRARIES      <INTERFACE|PUBLIC|PRIVATE> <library>... ...]
#       [LINK_OPTIONS        <INTERFACE|PUBLIC|PRIVATE> <option>... ...]
#       [SOURCES             <INTERFACE|PUBLIC|PRIVATE> <source>... ...]
#     )
#
#   参见：
#
#   - `add_library <https://cmake.org/cmake/help/latest/command/add_library.html>`_
#   - `set_target_properties <https://cmake.org/cmake/help/latest/command/set_target_properties.html>`_
#   - `target_compile_definitions <https://cmake.org/cmake/help/latest/command/target_compile_definitions.html>`_
#   - `target_compile_features <https://cmake.org/cmake/help/latest/command/target_compile_features.html>`_
#   - `target_compile_options <https://cmake.org/cmake/help/latest/command/target_compile_options.html>`_
#   - `target_include_directories <https://cmake.org/cmake/help/latest/command/target_include_directories.html>`_
#   - `target_link_directories <https://cmake.org/cmake/help/latest/command/target_link_directories.html>`_
#   - `target_link_libraries <https://cmake.org/cmake/help/latest/command/target_link_libraries.html>`_
#   - `target_link_options <https://cmake.org/cmake/help/latest/command/target_link_options.html>`_
#   - `target_sources <https://cmake.org/cmake/help/latest/command/target_sources.html>`_
function(add_library_ex _NAME)
  set(zMutValKws PROPERTIES
                 COMPILE_DEFINITIONS
                 COMPILE_FEATURES
                 COMPILE_OPTIONS
                 INCLUDE_DIRECTORIES
                 LINK_DIRECTORIES
                 LINK_LIBRARIES
                 LINK_OPTIONS
                 SOURCES)
  cmake_parse_arguments(PARSE_ARGV 1 "" "" "" "${zMutValKws}")

  # add_library
  add_library(${_NAME} ${_UNPARSED_ARGUMENTS})

  # set_target_properties
  if(DEFINED _PROPERTIES)
    list(LENGTH _PROPERTIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword PROPERTIES is used, but without value.")
    endif()
    set_target_properties(${_NAME} PROPERTIES ${_PROPERTIES})
  endif()

  # target_compile_definitions
  if(DEFINED _COMPILE_DEFINITIONS)
    list(LENGTH _COMPILE_DEFINITIONS sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword COMPILE_DEFINITIONS is used, but without value.")
    endif()
    target_compile_definitions(${_NAME} ${_COMPILE_DEFINITIONS})
  endif()

  # target_compile_features
  if(DEFINED _COMPILE_FEATURES)
    list(LENGTH _COMPILE_FEATURES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword COMPILE_FEATURES is used, but without value.")
    endif()
    target_compile_features(${_NAME} ${_COMPILE_FEATURES})
  endif()

  # target_compile_options
  if(DEFINED _COMPILE_OPTIONS)
    list(LENGTH _COMPILE_OPTIONS sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword COMPILE_OPTIONS is used, but without value.")
    endif()
    target_compile_options(${_NAME} ${_COMPILE_OPTIONS})
  endif()

  # target_include_directories
  if(DEFINED _INCLUDE_DIRECTORIES)
    list(LENGTH _INCLUDE_DIRECTORIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword INCLUDE_DIRECTORIES is used, but without value.")
    endif()
    target_include_directories(${_NAME} ${_INCLUDE_DIRECTORIES})
  endif()

  # target_link_libraries
  if(DEFINED _LINK_LIBRARIES)
    list(LENGTH _LINK_LIBRARIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword LINK_LIBRARIES is used, but without value.")
    endif()
    target_link_libraries(${_NAME} ${_LINK_LIBRARIES})
  endif()

  # target_link_directories
  if(DEFINED _LINK_DIRECTORIES)
    list(LENGTH _LINK_DIRECTORIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword LINK_DIRECTORIES is used, but without value.")
    endif()
    target_link_directories(${_NAME} ${_LINK_DIRECTORIES})
  endif()

  # target_link_options
  if(DEFINED _LINK_OPTIONS)
    list(LENGTH _LINK_OPTIONS sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword LINK_OPTIONS is used, but without value.")
    endif()
    target_link_options(${_NAME} ${_LINK_OPTIONS})
  endif()

  # target_sources
  if(DEFINED _SOURCES)
    list(LENGTH _SOURCES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword SOURCES is used, but without value.")
    endif()
    target_sources(${_NAME} ${_SOURCES})
  endif()
endfunction()

#.res:
# .. command:: add_library_con
#
#   添加库目标到项目（add library），遵循惯例（convention）。
#
#   .. code-block:: cmake
#
#     add_library_con(
#       <argument>...
#     )
#
#   参见：
#
#   - `option <https://cmake.org/cmake/help/latest/command/option.html>`_
#   - :command:`add_library_ex`
#   - `install <https://cmake.org/cmake/help/latest/command/install.html>`_
function(add_library_con _NAME)
  set(zMutValKws PROPERTIES
                 COMPILE_DEFINITIONS
                 COMPILE_FEATURES
                 COMPILE_OPTIONS
                 INCLUDE_DIRECTORIES
                 LINK_DIRECTORIES
                 LINK_LIBRARIES
                 LINK_OPTIONS
                 SOURCES)
  cmake_parse_arguments(PARSE_ARGV 1 "" "" "" "${zMutValKws}")

  if(MODULE IN_LIST _UNPARSED_ARGUMENTS)
    set(_TYPE MODULE)
  elseif(SHARED IN_LIST _UNPARSED_ARGUMENTS)
    set(_TYPE SHARED)
  elseif(STATIC IN_LIST _UNPARSED_ARGUMENTS)
    set(_TYPE STATIC)
  elseif(BUILD_SHARED_LIBS)
    set(_TYPE SHARED)
  else()
    set(_TYPE STATIC)
  endif()

  string(TOUPPER ${PROJECT_NAME} _PROJECT_NAME_UPPER)
  string(TOUPPER ${_NAME}        _NAME_UPPER)
  string(TOUPPER ${_TYPE}        _TYPE_UPPER)
  string(TOLOWER ${_TYPE}        _TYPE_LOWER)

  # option
  string(REGEX REPLACE "^${_PROJECT_NAME_UPPER}" "" sTrimmedNameUpper "${_NAME_UPPER}")
  string(LENGTH "${sTrimmedNameUpper}" sLen)
  if(0 LESS sLen)
    set(vOptVar ${_PROJECT_NAME_UPPER}_${sTrimmedNameUpper}_${_TYPE_UPPER}_LIBRARY)
  else()
    set(vOptVar ${_PROJECT_NAME_UPPER}_${_TYPE_UPPER}_LIBRARY)
  endif()
  option(${vOptVar} "Build ${_NAME} ${_TYPE_LOWER} library." ON)
  if(NOT ${vOptVar})
    return()
  endif()

  # PROPERTIES
  list(INSERT _PROPERTIES 0 PROPERTIES)
  if(NOT DEBUG_POSTFIX IN_LIST _PROPERTIES)
    list(APPEND _PROPERTIES DEBUG_POSTFIX "d")
  endif()
  if(NOT OUTPUT_NAME IN_LIST _PROPERTIES)
    list(APPEND _PROPERTIES OUTPUT_NAME "${_NAME}")
  endif()
  if(NOT PREFIX IN_LIST _PROPERTIES AND _STATIC)
    list(APPEND _PROPERTIES PREFIX "lib")
  endif()

  # COMPILE_DEFINITIONS
  if(DEFINED _COMPILE_DEFINITIONS)
    list(INSERT _COMPILE_DEFINITIONS 0 COMPILE_DEFINITIONS)
  endif()

  # COMPILE_FEATURES
  if(DEFINED _COMPILE_FEATURES)
    list(INSERT _COMPILE_FEATURES 0 COMPILE_FEATURES)
  endif()

  # COMPILE_OPTIONS
  if(DEFINED _COMPILE_OPTIONS)
    list(INSERT _COMPILE_OPTIONS 0 COMPILE_OPTIONS)
  endif()

  # INCLUDE_DIRECTORIES
  if(DEFINED _INCLUDE_DIRECTORIES)
    list(INSERT _INCLUDE_DIRECTORIES 0 INCLUDE_DIRECTORIES)
  endif()

  # LINK_DIRECTORIES
  if(DEFINED _LINK_DIRECTORIES)
    list(INSERT _LINK_DIRECTORIES 0 LINK_DIRECTORIES)
  endif()

  # LINK_LIBRARIE
  if(DEFINED _LINK_LIBRARIES)
    list(INSERT _LINK_LIBRARIES 0 LINK_LIBRARIES)
  endif()

  # LINK_OPTIONS
  if(DEFINED _LINK_OPTIONS)
    list(INSERT _LINK_OPTIONS 0 LINK_OPTIONS)
  endif()

  # SOURCES
  if(DEFINED _SOURCES)
    list(INSERT _SOURCES 0 SOURCES)
  endif()

  # add_library_ex
  add_library_ex(
    ${_NAME} ${_UNPARSED_ARGUMENTS}
    ${_PROPERTIES}
    ${_COMPILE_DEFINITIONS}
    ${_COMPILE_FEATURES}
    ${_COMPILE_OPTIONS}
    ${_INCLUDE_DIRECTORIES}
    ${_LINK_DIRECTORIES}
    ${_LINK_LIBRARIES}
    ${_LINK_OPTIONS}
    ${_SOURCES}
  )

  # post_build_copy_link_libraries
  post_build_copy_link_libraries(${_NAME} RECURSE)

  # install
  get_toolset_architecture_address_model_tag(sTag)
  install(
    TARGETS             ${_NAME}
    ARCHIVE DESTINATION "lib/${sTag}$<$<CONFIG:Debug>:d>/"
    LIBRARY DESTINATION "lib/${sTag}$<$<CONFIG:Debug>:d>/"
    RUNTIME DESTINATION "bin/${sTag}$<$<CONFIG:Debug>:d>/")
endfunction()
