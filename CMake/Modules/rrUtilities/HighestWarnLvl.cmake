# zhengrr
# 2016-10-08 – 2018-04-11
# The MIT License

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

#.rst:
# .. command:: highest_warning_level
#
#    尝试将编译器警告等级调整至最高：
#    ::
#
#       highest_warning_level(
#         [AS_ERROR]
#       )
#
#    参见：
#
#    + `CMAKE_<LANG>_FLAGS <https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_FLAGS>`_
#    + `<https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html>`_
#    + `<https://docs.microsoft.com/cpp/build/reference/compiler-option-warning-level>`_
#
function(highest_warning_level)
  set(zOptKws "AS_ERROR")
  set(zOneValKws)
  set(zMutValKws)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  get_property(zLangs GLOBAL PROPERTY ENABLED_LANGUAGES)

  set(wFlags)
  if(C IN_LIST zLangs)
    list(APPEND wFlags CMAKE_C_FLAGS)
  endif()
  if(CXX IN_LIST zLangs)
    list(APPEND wFlags CMAKE_CXX_FLAGS)
  endif()

  foreach(vFlag ${wFlags})
    if(CMAKE_COMPILER_IS_GNUCC)
      string(STRIP "${${vFlag}}" ${vFlag})
      string(CONCAT ${vFlag} "${${vFlag}}" " -Wall -Wextra")
      if(_AS_ERROR)
        string(CONCAT ${vFlag} "${${vFlag}}" " -Werror")
      endif()
    elseif(MSVC)
      string(STRIP "${${vFlag}}" ${vFlag})
      string(CONCAT ${vFlag} "${${vFlag}}" " /Wall")
      if(_AS_ERROR)
        string(CONCAT ${vFlag} "${${vFlag}}" " /WX")
      endif()
    endif()
    set(${vFlag} "${${vFlag}}" PARENT_SCOPE)
  endforeach()
endfunction()
