#            _____
#           /  __ \
#  _ __ _ __| /  \/
# | '__| '__| |     zhengrr
# | |  | |  | \__/\ 2016-08-01 – 2021-04-22
# |_|  |_|   \____/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

rr_project(
  rrC
  TIME_AS_VERSION
  LANGUAGES C)

rr_add_compile_options(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

rr_add_doxygen_wcon(
  rrCDoc
  OPTIMIZE_OUTPUT_FOR_C ON)

rr_include_conan_script()
conan_cmake_run(
  REQUIRES    libcheck/0.15.2
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

rr_aux_source_directory_with_convention("." zSrc RECURSE)
rr_add_executable_wcon(
  rrCTest             ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  COMPILE_OPTIONS     PRIVATE             $<$<C_COMPILER_ID:MSVC>:/wd4100>
  INCLUDE_DIRECTORIES PRIVATE             "."
  LINK_LIBRARIES      PRIVATE             CONAN_PKG::libcheck)

add_test(NAME rrCTest COMMAND rrCTest)
