#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____| rrMFC by FIGlet
# zhengrr
# 2017-12-08 – 2018-10-23
# The Unlicense

project(rrMFC VERSION 2018.10.23 LANGUAGES CXX)
project_more()
compile_option(UTF-8 WARNING_AS_ERROR)

facile_add_doxygen()

set(sRrwindowsLib "rrwindows_shared_library")

add_definitions("-D_AFXDLL")
set(CMAKE_MFC_FLAG 2)
add_definitions("-D_UNICODE")
remove_definitions("-D_MBCS")

aux_add_subdirectories(
  WITH_OPTION
  OPTION_NAME_PREFIX "${PROJECT_NAME_UPPER}_")
