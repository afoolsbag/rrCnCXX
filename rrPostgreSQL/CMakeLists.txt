#           ______         _                 _____  _____ _
#           | ___ \       | |               /  ___||  _  | |
#  _ __ _ __| |_/ /__  ___| |_ __ _ _ __ ___\ `--. | | | | |
# | '__| '__|  __/ _ \/ __| __/ _` | '__/ _ \`--. \| | | | |
# | |  | |  | | | (_) \__ \ || (_| | | |  __/\__/ /\ \/' / |____
# |_|  |_|  \_|  \___/|___/\__\__, |_|  \___\____/  \_/\_\_____/ zhengrr
#                              __/ |                             2019-10-14 – 2019-10-14
#                             |___/                              Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrPostgreSQL
  TIME_AS_VERSION
  LANGUAGES CXX)

include_conan_script()

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

conan_cmake_run(
  REQUIRES    gtest/1.8.1@bincrafters/stable
              libpqxx/6.4.5@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("." zTest RECURSE)
add_executable_con(
  rrPostgreSQLtest    ${zTest}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      PRIVATE               CONAN_PKG::gtest
                                            CONAN_PKG::libpqxx)

add_test(NAME rrPostgreSQLtest COMMAND rrPostgreSQLtest)
