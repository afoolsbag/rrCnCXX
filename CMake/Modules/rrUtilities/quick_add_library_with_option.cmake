# zhengrr
# 2016-10-8 – 2018-1-30
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
#    :option:                ``<NAME_UPPER>_COMPILE_<STATIC|SHARED|MODULE>``
#    :add_executable:        ``<NAME_LOWER>_<static|shared|module>``
#    :set_target_properties: ``OUTPUT_NAME <NAME>``
#    :install:               to ``lib``
#
function(quick_add_library_with_option)
  set(zOpts "STATIC" "SHARED" "MODULE" "C90" "C99" "C11" "CXX98" "CXX11" "CXX14" "CXX17")
  set(zOneValKws "NAME" "SUBNAME")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOpts}" "${zOneValKws}" "")

  if(DEFINED _NAME)
    set(sName "${_NAME}")
  elseif(DEFINED _SUBNAME)
    set(sName "${PROJECT_NAME}${_SUBNAME}")
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
    set(vTgtName "${sNameLwr}_static")
    option(${vOptName} "Build static library." ON)
    if(${vOptName})
      add_library(${vTgtName} STATIC ${_UNPARSED_ARGUMENTS})
      set_target_properties(${vTgtName} PROPERTIES
        ${zPropertyCStd}
        ${zPropertyCxxStd}
        OUTPUT_NAME "${sName}" CLEAN_DIRECT_OUTPUT ON)
      install(TARGETS ${vTgtName} DESTINATION "lib")
    endif()
  endif()

  if(_SHARED OR ((NOT _STATIC) AND (NOT _SHARED) AND (NOT _MODULE) AND (BUILD_SHARED_LIBS)))
    set(vOptName "${sNameUpr}_COMPILE_SHARED")
    set(vTgtName "${sNameLwr}_shared")
    option(${vOptName} "Build shared library." ON)
    if(${vOptName})
      add_library(${vTgtName} SHARED ${_UNPARSED_ARGUMENTS})
      set_target_properties(${vTgtName} PROPERTIES
        ${zPropertyCStd}
        ${zPropertyCxxStd}
        OUTPUT_NAME "${sName}" CLEAN_DIRECT_OUTPUT ON)
      install(TARGETS ${vTgtName} DESTINATION "lib")
    endif()
  endif()

  if(_MODULE)
    set(vOptName "${sNameUpr}_COMPILE_MODULE")
    set(vTgtName "${sNameLwr}_module")
    option(${vOptName} "Build module library." ON)
    if(${vOptName})
      add_library(${vTgtName} MODULE ${_UNPARSED_ARGUMENTS})
      set_target_properties(${vTgtName} PROPERTIES
        ${zPropertyCStd}
        ${zPropertyCxxStd}
        OUTPUT_NAME "${sName}" CLEAN_DIRECT_OUTPUT ON)
      install(TARGETS ${vTgtName} DESTINATION "lib")
    endif()
  endif()
endfunction()
