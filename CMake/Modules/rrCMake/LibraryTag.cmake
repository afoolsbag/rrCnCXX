# zhengrr
# 2018-06-06 – 2019-04-17
# Unlicense

cmake_minimum_required(VERSION 3.10)
cmake_policy(VERSION 3.10)

include_guard()

#.rst:
# .. command:: get_toolset_tag
#
#   获取工具集标签（get toolset tag）。
#
#   .. code-block:: cmake
#
#     get_toolset_tag(
#       <variable>
#     )
#
#   参见：
#
#   - `<https://boost.org/doc/libs/1_70_0/more/getting_started/windows.html#library-naming>`_
function(get_toolset_tag _VARIABLE)
  get_cmake_property(zLangs ENABLED_LANGUAGES)
  foreach(sL IN LISTS zLangs)

    if(CMAKE_${sL}_COMPILER_ID STREQUAL "Intel")
      if(WIN32)
        set(${_VARIABLE} "iw" PARENT_SCOPE)
      else()
        set(${_VARIABLE} "il" PARENT_SCOPE)
      endif()
      return()
    endif()

    if(GHS-MULTI)
      set(${_VARIABLE} "ghs" PARENT_SCOPE)
      return()
    endif()

    if(MSVC)
      if(1920 LESS_EQUAL MSVC_VERSION)
        set(${_VARIABLE} "vc142" PARENT_SCOPE)
      elseif(1910 LESS_EQUAL MSVC_VERSION)
        set(${_VARIABLE} "vc141" PARENT_SCOPE)
      elseif(1900 LESS_EQUAL MSVC_VERSION)
        set(${_VARIABLE} "vc140" PARENT_SCOPE)
      elseif(1800 LESS_EQUAL MSVC_VERSION)
        set(${_VARIABLE} "vc120" PARENT_SCOPE)
      elseif(1700 LESS_EQUAL MSVC_VERSION)
        set(${_VARIABLE} "vc110" PARENT_SCOPE)
      elseif(1600 LESS_EQUAL MSVC_VERSION)
        set(${_VARIABLE} "vc100" PARENT_SCOPE)
      elseif(1500 LESS_EQUAL MSVC_VERSION)
        set(${_VARIABLE} "vc90" PARENT_SCOPE)
      elseif(1400 LESS_EQUAL MSVC_VERSION)
        set(${_VARIABLE} "vc80" PARENT_SCOPE)
      elseif(1310 LESS_EQUAL MSVC_VERSION)
        set(${_VARIABLE} "vc71" PARENT_SCOPE)
      elseif(1300 LESS_EQUAL MSVC_VERSION)
        set(${_VARIABLE} "vc7" PARENT_SCOPE)
      elseif(1200 LESS_EQUAL MSVC_VERSION)
        set(${_VARIABLE} "vc6" PARENT_SCOPE)
      else()
        set(${_VARIABLE} "vc" PARENT_SCOPE)
      endif()
      return()
    endif()

    if(BORLAND)
      set(${_VARIABLE} "bcb" PARENT_SCOPE)
      return()
    endif()

    if(CMAKE_${sL}_COMPILER_ID STREQUAL "SunPro")
      set(${_VARIABLE} "sw" PARENT_SCOPE)
      return()
    endif()

    if(CMAKE_${sL}_COMPILER_ID STREQUAL "XL")
      set(${_VARIABLE} "xlc" PARENT_SCOPE)
      return()
    endif()

    if(MINGW)
      string(REGEX REPLACE "([0-9]+)\\.([0-9]+)(\\.[0-9]+)?" "\\1\\2" sVer "${CMAKE_${sL}_COMPILER_VERSION}")
      set(${_VARIABLE} "mgw${sVer}" PARENT_SCOPE)
      return()
    endif()

    if(UNIX AND CMAKE_${sL}_COMPILER_ID STREQUAL "GNU")
      string(REGEX REPLACE "([0-9]+)\\.([0-9]+)(\\.[0-9]+)?" "\\1\\2" sVer "${CMAKE_${sL}_COMPILER_VERSION}")
      if(APPLE)
        set(${_VARIABLE} "xgcc${sVer}" PARENT_SCOPE)
      else()
        set(${_VARIABLE} "gcc${sVer}" PARENT_SCOPE)
      endif()
      return()
    endif()

    if(UNIX AND CMAKE_${sL}_COMPILER_ID STREQUAL "Clang")
      string(REGEX REPLACE "([0-9]+)\\.([0-9]+)(\\.[0-9]+)?" "\\1\\2" sVer "${CMAKE_${sL}_COMPILER_VERSION}")
      set(${_VARIABLE} "clang${sVer}" PARENT_SCOPE)
      return()
    endif()

  endforeach()
  set(${_VARIABLE} "" PARENT_SCOPE)
endfunction()

#.rst:
# .. command:: get_architecture_tag
#
#   获取架构标签（get architecture tag）。
#
#   .. code-block:: cmake
#
#     get_architecture_tag(
#       <variable>
#     )
function(get_architecture_tag _VARIABLE)
  get_cmake_property(zLangs ENABLED_LANGUAGES)
  foreach(sL IN LISTS zLangs)

    if(CMAKE_${sL}_COMPILER_ARCHITECTURE_ID STREQUAL "IA64")
      set(${_VARIABLE} "i" PARENT_SCOPE)
      return()
    endif()

    if(CMAKE_${sL}_COMPILER_ARCHITECTURE_ID MATCHES "^[Xx](86|64)$")
      set(${_VARIABLE} "x" PARENT_SCOPE)
      return()
    endif()

    if(CMAKE_${sL}_COMPILER_ARCHITECTURE_ID MATCHES "^ARM")
      set(${_VARIABLE} "a" PARENT_SCOPE)
      return()
    endif()

    if(CMAKE_${sL}_COMPILER_ARCHITECTURE_ID STREQUAL "MIPS")
      set(${_VARIABLE} "m" PARENT_SCOPE)
      return()
    endif()

  endforeach()
  set(${_VARIABLE} "" PARENT_SCOPE)
endfunction()

#.rst:
# .. command::get_address_model_tag
#
#   获取地址模型标签（get address model tag）。
#
#   .. code-block:: cmake
#
#     get_address_model_tag(
#       <variable>
#     )
function(get_address_model_tag _VARIABLE)
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(${_VARIABLE} "64" PARENT_SCOPE)
    return()
  endif()

  if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(${_VARIABLE} "32" PARENT_SCOPE)
    return()
  endif()

  set(${_VARIABLE} "" PARENT_SCOPE)
endfunction()

#.rst:
# .. command::get_architecture_address_model_tag
#
#   获取架构和地址模型标签（get architecture address model tag）。
#
#   .. code-block:: cmake
#
#     get_architecture_address_model_tag(
#       <variable>
#     )
function(get_architecture_address_model_tag _VARIABLE)
  get_architecture_tag(sArch)
  get_address_model_tag(sAddr)
  set(${_VARIABLE} "${sArch}${sAddr}" PARENT_SCOPE)
endfunction()

#.rst:
# .. command::get_toolset_architecture_address_model_tag
#
#   获取工具集、架构和地址模型标签（get toolset architecture address model tag）。
#
#   .. code-block:: cmake
#
#     get_toolset_architecture_address_model_tag(
#       <variable>
#     )
function(get_toolset_architecture_address_model_tag _VARIABLE)
  get_toolset_tag(sTool)
  get_architecture_tag(sArch)
  get_address_model_tag(sAddr)
  set(${_VARIABLE} "${sTool}${sArch}${sAddr}" PARENT_SCOPE)
endfunction()
