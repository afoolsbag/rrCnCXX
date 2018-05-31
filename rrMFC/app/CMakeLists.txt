set(CMAKE_INCLUDE_CURRENT_DIR ON)
aux_source_directory_enhanced(zSrc RECURSE MFC)
facile_add_executable(SUBNAME "Application"
                        WIN32 ${zSrc}
               LINK_LIBRARIES rrwindows_static_library)
