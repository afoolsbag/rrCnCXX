#            _____       _____ __   ____   __
#           /  __ \     /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/_ __ | /  \/ \ V /  \ V /
# | '__| '__| |   | '_ \| |     /   \  /   \  zhengrr
# | |  | |  | \__/\ | | | \__/\/ /^\ \/ /^\ \ 2016-06-28 – 2018-11-12
# |_|  |_|   \____/_| |_|\____/\/   \/\/   \/ Unlicense

cmake_minimum_required(VERSION 3.9.6)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
include(rrCMake)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.13/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include("${CMAKE_BINARY_DIR}/conan.cmake")

project(rrCnCxx VERSION 2018.11.07 LANGUAGES NONE)
product_more(AUTHORS "zhengrr" LICENSE "Unlicense")

aux_add_subdirectories(WITH_OPTION)

install(FILES "UNLICENSE.txt" DESTINATION ".")
