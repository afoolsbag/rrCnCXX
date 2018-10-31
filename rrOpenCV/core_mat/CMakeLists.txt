aux_source_directory_ex(zSrc)
add_executable_ex(
  NAME "Core_Mat"
  ${zSrc}
  INCLUDE_DIRECTORIES PRIVATE "./"
                              ${OpenCV_INCLUDE_DIRS}
  LINK_LIBRARIES      PRIVATE opencv_core)
