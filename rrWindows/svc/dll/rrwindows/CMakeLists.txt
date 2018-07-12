configure_file("rrwindows/ver.rc.in" "rrwindows/ver.rc" @ONLY)
aux_source_directory_enhanced(zSrc RECURSE SOURCE_DIRECTORY "rrwindows")
target_sources("${sRrwindowsLib}" PRIVATE ${zSrc} "${CMAKE_CURRENT_BINARY_DIR}/rrwindows/ver.rc")
target_include_directories("${sRrwindowsLib}" PUBLIC ".")
