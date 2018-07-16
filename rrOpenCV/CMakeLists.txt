#             ___                    ______     __
#  _ __ _ __ / _ \ _ __   ___ _ __  / ___\ \   / /
# | '__| '__| | | | '_ \ / _ | '_ \| |    \ \ / /
# | |  | |  | |_| | |_) |  __| | | | |___  \ V /
# |_|  |_|   \___/| .__/ \___|_| |_|\____|  \_/
# zhengrr         |_|           rrOpenCV by FIGlet
# 2018-01-22 – 07-16
# The MIT License

project("rrOpenCV" VERSION 2018.7.16 LANGUAGES CXX)
project_extra()
compiler_warning_level(UTF-8)

facile_add_doxygen()

find_package(OpenCVPackage)
find_package(OpenCV)

facile_add_executable(SUBNAME "Scan"
                              "tut/core/scan.cpp"
          INCLUDE_DIRECTORIES PRIVATE ${OpenCV_INCLUDE_DIRS}
               LINK_LIBRARIES opencv_core)

facile_add_executable(SUBNAME "Mask"
                              "tut/core/mask.cpp"
          INCLUDE_DIRECTORIES PRIVATE ${OpenCV_INCLUDE_DIRS}
               LINK_LIBRARIES opencv_core)

facile_add_executable(SUBNAME "Blending"
                              "tut/core/blending.cpp"
          INCLUDE_DIRECTORIES PRIVATE ${OpenCV_INCLUDE_DIRS}
               LINK_LIBRARIES opencv_core)

facile_add_executable(SUBNAME "Trackbar"
                              "tut/highgui/trackbar.cpp"
          INCLUDE_DIRECTORIES PRIVATE ${OpenCV_INCLUDE_DIRS}
               LINK_LIBRARIES opencv_core)
