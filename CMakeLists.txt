#            _____       _____ __   ____   __
#           /  __ \     /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/_ __ | /  \/ \ V /  \ V /
# | '__| '__| |   | '_ \| |     /   \  /   \  zhengrr
# | |  | |  | \__/\ | | | \__/\/ /^\ \/ /^\ \ 2016-06-28 – 2019-04-17
# |_|  |_|   \____/_| |_|\____/\/   \/\/   \/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

# conan modules

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.13/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include("${CMAKE_BINARY_DIR}/conan.cmake")

# custom modules

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
include(rrCMake)

# product and subdirectories

product_ex(
  rrCnCxx
  VERSION   2019.04.17
  LANGUAGES NONE
  AUTHORS   "zhengrr"
  LICENSE   "Unlicense")

add_aux_subdirectories_con()

# miscellaneous installation

install(
  FILES       "UNLICENSE.txt"
  DESTINATION ".")
