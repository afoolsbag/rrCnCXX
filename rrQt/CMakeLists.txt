#             ___  _
#  _ __ _ __ / _ \| |_
# | '__| '__| | | | __|
# | |  | |  | |_| | |_
# |_|  |_|   \__\_\\__| rrQt by FIGlet
# zhengrr
# 2016-6-28 – 2018-1-23
# The MIT License

find_package(Qt5Package)
if(NOT Qt5Package_FOUND)
  return()
endif()

project("rrQt" VERSION 2018.1.29 LANGUAGES CXX)
project_variables()
highest_warning_level()

find_package(Qt5 COMPONENTS
  Core Gui Widgets
  Quick
  Test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

quick_qt_executable(SUBNAME "ConsoleApp" "console_app.cpp" MODULES Qt5::Core)
quick_qt_executable(SUBNAME "WidgetsApp" WIN32 "widgets_app.cpp" MODULES Qt5::Widgets)
