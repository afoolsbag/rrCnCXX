#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-04-20
# The MIT License

project("rrWindows" VERSION 2018.4.20 LANGUAGES C)
project_extra()
highest_warning_level(ANALYZE)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

aux_add_subdirectories()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_executable(SUBNAME "WindowsConsoleApplication"
  "win_con_app.c")

facile_add_executable(SUBNAME "WindowsDesktopApplication"
  WIN32 "win_dtp_app.c")
