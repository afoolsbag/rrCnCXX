#             ____        ____
#  _ __ _ __ / ___|_ __  / _____  ___  __
# | '__| '__| |   | '_ \| |   \ \/ \ \/ /
# | |  | |  | |___| | | | |___ >  < >  <
# |_|  |_|   \____|_| |_|\____/_/\_/_/\_\
# zhengrr               rrCnCxx by FIGlet
# 2016-06-28 – 2018-04-11
# The MIT License

cmake_minimum_required(VERSION 3.9.6)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
include("rrUtilities")

project("rrCnCxx" VERSION 2018.4.11 LANGUAGES NONE)
product_extra(AUTHORS "zhengrr" LICENSE "The MIT License")

aux_add_subdirectories(WITH_OPTION)

install(DIRECTORY "dzns" DESTINATION ".")
install(DIRECTORY "docs" DESTINATION ".")
install(DIRECTORY "spls" DESTINATION ".")
install(FILES "LICENSE.txt" DESTINATION ".")
