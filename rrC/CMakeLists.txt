#             ____
# _ __ _ __  / ___|
# | '__| '__| |
# | |  | |  | |___
# |_|  |_|   \____| rrC by FIGlet
# zhengrr
# 2016-08-01 – 2018-03-19
# The MIT License

project("rrC" VERSION 2018.3.19 LANGUAGES C)
project_variables()
highest_warning_level()

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("cfg.h.in" "cfg.h" @ONLY)

#enable_testing()
facile_add_check_executable(SUBNAME "Test"
  "lang/main.c"
  "mem/mem.c"
  "mem/tsuite_mem.h" "mem/tsuite_mem.c"
  "str/str_cnv.c"
  "str/str_man.c"
  "str/tsuite_str.h" "str/tsuite_str.c"
  "time/time.c"
  "time/tsuite_time.h" "time/tsuite_time.c"
)
#add_test(NAME "testname" COMMAND "targetname")

facile_add_executable(SUBNAME "Main"
  "lang/main.c")

facile_add_executable(SUBNAME "Array"
  "type/array.c")
facile_add_executable(SUBNAME "Character"
  "type/char.c")
facile_add_executable(SUBNAME "Structure"
  "type/struct.c")

facile_add_executable(SUBNAME "Library"
  "lib.c")
