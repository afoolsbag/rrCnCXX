# zhengrr
# 2017-12-17 – 2018-03-21
# The MIT License

# .rst
# .. command:: facile_add_gtest_executable
#
#    以``facile_add_executable``命令为基础，额外约定了若干默认参数：
#
#    额外约定：
#
#    :include_directories: ``${GTEST_INCLUDE_DIRS}``
#    :OPTDESC:             see code
#    :LINKS:               ``${GTEST_BOTH_LIBRARIES}``
#
function(facile_add_gtest_executable)
  if(NOT GTEST_FOUND)
    set(GTEST_ROOT "${GTEST_ROOT}" CACHE PATH "The root directory of the GTest installation.")
    find_package(GTest)
  endif()
  if(NOT GTEST_FOUND)
    message(WARNING "GTest is needed to build executable with GTest.")
  endif()

  set(zOptKws)
  set(zOneValKws "OPTDESC")
  set(zMutValKws "LINKS")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  if(DEFINED _OPTDESC)
    set(sOptDesc ${_OPTDESC})
  else()
    set(sOptDesc "Build executable with GTest (requires GTest).")
  endif()

  if(GTEST_INCLUDE_DIRS)
    include_directories(${GTEST_INCLUDE_DIRS})
  endif()

  if(GTEST_BOTH_LIBRARIES)
    foreach(sLib IN LISTS GTEST_BOTH_LIBRARIES)
      if(NOT sLib IN_LIST _LINKS)
        list(APPEND _LINKS "${sLib}")
      endif()
    endforeach()
  endif()

  facile_add_executable(
    OPTDESC "${sOptDesc}"
    ${_UNPARSED_ARGUMENTS}
    LINKS ${_LINKS})
endfunction()
