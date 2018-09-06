# zhengrr
# 2017-12-18 – 2018-09-06
# The Unlicense

if(NOT COMMAND check_name_with_cmake_recommend_variable_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CkNameCmakeVar.cmake")
endif()

# .rst
# .. command:: facile_add_executable
#
#    便捷加入可执行文件（目标）：
#    ::
#
#       facile_add_executable([NAME <full-name> | SUBNAME <sub-name>]
#               [OPTION_DESCRIPTION <option-description>] [OPTION_INITIAL_ON]
#             [TARGET_NAME_VARIABLE <target-name-variable>]
#                                   [FLAT_GROUP]
#                                   [WIN32]
#                                   [C90 | C99 | C11]
#                                   [CXX98 | CXX11 | CXX14 | CXX17]
#                                   <source>...
#                       [PROPERTIES <property-key property-value>...]
#              [COMPILE_DEFINITIONS <definition>...]
#              [INCLUDE_DIRECTORIES <directory>...]
#                   [LINK_LIBRARIES <library>...]
#                 [COMPILE_FEATURES <feature>...]
#                  [COMPILE_OPTIONS <option>...]
#                      [POST_COPIES <copies>...]
#       )
#
#    约定：
#
#    :NAME:           ``<full-name>`` or ``<PROJECT_NAME>_<sub-name>`` or ``<PROJECT_NAME>``
#    :option:         ``<NAME_UPPER>_COMPILE_EXECUTABLE``
#    :source_group:   to ``\\``
#    :add_executable: ``<NAME_LOWER>_executable``
#    :output:         ``<NAME>[d]``
#    :install:        to ``bin``
#
#    参见：
#
#    + `CMake Documentation <https://cmake.org/cmake/help/latest/>`_
#       + `cmake_parse_arguments <https://cmake.org/cmake/help/latest/command/cmake_parse_arguments>`_.
#       + `option <https://cmake.org/cmake/help/latest/command/option>`_
#       + `source_group <https://cmake.org/cmake/help/latest/command/source_group>`_
#
#       + `add_executable <https://cmake.org/cmake/help/latest/command/add_executable>`_
#       + `set_target_properties <https://cmake.org/cmake/help/latest/command/set_target_properties>`_
#       + `target_compile_definitions <https://cmake.org/cmake/help/latest/command/target_compile_definitions>`_
#       + `target_include_directories <https://cmake.org/cmake/help/latest/command/target_include_directories>`_
#       + `target_link_libraries <https://cmake.org/cmake/help/latest/command/target_link_libraries>`_
#       + `target_compile_features <https://cmake.org/cmake/help/latest/command/target_compile_features>`_
#       + `target_compile_options <https://cmake.org/cmake/help/latest/command/target_compile_options>`_
#
#       + `WIN32_EXECUTABLE <https://cmake.org/cmake/help/latest/prop_tgt/WIN32_EXECUTABLE>`_
#       + `C_STANDARD <https://cmake.org/cmake/help/latest/prop_tgt/C_STANDARD>`_
#       + `CXX_STANDARD <https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD>`_
#
function(facile_add_executable)
  set(zOptKws    OPTION_INITIAL_ON
                 FLAT_GROUP
                 WIN32
                 C90 C99 C11
                 CXX98 CXX11 CXX14 CXX17)
  set(zOneValKws NAME SUBNAME
                 OPTION_DESCRIPTION
                 TARGET_NAME_VARIABLE)
  set(zMutValKws PROPERTIES
                 COMPILE_DEFINITIONS
                 INCLUDE_DIRECTORIES
                 LINK_LIBRARIES
                 COMPILE_FEATURES
                 COMPILE_OPTIONS
                 POST_COPIES)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  # name
  if(DEFINED _NAME)
    set(sName "${_NAME}")
  elseif(DEFINED _SUBNAME)
    set(sName "${PROJECT_NAME}_${_SUBNAME}")
  else()
    set(sName "${PROJECT_NAME}")
  endif()
  string(TOUPPER "${sName}" sNameUpr)
  string(TOLOWER "${sName}" sNameLwr)

  # target name
  set(sTgtName "${sNameLwr}_executable")
  if(DEFINED _TARGET_NAME_VARIABLE)
    check_name_with_cmake_recommend_variable_rules("${_TARGET_NAME_VARIABLE}" sCkPassed)
    if(NOT sCkPassed)
      message(WARNING "The variable name not meet CMake recommend variable rules: ${_TARGET_NAME_VARIABLE}.")
    endif()
    set(${_TARGET_NAME_VARIABLE} "${sTgtName}" PARENT_SCOPE)
  endif()

  # option
  set(vOptName "${sNameUpr}_COMPILE_EXECUTABLE")

  if(_OPTION_INITIAL_ON)
    set(sOptInit ON)
  else()
    set(sOptInit)
  endif()

  if(DEFINED _OPTION_DESCRIPTION)
    set(sOptDesc "${_OPTION_DESCRIPTION}")
  else()
    set(sOptDesc "Build executable.")
  endif()

  option(${vOptName} "${sOptDesc}" ${sOptInit})
  if(NOT ${vOptName})
    return()
  endif()

  # source_group
  if(_FLAT_GROUP)
    source_group("\\" FILES ${_UNPARSED_ARGUMENTS})
  endif()

  # prop WIN32
  if(_WIN32)
    set(sWin32 "WIN32")
  else()
    set(sWin32)
  endif()

  # prop C_STANDARD
  if(_C11)
    set(zPropCStd C_STANDARD 11 C_STANDARD_REQUIRED ON)
  elseif(_C99)
    set(zPropCStd C_STANDARD 99 C_STANDARD_REQUIRED ON)
  elseif(_C90)
    set(zPropCStd C_STANDARD 90 C_STANDARD_REQUIRED ON)
  else()
    set(zPropCStd)
  endif()

  # prop CXX_STANDARD
  if(_CXX17)
    set(zPropCxxStd CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX14)
    set(zPropCxxStd CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX11)
    set(zPropCxxStd CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX98)
    set(zPropCxxStd CXX_STANDARD 98 CXX_STANDARD_REQUIRED ON)
  else()
    set(zPropertyCxxStd)
  endif()

  # add_executable
  add_executable("${sTgtName}" ${sWin32} ${_UNPARSED_ARGUMENTS})
  set_target_properties("${sTgtName}"
             PROPERTIES ${zPropCStd}
                        ${zPropCxxStd}
                        OUTPUT_NAME "${sName}"
                        DEBUG_POSTFIX "d"
                        CLEAN_DIRECT_OUTPUT ON)

  # set_target_properties
  if(DEFINED _PROPERTIES)
    list(LENGTH _PROPERTIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword PROPERTIES is used, but without value.")
    endif()
    set_target_properties("${sTgtName}" PROPERTIES ${_PROPERTIES})
  endif()

  # target_compile_definitions
  if(DEFINED _COMPILE_DEFINITIONS)
    list(LENGTH _COMPILE_DEFINITIONS sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword COMPILE_DEFINITIONS is used, but without value.")
    endif()
    list(REMOVE_DUPLICATES _COMPILE_DEFINITIONS)
    target_compile_definitions("${sTgtName}" ${_COMPILE_DEFINITIONS})
  endif()

  # target_include_directories
  if(DEFINED _INCLUDE_DIRECTORIES)
    list(LENGTH _INCLUDE_DIRECTORIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword INCLUDE_DIRECTORIES is used, but without value.")
    endif()
    list(REMOVE_DUPLICATES _INCLUDE_DIRECTORIES)
    target_include_directories("${sTgtName}" ${_INCLUDE_DIRECTORIES})
  endif()

  # target_link_libraries
  if(DEFINED _LINK_LIBRARIES)
    list(LENGTH _LINK_LIBRARIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword LINK_LIBRARIES is used, but without value.")
    endif()
    list(REMOVE_DUPLICATES _LINK_LIBRARIES)
    target_link_libraries("${sTgtName}" ${_LINK_LIBRARIES})
  endif()

  # target_compile_features
  if(DEFINED _COMPILE_FEATURES)
    list(LENGTH _COMPILE_FEATURES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword COMPILE_FEATURES is used, but without value.")
    endif()
    target_compile_features("${sTgtName}" ${_COMPILE_FEATURES})
  endif()

  # target_compile_options
  if(DEFINED _COMPILE_OPTIONS)
    list(LENGTH _COMPILE_OPTIONS sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword COMPILE_OPTIONS is used, but without value.")
    endif()
    target_compile_options("${sTgtName}" ${_COMPILE_OPTIONS})
  endif()

  # POST_COPIES
  if(DEFINED _POST_COPIES)
    list(LENGTH _POST_COPIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword POST_COPIES is used, but without value.")
    endif()
    list(REMOVE_DUPLICATES _POST_COPIES)
    foreach(sCopy ${_POST_COPIES})
      if(TARGET "${sCopy}")
        add_custom_command(TARGET ${sTgtName} POST_BUILD
                          COMMAND ${CMAKE_COMMAND} -E copy_if_different
                                  $<TARGET_FILE:${sCopy}>
                                  $<TARGET_FILE_DIR:${sTgtName}>)
      elseif(EXISTS "${sCopy}")
        add_custom_command(TARGET ${sTgtName} POST_BUILD
                          COMMAND ${CMAKE_COMMAND} -E copy_if_different
                                  ${sCopy}
                                  $<TARGET_FILE_DIR:${sTgtName}>)
      else()
        message(WARNING "A post-copy-item is invalid: ${sCopy}.")
      endif()
    endforeach()
  endif()

  # install
  install(TARGETS "${sTgtName}" DESTINATION "bin")
endfunction()
