configure_file("rrc/rrccfg.h.in" "rrc/rrccfg.h" @ONLY)
aux_source_directory_enhanced(zSrc RECURSE SOURCE_DIRECTORY "rrc")
target_sources("${sRrcLib}" PRIVATE ${zSrc})
target_include_directories("${sRrcLib}" PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
                                         PUBLIC ".")
