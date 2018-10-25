aux_source_directory_ex(
  zSrc
  QT)
add_executable_ex(
  NAME "App_Quick"
  WIN32 ${zSrc}
  FLAT_GROUP
  PROPERTIES     AUTOMOC ON
                 AUTORCC ON
  LINK_LIBRARIES Qt5::Quick
  POST_COPIES    Qt5::Core Qt5::Gui Qt5::Network Qt5::Qml Qt5::Quick)
