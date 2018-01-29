#             ______  ___  __
#  _ __ _ __ / ___\ \/ \ \/ /
# | '__| '__| |    \  / \  /
# | |  | |  | |___ /  \ /  \
# |_|  |_|   \____/_/\_/_/\_\ rrCxx by FIGlet
# zhengrr
# 2016-8-1 – 2018-1-25
# The MIT License

project("rrCXX" VERSION 2018.1.29 LANGUAGES CXX)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

quick_add_doxygen_with_option()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file("cfg.hxx.in" "cfg.hxx" @ONLY)

enable_testing()
quick_add_googletest_with_option(
  "conts_lib/vector.cxx"
  "general_utils_lib/dyn_mem_mgmt/unique_ptr.cxx"
  "general_utils_lib/dyn_mem_mgmt/shared_ptr.cxx"
  "lang/basic_concepts/main.cxx"
  "lang/basic_concepts/name_spc.cxx"
  "lang/basic_concepts/type/enum.cxx"
  "lang/classes/explicit.cxx"
  "thrd_supt_lib/thrd.cxx"
  "cxx_std_ver.hxx"
  "dzn_patterns/singleton.cxx"
)

quick_add_library_with_option(SUBNAME "Library" "${PROJECT_BINARY_DIR}/cfg.hxx" "api.hxx" "lib.hxx" "lib.cxx")
