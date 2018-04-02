#             ___  _
#  _ __ _ __ / _ \| |_
# | '__| '__| | | | __|
# | |  | |  | |_| | |_
# |_|  |_|   \__\_\\__| rrQt by FIGlet
# zhengrr
# 2016-06-28 – 2018-04-02
# The MIT License

project("rrQt" VERSION 2018.4.2 LANGUAGES CXX)
project_variables()
highest_warning_level()

if(NOT Qt5Package_FOUND)
  find_package(Qt5Package)
  if(NOT Qt5Package_FOUND)
    set(Qt5_ROOT_DIR "${Qt5_ROOT_DIR}" CACHE PATH "The root directory of the Qt5 installation.")
  endif()
endif()

facile_add_doxygen()

find_package(Qt5 COMPONENTS
  Core Gui Widgets
  Quick
  Test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_qt_executable(SUBNAME "ConApp"
  "con_app.cxx"
  LINKS Qt5::Core)
facile_add_qt_executable(SUBNAME "WgtApp"
  WIN32 "wgt_app.cxx"
  LINKS Qt5::Core Qt5::Gui Qt5::Widgets)

facile_add_qt_executable(SUBNAME "QckApp"
  WIN32 "QtQuick/qck_app.cxx"
  LINKS Qt5::Core Qt5::Gui Qt5::Qml Qt5::Quick)
