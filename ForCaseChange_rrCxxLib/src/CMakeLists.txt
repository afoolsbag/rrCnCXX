if(MSVC)
  add_compile_options("/wd4464")
  add_compile_options("/wd4514")
  add_compile_options("/wd4819")
  add_compile_options("/wd4820")
endif()

add_definitions("-D${PROJECT_NAME_UPPER}_EXPORTS")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
quick_aux_source_directory(
  RECURSE CONFIGURE INSTALL
  SRC_VAR srcfiles
  CXX
)

quick_add_library_with_option(
  SRC_VAR srcfiles
  TYPE STATIC
  CXXSTD 14
)

quick_add_library_with_option(
  SRC_VAR srcfiles
  TYPE SHARED
  CXXSTD 14
)
