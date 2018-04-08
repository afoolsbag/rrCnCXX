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

facile_add_executable(SUBNAME "abc"
  WIN32 "abc/main.cpp"
        "abc/stdafx.h"  "abc/stdafx.cpp"
        "abc/App.h"     "abc/App.cpp"
        "abc/MainWnd.h" "abc/MainWnd.cpp")

facile_add_executable(SUBNAME "appdlg"
  WIN32 "app_dlg/main.cpp"
        "app_dlg/stdafx.h"   "app_dlg/stdafx.cpp"
        "app_dlg/resource.h" "app_dlg/resource.rc"
        "app_dlg/App.h"      "app_dlg/App.cpp"
        "app_dlg/MainDlg.h"  "app_dlg/MainDlg.cpp")

facile_add_executable(SUBNAME "ctrltab"
  WIN32 "ctrl_tab/main.cpp"
        "ctrl_tab/stdafx.h"   "ctrl_tab/stdafx.cpp"
        "ctrl_tab/resource.h" "ctrl_tab/resource.rc"
        "ctrl_tab/App.h"      "ctrl_tab/App.cpp"
        "ctrl_tab/MainDlg.h"  "ctrl_tab/MainDlg.cpp"
        "ctrl_tab/PageDlg.h"  "ctrl_tab/PageDlg.cpp")
