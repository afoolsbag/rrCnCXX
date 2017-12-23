set(CMAKE_INCLUDE_CURRENT_DIR ON)
quick_aux_source_directory(
  RECURSE CONFIGURE
  SRC_VAR srcfiles
  CXX
)

quick_add_executable_with_option(
  SRC_VAR srcfiles
  CXXSTD 14
)
