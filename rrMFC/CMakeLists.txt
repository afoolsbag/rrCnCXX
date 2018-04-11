#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____|
# zhengrr       rrMFC by FIGlet
# 2017-12-08 – 2018-04-11
# The MIT License

project("rrMFC" VERSION 2018.4.11 LANGUAGES CXX)
project_extra()
highest_warning_level()

facile_add_doxygen()

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)

aux_add_subdirectories()

facile_add_executable(SUBNAME "DateTime"
  WIN32 "dt/main.cpp"
        "dt/stdafx.h"      "dt/stdafx.cpp"
        "dt/Application.h" "dt/Application.cpp")

facile_add_executable(SUBNAME "DialogApplication"
  WIN32 "gen/dlgapp/main.cpp"
        "gen/dlgapp/stdafx.h"      "gen/dlgapp/stdafx.cpp"
        "gen/dlgapp/resource.h"    "gen/dlgapp/resource.rc"
        "gen/dlgapp/Application.h" "gen/dlgapp/Application.cpp"
        "gen/dlgapp/MainDialog.h"  "gen/dlgapp/MainDialog.cpp")

facile_add_executable(SUBNAME "CustomMessage"
  WIN32 "msg/custom/main.h"         "msg/custom/main.cpp"
        "msg/custom/stdafx.h"       "msg/custom/stdafx.cpp"
        "msg/custom/Application.h"  "msg/custom/Application.cpp"
        "msg/custom/HiddenWindow.h" "msg/custom/HiddenWindow.cpp")

facile_add_executable(SUBNAME "TimerMessage"
  WIN32 "msg/timer/main.cpp"
        "msg/timer/stdafx.h"      "msg/timer/stdafx.cpp"
        "msg/timer/resource.h"    "msg/timer/resource.rc"
        "msg/timer/Application.h" "msg/timer/Application.cpp"
        "msg/timer/MainDialog.h"  "msg/timer/MainDialog.cpp")

facile_add_executable(SUBNAME "ListControl"
  WIN32 "uielem/ctrl/list/main.cpp"
        "uielem/ctrl/list/stdafx.h"      "uielem/ctrl/list/stdafx.cpp"
        "uielem/ctrl/list/resource.h"    "uielem/ctrl/list/resource.rc"
        "uielem/ctrl/list/Application.h" "uielem/ctrl/list/Application.cpp"
        "uielem/ctrl/list/MainDialog.h"  "uielem/ctrl/list/MainDialog.cpp")

facile_add_executable(SUBNAME "TabControl"
  WIN32 "uielem/ctrl/tab/main.cpp"
        "uielem/ctrl/tab/stdafx.h"      "uielem/ctrl/tab/stdafx.cpp"
        "uielem/ctrl/tab/resource.h"    "uielem/ctrl/tab/resource.rc"
        "uielem/ctrl/tab/Application.h" "uielem/ctrl/tab/Application.cpp"
        "uielem/ctrl/tab/MainDialog.h"  "uielem/ctrl/tab/MainDialog.cpp"
        "uielem/ctrl/tab/PageDialog.h"  "uielem/ctrl/tab/PageDialog.cpp")
