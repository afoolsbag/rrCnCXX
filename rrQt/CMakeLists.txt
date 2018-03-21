#             ___  _
#  _ __ _ __ / _ \| |_
# | '__| '__| | | | __|
# | |  | |  | |_| | |_
# |_|  |_|   \__\_\\__| rrQt by FIGlet
# zhengrr
# 2016-06-28 – 2018-03-19
# The MIT License

if(NOT QT5PACKAGE_FOUND)
  if(NOT CMAKE_SIZEOF_VOID_P)
    set(QTDIR "${QTDIR}" CACHE PATH "The root directory of the Qt5 installation.")
  endif()
  find_package(Qt5Package)
endif()

project("rrQt" VERSION 2018.3.19 LANGUAGES CXX)
project_variables()
highest_warning_level()

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
