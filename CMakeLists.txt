#             ____        ____
#  _ __ _ __ / ___|_ __  / _____  ___  __
# | '__| '__| |   | '_ \| |   \ \/ \ \/ /
# | |  | |  | |___| | | | |___ >  < >  <
# |_|  |_|   \____|_| |_|\____/_/\_/_/\_\
# zhengrr               rrCnCxx by FIGlet
# 2016-6-28 – 2018-1-29
# The MIT License

cmake_minimum_required(VERSION 3.9.6)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
include("rrUtilities")

project("rrCnCxx" VERSION 2018.1.31 LANGUAGES NONE)
product_variables(AUTHORS "zhengrr" COPYRIGHT "The MIT License")

add_subdirectory_with_option("rrC")
add_subdirectory_with_option("rrLinux")
add_subdirectory_with_option("rrLua")
add_subdirectory_with_option("rrOpenGL")
add_subdirectory_with_option("rrWindows")

add_subdirectory_with_option("rrCXX")
add_subdirectory_with_option("rrBoost")
add_subdirectory_with_option("rrDirectX")
add_subdirectory_with_option("rrLIVE555")
add_subdirectory_with_option("rrMFC")
add_subdirectory_with_option("rrOpenCV")
add_subdirectory_with_option("rrQt")

install(DIRECTORY "dzns" DESTINATION ".")
install(DIRECTORY "docs" DESTINATION ".")
install(DIRECTORY "spls" DESTINATION ".")
install(FILES "LICENSE.txt" DESTINATION ".")
