#            __  __ _____ ____
#  _ __ _ __|  \/  |  ___/ ___|
# | '__| '__| |\/| | |_ | |
# | |  | |  | |  | |  _|| |___
# |_|  |_|  |_|  |_|_|   \____|
# zhengrr       rrMFC by FIGlet
# 2017-12-08 – 2018-04-20
# The MIT License

project("rrMFC" VERSION 2018.4.20 LANGUAGES C CXX)
project_extra()
highest_warning_level(ANALYZE)

facile_add_doxygen()

facile_add_library(SUBNAME "Utilities" TARGET_NAME_VARIABLE sUtilsLib
  STATIC "utils/api.h"
         "utils/concol.h"    "utils/concol.c"
         "utils/dbgcon.h"    "utils/dbgcon.c"
         "utils/sysmsg.h"
         "utils/sysmsgstr.h" "utils/sysmsgstr.c"
  PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}")

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)
aux_add_subdirectories()
