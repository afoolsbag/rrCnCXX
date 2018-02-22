#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-2-22
# The MIT License

project("rrWindows" VERSION 2018.2.22 LANGUAGES C)
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

quick_executable(SUBNAME "FileAttrs" "data/lfsys/fmgmt/attrs.c")
quick_executable(SUBNAME "FileExists" "data/lfsys/fmgmt/exists.c")
quick_executable(SUBNAME "FileFild" "data/lfsys/fmgmt/find.c")
quick_executable(SUBNAME "Unicode" "ui/i18n/unicode.c")
quick_executable(SUBNAME "ErrHandling" "diag/debug/err_handling.c")
quick_executable(SUBNAME "TcpClient" "net/winsock/tcp_client.c")
quick_executable(SUBNAME "TcpServer" "net/winsock/tcp_server.c")
quick_executable(SUBNAME "UdpClient" "net/winsock/udp_client.c")
quick_executable(SUBNAME "UdpServer" "net/winsock/udp_server.c")
quick_executable(SUBNAME "Thread" "sys/procthrd/thread.c")
quick_executable(SUBNAME "SglInstApp" "sys/sync/sgl_inst_app.c")
quick_executable(SUBNAME "IniFile" "sys/info/reg/ini_file.c")

add_library(${PROJECT_NAME_LOWER}_dll_shared SHARED "sys/dll/lib.h" "sys/dll/lib.c")
add_executable(${PROJECT_NAME_LOWER}_dll_exe "sys/dll/exe.c")
target_link_libraries(${PROJECT_NAME_LOWER}_dll_exe ${PROJECT_NAME_LOWER}_dll_shared)
