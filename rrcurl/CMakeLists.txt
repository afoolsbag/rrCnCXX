#                           _
#                          | |
#  _ __ _ __ ___ _   _ _ __| |
# | '__| '__/ __| | | | '__| | zhengrr
# | |  | | | (__| |_| | |  | | 2019-03-20 – 2019-05-05
# |_|  |_|  \___|\__,_|_|  |_| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrcurl
  VERSION 2019.05.05
  LANGUAGES C)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen_con(
  rrcurlDoc
  OPTIMIZE_OUTPUT_FOR_C)

find_package(Check)
conan_cmake_run(
  REQUIRES    libcurl/7.61.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)

aux_source_directory_con("." zSrc RECURSE)
add_executable_con(
  rrcurl              ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE             "."
  LINK_LIBRARIES      PRIVATE             Check::check
                                          CONAN_PKG::libcurl
)
