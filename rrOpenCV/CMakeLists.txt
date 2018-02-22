#             ___                    ______     __
#  _ __ _ __ / _ \ _ __   ___ _ __  / ___\ \   / /
# | '__| '__| | | | '_ \ / _ | '_ \| |    \ \ / /
# | |  | |  | |_| | |_) |  __| | | | |___  \ V /
# |_|  |_|   \___/| .__/ \___|_| |_|\____|  \_/
# zhengrr         |_|           rrOpenCV by FIGlet
# 2018-1-22 – 2-22
# The MIT License

project("rrOpenCV" VERSION 2018.2.22 LANGUAGES CXX)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option()

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(DisplayImage test.cpp)
target_link_libraries(DisplayImage ${OpenCV_LIBS})
