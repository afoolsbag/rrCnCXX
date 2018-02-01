#             ______  ___  __
#  _ __ _ __ / ___\ \/ \ \/ /
# | '__| '__| |    \  / \  /
# | |  | |  | |___ /  \ /  \
# |_|  |_|   \____/_/\_/_/\_\ rrCxx by FIGlet
# zhengrr
# 2016-8-1 – 2018-1-25
# The MIT License

project("rrCXX" VERSION 2018.1.29 LANGUAGES CXX)
project_variables()
highest_warning_level()

quick_doxygen()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("cfg.hxx.in" "cfg.hxx" @ONLY)

enable_testing()
quick_googletest(
  "algo/nonmod_seq_ops.cxx"
  "cont/vector.cxx"
  "gen/dyn_mem_mgmt/unique_ptr.cxx"
  "gen/dyn_mem_mgmt/shared_ptr.cxx"
  "io/std_stream_objs.cxx"
  "lang/bsc_cce/main.cxx"
  "lang/bsc_cce/name_spc.cxx"
  "lang/bsc_cce/type/enum.cxx"
  "lang/class/explicit.cxx"
  "lang/class/nst_dat_mbr.cxx"
  "lang/class/sta_dat_mbr.cxx"
  "thrd/thrd.cxx"
  "std.hxx"
  "dzn/singleton.cxx"
)

quick_library(
  SUBNAME "Lib"
  "${PROJECT_BINARY_DIR}/cfg.hxx"
  "api.h"
  "lib.h"
  "lib.cxx"
)
