aux_source_directory_ex(
  zSrc
  QT)
add_executable_ex(
  NAME "App_Widget"
  WIN32 ${zSrc}
  FLAT_GROUP
  PROPERTIES     AUTOMOC ON
                 AUTOUIC ON
  LINK_LIBRARIES Qt5::Widgets
  POST_COPIES    Qt5::Core Qt5::Gui Qt5::Widgets)
