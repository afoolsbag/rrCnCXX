#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-2-23
# The MIT License

project("rrWindows" VERSION 2018.2.23 LANGUAGES C)
project_variables()
highest_warning_level()

quick_doxygen(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_executable(SUBNAME "WinConApp"
  "win_con_app.c")

facile_add_executable(SUBNAME "WinDtpApp"
  WIN32 "win_dtp_app.c")

facile_add_executable(SUBNAME "FileAttrs"
  "data/lfsys/fmgmt/attrs.c")
facile_add_executable(SUBNAME "FileExists"
  "data/lfsys/fmgmt/exists.c")
facile_add_executable(SUBNAME "FileFild"
  "data/lfsys/fmgmt/find.c")

facile_add_executable(SUBNAME "ErrHandling"
  "diag/debug/err_handling.c")

facile_add_executable(SUBNAME "GenUuid"
  "net/rpc/gen_uuid.c")

facile_add_executable(SUBNAME "TcpClient"
  "net/winsock/tcp_client.c")
facile_add_executable(SUBNAME "TcpServer"
  "net/winsock/tcp_server.c")
facile_add_executable(SUBNAME "UdpClient"
  "net/winsock/udp_client.c")
facile_add_executable(SUBNAME "UdpServer"
  "net/winsock/udp_server.c")

facile_add_executable(SUBNAME "AcsShrFlr"
  "net/wnet/acs_shr_flr.c")

facile_add_executable(SUBNAME "Thread"
  "sys/procthrd/thread.c")

facile_add_executable(SUBNAME "SglInstApp"
  "sys/sync/sgl_inst_app.c")

facile_add_executable(SUBNAME "IniFile"
  "sys/info/reg/ini_file.c")

facile_add_executable(SUBNAME "Gb2312Utf8"
  "ui/i18n/unicode/gb2312_utf8.c")

facile_add_executable(SUBNAME "CnvUpr"
  "ui/res/str/cnv_upr.c")

add_library(${PROJECT_NAME_LOWER}_dll_shared SHARED "sys/dll/lib.h" "sys/dll/lib.c")
add_executable(${PROJECT_NAME_LOWER}_dll_exe "sys/dll/exe.c")
target_link_libraries(${PROJECT_NAME_LOWER}_dll_exe ${PROJECT_NAME_LOWER}_dll_shared)
