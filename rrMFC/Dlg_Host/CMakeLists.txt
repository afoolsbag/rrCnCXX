aux_source_directory_ex(
  zSrc
  RECURSE
  MFC)
add_executable_ex(
  NAME "Dlg_Host"
  WIN32 ${zSrc}
  INCLUDE_DIRECTORIES PRIVATE "./")
