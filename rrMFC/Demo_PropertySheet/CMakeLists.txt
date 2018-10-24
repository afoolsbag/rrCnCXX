aux_source_directory_ex(
  zSrc
  RECURSE
  MFC)
add_executable_ex(
  NAME "Demo_PropertySheet"
  WIN32 ${zSrc}
  INCLUDE_DIRECTORIES PRIVATE "./")
