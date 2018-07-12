set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("ver.rc.in" "ver.rc" @ONLY)
aux_source_directory_enhanced(zSrc RECURSE MFC)
facile_add_executable(SUBNAME "Application"
                        WIN32 ${zSrc} "${CMAKE_CURRENT_BINARY_DIR}/ver.rc"
               LINK_LIBRARIES "${sRrwindowsLib}"
                  POST_COPIES "${sRrwindowsLib}")
