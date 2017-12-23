#             ____        ______  ___  __
#  _ __ _ __ / ___|_ __  / ___\ \/ \ \/ /
# | '__| '__| |   | '_ \| |    \  / \  /
# | |  | |  | |___| | | | |___ /  \ /  \
# |_|  |_|   \____|_| |_|\____/_/\_/_/\_\
#                       rrCnCXX by FIGlet

# zhengrr
# 2016-6-28 – 2017-12-20
# The MIT License

cmake_minimum_required(VERSION 3.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")
include("rrUtilities")

project("rrCnCXX" VERSION 1.3.3.7 LANGUAGES NONE)
set_product_variables(AUTHORS "zhengrr" COPYRIGHT "The MIT License")

add_subdirectory_with_option(SRC_DIR "rrclang")
add_subdirectory_with_option(SRC_DIR "rrcexe")
add_subdirectory_with_option(SRC_DIR "rrclib")

add_subdirectory_with_option(SRC_DIR "rrcxxlang")
add_subdirectory_with_option(SRC_DIR "rrcxxexe")
add_subdirectory_with_option(SRC_DIR "rrcxxlib")

add_subdirectory_with_option(SRC_DIR "rrlinux")
add_subdirectory_with_option(SRC_DIR "rrlua")
add_subdirectory_with_option(SRC_DIR "rropengl")
add_subdirectory_with_option(SRC_DIR "rrwindows")

add_subdirectory_with_option(SRC_DIR "rrboost")
add_subdirectory_with_option(SRC_DIR "rrdirectx")
add_subdirectory_with_option(SRC_DIR "rrlive555")
add_subdirectory_with_option(SRC_DIR "rrmfc")
add_subdirectory_with_option(SRC_DIR "rrqt")

install(DIRECTORY "dzns" DESTINATION ".")
install(DIRECTORY "docs" DESTINATION ".")
install(DIRECTORY "spls" DESTINATION ".")
install(FILES "LICENSE.txt" DESTINATION ".")
