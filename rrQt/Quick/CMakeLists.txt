aux_source_directory_con("." zSrc QT)
add_executable_con(
  rrQtQuick      WIN32
                 ${zSrc}
  PROPERTIES     CXX_STANDARD          17
                 CXX_STANDARD_REQUIRED ON
                 AUTOMOC               ON
                 AUTORCC               ON
  LINK_LIBRARIES Qt5::Core
                 Qt5::Gui
                 Qt5::Network
                 Qt5::Qml
                 Qt5::Quick)
