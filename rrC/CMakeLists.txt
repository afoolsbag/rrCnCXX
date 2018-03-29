#             ____
# _ __ _ __  / ___|
# | '__| '__| |
# | |  | |  | |___
# |_|  |_|   \____| rrC by FIGlet
# zhengrr
# 2016-08-01 – 2018-03-29
# The MIT License

project("rrC" VERSION 2018.3.29 LANGUAGES C)
project_variables()
highest_warning_level()

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("cfg.h.in" "cfg.h" @ONLY)

enable_testing()
facile_add_check_executable(SUBNAME "Test" TGTNAMEVAR sTgtName
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
add_test(NAME "${sTgtName}" COMMAND "${sTgtName}")

facile_add_executable(SUBNAME "Library"
  "api.h" "lib.h" "lib.c")
