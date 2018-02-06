#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____|
# zhengrr       rrMFC by FIGlet
# 2017-12-8 – 2018-2-6
# The MIT License

project("rrMFC" VERSION 2018.2.6 LANGUAGES CXX)
project_variables()
highest_warning_level()

quick_doxygen()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)

quick_executable(SUBNAME "Hello" WIN32 "pwmfc/CHelloApp.h" "pwmfc/CHelloApp.cpp")
quick_executable(SUBNAME "Sinusoid" WIN32 "pwmfc/CSinusoidApp.h" "pwmfc/CSinusoidApp.cpp")
quick_executable(SUBNAME "Text" WIN32 "pwmfc/CTextApp.h" "pwmfc/CTextApp.cpp")
quick_executable(SUBNAME "RotateText" WIN32 "pwmfc/CRotateTextApp.h" "pwmfc/CRotateTextApp.cpp")
quick_executable(SUBNAME "Ruler" WIN32 "pwmfc/CRulerApp.h" "pwmfc/CRulerApp.cpp")
quick_executable(SUBNAME "Accel" WIN32 "pwmfc/CAccelApp.h" "pwmfc/CAccelApp.cpp")
quick_executable(SUBNAME "Tictac" WIN32 "pwmfc/CTictacApp.h" "pwmfc/CTictacApp.cpp")
quick_executable(SUBNAME "MouseCap" WIN32 "pwmfc/CMouseCapApp.h" "pwmfc/CMouseCapApp.cpp")
quick_executable(SUBNAME "VisualKb" WIN32 "pwmfc/CVisualKbApp.h" "pwmfc/CVisualKbApp.cpp")
quick_executable(SUBNAME "FontView" WIN32 "pwmfc/CFontViewApp.h" "pwmfc/CFontViewApp.cpp")
