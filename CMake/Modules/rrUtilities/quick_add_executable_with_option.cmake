# zhengrr
# 2017-12-18 – 2018-1-31
# The MIT License

# .rst
# .. command:: quick_add_executable_with_option
#
#    轻快生成可执行文件：
#    ::
#
#       quick_add_executable_with_option(
#         [NAME name | SUBNAME subname]
#         [WIN32]
#         [C90 | C99 | C11]
#         [CXX98 | CXX11 | CXX14 | CXX17]
#         <source>...
#       )
#
#    作用：
#
#    :NAME:           ``<name>`` or ``<PROJECT_NAME>_<subname>`` or ``<PROJECT_NAME>``
#    :option:         ``<NAME_UPPER>_COMPILE_EXE``
#    :add_executable: ``<NAME_LOWER>_exe``
#    :output:         ``<NAME>``
#    :install:        to ``bin``
#
#    参见
#
#    + `"add_executable" <https://cmake.org/cmake/help/latest/command/add_executable>`_. *CMake Documentation*.
#    + `"set_target_properties" <https://cmake.org/cmake/help/latest/command/set_target_properties>`_. *CMake Documentation*.
#    + `"C_STANDARD" <https://cmake.org/cmake/help/latest/prop_tgt/C_STANDARD>`_. *CMake Documentation*.
#    + `"CXX_STANDARD" <https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD>`_. *CMake Documentation*.
#
function(quick_add_executable_with_option)
  set(zOptKws "WIN32" "C90" "C99" "C11" "CXX98" "CXX11" "CXX14" "CXX17")
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
    OUTPUT_NAME "${sName}" CLEAN_DIRECT_OUTPUT ON)

  install(TARGETS "${sTgtName}" DESTINATION "bin")
endfunction()
