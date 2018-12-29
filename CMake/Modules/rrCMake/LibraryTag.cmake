# zhengrr
# 2018-06-06 – 2018-12-29
# Unlicense

include_guard()

if(NOT COMMAND check_name_with_cmake_rules)
  include("${CMAKE_CURRENT_LIST_DIR}/CheckName.cmake")
endif()

#.rst:
# .. command:: get_toolset_tag
#
#   获取工具集标签：::
#
#     get_toolset_tag(<result-variable>)
#
#   参见：
#
#   - `<https://boost.org/doc/libs/1_68_0/more/getting_started/windows.html#library-naming>`_
function(get_toolset_tag _RESULT_VARIABLE)
  check_name_with_cmake_rules("${_RESULT_VARIABLE}" WARNING)
  get_cmake_property(zLangs ENABLED_LANGUAGES)
  foreach(sLang ${zLangs})

    if(CMAKE_${sLang}_COMPILER_ID STREQUAL "Intel")
      if(WIN32)
        set(${_RESULT_VARIABLE} "iw" PARENT_SCOPE)
      else()
        set(${_RESULT_VARIABLE} "il" PARENT_SCOPE)
      endif()
      return()
    endif()

    if(GHSMULTI)
      set(${_RESULT_VARIABLE} "ghs" PARENT_SCOPE)
      return()
    endif()

    if(MSVC)
      if(MSVC_VERSION GREATER_EQUAL 1910)
        set(${_RESULT_VARIABLE} "vc141" PARENT_SCOPE)
      elseif(MSVC14)
        set(${_RESULT_VARIABLE} "vc140" PARENT_SCOPE)
      elseif(MSVC12)
        set(${_RESULT_VARIABLE} "vc120" PARENT_SCOPE)
      elseif(MSVC11)
        set(${_RESULT_VARIABLE} "vc110" PARENT_SCOPE)
      elseif(MSVC10)
        set(${_RESULT_VARIABLE} "vc100" PARENT_SCOPE)
      elseif(MSVC90)
        set(${_RESULT_VARIABLE} "vc90" PARENT_SCOPE)
      elseif(MSVC80)
        set(${_RESULT_VARIABLE} "vc80" PARENT_SCOPE)
      elseif(MSVC71)
        set(${_RESULT_VARIABLE} "vc71" PARENT_SCOPE)
      elseif(MSVC70)
        set(${_RESULT_VARIABLE} "vc7" PARENT_SCOPE)
      elseif(MSVC60)
        set(${_RESULT_VARIABLE} "vc6" PARENT_SCOPE)
      else()
        message(FATAL_ERROR "Unsupported MSVC_VERSION: ${MSVC_VERSION}.")
      endif()
      return()
    endif()

    if(BORLAND)
      set(${_RESULT_VARIABLE} "bcb" PARENT_SCOPE)
      return()
    endif()

    if(CMAKE_${sLang}_COMPILER_ID STREQUAL "SunPro")
      set(${_RESULT_VARIABLE} "sw" PARENT_SCOPE)
      return()
    endif()

    if(CMAKE_${sLang}_COMPILER_ID STREQUAL "XL")
      set(${_RESULT_VARIABLE} "xlc" PARENT_SCOPE)
      return()
    endif()

    if(MINGW)
      string(REGEX REPLACE "([0-9]+)\\.([0-9]+)(\\.[0-9]+)?" "\\1\\2" sVer "${CMAKE_CXX_COMPILER_VERSION}")
      set(${_RESULT_VARIABLE} "mgw${sVer}" PARENT_SCOPE)
      return()
    endif()

    if(UNIX AND (CMAKE_COMPILER_IS_GNUC OR CMAKE_COMPILER_IS_GNUCXX))
      string(REGEX REPLACE "([0-9]+)\\.([0-9]+)(\\.[0-9]+)?" "\\1\\2" sVer "${CMAKE_CXX_COMPILER_VERSION}")
      if(APPLE)
        set(${_RESULT_VARIABLE} "xgcc${sVer}" PARENT_SCOPE)
      else()
        set(${_RESULT_VARIABLE} "gcc${sVer}" PARENT_SCOPE)
      endif()
      return()
    endif()

  endforeach()
  set(${_RESULT_VARIABLE} "" PARENT_SCOPE)
endfunction()

#.rst:
# .. command:: get_architecture_tag
#
#   获取架构标签::
#
#     get_architecture_tag(<result-variable>)
function(get_architecture_tag _RESULT_VARIABLE)
  get_cmake_property(zLangs ENABLED_LANGUAGES)
  foreach(sLang ${zLangs})

    if(CMAKE_${sLang}_COMPILER_ARCHITECTURE_ID STREQUAL "IA64")
      set(${_RESULT_VARIABLE} "i" PARENT_SCOPE)
      return()
    endif()

    if(CMAKE_${sLang}_COMPILER_ARCHITECTURE_ID MATCHES "^[Xx](86|64)$")
      set(${_RESULT_VARIABLE} "x" PARENT_SCOPE)
      return()
    endif()

    if(CMAKE_${sLang}_COMPILER_ARCHITECTURE_ID MATCHES "^ARM")
      set(${_RESULT_VARIABLE} "a" PARENT_SCOPE)
      return()
    endif()

    if(CMAKE_${sLang}_COMPILER_ARCHITECTURE_ID STREQUAL "MIPS")
      set(${_RESULT_VARIABLE} "m" PARENT_SCOPE)
      return()
    endif()

  endforeach()
  set(${_RESULT_VARIABLE} "" PARENT_SCOPE)
endfunction()

#.rst:
# .. command::get_address_model_tag
#
#   获取地址模型标签::
#
#     get_address_model_tag(<result-variable>)
function(get_address_model_tag _RESULT_VARIABLE)
  if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(${_RESULT_VARIABLE} "32" PARENT_SCOPE)
  elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(${_RESULT_VARIABLE} "64" PARENT_SCOPE)
  else()
    message(FATAL_ERROR "Unsupported CMAKE_SIZEOF_VOID_P: ${CMAKE_SIZEOF_VOID_P}.")
  endif()
endfunction()

#.rst:
# .. command::get_architecture_address_model_tag
#
#   获取架构和地址模型标签::
#
#     get_architecture_address_model_tag(<result-variable>)
function(get_architecture_address_model_tag _RESULT_VARIABLE)
  get_architecture_tag(sArch)
  get_address_model_tag(sAddr)
  set(${_RESULT_VARIABLE} "${sArch}${sAddr}" PARENT_SCOPE)
endfunction()

#.rst
# .. command::get_toolset_architecture_address_model_tag
#
#   获取工具集、架构和地址模型标签::
#
#     get_toolset_architecture_address_model_tag(<result-variable>)
function(get_toolset_architecture_address_model_tag _RESULT_VARIABLE)
  get_toolset_tag(sTool)
  get_architecture_tag(sArch)
  get_address_model_tag(sAddr)
  set(${_RESULT_VARIABLE} "${sTool}${sArch}${sAddr}" PARENT_SCOPE)
endfunction()
