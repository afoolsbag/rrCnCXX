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
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

# Qt Essentials Modules
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Sql REQUIRED)
# Qt Add-on Modules
find_package(Qt5WebSockets REQUIRED)
find_package(Qt5Widgets REQUIRED)
# Qt I18n Tools
find_package(Qt5LinguistTools REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
quick_aux_source_directory(
  zSourceFiles
  RECURSE CONFIGURE CXX QT)
set(zTsFiles "ts/hans-CN.ts")

if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/qml")
  file(COPY "qml" DESTINATION ".")
  install(DIRECTORY "qml" DESTINATION "bin/")
endif()

option(${PROJECT_NAME_UPPER}_UPDATE_TRANSLATIONS "Update source translation *.ts" OFF)
if(${PROJECT_NAME_UPPER}_UPDATE_TRANSLATIONS)
  qt5_create_translation(zQmFiles ${zSourceFiles} ${zTsFiles})
else()
  qt5_add_translation(zQmFiles ${zTsFiles})
endif()
list(APPEND zSourceFiles ${zQmFiles})
foreach(sFile IN LISTS zQmFiles)
  if(EXISTS "${sFile}")
    file(COPY "${sFile}" DESTINATION "${CMAKE_CURRENT_LIST_DIR}/rc/qm")
  endif()
endforeach()

option(${PROJECT_NAME_UPPER}_COMPILE_EXE "Build executable file." ON)
if(${PROJECT_NAME_UPPER}_COMPILE_EXE)
  add_executable(${PROJECT_NAME_LOWER}_exe WIN32 ${zSourceFiles})
  target_link_libraries(${PROJECT_NAME_LOWER}_exe
    Qt5::Core Qt5::Gui Qt5::Network Qt5::Qml Qt5::Quick Qt5::Sql
    Qt5::WebSockets Qt5::Widgets)
  set_target_properties(${PROJECT_NAME_LOWER}_exe PROPERTIES
    CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME "${PROJECT_NAME}" CLEAN_DIRECT_OUTPUT ON
    AUTOMOC ON AUTOUIC ON AUTORCC ON)
  install(TARGETS ${PROJECT_NAME_LOWER}_exe DESTINATION "bin")
endif()
