aux_source_directory_ex(
  zSrc
  MFC)
add_executable_ex(
  NAME "Ctrl_Edit"
  WIN32 ${zSrc}
  INCLUDE_DIRECTORIES PRIVATE "./")
