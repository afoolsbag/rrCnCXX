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

quick_executable(SUBNAME "WinConApp"
  "win_con_app.c")

quick_executable(SUBNAME "WinDtpApp"
  WIN32 "win_dtp_app.c")

quick_executable(SUBNAME "FileAttrs"
  "data/lfsys/fmgmt/attrs.c")
quick_executable(SUBNAME "FileExists"
  "data/lfsys/fmgmt/exists.c")
quick_executable(SUBNAME "FileFild"
  "data/lfsys/fmgmt/find.c")

quick_executable(SUBNAME "ErrHandling"
  "diag/debug/err_handling.c")

quick_executable(SUBNAME "GenUuid"
  "net/rpc/gen_uuid.c")

quick_executable(SUBNAME "TcpClient"
  "net/winsock/tcp_client.c")
quick_executable(SUBNAME "TcpServer"
  "net/winsock/tcp_server.c")
quick_executable(SUBNAME "UdpClient"
  "net/winsock/udp_client.c")
quick_executable(SUBNAME "UdpServer"
  "net/winsock/udp_server.c")

quick_executable(SUBNAME "AcsShrFlr"
  "net/wnet/acs_shr_flr.c")

quick_executable(SUBNAME "Thread"
  "sys/procthrd/thread.c")

quick_executable(SUBNAME "SglInstApp"
  "sys/sync/sgl_inst_app.c")

quick_executable(SUBNAME "IniFile"
  "sys/info/reg/ini_file.c")

quick_executable(SUBNAME "Gb2312Utf8"
  "ui/i18n/unicode/gb2312_utf8.c")

quick_executable(SUBNAME "CnvUpr"
  "ui/res/str/cnv_upr.c")

add_library(${PROJECT_NAME_LOWER}_dll_shared SHARED "sys/dll/lib.h" "sys/dll/lib.c")
add_executable(${PROJECT_NAME_LOWER}_dll_exe "sys/dll/exe.c")
target_link_libraries(${PROJECT_NAME_LOWER}_dll_exe ${PROJECT_NAME_LOWER}_dll_shared)
