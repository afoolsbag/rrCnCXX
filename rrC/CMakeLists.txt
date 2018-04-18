#             ____
# _ __ _ __  / ___|
# | '__| '__| |
# | |  | |  | |___
# |_|  |_|   \____| rrC by FIGlet
# zhengrr
# 2016-08-01 – 2018-04-17
# The MIT License

project("rrC" VERSION 2018.4.17 LANGUAGES C)
project_extra()
highest_warning_level(AS_ERROR)

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("cfg.h.in" "cfg.h" @ONLY)

facile_add_check_executable(SUBNAME "Test"
  "algo/algo.c"
  "algo/tsuite_algo.h" "algo/tsuite_algo.c"
  "lang/main.c"
  "mem/mem.c"
  "mem/tsuite_mem.h" "mem/tsuite_mem.c"
  "str/bstr_cnv.c"
  "str/bstr_exam.c"
  "str/bstr_man.c"
  "str/tsuite_str.h" "str/tsuite_str.c"
  "time/time.c"
  "time/tsuite_time.h" "time/tsuite_time.c"
  "type/array.c"
  "type/char.c"
  "type/struct.c"
  "type/tsuite_type.h" "type/tsuite_type.c")

facile_add_library(SUBNAME "dl" TARGET_NAME_VARIABLE sDlLib
  SHARED "api.h" "lib.h" "lib.c")

facile_add_executable(SUBNAME "dl"
  "api.h" "lib.h" "exe.c" LINK_LIBRARIES ${sDlLib})
