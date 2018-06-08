#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-06-08
# The MIT License

project(rrWindows VERSION 2018.6.8 LANGUAGES C)
project_extra()
compiler_warning_level(HIGHEST UTF-8)

add_definitions(-D_UNICODE -DUNICODE)
remove_definitions(-D_MBCS)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

facile_add_library(OPTION_INITIAL_ON
                TARGET_NAME_VARIABLE sRrwindowsLib
                              STATIC)

aux_source_directory_enhanced(zSrc RECURSE SOURCE_PREFIXS "tmain" "tsuite" "tcase")
facile_add_check_executable(SUBNAME Test
                  OPTION_INITIAL_ON
                                    ${zSrc}
                INCLUDE_DIRECTORIES PRIVATE "."
                     LINK_LIBRARIES "${sRrwindowsLib}")

facile_add_executable(SUBNAME ConsoleApplication
                              "conapp.c")
facile_add_executable(SUBNAME DesktopApplication
                        WIN32 "dtpapp.c")

aux_add_subdirectories()
