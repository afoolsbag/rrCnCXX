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
#quick_aux_source_directory(
#  zSourceFiles
#  RECURSE CONFIGURE CXX QT)
#set(zTsFiles "ts/hans-CN.ts")
#
#if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/qml")
#  file(COPY "qml" DESTINATION ".")
#  install(DIRECTORY "qml" DESTINATION "bin/")
#endif()
#
#option(${PROJECT_NAME_UPPER}_UPDATE_TRANSLATIONS "Update source translation *.ts" OFF)
#if(${PROJECT_NAME_UPPER}_UPDATE_TRANSLATIONS)
#  qt5_create_translation(zQmFiles ${zSourceFiles} ${zTsFiles})
#else()
#  qt5_add_translation(zQmFiles ${zTsFiles})
#endif()
#list(APPEND zSourceFiles ${zQmFiles})
#foreach(sFile IN LISTS zQmFiles)
#  if(EXISTS "${sFile}")
#    file(COPY "${sFile}" DESTINATION "${CMAKE_CURRENT_LIST_DIR}/rc/qm")
#  endif()
#endforeach()

quick_qt_executable(SUBNAME "ConsoleApp" "console_app.cpp" MODULES Qt5::Core)
quick_qt_executable(SUBNAME "WidgetsApp" WIN32 "widgets_app.cpp" MODULES Qt5::Widgets)
