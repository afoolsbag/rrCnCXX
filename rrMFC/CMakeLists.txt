#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____|
# zhengrr       rrMFC by FIGlet
# 2017-12-08 – 2018-04-04
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
  WIN32 "appdlg/main.cpp"
        "appdlg/stdafx.h"   "appdlg/stdafx.cpp"
        "appdlg/resource.h" "appdlg/resource.rc"
        "appdlg/App.h"      "appdlg/App.cpp"
        "appdlg/MainDlg.h"  "appdlg/MainDlg.cpp")

facile_add_executable(SUBNAME "ctrltab"
  WIN32 "ctrltab/main.cpp"
        "ctrltab/stdafx.h"   "ctrltab/stdafx.cpp"
        "ctrltab/resource.h" "ctrltab/resource.rc"
        "ctrltab/App.h"      "ctrltab/App.cpp"
        "ctrltab/MainDlg.h"  "ctrltab/MainDlg.cpp")
