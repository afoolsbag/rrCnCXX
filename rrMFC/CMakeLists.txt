#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____| rrMFC by FIGlet
# zhengrr
# 2017-12-08 – 2018-07-24
# The MIT License

set(sRrwindowsLib "rrwindows_shared_library")

project(rrMFC VERSION 2018.7.24 LANGUAGES CXX)
project_extra()
compiler_warning_level(AS_ERROR UTF-8 ANALYZE)

facile_add_doxygen()

add_definitions("-D_AFXDLL")
set(CMAKE_MFC_FLAG 2)

add_definitions("-D_UNICODE" "-DUNICODE")
remove_definitions("-D_MBCS")

aux_add_subdirectories()
