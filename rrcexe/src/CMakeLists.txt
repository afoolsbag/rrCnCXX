set(CMAKE_INCLUDE_CURRENT_DIR ON)
quick_aux_source_directory(
  RECURSE CONFIGURE
  SRC_VAR srcfiles
  C
)

quick_add_executable_with_option(
  SRC_VAR srcfiles
  CSTD 11
)
