#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____|
# zhengrr       rrMFC by FIGlet
# 2017-12-08 – 2018-04-08
# The MIT License

project("rrMFC" VERSION 2018.2.24 LANGUAGES CXX)
project_variables()
highest_warning_level()

facile_add_doxygen()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)

facile_add_executable(SUBNAME "MFC"
  WIN32 "cep/gen/mfc/main.cpp"
        "cep/gen/mfc/stdafx.h"      "cep/gen/mfc/stdafx.cpp"
        "cep/gen/mfc/Application.h" "cep/gen/mfc/Application.cpp"
        "cep/gen/mfc/MainWindow.h"  "cep/gen/mfc/MainWindow.cpp")

facile_add_executable(SUBNAME "DialogApplication"
  WIN32 "cep/gen/dlg/main.cpp"
        "cep/gen/dlg/stdafx.h"      "cep/gen/dlg/stdafx.cpp"
        "cep/gen/dlg/resource.h"    "cep/gen/dlg/resource.rc"
        "cep/gen/dlg/Application.h" "cep/gen/dlg/Application.cpp"
        "cep/gen/dlg/MainDialog.h"  "cep/gen/dlg/MainDialog.cpp")

facile_add_executable(SUBNAME "Timer"
  WIN32 "cep/msg/timer/main.cpp"
        "cep/msg/timer/stdafx.h"      "cep/msg/timer/stdafx.cpp"
        "cep/msg/timer/resource.h"    "cep/msg/timer/resource.rc"
        "cep/msg/timer/Application.h" "cep/msg/timer/Application.cpp"
        "cep/msg/timer/MainDialog.h"  "cep/msg/timer/MainDialog.cpp")

facile_add_executable(SUBNAME "ListControl"
  WIN32 "cep/uielem/ctrl/list/main.cpp"
        "cep/uielem/ctrl/list/stdafx.h"      "cep/uielem/ctrl/list/stdafx.cpp"
        "cep/uielem/ctrl/list/resource.h"    "cep/uielem/ctrl/list/resource.rc"
        "cep/uielem/ctrl/list/Application.h" "cep/uielem/ctrl/list/Application.cpp"
        "cep/uielem/ctrl/list/MainDialog.h"  "cep/uielem/ctrl/list/MainDialog.cpp")

facile_add_executable(SUBNAME "TabControl"
  WIN32 "cep/uielem/ctrl/tab/main.cpp"
        "cep/uielem/ctrl/tab/stdafx.h"      "cep/uielem/ctrl/tab/stdafx.cpp"
        "cep/uielem/ctrl/tab/resource.h"    "cep/uielem/ctrl/tab/resource.rc"
        "cep/uielem/ctrl/tab/Application.h" "cep/uielem/ctrl/tab/Application.cpp"
        "cep/uielem/ctrl/tab/MainDialog.h"  "cep/uielem/ctrl/tab/MainDialog.cpp"
        "cep/uielem/ctrl/tab/PageDialog.h"  "cep/uielem/ctrl/tab/PageDialog.cpp")
