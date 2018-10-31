#             ____        ____
#  _ __ _ __ / ___|_ __  / _____  ___  __
# | '__| '__| |   | '_ \| |   \ \/ \ \/ /
# | |  | |  | |___| | | | |___ >  < >  <
# |_|  |_|   \____|_| |_|\____/_/\_/_/\_\ rrCnCxx by FIGlet
# zhengrr
# 2016-06-28 – 2018-10-31
# The Unlicense

cmake_minimum_required(VERSION 3.9.6)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
include(rrCMake)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.12/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include("${CMAKE_BINARY_DIR}/conan.cmake")

project(rrCnCxx VERSION 2018.10.31 LANGUAGES NONE)
product_more(AUTHORS "zhengrr" LICENSE "The Unlicense")

aux_add_subdirectories(WITH_OPTION)

install(FILES "LICENSE.txt" DESTINATION ".")
