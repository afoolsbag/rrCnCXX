#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____|
# zhengrr       rrMFC by FIGlet
# 2017-12-8 – 2018-2-11
# The MIT License

project("rrMFC" VERSION 2018.2.11 LANGUAGES CXX)
project_variables()
highest_warning_level()

quick_doxygen()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)

quick_executable(SUBNAME "Frame"
  WIN32 "Frame/main.cpp"
        "Frame/stdafx.h"
        "Frame/FrameApp.h"
        "Frame/FrameApp.cpp"
        "Frame/FrameMainWnd.h"
        "Frame/FrameMainWnd.cpp")
quick_executable(SUBNAME "Window"
  WIN32 "Window/main.cpp"
        "Window/stdafx.h"
        "Window/WindowApp.h"
        "Window/WindowApp.cpp"
        "Window/WindowMainWnd.h"
        "Window/WindowMainWnd.cpp")

quick_executable(SUBNAME "DragLine"
  WIN32 "DragLine/main.cpp"
        "DragLine/stdafx.h"
        "DragLine/DragLineApp.h"
        "DragLine/DragLineApp.cpp"
        "DragLine/DragLineMainWnd.h"
        "DragLine/DragLineMainWnd.cpp")

quick_executable(SUBNAME "ComboBoxList"
  WIN32 "ComboBoxList/main.cpp"
        "ComboBoxList/stdafx.h"
		"ComboBoxList/resource.h"
        "ComboBoxList/ComboBoxListApp.h"
        "ComboBoxList/ComboBoxListApp.cpp"
        "ComboBoxList/ComboBoxListMainWnd.h"
        "ComboBoxList/ComboBoxListMainWnd.cpp"
		"ComboBoxList/ComboBoxListCtrl.h"
        "ComboBoxList/ComboBoxListCtrl.cpp")
