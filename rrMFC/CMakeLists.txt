#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____| rrMFC by FIGlet
# zhengrr
# 2017-12-08 – 2018-10-13
# The Unlicense

set(sRrwindowsLib "rrwindows_shared_library")

project(rrMFC VERSION 2018.10.13 LANGUAGES CXX)
project_extra()
compile_option(UTF-8 WARNING_AS_ERROR)

facile_add_doxygen()

add_definitions("-D_AFXDLL")
set(CMAKE_MFC_FLAG 2)
add_definitions("-D_UNICODE")
remove_definitions("-D_MBCS")

configure_file("test/version.h.in" "test/version.h" @ONLY)
aux_source_directory_ex(
  zSrc
  DIRECTORY    "src/"
  RECURSE
  MFC
  GROUP_ROOT   "src/"
  MFC_PCH_BASE "test")
aux_source_directory_ex(
  zTest
  DIRECTORY    "test/"
  RECURSE MFC
  GROUP_ROOT   "test/"
  MFC_PCH_BASE "test")
aux_source_directory_ex(
  zGenerate
  DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/test/"
  RECURSE
  MFC
  GROUP_ROOT "generate/")
add_executable_ex(
  NAME "test"
  WIN32 ${zSrc} ${zTest} ${zGenerate} "ygen.dox"
  INCLUDE_DIRECTORIES PRIVATE "src/"
                              "${CMAKE_CURRENT_BINARY_DIR}/src/"
                              "test/"
                              "${CMAKE_CURRENT_BINARY_DIR}/test/"
  LINK_LIBRARIES      PRIVATE ${sRrwindowsLib}
  POST_COPIES         ${sRrwindowsLib})

aux_source_directory_ex(
  zGuest
  DIRECTORY    "guest/"
  RECURSE
  MFC
  GROUP_ROOT   "guest/"
  MFC_PCH_BASE "guest")
add_executable_ex(
  NAME "guest"
  WIN32 ${zGuest}
  INCLUDE_DIRECTORIES PRIVATE "guest/"
  LINK_LIBRARIES      PRIVATE ${sRrwindowsLib}
  POST_COPIES         ${sRrwindowsLib})
