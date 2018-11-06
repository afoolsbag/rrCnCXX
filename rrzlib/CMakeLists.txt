#                _ _ _
#               | (_) |
#  _ __ _ __ ___| |_| |__
# | '__| '__|_  / | | '_ \
# | |  | |   / /| | | |_) |
# |_|  |_|  /___|_|_|_.__/  rrzlib by FIGlet doom
# zhengrr
# 2018-11-06 – 2018-11-06
# The Unlicense

project(rrzlib VERSION 2108.11.06 LANGUAGES C)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

conan_cmake_run(
  REQUIRES zlib/1.2.11@conan/stable
  BASIC_SETUP CMAKE_TARGETS)
find_package(Check)
aux_source_directory_ex(zTest)
add_executable_ex(
  NAME "test" ${zTest} C11
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE Check::Check
                              Check::Compat
                              CONAN_PKG::zlib)
