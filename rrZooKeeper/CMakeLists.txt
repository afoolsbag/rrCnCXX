#          ______            _   __
#         |___  /           | | / /
#  _ __ _ __ / /  ___   ___ | |/ /  ___  ___ _ __   ___ _ __
# | '__| '__/ /  / _ \ / _ \|    \ / _ \/ _ \ '_ \ / _ \ '__|
# | |  | |./ /__| (_) | (_) | |\  \  __/  __/ |_) |  __/ |
# |_|  |_|\_____/\___/ \___/\_| \_/\___|\___| .__/ \___|_|
# zhengrr                                   | |
# 2018-12-29 – 2019-11-20                   |_|
# Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

project_ex(
  rrZooKeeper
  TIME_AS_VERSION
  LANGUAGES CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

hunter_add_package(zookeeper)
find_package(zookeeper CONFIG REQUIRED)

include_conan_script()
conan_cmake_run(
  REQUIRES    gtest/1.10.0
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

find_package(rrZooKeeper REQUIRED CONFIG HINTS "${PRODUCT_SOURCE_DIR}/include/rrzookeeper")

aux_source_directory_ex("." zTest RECURSE)
add_executable_con(
  rrZooKeeperTest     ${zTest}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE rrZooKeeper
                              CONAN_PKG::gtest)

add_test(NAME rrZooKeeperTest COMMAND rrZooKeeperTest)
