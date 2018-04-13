set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_executable(SUBNAME "FrameApplication"
  WIN32 "main.cpp"
        "stdafx.h"       "stdafx.cpp"
        "resource.h"     "resource.rc"
        "Application.h"  "Application.cpp"
        "ui/MainFrame.h" "ui/MainFrame.cpp"
        "ui/MainView.h"  "ui/MainView.cpp")
