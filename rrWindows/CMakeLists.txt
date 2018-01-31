#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-1-31
# The MIT License

project("rrWindows" VERSION 2018.1.20 LANGUAGES C)
project_variables()
highest_warning_level()

quick_doxygen()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

quick_executable(SUBNAME "ConsoleApp" "ConsoleApp.c")
quick_executable(SUBNAME "DesktopApp" WIN32 "DesktopApp.c")
quick_executable(SUBNAME "FileAttrs" "DaSto/LocalFS/FileMgmt/Attrs.c")
quick_executable(SUBNAME "FileExists" "DaSto/LocalFS/FileMgmt/Exists.c")
quick_executable(SUBNAME "FileFild" "DaSto/LocalFS/FileMgmt/Find.c")
quick_executable(SUBNAME "Unicode" "DesktopAppUi/I18n4WinApps/Unicode.c")
quick_executable(SUBNAME "ErrHandling" "Diags/DebugEh/ErrHandling.c")
quick_executable(SUBNAME "TcpClient" "NetInternet/WinSock2/TcpClient.c")
quick_executable(SUBNAME "TcpServer" "NetInternet/WinSock2/TcpServer.c")
quick_executable(SUBNAME "UdpClient" "NetInternet/WinSock2/UdpClient.c")
quick_executable(SUBNAME "UdpServer" "NetInternet/WinSock2/UdpServer.c")
quick_executable(SUBNAME "Thread" "SysSvs/ProcThrd/Thread.c")
quick_executable(SUBNAME "SglInstApp" "SysSvs/Sync/SglInstApp.c")
quick_executable(SUBNAME "IniFile" "SysSvs/WinSysInfo/Reg/IniFile.c")

add_library(${PROJECT_NAME_LOWER}_dll_shared SHARED "SysSvs/Dlls/Lib.h" "SysSvs/Dlls/Lib.c")
add_executable(${PROJECT_NAME_LOWER}_dll_exe "SysSvs/Dlls/Exe.c")
target_link_libraries(${PROJECT_NAME_LOWER}_dll_exe ${PROJECT_NAME_LOWER}_dll_shared)
