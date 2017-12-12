# zhengrr
# 2016-10-8 – 2017-12-12
# The MIT License

#.rst:
# CompilerWarningLevel
# --------------------
#
# 此模块提供了若干指令，用于配置编译器警告等级。
#
# 须 CMake 3.3 及以上版本。
#
# 典型用法形如：
#
# .. code-block:: cmake
#
#  project("<project>")
#  # ...
#  adjust_compiler_warning_level_to_highest()
#  # ...
#
# 参见：
#
# + `GCC Warning Options <https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html>`_
# + `VC++ Warning Level <https://msdn.microsoft.com/library/thxezb7y.aspx>`_

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW)  # CMake 3.3+

#.rst:
# .. command:: adjust_compiler_warning_level_to_highest
#
#  此指令尝试将编译器警告等级调整至最高::
#
#   adjust_compiler_warning_level_to_highest()
function(adjust_compiler_warning_level_to_highest)
  get_property(langs GLOBAL PROPERTY ENABLED_LANGUAGES)
  # C language
  if("C" IN_LIST langs)
    # GCC C
    if(CMAKE_COMPILER_IS_GNUCC)
      string(CONCAT CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" " -Wall ")
    # Visual C++
    elseif(MSVC)
      if(CMAKE_C_FLAGS MATCHES "/Wall")
      elseif(CMAKE_C_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/Wall" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
      else()
        string(CONCAT CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" " /Wall ")
      endif()
    endif()
    set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} PARENT_SCOPE)
  endif()
  # C++ language
  if("CXX" IN_LIST langs)
    # GCC C++
    if(CMAKE_COMPILER_IS_GNUCXX)
      string(CONCAT CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" " -Wall ")
    # Visual C++
    elseif(MSVC)
      if(CMAKE_CXX_FLAGS MATCHES "/Wall")
      elseif(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/Wall" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
      else()
        string(CONCAT CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" " /Wall ")
      endif()
    endif()
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} PARENT_SCOPE)
  endif()
endfunction()
