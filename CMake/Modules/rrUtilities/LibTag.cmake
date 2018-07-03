# zhengrr
# 2018-06-06 – 2018-07-03
# The MIT License

#.rst:
# .. command:: get_toolset_tag
#
#    获取工具集标签：
#    ::
#
#       get_toolset_tag(
#         <variable>
#       )
#
#    参见：
#
#    + `<https://boost.org/doc/libs/1_67_0/more/getting_started/windows.html#library-naming>`_
#
function(get_toolset_tag _VARIABLE)
  get_cmake_property(zLangs ENABLED_LANGUAGES)
  foreach(sLang ${zLangs})
    if(CMAKE_${sLang}_COMPILER_ID STREQUAL "Intel")
      if(WIN32)
        set(${_VARIABLE} "iw" PARENT_SCOPE)
      else()
        set(${_VARIABLE} "il" PARENT_SCOPE)
      endif()
    elseif(GHSMULTI)
      set(${_VARIABLE} "ghs" PARENT_SCOPE)
    elseif(MSVC)
      if(MSVC_VERSION GREATER_EQUAL 1910)
        set(${_VARIABLE} "vc141" PARENT_SCOPE)
      elseif(MSVC14)
        set(${_VARIABLE} "vc140" PARENT_SCOPE)
      elseif(MSVC12)
        set(${_VARIABLE} "vc120" PARENT_SCOPE)
      elseif(MSVC11)
        set(${_VARIABLE} "vc110" PARENT_SCOPE)
      elseif(MSVC10)
        set(${_VARIABLE} "vc100" PARENT_SCOPE)
      elseif(MSVC90)
        set(${_VARIABLE} "vc90" PARENT_SCOPE)
      elseif(MSVC80)
        set(${_VARIABLE} "vc80" PARENT_SCOPE)
      elseif(MSVC71)
        set(${_VARIABLE} "vc71" PARENT_SCOPE)
      elseif(MSVC70)
        set(${_VARIABLE} "vc7" PARENT_SCOPE)
      elseif(MSVC60)
        set(${_VARIABLE} "vc6" PARENT_SCOPE)
      else()
        message(FATAL_ERROR "Unsupported MSVC_VERSION: ${MSVC_VERSION}.")
      endif()
    elseif(BORLAND)
      set(${_VARIABLE} "bcb" PARENT_SCOPE)
    elseif(CMAKE_${sLang}_COMPILER_ID STREQUAL "SunPro")
      set(${_VARIABLE} "sw" PARENT_SCOPE)
    elseif(CMAKE_${sLang}_COMPILER_ID STREQUAL "XL")
      set(${_VARIABLE} "xlc" PARENT_SCOPE)
    elseif(MINGW)
      string(REGEX REPLACE "([0-9]+)\\.([0-9]+)(\\.[0-9]+)?" "\\1\\2" sCompVer "${CMAKE_CXX_COMPILER_VERSION}")
      set(${_VARIABLE} "mgw${sCompVer}" PARENT_SCOPE)
    elseif(UNIX AND (CMAKE_COMPILER_IS_GNUC OR CMAKE_COMPILER_IS_GNUCXX))
      string(REGEX REPLACE "([0-9]+)\\.([0-9]+)(\\.[0-9]+)?" "\\1\\2" sCompVer "${CMAKE_CXX_COMPILER_VERSION}")
      if(APPLE)
        set(${_VARIABLE} "xgcc${sCompVer}" PARENT_SCOPE)
      else()
        set(${_VARIABLE} "gcc${sCompVer}" PARENT_SCOPE)
      endif()
    else()
      continue()
    endif()
    return()
  endforeach()
  set(${_VARIABLE} "" PARENT_SCOPE)
endfunction()

#.rst:
# .. command:: get_architecture_tag
#
#    获取架构标签：
#    ::
#
#       get_architecture_tag(
#         <variable>
#       )
#
function(get_architecture_tag _VARIABLE)
  get_cmake_property(zLangs ENABLED_LANGUAGES)
  foreach(sLang ${zLangs})
    if(CMAKE_${sLang}_COMPILER_ARCHITECTURE_ID STREQUAL "IA64")
      set(${_VARIABLE} "i" PARENT_SCOPE)
    elseif(CMAKE_${sLang}_COMPILER_ARCHITECTURE_ID MATCHES "^[Xx](86|64)$")
      set(${_VARIABLE} "x" PARENT_SCOPE)
    elseif(CMAKE_${sLang}_COMPILER_ARCHITECTURE_ID MATCHES "^ARM")
      set(${_VARIABLE} "a" PARENT_SCOPE)
    elseif(CMAKE_${sLang}_COMPILER_ARCHITECTURE_ID STREQUAL "MIPS")
      set(${_VARIABLE} "m" PARENT_SCOPE)
    else()
      continue()
    endif()
    return()
  endforeach()
  set(_VARIABLE "" PARENT_SCOPE)
endfunction()

#.rst:
# .. command::get_address_model_tag
#
#    获取地址模式标签：
#    ::
#
#       get_address_model_tag(
#         <variable>
#       )
#
function(get_address_model_tag _VARIABLE)
  if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(${_VARIABLE} "32" PARENT_SCOPE)
  elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(${_VARIABLE} "64" PARENT_SCOPE)
  else()
    message(FATAL_ERROR "Unsupported CMAKE_SIZEOF_VOID_P: ${CMAKE_SIZEOF_VOID_P}.")
  endif()
endfunction()

#.rst:
# .. command::get_architecture_address_model_tag
#
#    获取架构地址模式标签：
#    ::
#
#       get_architecture_address_model_tag(
#         <variable>
#       )
#
function(get_architecture_address_model_tag _VARIABLE)
  get_architecture_tag(sArch)
  get_address_model_tag(sAddr)
  set(${_VARIABLE} "${sArch}${sAddr}" PARENT_SCOPE)
endfunction()
