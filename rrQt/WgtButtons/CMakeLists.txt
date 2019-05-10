aux_source_directory_ex(zSource QT)
add_executable_ex(
  NAME "Wgt_Buttons" WIN32 ${zSource}
  PROPERTIES     AUTOMOC ON
                 AUTOUIC ON
  LINK_LIBRARIES Qt5::Widgets
  POST_COPIES    Qt5::Core Qt5::Gui Qt5::Widgets)
