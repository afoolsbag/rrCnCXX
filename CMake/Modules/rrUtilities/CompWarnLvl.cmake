# zhengrr
# 2016-10-08 – 2018-07-03
# The MIT License

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

#.rst:
# .. command:: compiler_warning_level
#
#    调整编译器警告等级（和其它配置）：
#    ::
#
#       compiler_warning_level(
#         [HIGHEST] [AS_ERROR]
#         [UTF-8]
#         [ANALYZE]
#       )
#
#    参见：
#
#    + `CMAKE_<LANG>_FLAGS <https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_FLAGS>`_
#    + `add_compile_options <https://cmake.org/cmake/help/latest/command/add_compile_options.html>`_
#    + `<https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html>`_
#    + `<https://docs.microsoft.com/cpp/build/reference/compiler-option-warning-level>`_
#    + `<https://docs.microsoft.com/cpp/build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8>`_
#    + `<https://docs.microsoft.com/cpp/build/reference/analyze-code-analysis>`_
#
function(compiler_warning_level)
  set(zOptKws    HIGHEST AS_ERROR UTF-8 ANALYZE)
  set(zOneValKws)
  set(zMutValKws)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
    return()
  endif()

  if(_HIGHEST)
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
      add_compile_options("-Wall")
      add_compile_options("-Wextra")
    elseif(MSVC)
      add_compile_options("/Wall")
    endif()
  endif()

  if(_AS_ERROR)
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
      add_compile_options("-Werror")
    elseif(MSVC)
      add_compile_options("/WX")
    endif()
  endif()

  if(_UTF-8)
    if(MSVC)
      add_compile_options("/utf-8")
    endif()
  endif()

  if(_ANALYZE)
    if(MSVC)
      add_compile_options("/analyze")
    endif()
  endif()
endfunction()
