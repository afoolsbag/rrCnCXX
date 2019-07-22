#            _____  _____ _     _ _
#           /  ___||  _  | |   (_) |
#  _ __ _ __\ `--. | | | | |    _| |_ ___
# | '__| '__|`--. \| | | | |   | | __/ _ \ zhengrr
# | |  | |  /\__/ /\ \/' / |___| | ||  __/ 2018-05-23 – 2019-07-22
# |_|  |_|  \____/  \_/\_\_____/_|\__\___| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

string(TIMESTAMP sYear       "%Y")
string(TIMESTAMP sMonth      "%m")
string(TIMESTAMP sDay        "%d")
string(TIMESTAMP sHourMinute "%H%M")

project_ex(
  rrSQLite
  VERSION   ${sYear}.${sMonth}.${sDay}.${sHourMinute}
  LANGUAGES CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

add_doxygen_con(
  rrSQLiteDoc)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
hunter_add_package(sqlite3)
find_package(sqlite3 CONFIG REQUIRED)
  
aux_source_directory_con("." zTest RECURSE)
add_executable_con(
  rrSQLiteTest        ${zTest}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      PRIVATE               GTest::main
                                            sqlite3::sqlite3)

add_test(NAME rrSQLiteTest COMMAND rrSQLiteTest)
