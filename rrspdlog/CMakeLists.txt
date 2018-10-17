#                          _ _
#                         | | |
#  _ __ _ __ ___ _ __   __| | | ___   __ _
# | '__| '__/ __| '_ \ / _` | |/ _ \ / _` |
# | |  | |  \__ \ |_) | (_| | | (_) | (_| |
# |_|  |_|  |___/ .__/ \__,_|_|\___/ \__, |
#               | |                   __/ |
# zhengrr       |_|                  |___/  rrspdlog by FIGlet doom
# 2018-08-04 – 2018-10-16
# The Unlicense

cmake_policy(SET CMP0074 NEW) #3.12+

project(rrspdlog VERSION 2108.10.16 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8)

facile_add_doxygen()

find_package(spdlog)

aux_source_directory_ex(zSource RECURSE)
facile_add_gtest_executable(
  NAME "test"
  ${zSource}
  CXX17
  INCLUDE_DIRECTORIES PRIVATE "./"
                              ${spdlog_INCLUDE_DIRS})
