# zhengrr
# 2016-10-08 – 2018-04-04
# The MIT License

# .rst
# .. command:: facile_add_library
#
#    便捷加入库文件（目标）：
#    ::
#
#       facile_add_library(
#         [NAME <full-name> | SUBNAME <sub-name>]
#         [OPTION_DESCRIPTION <option-description>]
#         [TARGET_NAME_VARIABLE <target-name-variable>]
#         [NO_DEFAULT_GROUP]
#         [STATIC | SHARED | MODULE]
#         [C90 | C99 | C11]
#         [CXX98 | CXX11 | CXX14 | CXX17]
#         <source>...
#         [PROPERTIES <property-key property-value>...]
#         [COMPILE_DEFINITIONS <definition>...]
#         [INCLUDE_DIRECTORIES <directory>...]
#         [LINK_LIBRARIES <library>...]
#         [COMPILE_FEATURES <feature>...]
#         [COMPILE_OPTIONS <option>...]
#       )
#
#    约定：
#
#    :NAME:         ``<full-name>`` or ``<PROJECT_NAME>_<sub-name>`` or ``<PROJECT_NAME>``
#    :option:       ``<NAME_UPPER>_COMPILE_<STATIC|SHARED|MODULE>_LIBRARY``
#    :source_group: to ``\\``
#    :add_library:  ``<NAME_LOWER>_<static|shared|module>_library``
#    :output:       ``<NAME>[d]``
#    :install:      to ``lib``
#
function(facile_add_library)
  set(zOptKws    "STATIC" "SHARED" "MODULE"
                 "C90" "C99" "C11"
                 "CXX98" "CXX11" "CXX14" "CXX17"
                 "NO_DEFAULT_GROUP")
  set(zOneValKws "NAME" "SUBNAME"
                 "OPTION_DESCRIPTION"
                 "TARGET_NAME_VARIABLE")
  set(zMutValKws "PROPERTIES"
                 "COMPILE_DEFINITIONS"
                 "INCLUDE_DIRECTORIES"
                 "LINK_LIBRARIES"
                 "COMPILE_FEATURES"
                 "COMPILE_OPTIONS")
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

  if(_STATIC)
    set(sType "static")
  elseif(_SHARED)
    set(sType "shared")
  elseif(_MODULE)
    set(sType "module")
  elseif(BUILD_SHARED_LIBS)
    set(sType "shared")
  else()
    set(sType "static")
  endif()
  string(TOUPPER "${sType}" sTypeUpr)
  string(TOLOWER "${sType}" sTypeLwr)

  # option
  set(vOptName "${sNameUpr}_COMPILE_${sTypeUpr}_LIBRARY")

  if(DEFINED _OPTION_DESCRIPTION)
    set(sOptDesc ${_OPTION_DESCRIPTION})
  else()
    set(sOptDesc "Build ${sTypeLwr} library.")
  endif()

  option(${vOptName} "${sOptDesc}" ON)
  if(NOT ${vOptName})
    return()
  endif()

  # source_group
  if(NOT _NO_DEFAULT_GROUP)
    source_group("\\" FILES ${_UNPARSED_ARGUMENTS})
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

  # add_library
  set(sTgtName "${sNameLwr}_${sTypeLwr}_library")
  if(DEFINED _TARGET_NAME_VARIABLE)
    set(${_TARGET_NAME_VARIABLE} "${sTgtName}" PARENT_SCOPE)
  endif()

  add_library("${sTgtName}" ${sTypeUpr} ${_UNPARSED_ARGUMENTS})
  set_target_properties("${sTgtName}" PROPERTIES
    ${zPropCStd} ${zPropCxxStd}
    OUTPUT_NAME "${sName}" DEBUG_POSTFIX "d" CLEAN_DIRECT_OUTPUT ON)
  if(DEFINED _PROPERTIES)
    set_target_properties("${sTgtName}" PROPERTIES ${_PROPERTIES})
  endif()
  if(DEFINED _COMPILE_DEFINITIONS)
    target_compile_definitions("${sTgtName}" ${_COMPILE_DEFINITIONS})
  endif()
  if(DEFINED _INCLUDE_DIRECTORIES)
    target_include_directories("${sTgtName}" ${_INCLUDE_DIRECTORIES})
  endif()
  if(DEFINED _LINK_LIBRARIES)
    target_link_libraries("${sTgtName}" ${_LINK_LIBRARIES})
  endif()
  if(DEFINED _COMPILE_FEATURES)
    target_compile_features("${sTgtName}" ${_COMPILE_FEATURES})
  endif()
  if(DEFINED _COMPILE_OPTIONS)
    target_compile_options("${sTgtName}" ${_COMPILE_OPTIONS})
  endif()

  # install
  install(TARGETS "${sTgtName}" DESTINATION "lib")
endfunction()
