#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___               2017-12-18 – 2018-1-24
# | '__| '__| | | | __| | | | __| |/ _ / __|                     The MIT License
# | |  | |  | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   \___/ \__|_|_|_|\__|_|\___|___/ rrUtilities by FIGlet
#            _     _                _                  _                       _
#   __ _  __| | __| | ___ _   _ ___| |_ ___  _ __ ___ | |_ __ _ _ __ __ _  ___| |_
#  / _` |/ _` |/ _` |/ __| | | / __| __/ _ \| '_ ` _ \| __/ _` | '__/ _` |/ _ | __|
# | (_| | (_| | (_| | (__| |_| \__ | || (_) | | | | | | || (_| | | | (_| |  __| |_
#  \__,_|\__,_|\__,_|\___|\__,_|___/\__\___/|_| |_| |_|\__\__,_|_|  \__, |\___|\__|
#                                       add_custom_target by FIGlet |___/

# .rst
# .. command:: quick_add_executable_with_option
#
#    简便生成可执行文件 ::
#
#       quick_add_executable_with_option(
#         [SUBNAME subname]
#         [WIN32]
#         [C90 | C99 | C11]
#         [CXX98 | CXX11 | CXX14 | CXX17]
#         <source>...
#       )
#
#    参见
#
#    + `add_executable <https://cmake.org/cmake/help/latest/command/add_executable>`_
#    + `set_target_properties <https://cmake.org/cmake/help/latest/command/set_target_properties>`_
#    + `C_STANDARD <https://cmake.org/cmake/help/latest/prop_tgt/C_STANDARD>`_
#    + `CXX_STANDARD <https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD>`_
#
function(quick_add_executable_with_option)
  set(vOptions "WIN32" "C90" "C99" "C11" "CXX98" "CXX11" "CXX14" "CXX17")
  set(vOneValueKeywords "SUBNAME")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${vOptions}" "${vOneValueKeywords}" "")

  if(DEFINED _SUBNAME)
    set(sName "${PROJECT_NAME}_${_SUBNAME}")
  else()
    set(sName "${PROJECT_NAME}")
  endif()
  string(TOUPPER "${sName}" sNameUpper)
  string(TOLOWER "${sName}" sNameLower)

  if(_WIN32)
    set(win32 "WIN32")
  else()
    set(win32)
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

  set(vOption "${sNameUpper}_COMPILE_EXE")
  set(vTarget "${sNameLower}_exe")

  option(${vOption} "Build executable file." ON)
  if(NOT ${vOption})
    return()
  endif()

  add_executable(${vTarget} ${win32} ${_UNPARSED_ARGUMENTS})
  set_target_properties(${vTarget} PROPERTIES
    ${zPropertyCStd}
    ${zPropertyCxxStd}
    OUTPUT_NAME "${sName}" CLEAN_DIRECT_OUTPUT ON)
  install(TARGETS ${vTarget} DESTINATION "bin")
endfunction()
