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

aux_source_directory_enhanced(zSrc RECURSE SOURCE_PREFIXS "gt")
facile_add_gtest_executable(SUBNAME "Test"
                                    OPTION_INITIAL_ON
                                    ${zSrc}
                INCLUDE_DIRECTORIES PRIVATE "."
                 PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON
                     LINK_LIBRARIES Qt5::Core
                        POST_COPIES Qt5::Core)

facile_add_executable(SUBNAME "ConsoleApplication"
         TARGET_NAME_VARIABLE sTgt
                              FLAT_GROUP
                              "conapp.cpp"
                   PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON
               LINK_LIBRARIES Qt5::Core
                  POST_COPIES Qt5::Core)

facile_add_executable(SUBNAME "WidgetApplication"
         TARGET_NAME_VARIABLE sTgt
                              FLAT_GROUP
                        WIN32 "wgtapp.cpp"
                   PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON
               LINK_LIBRARIES Qt5::Core Qt5::Gui Qt5::Widgets
                  POST_COPIES Qt5::Core Qt5::Gui Qt5::Widgets)

facile_add_executable(SUBNAME "QuickApplication"
         TARGET_NAME_VARIABLE sTgt
                              FLAT_GROUP
                        WIN32 "qckapp.cpp"
                   PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON
               LINK_LIBRARIES Qt5::Core Qt5::Gui Qt5::Qml Qt5::Quick
                  POST_COPIES Qt5::Core Qt5::Gui Qt5::Qml Qt5::Quick)

aux_add_subdirectories()
