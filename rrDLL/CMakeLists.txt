#           ______ _      _
#           |  _  \ |    | |
#  _ __ _ __| | | | |    | |
# | '__| '__| | | | |    | |     zhengrr
# | |  | |  | |/ /| |____| |____ 2019-01-14 – 2019-06-20
# |_|  |_|  |___/ \_____/\_____/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrDLL
  VERSION   2019.06.20
  LANGUAGES C CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

configure_file("rrLibC/src/cfg.h.in" "rrLibC/src/cfg.h" @ONLY)
aux_source_directory_con("rrLibC/include"                         zInc RECURSE PREFIX "include")
aux_source_directory_con("rrLibC/src"                             zSrc RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrLibC/src" zGen RECURSE PREFIX "generated")
add_library_con(
  rrLibC
  SHARED              ${zInc} ${zSrc} ${zGen}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PUBLIC  "RRLIBC_SHARED"
                      PRIVATE "RRLIBC_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC  "rrLibC/include"
                      PRIVATE "rrLibC/src"
                              "${CMAKE_CURRENT_BINARY_DIR}/rrLibC/src")
install(
  DIRECTORY   "rrLibC/include/"
  DESTINATION "include/")

configure_file("rrLibX/src/cfg.hxx.in" "rrLibX/src/cfg.hxx" @ONLY)
aux_source_directory_con("rrLibX/include"                         zInc RECURSE PREFIX "include")
aux_source_directory_con("rrLibX/src"                             zSrc RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrLibX/src" zGen RECURSE PREFIX "generated")
add_library_con(
  rrLibX
  SHARED              ${zInc} ${zSrc} ${zGen}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PUBLIC  "RRLIBX_SHARED"
                      PRIVATE "RRLIBX_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC  "rrLibX/include"
                      PRIVATE "rrLibX/src"
                              "${CMAKE_CURRENT_BINARY_DIR}/rrLibX/src")
install(
  DIRECTORY   "rrLibX/include/"
  DESTINATION "include/")

# REC: rr-executable by c language
find_package(Check)
aux_source_directory_con("rrExeC" zSrc RECURSE)
add_executable_con(
  rrExeC              ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "rrExeC"
  LINK_LIBRARIES      PRIVATE rrLibC
                              rrLibX
                              Check::check)

# REC++/REX: rr-executable by c++ language
conan_cmake_run(
  REQUIRES    gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
aux_source_directory_con("rrExeX" zSrc RECURSE)
add_executable_con(
  rrExeX              ${zSrc}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "rrExeX"
  LINK_LIBRARIES      PRIVATE rrLibC
                              rrLibX
                              CONAN_PKG::gtest)
