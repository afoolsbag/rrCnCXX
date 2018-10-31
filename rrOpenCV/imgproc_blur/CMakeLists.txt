aux_source_directory_enhanced(zSrc RECURSE)
facile_add_executable(SUBNAME "Blur"
                              ${zSrc}
          INCLUDE_DIRECTORIES PRIVATE ${OpenCV_INCLUDE_DIRS}
               LINK_LIBRARIES opencv_core)
