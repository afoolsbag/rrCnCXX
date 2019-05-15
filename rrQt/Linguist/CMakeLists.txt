aux_source_directory_con("." zSrc QT)

qt5_create_translation(zCompTrans ${zSrc})
source_group("generated" FILES ${zCompTrans})
list(APPEND zSrc ${zCompTrans})

add_executable_con(
  rrQtLinguist   WIN32
                 ${zSrc}
  PROPERTIES     CXX_STANDARD          17
                 CXX_STANDARD_REQUIRED ON
                 AUTOMOC ON
                 AUTORCC ON
                 AUTOUIC ON
  LINK_LIBRARIES Qt5::Core
                 Qt5::Gui
                 Qt5::Widgets)

add_custom_command(
    TARGET rrQtLinguist POST_BUILD
    COMMAND "${CMAKE_COMMAND}" "-E" "make_directory"
            "$<TARGET_FILE_DIR:rrQtLinguist>/lang")

add_custom_command(
  TARGET rrQtLinguist POST_BUILD
  COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
          ${zCompTrans}
          "$<TARGET_FILE_DIR:rrQtLinguist>/lang")
