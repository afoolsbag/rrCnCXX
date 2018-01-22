#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-1-20
# The MIT License

project("rrWindows" VERSION 2018.1.20 LANGUAGES C)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

quick_add_executable_with_option(SUBNAME "ConsoleApp" "ConsoleApp.c")
quick_add_executable_with_option(SUBNAME "DesktopApp" WIN32 "DesktopApp.c")
quick_add_executable_with_option(SUBNAME "FileAttrs" "DaSto/LocalFS/FileMgmt/Attrs.c")
quick_add_executable_with_option(SUBNAME "FileExists" "DaSto/LocalFS/FileMgmt/Exists.c")
quick_add_executable_with_option(SUBNAME "FileFild" "DaSto/LocalFS/FileMgmt/Find.c")
quick_add_executable_with_option(SUBNAME "Unicode" "DesktopAppUi/I18n4WinApps/Unicode.c")
quick_add_executable_with_option(SUBNAME "ErrHandling" "Diags/DebugEh/ErrHandling.c")
quick_add_executable_with_option(SUBNAME "TcpClient" "NetInternet/WinSock2/TcpClient.c")
quick_add_executable_with_option(SUBNAME "TcpServer" "NetInternet/WinSock2/TcpServer.c")
quick_add_executable_with_option(SUBNAME "UdpClient" "NetInternet/WinSock2/UdpClient.c")
quick_add_executable_with_option(SUBNAME "UdpServer" "NetInternet/WinSock2/UdpServer.c")
quick_add_executable_with_option(SUBNAME "Thread" "SysSvs/ProcThrd/Thread.c")
quick_add_executable_with_option(SUBNAME "SglInstApp" "SysSvs/Sync/SglInstApp.c")
quick_add_executable_with_option(SUBNAME "IniFile" "SysSvs/WinSysInfo/Reg/IniFile.c")

add_library(${PROJECT_NAME_LOWER}_dll_shared SHARED "SysSvs/Dlls/Lib.h" "SysSvs/Dlls/Lib.c")
add_executable(${PROJECT_NAME_LOWER}_dll_exe "SysSvs/Dlls/Exe.c")
target_link_libraries(${PROJECT_NAME_LOWER}_dll_exe ${PROJECT_NAME_LOWER}_dll_shared)
