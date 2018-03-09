﻿#             ______  ___  __
#  _ __ _ __ / ___\ \/ \ \/ /
# | '__| '__| |    \  / \  /
# | |  | |  | |___ /  \ /  \
# |_|  |_|   \____/_/\_/_/\_\ rrCxx by FIGlet
# zhengrr
# 2016-8-1 – 2018-2-9
# The MIT License

project("rrCXX" VERSION 2018.2.9 LANGUAGES CXX)
project_variables()
highest_warning_level()

facile_add_doxygen()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("cfg.hxx.in" "cfg.hxx" @ONLY)

enable_testing()
quick_gtest(
  "algo/nmodseq.cxx"
  "cont/vector.cxx"
  "gen/mem/unique_ptr.cxx"
  "gen/mem/shared_ptr.cxx"
  "io/std_stream_objs.cxx"
  "lang/class/explicit.cxx"
  "lang/class/nstdatmbr.cxx"
  "lang/class/stadatmbr.cxx"
  "lang/flctrl/main.cxx"
  "lang/type/enum.cxx"
  "lang/namesp.cxx"
  "thrd/thrd.cxx"
  "dzn/singleton.cxx")

quick_library(SUBNAME "Library"
  "lib.cxx")