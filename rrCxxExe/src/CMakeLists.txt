set(CMAKE_INCLUDE_CURRENT_DIR ON)
quick_aux_source_directory(
  RECURSE CONFIGURE
  SRCVAR srcfiles
  CXX
)

quick_add_executable_with_option(
  SRCVAR srcfiles
  CXXSTD 14
)
