#             ___  _
#  _ __ _ __ / _ \| |_
# | '__| '__| | | | __|
# | |  | |  | |_| | |_
# |_|  |_|   \__\_\\__| rrQt by FIGlet
# zhengrr
# 2016-06-28 – 2018-07-03
# The MIT License

project(rrQt VERSION 2018.7.3 LANGUAGES CXX)
project_extra()
compiler_warning_level(AS_ERROR UTF-8)

facile_add_doxygen()

find_package(Qt5Package)
find_package(Qt5
  COMPONENTS Core Gui Widgets
             Quick
             Test)

facile_add_executable(SUBNAME ConApp
                              "conapp.cxx"
                   PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON
               LINK_LIBRARIES Qt5::Core)
facile_add_executable(SUBNAME WgtApp
                        WIN32 "wgtapp.cxx"
                   PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON
               LINK_LIBRARIES Qt5::Core Qt5::Gui Qt5::Widgets)
facile_add_executable(SUBNAME QckApp
                        WIN32 "qckapp.cxx"
                   PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON
               LINK_LIBRARIES Qt5::Core Qt5::Gui Qt5::Qml Qt5::Quick)
