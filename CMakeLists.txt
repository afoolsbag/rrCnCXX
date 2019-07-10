#            _____       _____ __   ____   __
#           /  __ \     /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/_ __ | /  \/ \ V /  \ V /
# | '__| '__| |   | '_ \| |     /   \  /   \  zhengrr
# | |  | |  | \__/\ | | | \__/\/ /^\ \/ /^\ \ 2016-06-28 – 2019-07-08
# |_|  |_|   \____/_| |_|\____/\/   \/\/   \/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
include(rrCMake)
include_conan_script()

product_ex(
  rrCnCxx
  VERSION   2019.07.08
  LANGUAGES NONE
  AUTHORS   "zhengrr"
  LICENSE   "Unlicense")

add_aux_subdirectories_con()

install(
  FILES       "UNLICENSE.txt"
  DESTINATION ".")
