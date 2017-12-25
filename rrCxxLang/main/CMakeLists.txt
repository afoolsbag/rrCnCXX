# zhengrr
# 2016-10-13 – 2017-12-25
# The MIT License

cmake_minimum_required(VERSION 3.0)

project("rrCxxLanguage_main" LANGUAGES CXX)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
quick_aux_source_directory(
  RECURSE
  SRCVAR srcfiles
  CXX
)
list(APPEND srcfiles "../cxx_standard_version.hpp")

quick_add_executable_with_option(
  SRCVAR srcfiles
  CXXSTD 11
)
