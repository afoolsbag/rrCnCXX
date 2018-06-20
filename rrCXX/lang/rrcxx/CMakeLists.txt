configure_file("rrcxx/rrcxxcfg.hxx.in" "rrcxx/rrcxxcfg.hxx" @ONLY)
aux_source_directory_enhanced(zSrc RECURSE SOURCE_DIRECTORY "rrcxx")
target_sources("${sRrcxxLib}" PRIVATE ${zSrc})
target_include_directories("${sRrcxxLib}"
                   PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
                    PUBLIC ".")
