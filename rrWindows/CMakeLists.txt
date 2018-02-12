#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-2-9
# The MIT License

project("rrWindows" VERSION 2018.2.9 LANGUAGES C)
project_variables()
highest_warning_level()

quick_doxygen(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#enable_testing()
#quick_gtest()

quick_executable(SUBNAME "ConsoleApp"
  "csapp.c")

quick_executable(SUBNAME "DesktopApp"
  WIN32 "dtapp.c")

quick_executable(SUBNAME "FileAttrs" "data/lfsys/fmgmt/Attrs.c")
quick_executable(SUBNAME "FileExists" "data/lfsys/fmgmt/Exists.c")
quick_executable(SUBNAME "FileFild" "data/lfsys/fmgmt/Find.c")
quick_executable(SUBNAME "Unicode" "ui/i18n/Unicode.c")
quick_executable(SUBNAME "ErrHandling" "diag/debug/ErrHandling.c")
quick_executable(SUBNAME "TcpClient" "net/winsock/TcpClient.c")
quick_executable(SUBNAME "TcpServer" "net/winsock/TcpServer.c")
quick_executable(SUBNAME "UdpClient" "net/winsock/UdpClient.c")
quick_executable(SUBNAME "UdpServer" "net/winsock/UdpServer.c")
quick_executable(SUBNAME "Thread" "sys/procthrd/Thread.c")
quick_executable(SUBNAME "SglInstApp" "sys/sync/SglInstApp.c")
quick_executable(SUBNAME "IniFile" "sys/info/reg/IniFile.c")

add_library(${PROJECT_NAME_LOWER}_dll_shared SHARED "sys/dll/Lib.h" "sys/dll/Lib.c")
add_executable(${PROJECT_NAME_LOWER}_dll_exe "sys/dll/Exe.c")
target_link_libraries(${PROJECT_NAME_LOWER}_dll_exe ${PROJECT_NAME_LOWER}_dll_shared)
