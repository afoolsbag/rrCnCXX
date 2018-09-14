#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____| rrMFC by FIGlet
# zhengrr
# 2017-12-08 – 2018-09-14
# The Unlicense

set(sRrwindowsLib "rrwindows_shared_library")

project(rrMFC VERSION 2018.9.14 LANGUAGES CXX)
project_extra()
compiler_warning_level(AS_ERROR UTF-8)

facile_add_doxygen()

add_definitions("-D_AFXDLL")
set(CMAKE_MFC_FLAG 2)
add_definitions("-D_UNICODE")
remove_definitions("-D_MBCS")

configure_file("test/version.h.in" "test/version.h" @ONLY)
aux_source_directory_enhanced(zSrc
                              RECURSE MFC
                 MFC_PCH_NAME "test"
             SOURCE_DIRECTORY "src/"
                 SOURCE_GROUP "src/")
aux_source_directory_enhanced(zTest
                              RECURSE MFC
                 MFC_PCH_NAME "test"
             SOURCE_DIRECTORY "test/"
                 SOURCE_GROUP "test/")
aux_source_directory_enhanced(zGenerate
                              RECURSE MFC
             SOURCE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/test/"
                 SOURCE_GROUP "generate/")
facile_add_executable(SUBNAME "test"
                              OPTION_INITIAL_ON
                        WIN32 ${zSrc} ${zTest} ${zGenerate} "ygen.dox"
          INCLUDE_DIRECTORIES PRIVATE "src/"
                                      "${CMAKE_CURRENT_BINARY_DIR}/src/"
                                      "test/"
                                      "${CMAKE_CURRENT_BINARY_DIR}/test/"
               LINK_LIBRARIES ${sRrwindowsLib}
                  POST_COPIES ${sRrwindowsLib})

aux_source_directory_enhanced(zGuest
                              RECURSE MFC
                 MFC_PCH_NAME "guest"
             SOURCE_DIRECTORY "guest/"
                 SOURCE_GROUP "guest/")
facile_add_executable(SUBNAME "guest"
                              OPTION_INITIAL_ON
                        WIN32 ${zGuest}
          INCLUDE_DIRECTORIES PRIVATE "guest/"
               LINK_LIBRARIES ${sRrwindowsLib}
                  POST_COPIES ${sRrwindowsLib})
