#            _____  _____ _     _ _
#           /  ___||  _  | |   (_) |
#  _ __ _ __\ `--. | | | | |    _| |_ ___
# | '__| '__|`--. \| | | | |   | | __/ _ \ zhengrr
# | |  | |  /\__/ /\ \/' / |___| | ||  __/ 2018-05-23 – 2018-11-07
# |_|  |_|  \____/  \_/\_\_____/_|\__\___| Unlicense

project(rrSQLite VERSION 2018.11.6 LANGUAGES C)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

find_package(Check)
conan_cmake_run(
  REQUIRES sqlite3/3.21.0@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)

aux_source_directory_ex(zSource)

add_executable_ex(
  ${zSource} C11
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE Check::Check
                              Check::Compat
                              CONAN_PKG::sqlite3)
