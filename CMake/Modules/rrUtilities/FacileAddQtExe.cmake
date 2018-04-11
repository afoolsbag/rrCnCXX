# zhengrr
# 2018-01-30 – 04-11
# The MIT License

if(NOT COMMAND facile_add_executable)
  include("${CMAKE_CURRENT_LIST_DIR}/FacileAddExe.cmake")
endif()

# .rst
# .. command:: facile_add_qt_executable
#
#    以``facile_add_executable``命令为基础，额外约定了若干默认参数：
#
#    额外约定：
#
#    :OPTDESC:             see code
#    :PROPS:               ``AUTOMOC ON AUTOUIC ON AUTORCC ON``
#
function(facile_add_qt_executable)
  if(NOT Qt5_DIR)
    message(WARNING "Qt5 is needed to build executable with Qt5.")
  endif()

  set(zOptKws)
  set(zOneValKws "OPTDESC")
  set(zMutValKws "PROPS")
  cmake_parse_arguments(PARSE_ARGV 0 "" "${zOptKws}" "${zOneValKws}" "${zMutValKws}")

  if(DEFINED _OPTDESC)
    set(sOptDesc ${_OPTDESC})
  else()
    set(sOptDesc "Build executable with Qt5 (requires Qt5).")
  endif()

  if(NOT "AUTOMOC" IN_LIST _PROPS)
    list(APPEND _PROPS "AUTOMOC" "ON")
  endif()
  if(NOT "AUTOUIC" IN_LIST _PROPS)
    list(APPEND _PROPS "AUTOUIC" "ON")
  endif()
  if(NOT "AUTORCC" IN_LIST _PROPS)
    list(APPEND _PROPS "AUTORCC" "ON")
  endif()

  facile_add_executable(
    OPTDESC "${sOptDesc}"
    ${_UNPARSED_ARGUMENTS}
    PROPS ${_PROPS})
endfunction()
