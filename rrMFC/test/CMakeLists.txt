aux_source_directory_ex(
  zSrc
  RECURSE
  MFC)
facile_add_gtest_executable(
  NAME "test"
  ${zSrc}
  CXX17
  INCLUDE_DIRECTORIES PRIVATE "./")
