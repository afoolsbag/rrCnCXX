# zhengrr
# 2016-10-08 – 2019-03-19
# Unlicense

include_guard()

cmake_minimum_required(VERSION 3.3)
cmake_policy(SET CMP0057 NEW) #3.3+

#.rst:
# .. command:: compile_option
#
#   调整编译配置::
#
#     compile_option(
#       [ANALYZE]
#       [DISABLE_LANGUAGE_EXTENSIONS]
#       [HIGHEST_WARNING_LEVEL | RECOMMENDED_WARNING_LEVEL]
#       [MULTIPLE_PROCESSES]
#       [UTF-8]
#       [WARNING_AS_ERROR]
#     )
#
#   参见：
#
#   - `add_compile_options <https://cmake.org/cmake/help/latest/command/add_compile_options.html>`_
#
#   - `<https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html>`_
#
#   - `<https://docs.microsoft.com/cpp/build/reference/analyze-code-analysis>`_
#   - `<https://docs.microsoft.com/cpp/build/reference/compiler-option-warning-level>`_
#   - `<https://docs.microsoft.com/cpp/build/reference/mp-build-with-multiple-processes>`_
#   - `<https://docs.microsoft.com/cpp/build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8>`_
#   - `<https://docs.microsoft.com/cpp/build/reference/za-ze-disable-language-extensions>`_
function(compile_option)
  set(zOptKws    ANALYZE
                 DISABLE_LANGUAGE_EXTENSIONS
                 HIGHEST_WARNING_LEVEL
                 MULTIPLE_PROCESSES
                 RECOMMENDED_WARNING_LEVEL
                 UTF-8
                 WARNING_AS_ERROR)
  set(zOneValKws)
  set(zMutValKws)
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unexpected arguments: ${_UNPARSED_ARGUMENTS}.")
  endif()

  if(_ANALYZE)
    if(1910 LESS_EQUAL MSVC_VERSION AND CMAKE_CXX_COMPILER)
      add_compile_options("/analyze" "/analyze:WX-" "/analyze:ruleset AllRules.ruleset")
    endif()
  endif()

  if(_DISABLE_LANGUAGE_EXTENSIONS)
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
      add_compile_options("-Wpedantic")
    endif()
    if(MSVC AND NOT CMAKE_CXX_COMPILER)
      add_compile_options("/Za")
    endif()
  endif()

  if(_HIGHEST_WARNING_LEVEL)
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
      add_compile_options("-Wall" "-Wextra")
    endif()
    if(MSVC)
      add_compile_options("/Wall")
    endif()
  elseif(_RECOMMENDED_WARNING_LEVEL)
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
      add_compile_options("-Wall")
    endif()
    if(MSVC)
      add_compile_options("/W4")
    endif()
  endif()

  if(_MULTIPLE_PROCESSES)
    if(MSVC)
      add_compile_options("/MP")
    endif()
  endif()

  if(_UTF-8)
    if(MSVC)
      add_compile_options("/utf-8")
    endif()
  endif()

  if(_WARNING_AS_ERROR)
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
      add_compile_options("-Werror")
    endif()
    if (MSVC)
      add_compile_options("/WX")
    endif()
  endif()
endfunction()
