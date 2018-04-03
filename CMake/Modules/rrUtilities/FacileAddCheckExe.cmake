# zhengrr
# 2018-02-02 – 04-02
# The MIT License

# .rst
# .. command:: facile_add_check_executable
#
#    以``facile_add_executable``命令为基础，额外约定了若干缺省参数：
#
#    额外约定：
#
#    :OPTDESC:             see code
#    :LINKS:               ``Check::Check``
#
function(facile_add_check_executable)
  set(zOptKws)
  set(zOneValKws "TGTNAMEVAR" "OPTDESC")
  set(zMutValKws "LINKS")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  if(DEFINED _OPTDESC)
    set(sOptDesc ${_OPTDESC})
  else()
    set(sOptDesc "Build executable with Check (requires Check).")
  endif()

  if(NOT Check_FOUND)
    find_package(Check)
    if(NOT Check_FOUND)
      set(Check_ROOT_DIR "${CHECK_ROOT_DIR}" CACHE PATH "The root directory of the Check installation.")
    endif()
  endif()
  if(NOT CHECK_FOUND)
    message(WARNING "Check is needed to build executable with Check.")
  endif()

  if(Check_FOUND)
    if(NOT Check::Check IN_LIST _LINKS)
      list(APPEND _LINKS Check::Check)
    endif()
    if(NOT Check::Compat IN_LIST _LINKS)
      list(APPEND _LINKS Check::Compat)
    endif()
  endif()

  enable_testing()
  facile_add_executable(
    TGTNAMEVAR sTgtName OPTDESC "${sOptDesc}"
    ${_UNPARSED_ARGUMENTS}
    LINKS ${_LINKS})
  add_test(NAME "${sTgtName}" COMMAND "${sTgtName}")

  if(DEFINED _TGTNAMEVAR)
    set(${_TGTNAMEVAR} "${sTgtName}" PARENT_SCOPE)
  endif()
endfunction()
