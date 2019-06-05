#            _____       _____ __   ____   __
#           /  __ \     /  __ \\ \ / /\ \ / /
#  _ __ _ __| /  \/_ __ | /  \/ \ V /  \ V /
# | '__| '__| |   | '_ \| |     /   \  /   \  zhengrr
# | |  | |  | \__/\ | | | \__/\/ /^\ \/ /^\ \ 2016-06-28 – 2019-06-05
# |_|  |_|   \____/_| |_|\____/\/   \/\/   \/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

# custom modules

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
include(rrCMake)
include_conan_script()

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
