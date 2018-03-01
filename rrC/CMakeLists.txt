#             ____
# _ __ _ __  / ___|
# | '__| '__| |
# | |  | |  | |___
# |_|  |_|   \____| rrC by FIGlet
# zhengrr
# 2016-8-1 – 2018-3-1
# The MIT License

project("rrC" VERSION 2018.3.1 LANGUAGES C)
project_variables()
highest_warning_level()

facile_add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("cfg.h.in" "cfg.h" @ONLY)

enable_testing()
quick_check(
  "lang/main.c"
  "str/bstrcnv.c"
  "str/bstrexam.c" "str/test.c"
  "time/time.c" "time/test.c"
)

facile_add_executable(SUBNAME "Main"
  "lang/main.c")

facile_add_executable(SUBNAME "Memery"
  "mem/mem.c")

facile_add_executable(SUBNAME "Array"
  "type/array.c")
facile_add_executable(SUBNAME "Character"
  "type/char.c")
facile_add_executable(SUBNAME "Structure"
  "type/struct.c")

facile_add_executable(SUBNAME "Library"
  "lib.c")
