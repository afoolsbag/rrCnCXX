#             ______  ___  __
#  _ __ _ __ / ___\ \/ \ \/ /
# | '__| '__| |    \  / \  /
# | |  | |  | |___ /  \ /  \
# |_|  |_|   \____/_/\_/_/\_\ rrCxx by FIGlet
# zhengrr
# 2016-08-01 – 2018-04-17
# The MIT License

project("rrCXX" VERSION 2018.4.17 LANGUAGES CXX)
project_extra()
highest_warning_level(AS_ERROR)

facile_add_doxygen()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("cfg.hxx.in" "cfg.hxx" @ONLY)

facile_add_gtest_executable(SUBNAME "Test"
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

facile_add_library(SUBNAME "dl" TARGET_NAME_VARIABLE sRrcxxDlLibTgt
  SHARED "api.h" "lib.h" "lib.cxx")

facile_add_executable(SUBNAME "dl"
  "api.h" "lib.h" "exe.cxx" LINK_LIBRARIES ${sRrcxxDlLibTgt})
