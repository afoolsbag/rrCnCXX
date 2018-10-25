aux_source_directory_ex(
  zSrc
  MFC)
configure_file("version.h.in" "version.h" @ONLY)
aux_source_directory_ex(
  zGenerated
  DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/"
  GROUP_ROOT "generated/")
add_executable_ex(
  NAME "App"
  WIN32 ${zSrc} ${zGenerated}
  INCLUDE_DIRECTORIES PRIVATE "./"
                              "${CMAKE_CURRENT_BINARY_DIR}/")
