#             ____
# _ __ _ __  / ___|
# | '__| '__| |
# | |  | |  | |___
# |_|  |_|   \____| rrC by FIGlet
# zhengrr
# 2016-8-1 – 2018-2-9
# The MIT License

project("rrC" VERSION 2018.2.9 LANGUAGES C)
project_variables()
highest_warning_level()

quick_doxygen(OPTIMIZE_OUTPUT_FOR_C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("cfg.h.in" "cfg.h" @ONLY)

enable_testing()
quick_check(
  "lang/main.c"
  "str/bstrcnv.c"
  "str/bstrexam.c" "str/test.c"
  "time/time.c" "time/test.c"
)

quick_executable(SUBNAME "Main"
  "lang/main.c")

quick_executable(SUBNAME "Memery"
  "mem/mem.c")

quick_executable(SUBNAME "Array"
  "type/array.c")
quick_executable(SUBNAME "Character"
  "type/char.c")
quick_executable(SUBNAME "Structure"
  "type/struct.c")

quick_library(SUBNAME "Library"
  "lib.c")
