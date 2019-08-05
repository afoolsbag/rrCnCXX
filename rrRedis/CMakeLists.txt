#           ______         _ _
#           | ___ \       | (_)
#  _ __ _ __| |_/ /___  __| |_ ___
# | '__| '__|    // _ \/ _` | / __| zhengrr
# | |  | |  | |\ \  __/ (_| | \__ \ 2019-04-02 – 2019-05-05
# |_|  |_|  \_| \_\___|\__,_|_|___/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrRedis
  TIME_AS_VERSION
  LANGUAGES C)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen_con(
  rrRedisDoc
  OPTIMIZE_OUTPUT_FOR_C)

find_package(Check)
find_package(hiredis)

aux_source_directory_con("." zSrc RECURSE)
add_executable_con(
  rrRedis             ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE             "./"
  LINK_LIBRARIES      PRIVATE             Check::check
                                          hiredis::hiredis)
