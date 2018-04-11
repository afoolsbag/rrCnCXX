set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_executable(SUBNAME "CustomMessage"
  WIN32 "main.h"            "main.cpp"
        "stdafx.h"          "stdafx.cpp"
        "Application.h"     "Application.cpp"
        "ui/HiddenWindow.h" "ui/HiddenWindow.cpp")
