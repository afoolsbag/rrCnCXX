set(CMAKE_INCLUDE_CURRENT_DIR ON)
quick_aux_source_directory(sourceFiles RECURSE C)
quick_add_executable_with_option(sourceFiles WIN32 NAME "${PROJECT_NAME}_HelloMsg")
