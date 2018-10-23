#             ___  _
#  _ __ _ __ / _ \| |_
# | '__| '__| | | | __|
# | |  | |  | |_| | |_
# |_|  |_|   \__\_\\__| rrQt by FIGlet
# zhengrr
# 2016-06-28 – 2018-10-22
# The Unlicense

project(rrQt VERSION 2018.10.22 LANGUAGES CXX)
project_more()
compile_option(UTF-8)

facile_add_doxygen()

find_package(Qt5Package)
find_package(
  Qt5
  COMPONENTS Core Gui Widgets
             Quick
             Test)

aux_add_subdirectories(
  WITH_OPTION
  OPTION_NAME_PREFIX "${PROJECT_NAME_UPPER}_")
