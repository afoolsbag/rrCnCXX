#            _____  _____ _     _ _
#           /  ___||  _  | |   (_) |
#  _ __ _ __\ `--. | | | | |    _| |_ ___
# | '__| '__|`--. \| | | | |   | | __/ _ \
# | |  | |  /\__/ /\ \/' / |___| | ||  __/
# |_|  |_|  \____/  \_/\_\_____/_|\__\___| rrSQLite by FIGlet doom
# zhengrr
# 2018-05-23 – 2018-10-31
# The Unlicense

project(rrSQLite VERSION 2018.10.31 LANGUAGES C)
project_more()
compile_option(HIGHEST_WARNING_LEVEL MULTIPLE_PROCESSES UTF-8)

add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

conan_cmake_run(
  REQUIRES sqlite3/3.21.0@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
find_package(Check)
aux_source_directory_ex(zTest)
add_executable_ex(
  NAME "test" ${zTest}
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::sqlite3
                              Check::Check
                              Check::Compat)
