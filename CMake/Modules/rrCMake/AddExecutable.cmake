# zhengrr
# 2017-12-18 – 2019-04-15
# Unlicense

cmake_minimum_required(VERSION 3.10)
cmake_policy(VERSION 3.10)

include_guard()

if(NOT COMMAND copy_link_libraries)
  include("${CMAKE_CURRENT_LIST_DIR}/CopyLinkLibraries.cmake")
endif()

if(NOT COMMAND get_toolset_architecture_address_model_tag)
  include("${CMAKE_CURRENT_LIST_DIR}/LibraryTag.cmake")
endif()

#-------------------------------------------------------------------------------
# FUNCTIONS

#.rst
# .. command:: add_executable_ex
#
#   添加可执行目标到项目（add executable），扩展功能（extend）。
#
#   .. code-block:: cmake
#
#     add_executable_ex(
#       <name> <arguments...>
#       [PROPERTIES          <property-key> <property-value> ...]
#       [COMPILE_DEFINITIONS <INTERFACE|PUBLIC|PRIVATE> <definitions...> ...]
#       [COMPILE_FEATURES    <INTERFACE|PUBLIC|PRIVATE> <features...> ...]
#       [COMPILE_OPTIONS     <INTERFACE|PUBLIC|PRIVATE> <options...> ...]
#       [INCLUDE_DIRECTORIES <INTERFACE|PUBLIC|PRIVATE> <directories...> ...]
#       [LINK_DIRECTORIES    <INTERFACE|PUBLIC|PRIVATE> <directories...> ...]
#       [LINK_LIBRARIES      <INTERFACE|PUBLIC|PRIVATE> <libraries...> ...]
#       [LINK_OPTIONS        <INTERFACE|PUBLIC|PRIVATE> <options...> ...]
#       [SOURCES             <INTERFACE|PUBLIC|PRIVATE> <sources...> ...]
#     )
#
#   参见：
#
#   - `add_executable <https://cmake.org/cmake/help/latest/command/add_executable.html>`_
#   - `set_target_properties <https://cmake.org/cmake/help/latest/command/set_target_properties.html>`_
#   - `target_compile_definitions <https://cmake.org/cmake/help/latest/command/target_compile_definitions.html>`_
#   - `target_compile_features <https://cmake.org/cmake/help/latest/command/target_compile_features.html>`_
#   - `target_compile_options <https://cmake.org/cmake/help/latest/command/target_compile_options.html>`_
#   - `target_include_directories <https://cmake.org/cmake/help/latest/command/target_include_directories.html>`_
#   - `target_link_directories <https://cmake.org/cmake/help/latest/command/target_link_directories.html>`_
#   - `target_link_libraries <https://cmake.org/cmake/help/latest/command/target_link_libraries.html>`_
#   - `target_link_options <https://cmake.org/cmake/help/latest/command/target_link_options.html>`_
#   - `target_sources <https://cmake.org/cmake/help/latest/command/target_sources.html>`_
function(add_executable_ex _NAME)
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

  # add_executable
  add_executable(${_NAME} ${_UNPARSED_ARGUMENTS})

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

#.res
# .. command:: add_executable_con
#
#   添加库目标到项目（add executable），遵循惯例（convention）。
#
#   .. code-block:: cmake
#
#     add_executable_con(
#       <arguments...>
#     )
#
#   参见：
#
#   - `option <https://cmake.org/cmake/help/latest/command/option.html>`_
#   - :command:`add_executable_ex`
#   - `install <https://cmake.org/cmake/help/latest/command/install.html>`_
function(add_executable_con _NAME)
  set(zMutValKws PROPERTIES)
  cmake_parse_arguments(PARSE_ARGV 1 "" "" "" "${zMutValKws}")

  string(TOUPPER ${PROJECT_NAME} _PROJECT_NAME_UPPER)
  string(TOUPPER ${_NAME}        _NAME_UPPER)

  # option
  set(vOptVar ${_PROJECT_NAME_UPPER}_${_NAME_UPPER}_EXECUTABLE)
  option(${vOptVar} "Build ${_NAME} executable." ON)
  if(NOT ${vOptVar})
    return()
  endif()

  # PROPERTIES
  list(INSERT _PROPERTIES 0 PROPERTIES)
  set(zDefProps)
  if(NOT DEBUG_POSTFIX IN_LIST _PROPERTIES)
    list(APPEND zDefProps DEBUG_POSTFIX d)
  endif()
  if(NOT OUTPUT_NAME IN_LIST _PROPERTIES)
    list(APPEND zDefProps OUTPUT_NAME "${_NAME}")
  endif()

  # add_executable_ex
  add_executable_ex(
    ${_NAME} ${_UNPARSED_ARGUMENTS}
    ${_PROPERTIES}
  )

  # copy_link_libraries
  copy_link_libraries(${_NAME})

  # install
  get_toolset_architecture_address_model_tag(sTag)
  install(
    TARGETS     ${_NAME}
    DESTINATION "bin/${sTag}$<$<CONFIG:Debug>:d>/")
endfunction()
