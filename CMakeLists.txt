#             ____        ____
#  _ __ _ __ / ___|_ __  / _____  ___  __
# | '__| '__| |   | '_ \| |   \ \/ \ \/ /
# | |  | |  | |___| | | | |___ >  < >  <
# |_|  |_|   \____|_| |_|\____/_/\_/_/\_\
# zhengrr               rrCnCxx by FIGlet
# 2016-6-28 – 2018-1-8
# The MIT License

cmake_minimum_required(VERSION 3.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake/Modules")
include("rrUtilities")

project("rrCnCXX" VERSION 1.3.3.7 LANGUAGES NONE)
set_product_variables(AUTHORS "zhengrr" COPYRIGHT "The MIT License")

add_subdirectory_with_option("rrCLang")
add_subdirectory_with_option("rrLinux")
add_subdirectory_with_option("rrLua")
add_subdirectory_with_option("rrOpenGL")
add_subdirectory_with_option("rrWindows")

add_subdirectory_with_option("rrCxxLang")
add_subdirectory_with_option("rrCxxExe")
add_subdirectory_with_option("rrCxxLib")

add_subdirectory_with_option("rrBoost")
add_subdirectory_with_option("rrDirectX")
add_subdirectory_with_option("rrLIVE555")
add_subdirectory_with_option("rrMFC")
add_subdirectory_with_option("rrQt")

install(DIRECTORY "dzns" DESTINATION ".")
install(DIRECTORY "docs" DESTINATION ".")
install(DIRECTORY "spls" DESTINATION ".")
install(FILES "LICENSE.txt" DESTINATION ".")
