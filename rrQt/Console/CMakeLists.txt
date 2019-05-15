aux_source_directory_con("." zSrc QT)
add_executable_con(
  rrQtConsole    ${zSrc}
  PROPERTIES     CXX_STANDARD          17
                 CXX_STANDARD_REQUIRED ON
                 AUTOMOC               ON
  LINK_LIBRARIES Qt5::Core)
