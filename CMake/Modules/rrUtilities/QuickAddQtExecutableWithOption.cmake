# zhengrr
# 2018-1-30 – 31
# The MIT License

# .rst
# .. command:: quick_add_qt_executable_with_option
#
#    简便生成可执行文件：
#    ::
#
#       quick_add_qt_executable_with_option(
#         [NAME name | SUBNAME subname]
#         [WIN32]
#         [C90 | C99 | C11]
#         [CXX98 | CXX11 | CXX14 | CXX17]
#         <source>...
#         MODULES <qt5 libraries>...
#       )
#
function(quick_add_qt_executable_with_option)
  set(zOptKws "WIN32" "C90" "C99" "C11" "CXX98" "CXX11" "CXX14" "CXX17")
  set(zOneValKws "NAME" "SUBNAME")
  set(zMutValKws "MODULES")
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

  if(_WIN32)
    set(sWin32 "WIN32")
  else()
    set(sWin32)
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

  set(vOptName "${sNameUpr}_COMPILE_EXE")
  set(sTgtName "${sNameLwr}_exe")

  option(${vOptName} "Build executable file." ON)
  if(NOT ${vOptName})
    return()
  endif()

  add_executable("${sTgtName}" ${sWin32} ${_UNPARSED_ARGUMENTS})
  set_target_properties("${sTgtName}" PROPERTIES
    ${zPropertyCStd}
    ${zPropertyCxxStd}
    OUTPUT_NAME "${sName}" CLEAN_DIRECT_OUTPUT ON
    AUTOMOC ON AUTOUIC ON AUTORCC ON)
  target_link_libraries("${sTgtName}" ${_MODULES})

  install(TARGETS "${sTgtName}" DESTINATION "bin")
endfunction()

# .rst
# .. command:: quick_qt_executable
#
#    同``quick_add_qt_executable_with_option``。
#
macro(quick_qt_executable)
  quick_add_qt_executable_with_option(${ARGN})
endmacro()
