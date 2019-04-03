#           ______         _ _
#           | ___ \       | (_)
#  _ __ _ __| |_/ /___  __| |_ ___
# | '__| '__|    // _ \/ _` | / __| zhengrr
# | |  | |  | |\ \  __/ (_| | \__ \ 2019-04-02 – 2019-04-02
# |_|  |_|  \_| \_\___|\__,_|_|___/ Unlicense

project(rrRedis VERSION 2019.04.02 LANGUAGES C)
project_more()
compile_option(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen(WITH_OPTION OPTIMIZE_OUTPUT_FOR_C)

if(3.12 VERSION_LESS CMAKE_VERSION)
  cmake_policy(SET CMP0074 NEW)
endif()
find_package(Check)
find_package(hiredis)

aux_source_directory_ex(zSource RECURSE)
add_executable_ex(
                      ${zSource}
                      C11
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE Check::check
                              hiredis::hiredis
)
