# zhengrr
# 2018-02-02 – 04-04
# The MIT License

# .rst
# .. command:: facile_add_check_executable
#
#    以``facile_add_executable``命令为基础，额外约定了若干缺省参数：
#
#    额外约定：
#
#    :OPTION_DESCRIPTION: see code
#    :LINK_LIBRARIES:     ``Check::Check``
#
function(facile_add_check_executable)
  set(zOptKws)
  set(zOneValKws "OPTION_DESCRIPTION" "TARGET_NAME_VARIABLE")
  set(zMutValKws "LINK_LIBRARIES")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  # OPTION_DESCRIPTION
  if(DEFINED _OPTION_DESCRIPTION)
    set(sOptDesc ${_OPTION_DESCRIPTION})
  else()
    set(sOptDesc "Build executable with Check (requires Check).")
  endif()

  # LINK_LIBRARIES
  set(zLinkLibs ${_LINK_LIBRARIES})

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
    if(NOT Check::Check IN_LIST zLinkLibs)
      list(APPEND zLinkLibs Check::Check)
    endif()
    if(NOT Check::Compat IN_LIST zLinkLibs)
      list(APPEND zLinkLibs Check::Compat)
    endif()
  endif()

  # facile_add_executable
  enable_testing()
  facile_add_executable(
    OPTION_DESCRIPTION     "${sOptDesc}"
    TARGET_NAME_VARIABLE    sTgtName
    ${_UNPARSED_ARGUMENTS}
    LINK_LIBRARIES          ${zLinkLibs})
  add_test(NAME "${sTgtName}" COMMAND "${sTgtName}")

  if(DEFINED _TARGET_NAME_VARIABLE)
    set(${_TARGET_NAME_VARIABLE} "${sTgtName}" PARENT_SCOPE)
  endif()
endfunction()
