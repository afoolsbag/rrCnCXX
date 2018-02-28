#             ___                    ______     __
#  _ __ _ __ / _ \ _ __   ___ _ __  / ___\ \   / /
# | '__| '__| | | | '_ \ / _ | '_ \| |    \ \ / /
# | |  | |  | |_| | |_) |  __| | | | |___  \ V /
# |_|  |_|   \___/| .__/ \___|_| |_|\____|  \_/
# zhengrr         |_|           rrOpenCV by FIGlet
# 2018-1-22 – 2-28
# The MIT License

project("rrOpenCV" VERSION 2018.2.24 LANGUAGES CXX)
project_variables()
highest_warning_level()

quick_doxygen()

facile_add_opencv_executable(SUBNAME "Scan"
  "tut/core/scan.cpp")

facile_add_opencv_executable(SUBNAME "Mask"
  "tut/core/mask.cpp")

facile_add_opencv_executable(SUBNAME "Trackbar"
  "tut/highgui/trackbar.cpp")
