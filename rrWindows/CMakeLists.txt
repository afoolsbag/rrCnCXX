#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-1-18
# The MIT License

project("rrWindows" VERSION 2018.1.18 LANGUAGES C)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

quick_add_executable_with_option(SUBNAME "AppConsole" "App-Main.c")
quick_add_executable_with_option(SUBNAME "AppDesktop" WIN32 "App-WinMain.c")
quick_add_executable_with_option(SUBNAME "TcpClient" "Net-Sock-TcpClient.c")
quick_add_executable_with_option(SUBNAME "TcpServer" "Net-Sock-TcpServer.c")
quick_add_executable_with_option(SUBNAME "UdpClient" "Net-Sock-UdpClient.c")
quick_add_executable_with_option(SUBNAME "UdpServer" "Net-Sock-UdpServer.c")
quick_add_executable_with_option(SUBNAME "FileAttributes" "Sto-Local-File-Attributes.c")
quick_add_executable_with_option(SUBNAME "FileFild" "Sto-Local-File-Find.c")
quick_add_executable_with_option(SUBNAME "Ini" "Sys-Info-Reg-Ini.c")
quick_add_executable_with_option(SUBNAME "Thread" "Sys-Process-Thread.c")
quick_add_executable_with_option(SUBNAME "Unicode" "Ui-I18n-Unicode.c")

add_library(${PROJECT_NAME_LOWER}_dyn_shared SHARED "Sys-Dyn-Lib.h" "Sys-Dyn-Lib.c")
add_executable(${PROJECT_NAME_LOWER}_dyn_exe "Sys-Dyn-Exe.c")
target_link_libraries(${PROJECT_NAME_LOWER}_dyn_exe ${PROJECT_NAME_LOWER}_dyn_shared)
