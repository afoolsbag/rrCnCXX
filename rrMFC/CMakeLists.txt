#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____|
# zhengrr       rrMFC by FIGlet
# 2017-12-8 – 2018-2-12
# The MIT License

project("rrMFC" VERSION 2018.2.12 LANGUAGES CXX)
project_variables()
highest_warning_level()

quick_doxygen()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)

quick_executable(SUBNAME "PWMFC010300"
  WIN32 "PWMFC010300/main.cpp"
        "PWMFC010300/stdafx.h"
        "PWMFC010300/HelloApp.h"
        "PWMFC010300/HelloApp.cpp"
        "PWMFC010300/HelloMainWnd.h"
        "PWMFC010300/HelloMainWnd.cpp")

quick_executable(SUBNAME "PWMFC020212"
  WIN32 "PWMFC020212/main.cpp"
        "PWMFC020212/stdafx.h"
        "PWMFC020212/RulerApp.h"
        "PWMFC020212/RulerApp.cpp"
        "PWMFC020212/RulerMainWnd.h"
        "PWMFC020212/RulerMainWnd.cpp")

quick_executable(SUBNAME "PWMFC020306"
  WIN32 "PWMFC020306/main.cpp"
        "PWMFC020306/stdafx.h"
        "PWMFC020306/AccelApp.h"
        "PWMFC020306/AccelApp.cpp"
        "PWMFC020306/AccelMainWnd.h"
        "PWMFC020306/AccelMainWnd.cpp")

quick_executable(SUBNAME "PWMFC030102"
  WIN32 "PWMFC030102/main.cpp"
        "PWMFC030102/stdafx.h"
        "PWMFC030102/TicTacToeApp.h"
        "PWMFC030102/TicTacToeApp.cpp"
        "PWMFC030102/TicTacToeMainWnd.h"
        "PWMFC030102/TicTacToeMainWnd.cpp")

quick_executable(SUBNAME "PWMFC030108"
  WIN32 "PWMFC030108/main.cpp"
        "PWMFC030108/stdafx.h"
        "PWMFC030108/DragLineApp.h"
        "PWMFC030108/DragLineApp.cpp"
        "PWMFC030108/DragLineMainWnd.h"
        "PWMFC030108/DragLineMainWnd.cpp")

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
