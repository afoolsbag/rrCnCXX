#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____|
# zhengrr       rrMFC by FIGlet
# 2017-12-08 – 2018-04-11
# The MIT License

project("rrMFC" VERSION 2018.4.11 LANGUAGES CXX)
project_extra()
highest_warning_level()

facile_add_doxygen()

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)

aux_add_subdirectories()
