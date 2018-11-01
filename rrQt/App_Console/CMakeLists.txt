aux_source_directory_ex(zSource QT)
add_executable_ex(
  NAME "App_Console" ${zSource}
  PROPERTIES     AUTOMOC ON
  LINK_LIBRARIES Qt5::Core
  POST_COPIES    Qt5::Core)
