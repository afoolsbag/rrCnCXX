aux_source_directory_ex(
  zSrc
  QT)
add_executable_ex(
  NAME "App_Console"
  ${zSrc}
  FLAT_GROUP
  PROPERTIES     AUTOMOC ON
  LINK_LIBRARIES Qt5::Core
  POST_COPIES    Qt5::Core)
