#             ___                    ______     __
#  _ __ _ __ / _ \ _ __   ___ _ __  / ___\ \   / /
# | '__| '__| | | | '_ \ / _ | '_ \| |    \ \ / /
# | |  | |  | |_| | |_) |  __| | | | |___  \ V /
# |_|  |_|   \___/| .__/ \___|_| |_|\____|  \_/ rrOpenCV by FIGlet
# zhengrr         |_|
# 2018-01-22 – 2018-10-31
# The Unlicense

project(rrOpenCV VERSION 2018.10.31 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

facile_add_doxygen()

find_package(OpenCVPackage)
find_package(OpenCV)

aux_add_subdirectories(
  WITH_OPTION
  OPTION_NAME_PREFIX "${PROJECT_NAME_UPPER}_")
