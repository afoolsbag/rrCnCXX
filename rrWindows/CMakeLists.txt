#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-04-27
# The MIT License

project("rrWindows" VERSION 2018.4.27 LANGUAGES C)
project_extra()
highest_warning_level(ANALYZE UTF-8)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
facile_add_executable(SUBNAME "ConsoleApplication"
                              "conapp.c")
facile_add_executable(SUBNAME "DesktopApplication"
                        WIN32 "dtpapp.c")

aux_source_directory_enhanced(zSrc RECURSE SOURCE_PREFIXS "tsuite_" "tcase_")
facile_add_check_executable(SUBNAME "Test"
                                    "tmain.c" ${zSrc}
                     LINK_LIBRARIES  rrwindows_stringtranscode_static_library)

aux_add_subdirectories()
