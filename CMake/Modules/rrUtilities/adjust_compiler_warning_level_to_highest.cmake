#            _   _ _   _ _ _ _   _
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___
# | '__| '__| | | | __| | | | __| |/ _ / __|
# | |  | |  | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   \___/ \__|_|_|_|\__|_|\___|___/
#        rrUtilities by FIGlet  _               _
#                           ___| |__   ___  ___| | _ _ __   __ _ _ __ ___   ___
#                          / __| '_ \ / _ \/ __| |/ | '_ \ / _` | '_ ` _ \ / _ \
# zhengrr                 | (__| | | |  __| (__|   <| | | | (_| | | | | | |  __/
# 2016-10-8 – 2018-1-26    \___|_| |_|\___|\___|_|\_|_| |_|\__,_|_| |_| |_|\___|
# The MIT License                                           check_name by FIGlet

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
cmake_policy(SET CMP0057 NEW) #3.3+

#.rst:
# .. command:: adjust_compiler_warning_level_to_highest
#
#    尝试将编译器警告等级调整至最高::
#
#       adjust_compiler_warning_level_to_highest()
#
#    参见
#
#    + `CMAKE_<LANG>_FLAGS <https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_FLAGS>`_
#
function(adjust_compiler_warning_level_to_highest)
  get_property(langs GLOBAL PROPERTY ENABLED_LANGUAGES)

  if("C" IN_LIST langs)
    if(CMAKE_COMPILER_IS_GNUCC)
      string(CONCAT CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" " -Wall ")
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

  if("CXX" IN_LIST langs)
    if(CMAKE_COMPILER_IS_GNUCXX)
      string(CONCAT CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" " -Wall ")
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
