aux_source_directory_enhanced(zSrc RECURSE SOURCE_DIRECTORY "rrc")
target_sources("${sRrcLib}" PRIVATE ${zSrc})
target_include_directories("${sRrcLib}" PUBLIC ".")
