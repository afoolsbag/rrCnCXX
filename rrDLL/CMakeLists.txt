#           ______ _      _
#           |  _  \ |    | |
#  _ __ _ __| | | | |    | |
# | '__| '__| | | | |    | |     zhengrr
# | |  | |  | |/ /| |____| |____ 2019-01-14 – 2019-04-16
# |_|  |_|  |___/ \_____/\_____/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project(rrDLL VERSION 2018.04.16 LANGUAGES C CXX)
project_more()
compile_option(RECOMMENDED_WARNING_LEVEL MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

set(sPathName "rrdllc")
configure_file("${sPathName}/src/cfg.h.in" "${CMAKE_CURRENT_BINARY_DIR}/${sPathName}/src/cfg.h" @ONLY)
aux_source_directory_ex(zInc DIRECTORY "${sPathName}/include"                         RECURSE GROUP_ROOT "include/")
aux_source_directory_ex(zSrc DIRECTORY "${sPathName}/src"                             RECURSE GROUP_ROOT "src/")
aux_source_directory_ex(zGen DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${sPathName}/src" RECURSE GROUP_ROOT "generated/")
add_library_con(
  rrDLLc
  SHARED              ${zInc} ${zSrc} ${zGen}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PUBLIC  "RRDLLC_SHARED"
  INCLUDE_DIRECTORIES PUBLIC  "."
                              "${sPathName}/include"
                      PRIVATE "${sPathName}/src"
                              "${CMAKE_CURRENT_BINARY_DIR}/${sPathName}/src")

set(sPathName "rrdllcxx")
configure_file("${sPathName}/src/cfg.hxx.in" "${CMAKE_CURRENT_BINARY_DIR}/${sPathName}/src/cfg.hxx" @ONLY)
aux_source_directory_ex(zInc DIRECTORY "${sPathName}/include"                         RECURSE GROUP_ROOT "include/")
aux_source_directory_ex(zSrc DIRECTORY "${sPathName}/src"                             RECURSE GROUP_ROOT "src/")
aux_source_directory_ex(zGen DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${sPathName}/src" RECURSE GROUP_ROOT "generated/")
add_library_con(
  rrDLLcxx
  SHARED              ${zInc} ${zSrc} ${zGen}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PUBLIC  "RRDLLCXX_SHARED"
  INCLUDE_DIRECTORIES PUBLIC  "."
                              "${sPathName}/include"
                      PRIVATE "${sPathName}/src"
                              "${CMAKE_CURRENT_BINARY_DIR}/${sPathName}/src")

set(sPathName "rrexec")
aux_source_directory_ex(zSrc DIRECTORY "${sPathName}/src" RECURSE GROUP_ROOT "src/")
add_executable_con(
  rrEXEc              ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "${sPathName}/src"
  LINK_LIBRARIES      rrDLLc
                      rrDLLcxx)

set(sPathName "rrexecxx")
aux_source_directory_ex(zSrc DIRECTORY "${sPathName}/src" RECURSE GROUP_ROOT "src/")
add_executable_con(
  rrEXEcxx            ${zSrc}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "${sPathName}/src"
  LINK_LIBRARIES      rrDLLc
                      rrDLLcxx)
