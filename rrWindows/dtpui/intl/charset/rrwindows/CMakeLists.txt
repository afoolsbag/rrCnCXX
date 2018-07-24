aux_source_directory_enhanced(zSrc RECURSE SOURCE_DIRECTORY "rrwindows")
target_sources("${sRrwindowsLib}" PRIVATE ${zSrc})
target_include_directories("${sRrwindowsLib}" PUBLIC ".")
