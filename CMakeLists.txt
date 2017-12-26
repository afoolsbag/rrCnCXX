#             ____        ____
#  _ __ _ __ / ___|_ __  / _____  ___  __
# | '__| '__| |   | '_ \| |   \ \/ \ \/ /
# | |  | |  | |___| | | | |___ >  < >  <
# |_|  |_|   \____|_| |_|\____/_/\_/_/\_\
# zhengrr               rrCnCxx by FIGlet
# 2016-6-28 – 2017-12-26
# The MIT License

cmake_minimum_required(VERSION 3.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake/Modules")
include("rrUtilities")

project("rrCnCXX" VERSION 1.3.3.7 LANGUAGES NONE)
set_product_variables(AUTHORS "zhengrr" COPYRIGHT "The MIT License")

add_subdirectory_with_option(SRCDIR "rrCLang")
add_subdirectory_with_option(SRCDIR "rrCExe")
add_subdirectory_with_option(SRCDIR "rrCLib")

add_subdirectory_with_option(SRCDIR "rrCxxLang")
add_subdirectory_with_option(SRCDIR "rrCxxExe")
add_subdirectory_with_option(SRCDIR "rrCxxLib")

add_subdirectory_with_option(SRCDIR "rrLinux")
add_subdirectory_with_option(SRCDIR "rrLua")
add_subdirectory_with_option(SRCDIR "rrOpenGL")
add_subdirectory_with_option(SRCDIR "rrWindows")

add_subdirectory_with_option(SRCDIR "rrBoost")
add_subdirectory_with_option(SRCDIR "rrDirectX")
add_subdirectory_with_option(SRCDIR "rrLIVE555")
add_subdirectory_with_option(SRCDIR "rrMFC")
add_subdirectory_with_option(SRCDIR "rrQt")

install(DIRECTORY "dzns" DESTINATION ".")
install(DIRECTORY "docs" DESTINATION ".")
install(DIRECTORY "spls" DESTINATION ".")
install(FILES "LICENSE.txt" DESTINATION ".")
