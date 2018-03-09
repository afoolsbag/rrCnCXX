#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____|
# zhengrr       rrMFC by FIGlet
# 2017-12-8 – 2018-2-24
# The MIT License

project("rrMFC" VERSION 2018.2.24 LANGUAGES CXX)
project_variables()
highest_warning_level()

facile_add_doxygen()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)

facile_add_executable(SUBNAME "hello"
  WIN32 "hello/main.cpp"
        "hello/stdafx.h"
        "hello/HelloApp.h"
        "hello/HelloApp.cpp"
        "hello/HelloMainWnd.h"
        "hello/HelloMainWnd.cpp")

facile_add_executable(SUBNAME "ruler"
  WIN32 "ruler/main.cpp"
        "ruler/stdafx.h"
        "ruler/RulerApp.h"
        "ruler/RulerApp.cpp"
        "ruler/RulerMainWnd.h"
        "ruler/RulerMainWnd.cpp")

facile_add_executable(SUBNAME "accel"
  WIN32 "accel/main.cpp"
        "accel/stdafx.h"
        "accel/AccelApp.h"
        "accel/AccelApp.cpp"
        "accel/AccelMainWnd.h"
        "accel/AccelMainWnd.cpp")

facile_add_executable(SUBNAME "tictactoe"
  WIN32 "tictactoe/main.cpp"
        "tictactoe/stdafx.h"
        "tictactoe/TicTacToeApp.h"
        "tictactoe/TicTacToeApp.cpp"
        "tictactoe/TicTacToeMainWnd.h"
        "tictactoe/TicTacToeMainWnd.cpp")

facile_add_executable(SUBNAME "dragline"
  WIN32 "dragline/main.cpp"
        "dragline/stdafx.h"
        "dragline/DragLineApp.h"
        "dragline/DragLineApp.cpp"
        "dragline/DragLineMainWnd.h"
        "dragline/DragLineMainWnd.cpp")

facile_add_executable(SUBNAME "viskb"
  WIN32 "viskb/main.cpp"
        "viskb/stdafx.h"
        "viskb/VisualKeyboardApp.h"
        "viskb/VisualKeyboardApp.cpp"
        "viskb/VisualKeyboardMainWnd.h"
        "viskb/VisualKeyboardMainWnd.cpp")

facile_add_executable(SUBNAME "shapes"
  WIN32 "shapes/main.cpp"
        "shapes/stdafx.h"
        "shapes/resource.h"
        "shapes/resource.rc"
        "shapes/ShapesApp.h"
        "shapes/ShapesApp.cpp"
        "shapes/ShapesAboutDlg.h"
        "shapes/ShapesAboutDlg.cpp"
        "shapes/ShapesMainFrm.h"
        "shapes/ShapesMainFrm.cpp"
        "shapes/ShapesChildView.h"
        "shapes/ShapesChildView.cpp")
