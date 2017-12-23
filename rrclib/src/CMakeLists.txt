if(MSVC)
  add_compile_options("/wd4819")  # character cannot be represented
endif()

add_definitions("-D${PROJECT_NAME_UPPER}_EXPORTS")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
quick_aux_source_directory(
  RECURSE CONFIGURE INSTALL
  SRC_VAR srcfiles
  C
)

quick_add_library_with_option(
  SRC_VAR srcfiles
  TYPE STATIC
  CSTD 11
)

quick_add_library_with_option(
  SRC_VAR srcfiles
  TYPE SHARED
  CSTD 11
)
