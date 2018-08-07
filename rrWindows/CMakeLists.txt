#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __|
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/
# zhengrr                           rrWindows by FIGlet
# 2016-10-12 – 2018-08-07
# The MIT License

project(rrWindows VERSION 2018.8.7 LANGUAGES C)
project_extra()
compiler_warning_level(AS_ERROR UTF-8)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

#add_definitions("-D_UNICODE" "-DUNICODE")
#remove_definitions("-D_MBCS")

configure_file("exever.rc.in" "exever.rc" @ONLY)
aux_source_directory_enhanced(zSrc
                              RECURSE)
facile_add_check_executable(  OPTION_INITIAL_ON
                              ${zSrc}
                              "${CMAKE_CURRENT_BINARY_DIR}/exever.rc"
          INCLUDE_DIRECTORIES PRIVATE "."
                                      "../")

configure_file("dllver.rc.in" "dllver.rc" @ONLY)
aux_source_directory_enhanced(zSrc
                              RECURSE
          SOURCE_BASE_CLASHES "_test$|^test$|^ygen$")
facile_add_library(           OPTION_INITIAL_ON
         TARGET_NAME_VARIABLE sRrwindowsLib
                              SHARED
                              ${zSrc}
                              "${CMAKE_CURRENT_BINARY_DIR}/dllver.rc"
          COMPILE_DEFINITIONS PUBLIC "-DRRWINDOWS_SHARED"
          INCLUDE_DIRECTORIES PUBLIC "../")
