#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____|
# zhengrr       rrMFC by FIGlet
# 2017-12-08 – 2018-06-08
# The MIT License

project(rrMFC VERSION 2018.6.8 LANGUAGES CXX)
project_extra()
compiler_warning_level(AS_ERROR UTF-8 ANALYZE)

facile_add_doxygen()

add_definitions(-D_UNICODE -DUNICODE)
remove_definitions(-D_MBCS)
add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)
aux_add_subdirectories()
