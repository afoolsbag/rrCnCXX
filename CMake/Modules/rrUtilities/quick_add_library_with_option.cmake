# zhengrr
# 2016-10-8 – 2018-1-31
# The MIT License

# .rst
# .. command:: quick_add_library_with_option
#
#    轻快生成库文件：
#    ::
#
#       quick_add_library_with_option(
#         [NAME name | SUBNAME subname]
#         [STATIC] [SHARED] [MODULE]
#         [C90 | C99 | C11]
#         [CXX98 | CXX11 | CXX14 | CXX17]
#         <source>...
#       )
#
#    影响：
#
#    :NAME:           ``<name>`` or ``<PROJECT_NAME>_<subname>`` or ``<PROJECT_NAME>``
#    :option:         ``<NAME_UPPER>_COMPILE_<STATIC|SHARED|MODULE>``
#    :add_executable: ``<NAME_LOWER>_<static|shared|module>``
#    :output:         ``<NAME>``
#    :install:        to ``lib``
#
function(quick_add_library_with_option)
  set(zOpts "STATIC" "SHARED" "MODULE" "C90" "C99" "C11" "CXX98" "CXX11" "CXX14" "CXX17")
  set(zOneValKws "NAME" "SUBNAME")
  set(zMutValKws)
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

  if(_STATIC OR ((NOT _STATIC) AND (NOT _SHARED) AND (NOT _MODULE) AND (NOT BUILD_SHARED_LIBS)))
    set(vOptName "${sNameUpr}_COMPILE_STATIC")
    set(sTgtName "${sNameLwr}_static")
    option(${vOptName} "Build static library." ON)
    if(${vOptName})
      add_library("${sTgtName}" STATIC ${_UNPARSED_ARGUMENTS})
      set_target_properties("${sTgtName}" PROPERTIES
        ${zPropertyCStd}
        ${zPropertyCxxStd}
        OUTPUT_NAME "${sName}" CLEAN_DIRECT_OUTPUT ON)
      install(TARGETS "${sTgtName}" DESTINATION "lib")
    endif()
  endif()

  if(_SHARED OR ((NOT _STATIC) AND (NOT _SHARED) AND (NOT _MODULE) AND (BUILD_SHARED_LIBS)))
    set(vOptName "${sNameUpr}_COMPILE_SHARED")
    set(sTgtName "${sNameLwr}_shared")
    option(${vOptName} "Build shared library." ON)
    if(${vOptName})
      add_library("${sTgtName}" SHARED ${_UNPARSED_ARGUMENTS})
      set_target_properties("${sTgtName}" PROPERTIES
        ${zPropertyCStd}
        ${zPropertyCxxStd}
        OUTPUT_NAME "${sName}" CLEAN_DIRECT_OUTPUT ON)
      install(TARGETS "${sTgtName}" DESTINATION "lib")
    endif()
  endif()

  if(_MODULE)
    set(vOptName "${sNameUpr}_COMPILE_MODULE")
    set(sTgtName "${sNameLwr}_module")
    option(${vOptName} "Build module library." ON)
    if(${vOptName})
      add_library("${sTgtName}" MODULE ${_UNPARSED_ARGUMENTS})
      set_target_properties("${sTgtName}" PROPERTIES
        ${zPropertyCStd}
        ${zPropertyCxxStd}
        OUTPUT_NAME "${sName}" CLEAN_DIRECT_OUTPUT ON)
      install(TARGETS "${sTgtName}" DESTINATION "lib")
    endif()
  endif()
endfunction()
