#          ______            _   __
#         |___  /           | | / /
#  _ __ _ __ / /  ___   ___ | |/ /  ___  ___ _ __   ___ _ __
# | '__| '__/ /  / _ \ / _ \|    \ / _ \/ _ \ '_ \ / _ \ '__|
# | |  | |./ /__| (_) | (_) | |\  \  __/  __/ |_) |  __/ |
# |_|  |_|\_____/\___/ \___/\_| \_/\___|\___| .__/ \___|_|
# zhengrr                                   | |
# 2018-12-29 – 2019-03-15                   |_|
# Unlicense

project(rrZooKeeper VERSION 2018.03.15 LANGUAGES C)
project_more()

compile_option(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen(WITH_OPTION OPTIMIZE_OUTPUT_FOR_C)

if(3.12 VERSION_LESS CMAKE_VERSION)
  cmake_policy(SET CMP0074 NEW)
endif()
find_package(Check)
find_package(ZooKeeperC)

aux_source_directory_ex(zSource RECURSE)
add_executable_ex(
  ${zSource} C11
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE Check::check
                              ZooKeeperC::zookeeper)
