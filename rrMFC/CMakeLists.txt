#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____| rrMFC by FIGlet
# zhengrr
# 2017-12-08 – 2018-09-05
# The Unlicense

set(sRrwindowsLib "rrwindows_shared_library")

project(rrMFC VERSION 2018.9.5 LANGUAGES CXX)
project_extra()
compiler_warning_level(AS_ERROR UTF-8)

facile_add_doxygen()

add_definitions("-D_AFXDLL")
set(CMAKE_MFC_FLAG 2)
add_definitions("-D_UNICODE" "-DUNICODE")
remove_definitions("-D_MBCS")

configure_file("src/config.h.in" "src/config.h" @ONLY)
aux_source_directory_enhanced(zSrc
                              RECURSE MFC
             SOURCE_DIRECTORY "src/"
                 SOURCE_GROUP "src/")
aux_source_directory_enhanced(zGenerate
                              RECURSE MFC
             SOURCE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/src/"
                 SOURCE_GROUP "generate/")
facile_add_executable(OPTION_INITIAL_ON
                WIN32 ${zSrc} ${zGenerate} "ygen.dox"
  INCLUDE_DIRECTORIES PRIVATE "src/"
                              "${CMAKE_CURRENT_BINARY_DIR}/src"
       LINK_LIBRARIES "${sRrwindowsLib}"
          POST_COPIES "${sRrwindowsLib}")
