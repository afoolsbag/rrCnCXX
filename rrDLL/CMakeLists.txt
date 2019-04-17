#           ______ _      _
#           |  _  \ |    | |
#  _ __ _ __| | | | |    | |
# | '__| '__| | | | |    | |     zhengrr
# | |  | |  | |/ /| |____| |____ 2019-01-14 – 2019-04-17
# |_|  |_|  |___/ \_____/\_____/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrDLL
  VERSION   2018.04.17
  LANGUAGES C CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

configure_file("rrdllc/src/cfg.h.in" "rrdllc/src/cfg.h" @ONLY)
aux_source_directory_con("rrdllc/include"                         zInc RECURSE PREFIX "include")
aux_source_directory_con("rrdllc/src"                             zSrc RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrdllc/src" zGen RECURSE PREFIX "generated")
add_library_con(
  rrDLLc
  SHARED              ${zInc} ${zSrc} ${zGen}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PUBLIC  "RRDLLC_SHARED"
  INCLUDE_DIRECTORIES PUBLIC  "."
                              "rrdllc/include"
                      PRIVATE "rrdllc/src"
                              "${CMAKE_CURRENT_BINARY_DIR}/rrdllc/src")

configure_file("rrdllcxx/src/cfg.hxx.in" "rrdllcxx/src/cfg.hxx" @ONLY)
aux_source_directory_con("rrdllcxx/include"                         zInc RECURSE PREFIX "include")
aux_source_directory_con("rrdllcxx/src"                             zSrc RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrdllcxx/src" zGen RECURSE PREFIX "generated")
add_library_con(
  rrDLLcxx
  SHARED              ${zInc} ${zSrc} ${zGen}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PUBLIC  "RRDLLCXX_SHARED"
  INCLUDE_DIRECTORIES PUBLIC  "."
                              "rrdllcxx/include"
                      PRIVATE "rrdllcxx/src"
                              "${CMAKE_CURRENT_BINARY_DIR}/rrdllcxx/src")

aux_source_directory_con("rrexec/src" zSrc RECURSE PREFIX "src")
add_executable_con(
  rrEXEc              ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "rrexec/src"
  LINK_LIBRARIES      rrDLLc
                      rrDLLcxx)

aux_source_directory_con("rrexecxx/src" zSrc RECURSE PREFIX "src")
add_executable_con(
  rrEXEcxx            ${zSrc}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "rrexecxx/src"
  LINK_LIBRARIES      rrDLLc
                      rrDLLcxx)
