set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_executable(SUBNAME "ListControl"
  WIN32 "main.cpp"
        "stdafx.h"        "stdafx.cpp"
        "resource.h"      "resource.rc"
        "Application.h"   "Application.cpp"
        "ui/MainDialog.h" "ui/MainDialog.cpp")
