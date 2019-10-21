#            _____  _____ _     _ _
#           /  ___||  _  | |   (_) |
#  _ __ _ __\ `--. | | | | |    _| |_ ___
# | '__| '__|`--. \| | | | |   | | __/ _ \ zhengrr
# | |  | |  /\__/ /\ \/' / |___| | ||  __/ 2018-05-23 – 2019-10-21
# |_|  |_|  \____/  \_/\_\_____/_|\__\___| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrSQLite
  TIME_AS_VERSION
  LANGUAGES C CXX)

include_conan_script()

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

conan_cmake_run(
  REQUIRES    gsl_microsoft/2.0.0@bincrafters/stable
              gtest/1.8.1@bincrafters/stable
              sqlite3/3.29.0@bincrafters/stable
              sqlitecpp/2.4.0@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("." zTest)
add_executable_con(
  rrSQLiteTest        ${zTest}
  PROPERTIES          C_STANDARD            11
                      C_STANDARD_REQUIRED   ON
                      CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      PRIVATE               CONAN_PKG::gsl_microsoft
                                            CONAN_PKG::gtest
                                            CONAN_PKG::sqlite3
                                            CONAN_PKG::sqlitecpp)

add_test(NAME rrSQLiteTest COMMAND rrSQLiteTest)

add_executable_con(
  rrTracksGizmo       "tracks_gizmo/main.cxx"
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  LINK_LIBRARIES      PRIVATE               CONAN_PKG::gsl_microsoft
                                            CONAN_PKG::sqlitecpp)
