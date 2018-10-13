# zhengrr
# 2017-12-18 – 2018-10-13
# The Unlicense

include_guard()

if(NOT COMMAND check_name_with_cmake_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CkName.cmake")
endif()

# .rst
# .. command:: add_executable_ex
#
#   添加可执行目标到项目（附加功能）::
#
#     add_executable_ex(
#       [NAME_PREFIX          <name-prefix>]           default: NAME ? "${PROJECT_NAME}_" : "${PROJECT_NAME}"
#       [NAME                 <name>]
#       [NAME_SUFFIX          <name-suffix>]
#       [WIN32] [MACOSX_BUNDLE]
#       [EXCLUDE_FROM_ALL]
#       <source>...
#
#       [WITH_OPTION]
#       [OPTION_NAME_PREFIX   <option-name-prefix>]
#       [OPTION_NAME          <option-name>]           default: "${FULL_NAME_UPPER}"
#       [OPTION_NAME_SUFFIX   <option-name-suffix>]    default: "_COMPILE_EXECUTABLE"
#       [OPTION_DESCRIPTION   <option-description>]    default: "Build ${FULL_NAME} executable."
#       [OPTION_INITIAL_ON]
#
#       [FLAT_GROUP]
#
#       [TARGET_NAME_PREFIX   <target-name-prefix>]
#       [TARGET_NAME          <target-name>]           default: "${FULL_NAME_LOWER}"
#       [TARGET_NAME_SUFFIX   <target-name-suffix>]    default: "_executable"
#       [TARGET_NAME_VARIABLE <target-name-variable>]
#
#       [C90 | C99 | C11]
#       [CXX98 | CXX11 | CXX14 | CXX17 | CXX20]
#       [PROPERTIES           <property-key property-value>...]
#
#       [COMPILE_DEFINITIONS  <INTERFACE|PUBLIC|PRIVATE> <definition>...]
#       [COMPILE_FEATURES     <INTERFACE|PUBLIC|PRIVATE> <feature>...]
#       [COMPILE_OPTIONS      <INTERFACE|PUBLIC|PRIVATE> <option>...]
#       [INCLUDE_DIRECTORIES  <INTERFACE|PUBLIC|PRIVATE> <directory>...]
#       [LINK_DIRECTORIES     <INTERFACE|PUBLIC|PRIVATE> <directory>...]
#       [LINK_LIBRARIES       <INTERFACE|PUBLIC|PRIVATE> <library>...]
#       [LINK_OPTIONS         <INTERFACE|PUBLIC|PRIVATE> <option>...]
#       [POST_COPIES          <copies>...]
#     )
function(add_executable_ex)
  set(zOptKws    WIN32 MACOSX_BUNDLE
                 EXCLUDE_FROM_ALL
                 WITH_OPTION
                 OPTION_INITIAL_ON
                 FLAT_GROUP
                 C90 C99 C11
                 CXX98 CXX11 CXX14 CXX17 CXX20)
  set(zOneValKws NAME_PREFIX
                 NAME
                 NAME_SUFFIX
                 OPTION_NAME_PREFIX
                 OPTION_NAME
                 OPTION_NAME_SUFFIX
                 OPTION_DESCRIPTION
                 TARGET_NAME_PREFIX
                 TARGET_NAME
                 TARGET_NAME_SUFFIX
                 TARGET_NAME_VARIABLE)
  set(zMutValKws PROPERTIES
                 COMPILE_DEFINITIONS
                 COMPILE_FEATURES
                 COMPILE_OPTIONS
                 INCLUDE_DIRECTORIES
                 LINK_DIRECTORIES
                 LINK_LIBRARIES
                 LINK_OPTIONS
                 POST_COPIES)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  set(_SOURCE ${_UNPARSED_ARGUMENTS})

  if(NOT DEFINED _NAME_PREFIX)
    if(DEFINED _NAME)
      set(_NAME_PREFIX "${PROJECT_NAME}_")
    else()
      set(_NAME_PREFIX "${PROJECT_NAME}")
    endif()
  endif()
  set(sName "${_NAME_PREFIX}${_NAME}${_NAME_SUFFIX}")

  if(_WIN32)
    set(_WIN32 WIN32)
  else()
    set(_WIN32)
  endif()

  if(_MACOSX_BUNDLE)
    set(_MACOSX_BUNDLE MACOSX_BUNDLE)
  else()
    set(_MACOSX_BUNDLE)
  endif()

  if(_EXCLUDE_FROM_ALL)
    set(_EXCLUDE_FROM_ALL EXCLUDE_FROM_ALL)
  else()
    set(_EXCLUDE_FROM_ALL)
  endif()

  if(_WITH_OPTION)
    if(NOT DEFINED _OPTION_NAME)
      string(TOUPPER "${sName}" _OPTION_NAME)
    endif()
    if(NOT DEFINED _OPTION_NAME_SUFFIX)
      set(_OPTION_NAME_SUFFIX "_COMPILE_EXECUTABLE")
    endif()
    set(vOptName "${_OPTION_NAME_PREFIX}${_OPTION_NAME}${_OPTION_NAME_SUFFIX}")
    check_name_with_cmake_rules("${vOptName}" WARNING)
    if(NOT DEFINED _OPTION_DESCRIPTION)
      set(_OPTION_DESCRIPTION "Build ${sName} executable.")
    endif()
    option(${vOptName} "${_OPTION_DESCRIPTION}" ${_OPTION_INITIAL_ON})
    if(NOT ${vOptName})
      return()
    endif()
  endif()

  if(_FLAT_GROUP)
    source_group("\\" FILES ${_SOURCE})
  endif()

  if(NOT DEFINED _TARGET_NAME)
    string(TOLOWER "${sName}" _TARGET_NAME)
  endif()
  if(NOT DEFINED _TARGET_NAME_SUFFIX)
    set(_TARGET_NAME_SUFFIX "_executable")
  endif()
  set(sTgtName "${_TARGET_NAME_PREFIX}${_TARGET_NAME}${_TARGET_NAME_SUFFIX}")
  check_name_with_cmake_rules("${sTgtName}" WARNING)
  if(DEFINED _TARGET_NAME_VARIABLE)
    check_name_with_cmake_rules("${_TARGET_NAME_VARIABLE}" WARNING)
    set(${_TARGET_NAME_VARIABLE} "${sTgtName}" PARENT_SCOPE)
  endif()

  if(_C11)
    set(zPropCStd C_STANDARD 11 C_STANDARD_REQUIRED ON)
  elseif(_C99)
    set(zPropCStd C_STANDARD 99 C_STANDARD_REQUIRED ON)
  elseif(_C90)
    set(zPropCStd C_STANDARD 90 C_STANDARD_REQUIRED ON)
  else()
    set(zPropCStd)
  endif()

  if(_CXX20)
    set(zPropCxxStd CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX17)
    set(zPropCxxStd CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX14)
    set(zPropCxxStd CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX11)
    set(zPropCxxStd CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX98)
    set(zPropCxxStd CXX_STANDARD 98 CXX_STANDARD_REQUIRED ON)
  else()
    set(zPropCxxStd)
  endif()

  add_executable("${sTgtName}" ${_WIN32} ${_MACOSX_BUNDLE} ${_EXCLUDE_FROM_ALL} ${_SOURCE})
  set_target_properties(
    "${sTgtName}"
    PROPERTIES ${zPropCStd}
               ${zPropCxxStd}
               OUTPUT_NAME         "${sName}"
               DEBUG_POSTFIX       "d"
               CLEAN_DIRECT_OUTPUT ON)

  if(DEFINED _PROPERTIES)
    list(LENGTH _PROPERTIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword PROPERTIES is used, but without value.")
    endif()
    set_target_properties("${sTgtName}" PROPERTIES ${_PROPERTIES})
  endif()

  if(DEFINED _COMPILE_DEFINITIONS)
    list(LENGTH _COMPILE_DEFINITIONS sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword COMPILE_DEFINITIONS is used, but without value.")
    endif()
    target_compile_definitions("${sTgtName}" ${_COMPILE_DEFINITIONS})
  endif()

  if(DEFINED _COMPILE_FEATURES)
    list(LENGTH _COMPILE_FEATURES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword COMPILE_FEATURES is used, but without value.")
    endif()
    target_compile_features("${sTgtName}" ${_COMPILE_FEATURES})
  endif()

  if(DEFINED _COMPILE_OPTIONS)
    list(LENGTH _COMPILE_OPTIONS sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword COMPILE_OPTIONS is used, but without value.")
    endif()
    target_compile_options("${sTgtName}" ${_COMPILE_OPTIONS})
  endif()

  if(DEFINED _INCLUDE_DIRECTORIES)
    list(LENGTH _INCLUDE_DIRECTORIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword INCLUDE_DIRECTORIES is used, but without value.")
    endif()
    target_include_directories("${sTgtName}" ${_INCLUDE_DIRECTORIES})
  endif()

  if(DEFINED _LINK_LIBRARIES)
    list(LENGTH _LINK_LIBRARIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword LINK_LIBRARIES is used, but without value.")
    endif()
    target_link_libraries("${sTgtName}" ${_LINK_LIBRARIES})
  endif()

  if(DEFINED _LINK_DIRECTORIES)
    list(LENGTH _LINK_DIRECTORIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword LINK_DIRECTORIES is used, but without value.")
    endif()
    target_link_directories("${sTgtName}" ${_LINK_DIRECTORIES})
  endif()

  if(DEFINED _LINK_OPTIONS)
    list(LENGTH _LINK_OPTIONS sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword LINK_OPTIONS is used, but without value.")
    endif()
    target_link_options("${sTgtName}" ${_LINK_OPTIONS})
  endif()

  if(DEFINED _POST_COPIES)
    list(LENGTH _POST_COPIES sLen)
    if(sLen EQUAL 0)
      message(WARNING "Keyword POST_COPIES is used, but without value.")
    endif()
    list(REMOVE_DUPLICATES _POST_COPIES)
    foreach(sCopy ${_POST_COPIES})
      if(TARGET "${sCopy}")
        add_custom_command(
          TARGET  ${sTgtName}
          POST_BUILD
          COMMAND ${CMAKE_COMMAND} -E copy_if_different
                  $<TARGET_FILE:${sCopy}>
                  $<TARGET_FILE_DIR:${sTgtName}>)
      elseif(EXISTS "${sCopy}")
        add_custom_command(
          TARGET  ${sTgtName}
          POST_BUILD
          COMMAND ${CMAKE_COMMAND} -E copy_if_different
                  ${sCopy}
                  $<TARGET_FILE_DIR:${sTgtName}>)
      else()
        message(WARNING "A post-copy-item is invalid: ${sCopy}.")
      endif()
    endforeach()
  endif()

  install(TARGETS "${sTgtName}" DESTINATION "bin")
endfunction()
