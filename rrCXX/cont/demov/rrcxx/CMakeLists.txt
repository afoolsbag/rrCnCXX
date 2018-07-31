aux_source_directory_enhanced(zSrc RECURSE SOURCE_DIRECTORY "rrcxx")
target_sources("${sRrcxxLib}" PRIVATE ${zSrc})
target_include_directories("${sRrcxxLib}" PUBLIC ".")
