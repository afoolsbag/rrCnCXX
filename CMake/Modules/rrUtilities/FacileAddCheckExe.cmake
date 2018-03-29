# zhengrr
# 2018-02-02 – 03-29
# The MIT License

# .rst
# .. command:: facile_add_check_executable
#
#    以``facile_add_executable``命令为基础，额外约定了若干默认参数：
#
#    额外约定：
#
#    :include_directories: ``${CHECK_INCLUDE_DIRS}``
#    :OPTDESC:             see code
#    :LINKS:               ``${CHECK_LIBRARIES}``
#
function(facile_add_check_executable)
  if(NOT CHECK_FOUND)
    if(NOT "${CMAKE_CURRENT_LIST_DIR}/../" IN_LIST CMAKE_PREFIX_PATH)
      list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/../")
    endif()
    set(CHECK_ROOT_DIR "${CHECK_ROOT_DIR}" CACHE PATH "The root directory of the Check installation.")
    find_package(Check)
  endif()
  if(NOT CHECK_FOUND)
    message(WARNING "Check is needed to build executable with Check.")
  endif()

  set(zOptKws)
  set(zOneValKws "TGTNAMEVAR" "OPTDESC")
  set(zMutValKws "LINKS")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  if(DEFINED _OPTDESC)
    set(sOptDesc ${_OPTDESC})
  else()
    set(sOptDesc "Build executable with Check (requires Check).")
  endif()

  if(CHECK_INCLUDE_DIRS)
    include_directories(${CHECK_INCLUDE_DIRS})
  endif()

  if(CHECK_LIBRARIES)
    foreach(sLib IN LISTS CHECK_LIBRARIES)
      if(NOT sLib IN_LIST _LINKS)
        list(APPEND _LINKS "${sLib}")
      endif()
    endforeach()
  endif()

  facile_add_executable(
    TGTNAMEVAR sTgtName OPTDESC "${sOptDesc}"
    ${_UNPARSED_ARGUMENTS}
    LINKS ${_LINKS})
  if(DEFINED _TGTNAMEVAR)
    set(${_TGTNAMEVAR} "${sTgtName}" PARENT_SCOPE)
  endif()
endfunction()
