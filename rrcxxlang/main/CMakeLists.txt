# zhengrr
# 2016-10-13 – 2017-12-20
# The MIT License

cmake_minimum_required(VERSION 3.0)

project("rrCXXLanguage_main" LANGUAGES CXX)
set_project_extra_variables()

adjust_compiler_warning_level_to_highest()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
quick_aux_source_directory(
  RECURSE
  SRC_VAR srcfiles
  CXX
)
list(APPEND srcfiles "../cxx_standard_version.hpp")

quick_add_executable_with_option(
  SRC_VAR srcfiles
  CXXSTD 14
)
