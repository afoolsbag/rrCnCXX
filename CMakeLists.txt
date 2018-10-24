#             ____        ____
#  _ __ _ __ / ___|_ __  / _____  ___  __
# | '__| '__| |   | '_ \| |   \ \/ \ \/ /
# | |  | |  | |___| | | | |___ >  < >  <
# |_|  |_|   \____|_| |_|\____/_/\_/_/\_\ rrCnCxx by FIGlet
# zhengrr
# 2016-06-28 – 2018-10-23
# The Unlicense

cmake_minimum_required(VERSION 3.9.6)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
include(rrCMake)

project(rrCnCxx VERSION 2018.10.23 LANGUAGES NONE)
product_more(AUTHORS "zhengrr" LICENSE "The Unlicense")

aux_add_subdirectories(WITH_OPTION)

install(FILES "LICENSE.txt" DESTINATION ".")
