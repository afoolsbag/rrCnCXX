aux_source_directory_ex(zSource)
add_executable_ex(
  NAME "ImgProc_Blur" ${zSource}
  INCLUDE_DIRECTORIES PRIVATE ${OpenCV_INCLUDE_DIRS}
  LINK_LIBRARIES      PRIVATE opencv_core
  POST_COPIES                 opencv_core)
