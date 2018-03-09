# zhengrr
# 2018-2-24 – 2018-2-27
# The MIT License

include("${CMAKE_CURRENT_LIST_DIR}/FacileAddExe.cmake")

# .rst
# .. command:: facile_add_opencv_executable
#
#    以``facile_add_executable``命令为基础，额外约定了若干默认参数：
#
#    额外约定：
#
#    :include_directories: ``${OpenCV_INCLUDE_DIRS}``
#    :OPTDESC:             see code
#    :LINKS:               ``${OpenCV_LIBS}``
#
#    参见：
#
#    + `"include_directories" <https://cmake.org/cmake/help/latest/command/include_directories>`_. *CMake Documentation*.
#    + `"INCLUDE_DIRECTORIES" <https://cmake.org/cmake/help/latest/prop_dir/INCLUDE_DIRECTORIES>`_. *CMake Documentation*.
#
function(facile_add_opencv_executable)
  if(NOT OpenCV_FOUND)
    find_package(OpenCV)
  endif()
  if(NOT OpenCV_FOUND)
    message(WARNING "OpenCV is needed to build executable with OpenCV.")
  endif()

  set(zOptKws)
  set(zOneValKws "OPTDESC")
  set(zMutValKws "LINKS")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  if(DEFINED _OPTDESC)
    set(sOptDesc ${_OPTDESC})
  else()
    set(sOptDesc "Build executable with OpenCV (requires OpenCV).")
  endif()

  foreach(sInclDir IN LISTS OpenCV_INCLUDE_DIRS)
    if(NOT sInclDir IN_LIST INCLUDE_DIRECTORIES)
      include_directories(${sInclDir})
    endif()
  endforeach()

  foreach(sLib IN LISTS OpenCV_LIBS)
    if(NOT sLib IN_LIST _LINKS)
      list(APPEND _LINKS ${sLib})
    endif()
  endforeach()

  facile_add_executable(${_UNPARSED_ARGUMENTS} OPTDESC "${sOptDesc}" LINKS ${_LINKS})
endfunction()