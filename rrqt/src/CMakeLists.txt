# Qt CMake Tools
find_package(Qt5Directory REQUIRED)
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
source_file_helper(
    RECURSE CONFIGURE CPP QT
    SRC_VAR source_files
    GRP_DIR "/")
set(ts_files "ts/hans-CN.ts")

if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/qml")
  file(COPY "qml" DESTINATION ".")
  install(DIRECTORY "qml" DESTINATION "bin/")
endif()

option(${PROJECT_NAME_UPPER}_UPDATE_TRANSLATIONS "Update source translation *.ts" OFF)
if(${PROJECT_NAME_UPPER}_UPDATE_TRANSLATIONS)
  qt5_create_translation(qm_files ${source_files} ${ts_files})
else()
  qt5_add_translation(qm_files ${ts_files})
endif()
list(APPEND source_files ${qm_files})
foreach(file IN LISTS qm_files)
  if(EXISTS "${file}")
    file(COPY "${file}" DESTINATION "${CMAKE_CURRENT_LIST_DIR}/rc/qm")
  endif()
endforeach()

option(${PROJECT_NAME_UPPER}_COMPILE_EXE "Build executable file." ON)
if(${PROJECT_NAME_UPPER}_COMPILE_EXE)
  add_executable(${PROJECT_NAME_LOWER}_exe WIN32 ${source_files})
  target_link_libraries(${PROJECT_NAME_LOWER}_exe
      Qt5::Core Qt5::Gui Qt5::Network Qt5::Qml Qt5::Quick Qt5::Sql
      Qt5::WebSockets Qt5::Widgets)
  set_target_properties(${PROJECT_NAME_LOWER}_exe PROPERTIES
      CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON
      OUTPUT_NAME "${PROJECT_NAME}" CLEAN_DIRECT_OUTPUT ON
      AUTOMOC ON AUTOUIC ON AUTORCC ON)
  install(TARGETS ${PROJECT_NAME_LOWER}_exe DESTINATION "bin")
endif()
