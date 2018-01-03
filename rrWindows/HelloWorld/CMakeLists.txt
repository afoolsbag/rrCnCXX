set(CMAKE_INCLUDE_CURRENT_DIR ON)
quick_aux_source_directory(sourceFiles C)
quick_add_executable_with_option(sourceFiles ORIGINAL_NAME "${PROJECT_NAME}_HelloWorld")
