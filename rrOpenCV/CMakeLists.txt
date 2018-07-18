#             ___                    ______     __
#  _ __ _ __ / _ \ _ __   ___ _ __  / ___\ \   / /
# | '__| '__| | | | '_ \ / _ | '_ \| |    \ \ / /
# | |  | |  | |_| | |_) |  __| | | | |___  \ V /
# |_|  |_|   \___/| .__/ \___|_| |_|\____|  \_/
# zhengrr         |_|           rrOpenCV by FIGlet
# 2018-01-22 – 2018-07-17
# The MIT License

project("rrOpenCV" VERSION 2018.7.17 LANGUAGES CXX)
project_extra()
compiler_warning_level(AS_ERROR UTF-8)

facile_add_doxygen()

find_package(OpenCVPackage)
find_package(OpenCV)

aux_add_subdirectories()
