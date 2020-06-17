#            _____       _____
#           /  __ \     /  __ \
#  _ __ _ __| /  \/_ __ | /  \/_  ____  __
# | '__| '__| |   | '_ \| |   \ \/ /\ \/ / zhengrr
# | |  | |  | \__/\ | | | \__/\>  <  >  <  2016-06-28 – 2020-06-17
# |_|  |_|   \____/_| |_|\____/_/\_\/_/\_\ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
include(rrCMake)

project(
  rrCnCxx
  VERSION   2020.06.17
  LANGUAGES NONE)
rr_product_extra(
  AUTHORS   "zhengrr"
  LICENSE   "Unlicense")

include(CTest)

add_subdirectory_aux()

install(
  FILES       "UNLICENSE.txt"
  DESTINATION ".")
