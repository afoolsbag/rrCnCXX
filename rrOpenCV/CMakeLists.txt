#             ___                    ______     __
#  _ __ _ __ / _ \ _ __   ___ _ __  / ___\ \   / /
# | '__| '__| | | | '_ \ / _ | '_ \| |    \ \ / /
# | |  | |  | |_| | |_) |  __| | | | |___  \ V /
# |_|  |_|   \___/| .__/ \___|_| |_|\____|  \_/
# zhengrr         |_|           rrOpenCV by FIGlet
# 2018-1-22
# The MIT License

project("rrOpenCV" VERSION 2018.1.22 LANGUAGES CXX)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option()

project(DisplayImage)
find_package(OpenCV REQUIRED)
add_executable(DisplayImage DisplayImage.cpp)
target_link_libraries(DisplayImage ${OpenCV_LIBS})
