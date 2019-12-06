#            _____ _
#           |  _  | |
#  _ __ _ __| | | | |_
# | '__| '__| | | | __| zhengrr
# | |  | |  \ \/' / |_  2016-06-28 – 2019-12-05
# |_|  |_|   \_/\_\\__| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrQt
  TIME_AS_VERSION
  LANGUAGES CXX)

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

find_package(Qt5Config)
find_package(Qt5              # All Modules        https://doc.qt.io/qt-5/qtmodules.html
  COMPONENTS Core             # Qt Core            https://doc.qt.io/qt-5/qtcore-index.html
             Gui              # Qt GUI             https://doc.qt.io/qt-5/qtgui-index.html
             LinguistTools    #
             Qml              # Qt QML             https://doc.qt.io/qt-5/qtqml-index.html
             Quick            # Qt Quick           https://doc.qt.io/qt-5/qtquick-index.html
             QuickControls2   # Qt Quick Controls  https://doc.qt.io/qt-5/qtquickcontrols-index.html
             QuickTemplates2  #
             Test             # Qt Test            https://doc.qt.io/qt-5/qttest-index.html
             Widgets)         # Qt Widgets         https://doc.qt.io/qt-5/qtwidgets-index.html
set_property(GLOBAL PROPERTY AUTOGEN_SOURCE_GROUP "generated")

include_conan_script()
conan_cmake_run(
  REQUIRES    gtest/1.10.0
              ms-gsl/2.0.0
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

add_doxygen_con(
  rrQtDoc)

macro(quickadd_console_executable)
  get_filename_component(pDirName "${CMAKE_CURRENT_LIST_DIR}" NAME)
  aux_source_directory_con("." zSrc RECURSE QT)
  add_executable_con(
    ${PROJECT_NAME}_${pDirName} ${zSrc}
    PROPERTIES                  CXX_STANDARD          20
                                CXX_STANDARD_REQUIRED ON
                                AUTOMOC               ON
    INCLUDE_DIRECTORIES         PRIVATE "."
    LINK_LIBRARIES              PRIVATE CONAN_PKG::ms-gsl
                                        CONAN_PKG::gtest
                                        Qt5::Core)
endmacro()

macro(quickadd_widget_executable)
  get_filename_component(pDirName "${CMAKE_CURRENT_LIST_DIR}" NAME)
  aux_source_directory_con("." zSrc RECURSE QT)
  add_executable_con(
    ${PROJECT_NAME}_${pDirName} WIN32 ${zSrc}
    PROPERTIES                  CXX_STANDARD          20
                                CXX_STANDARD_REQUIRED ON
                                AUTOMOC               ON
                                AUTOUIC               ON
    INCLUDE_DIRECTORIES         PRIVATE "."
    LINK_LIBRARIES              PRIVATE CONAN_PKG::ms-gsl
                                        CONAN_PKG::gtest
                                        Qt5::Core
                                        Qt5::Gui
                                        Qt5::Widgets)
endmacro()

macro(quickadd_quick_executable)
  get_filename_component(pDirName "${CMAKE_CURRENT_LIST_DIR}" NAME)
  aux_source_directory_con("." zSrc RECURSE QT)
  add_executable_con(
    ${PROJECT_NAME}_${pDirName} WIN32 ${zSrc}
    PROPERTIES                  CXX_STANDARD          20
                                CXX_STANDARD_REQUIRED ON
                                AUTOMOC               ON
                                AUTORCC               ON
    INCLUDE_DIRECTORIES         PRIVATE "."
    LINK_LIBRARIES              PRIVATE CONAN_PKG::ms-gsl
                                        CONAN_PKG::gtest
                                        Qt5::Core
                                        Qt5::Gui
                                        Qt5::Network
                                        Qt5::Qml
                                        Qt5::Quick
                                        Qt5::QuickControls2
                                        Qt5::QuickTemplates2)
endmacro()

add_subdirectory_aux(WITHOUT_OPTION)
