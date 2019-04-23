configure_file("version.h.in" "version.h" @ONLY)
aux_source_directory_con("."                           zSrc MFC)
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}" zGen PREFIX "generated")
add_executable_con(
  "rrMFCapp"
  WIN32               ${zSrc} ${zGen}
  INCLUDE_DIRECTORIES PRIVATE "."
                              "${CMAKE_CURRENT_BINARY_DIR}")
