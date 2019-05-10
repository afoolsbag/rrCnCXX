aux_source_directory_ex(zSource QT)

qt5_create_translation(zCompiledTranslations ${zSource})
source_group("generated" FILES ${zCompiledTranslations})
list(APPEND zSource ${zCompiledTranslations})

add_executable_ex(
  NAME "App_Linguist" TARGET_NAME_VARIABLE sTarget WIN32 ${zSource}
  PROPERTIES     AUTOMOC ON
                 AUTORCC ON
                 AUTOUIC ON
  LINK_LIBRARIES Qt5::Widgets
  POST_COPIES    Qt5::Core Qt5::Gui Qt5::Widgets)

add_custom_command(
  TARGET ${sTarget} POST_BUILD
  COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
          ${zCompiledTranslations}
          "$<TARGET_FILE_DIR:${sTarget}>/lang")
