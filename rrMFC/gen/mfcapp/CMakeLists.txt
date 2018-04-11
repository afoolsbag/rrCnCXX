set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_executable(SUBNAME "MfcApplication"
  WIN32 "main.cpp"
        "stdafx.h"        "stdafx.cpp"
        "Application.h"   "Application.cpp"
        "ui/MainWindow.h" "ui/MainWindow.cpp")
