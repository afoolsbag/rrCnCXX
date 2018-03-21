# zhengrr
# 2018-03-21 – 21
# The MIT License

include("${CMAKE_CURRENT_LIST_DIR}/FacileAddExe.cmake")

# .rst
# .. command:: facile_add_ice_executable
#
#    以``facile_add_executable``命令为基础，额外约定了若干默认参数：
#
#    额外约定：
#
#    :OPTDESC:             see code
#    :include_directories: ``${Ice_INCLUDE_DIRS}``
#    :LINKS:               ``${Ice_LIBRARIES}``
#    :SLICEDIR:            ``ice``
#
#    参见：
#
#    + `"FindIce" <https://cmake.org/cmake/help/latest/module/FindIce>`_. *CMake Documentation*.
#
function(facile_add_ice_executable)
  if(NOT ICE_FOUND)
    find_package(Ice)
  endif()
  if(NOT ICE_FOUND)
    message(WARNING "ICE is needed to build executable with ICE.")
  endif()

  set(zOptKws)
  set(zOneValKws "TGTNAMEVAR" "OPTDESC" "SLICEDIR")
  set(zMutValKws "LINKS")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  if(DEFINED _OPTDESC)
    set(sOptDesc ${_OPTDESC})
  else()
    set(sOptDesc "Build executable with ICE (requires ICE).")
  endif()

  if(DEFINED _SLICEDIR)
    set(sSliceDir ${_SLICEDIR})
  else()
    set(sSliceDir "ice")
  endif()

  file(GLOB zSliceIces "${sSliceDir}/*.ice")
  string(REGEX REPLACE ".ice$" ".h" zSliceHdrs ${zSliceIces})
  string(REGEX REPLACE ".ice$" ".cpp" zSliceSrcs ${zSliceIces})

  if(Ice_INCLUDE_DIRS)
    foreach(sInclDir IN LISTS Ice_INCLUDE_DIRS)
      if(NOT sInclDir IN_LIST INCLUDE_DIRECTORIES)
        include_directories("${sInclDir}")
      endif()
    endforeach()
  endif()

  if(Ice_LIBRARIES)
    foreach(sLib IN LISTS Ice_LIBRARIES)
      if(NOT sLib IN_LIST _LINKS)
        list(APPEND _LINKS "${sLib}")
      endif()
    endforeach()
  endif()

  if(Ice_SLICE2CPP_EXECUTABLE)
    if(NOT sSliceDir IN_LIST INCLUDE_DIRECTORIES)
      include_directories("${sSliceDir}")
    endif()
    get_filename_component(sSliceDirAbs "${sSliceDir}" ABSOLUTE)
    execute_process(
      COMMAND "${Ice_SLICE2CPP_EXECUTABLE}" "${zSliceIces}"
      WORKING_DIRECTORY "${sSliceDirAbs}"
    )
  else()
    unset(zSliceHdrs)
    unset(zSliceSrcs)
  endif()

  facile_add_executable(
    TGTNAMEVAR sTgtName OPTDESC "${sOptDesc}"
    ${zSliceIces} ${zSliceHdrs} ${zSliceSrcs} ${_UNPARSED_ARGUMENTS}
    LINKS ${_LINKS})
  source_group("\\ice" FILES ${zSliceHdrs} ${zSliceSrcs})
  if(DEFINED _TGTNAMEVAR)
    set(${_TGTNAMEVAR} "${sTgtName}" PARENT_SCOPE)
  endif()

endfunction()
