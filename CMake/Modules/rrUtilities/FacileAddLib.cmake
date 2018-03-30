# zhengrr
# 2016-10-08 – 2018-03-30
# The MIT License

# .rst
# .. command:: facile_add_library
#
#    轻快生成库文件：
#    ::
#
#       facile_add_library(
#         [NAME name | SUBNAME subname]
#         [TGTNAMEVAR <target_name_variable>]
#         [OPTDESC <option_description>]
#         [STATIC] [SHARED] [MODULE]
#         [C90 | C99 | C11]
#         [CXX98 | CXX11 | CXX14 | CXX17]
#         <source>...
#         [PROPS <property value>...]
#         [LINKS <library>...]
#       )
#
#    影响：
#
#    :NAME:         ``<name>`` or ``<PROJECT_NAME>_<subname>`` or ``<PROJECT_NAME>``
#    :option:       ``<NAME_UPPER>_COMPILE_<STATIC|SHARED|MODULE>``
#    :source_group: to ``\\``
#    :add_library:  ``<NAME_LOWER>_<static|shared|module>``
#    :output:       ``<NAME>``
#    :install:      to ``lib``
#
function(facile_add_library)
  set(zOptKws
    "STATIC" "SHARED" "MODULE"
    "C90" "C99" "C11"
    "CXX98" "CXX11" "CXX14" "CXX17"
    "FLATGRP")
  set(zOneValKws "NAME" "SUBNAME" "TGTNAMEVAR" "OPTDESC")
  set(zMutValKws "PROPS" "LINKS")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

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
    set(sLibType "static")
  elseif(_SHARED)
    set(sLibType "shared")
  elseif(_MODULE)
    set(sLibType "module")
  elseif(BUILD_SHARED_LIBS)
    set(sLibType "shared")
  else()
    set(sLibType "static")
  endif()
  string(TOUPPER "${sLibType}" sLibTypeUpr)
  string(TOLOWER "${sLibType}" sLibTypeLwr)

  if(DEFINED _OPTDESC)
    set(sOptDesc ${_OPTDESC})
  else()
    set(sOptDesc "Build ${sLibTypeLwr} library.")
  endif()

  if(_C11)
    set(zPropertyCStd C_STANDARD 11 C_STANDARD_REQUIRED ON)
  elseif(_C99)
    set(zPropertyCStd C_STANDARD 99 C_STANDARD_REQUIRED ON)
  elseif(_C90)
    set(zPropertyCStd C_STANDARD 90 C_STANDARD_REQUIRED ON)
  else()
    set(zPropertyCStd)
  endif()

  if(_CXX17)
    set(zPropertyCxxStd CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX14)
    set(zPropertyCxxStd CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX11)
    set(zPropertyCxxStd CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
  elseif(_CXX98)
    set(zPropertyCxxStd CXX_STANDARD 98 CXX_STANDARD_REQUIRED ON)
  else()
    set(zPropertyCxxStd)
  endif()

  set(vOptName "${sNameUpr}_COMPILE_${sLibTypeUpr}")
  set(sTgtName "${sNameLwr}_${sLibTypeLwr}")
  if(DEFINED _TGTNAMEVAR)
    set(${_TGTNAMEVAR} "${sTgtName}" PARENT_SCOPE)
  endif()

  option(${vOptName} "${sOptDesc}" ON)
  if(NOT ${vOptName})
    return()
  endif()

  if(NOT _NOFLATGRP)
    source_group("\\" FILES ${_UNPARSED_ARGUMENTS})
  endif()
  add_library("${sTgtName}" ${sLibTypeUpr} ${_UNPARSED_ARGUMENTS})
  set_target_properties("${sTgtName}" PROPERTIES
    ${zPropertyCStd}
    ${zPropertyCxxStd}
    OUTPUT_NAME "${sName}" CLEAN_DIRECT_OUTPUT ON
    ${_PROPS})
  if(DEFINED _LINKS)
    target_link_libraries("${sTgtName}" ${_LINKS})
  endif()

  install(TARGETS "${sTgtName}" DESTINATION "lib")
endfunction()
