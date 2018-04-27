#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____|
# zhengrr       rrMFC by FIGlet
# 2017-12-08 – 2018-04-27
# The MIT License

project("rrMFC" VERSION 2018.4.27 LANGUAGES C CXX)
project_extra()
highest_warning_level(ANALYZE UTF-8)

facile_add_doxygen()

aux_source_directory_enhanced(zSrc RECURSE C SOURCE_DIRECTORY "utils")
facile_add_library(SUBNAME "Utilities"
      TARGET_NAME_VARIABLE  sUtilsLib
                    STATIC  ${zSrc}
                PROPERTIES  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}")

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)
aux_add_subdirectories()
