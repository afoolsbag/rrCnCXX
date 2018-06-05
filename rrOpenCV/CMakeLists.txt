#             ___                    ______     __
#  _ __ _ __ / _ \ _ __   ___ _ __  / ___\ \   / /
# | '__| '__| | | | '_ \ / _ | '_ \| |    \ \ / /
# | |  | |  | |_| | |_) |  __| | | | |___  \ V /
# |_|  |_|   \___/| .__/ \___|_| |_|\____|  \_/
# zhengrr         |_|           rrOpenCV by FIGlet
# 2018-01-22 – 06-04
# The MIT License

project("rrOpenCV" VERSION 2018.6.4 LANGUAGES CXX)
project_extra()
compiler_warning_level(HIGHEST)

facile_add_doxygen()

find_package(OpenCVPackage)
find_package(OpenCV)

facile_add_executable(SUBNAME "Scan"
                              "tut/core/scan.cpp"
               LINK_LIBRARIES ${OpenCV_LIBS})

facile_add_executable(SUBNAME "Mask"
                              "tut/core/mask.cpp"
               LINK_LIBRARIES ${OpenCV_LIBS})

facile_add_executable(SUBNAME "Blending"
                              "tut/core/blending.cpp"
               LINK_LIBRARIES ${OpenCV_LIBS})

facile_add_executable(SUBNAME "Trackbar"
                              "tut/highgui/trackbar.cpp"
               LINK_LIBRARIES ${OpenCV_LIBS})
