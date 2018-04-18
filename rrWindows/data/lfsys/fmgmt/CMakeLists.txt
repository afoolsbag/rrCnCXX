set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_executable(SUBNAME "FileAttributes"
  "attrs.c")

facile_add_executable(SUBNAME "FileExists"
  "exists.c")

facile_add_executable(SUBNAME "FileFild"
  "find.c")

facile_add_executable(SUBNAME "RegularlyClearupExpiredFiles"
  "rcef.c")
