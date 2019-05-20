#            _____  _____ _     _ _
#           /  ___||  _  | |   (_) |
#  _ __ _ __\ `--. | | | | |    _| |_ ___
# | '__| '__|`--. \| | | | |   | | __/ _ \ zhengrr
# | |  | |  /\__/ /\ \/' / |___| | ||  __/ 2018-05-23 – 2019-05-20
# |_|  |_|  \____/  \_/\_\_____/_|\__\___| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrSQLite
  VERSION   2019.05.20
  LANGUAGES C)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen(
  rrSQLiteDoc
  OPTIMIZE_OUTPUT_FOR_C ON)

find_package(Check)
conan_cmake_run(
  REQUIRES    sqlite3/3.28.0@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
  
aux_source_directory_con("." zSrc RECURSE)
add_executable_con(
  rrSQLiteTest        ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE             "."
  LINK_LIBRARIES      PRIVATE             Check::check
                                          CONAN_PKG::sqlite3)
