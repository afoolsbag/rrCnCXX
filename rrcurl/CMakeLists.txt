#                           _
#                          | |
#  _ __ _ __ ___ _   _ _ __| |
# | '__| '__/ __| | | | '__| | zhengrr
# | |  | | | (__| |_| | |  | | 2019-03-20 – 2019-03-20
# |_|  |_|  \___|\__,_|_|  |_| Unlicense

project(rrcurl VERSION 2019.03.20 LANGUAGES C)
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
conan_cmake_run(
  REQUIRES    libcurl/7.61.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)

aux_source_directory_ex(zSource RECURSE)
add_executable_ex(
                      ${zSource}
                      C11
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE Check::check
                              CONAN_PKG::libcurl
)
