#            _____       _____
#           /  __ \     /  __ \
#  _ __ _ __| /  \/_ __ | /  \/_  ____  __
# | '__| '__| |   | '_ \| |   \ \/ /\ \/ / zhengrr
# | |  | |  | \__/\ | | | \__/\>  <  >  <  2016-06-28 – 2019-07-18
# |_|  |_|   \____/_| |_|\____/_/\_\/_/\_\ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
include(rrCMake)

product_ex(
  rrCnCxx
  VERSION   2019.07.11
  LANGUAGES NONE
  AUTHORS   "zhengrr"
  LICENSE   "Unlicense")

add_aux_subdirectories_con()

install(
  FILES       "UNLICENSE.txt"
  DESTINATION ".")
