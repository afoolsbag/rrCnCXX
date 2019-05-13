#           ______ _      _
#           |  _  \ |    | |
#  _ __ _ __| | | | |    | |
# | '__| '__| | | | |    | |     zhengrr
# | |  | |  | |/ /| |____| |____ 2019-01-14 – 2019-05-10
# |_|  |_|  |___/ \_____/\_____/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrDLL
  VERSION   2018.05.10
  LANGUAGES C CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

# rrDLLc (c library)
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
                      PRIVATE "RRDLLC_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC  "rrdllc/include"
                      PRIVATE "rrdllc/src"
                              "${CMAKE_CURRENT_BINARY_DIR}/rrdllc/src")
install(
  DIRECTORY   "rrdllc/include/"
  DESTINATION "include/")

# rrDLLx (cxx library)
configure_file("rrdllx/src/cfg.hxx.in" "rrdllx/src/cfg.hxx" @ONLY)
aux_source_directory_con("rrdllx/include"                         zInc RECURSE PREFIX "include")
aux_source_directory_con("rrdllx/src"                             zSrc RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrdllx/src" zGen RECURSE PREFIX "generated")
add_library_con(
  rrDLLx
  SHARED              ${zInc} ${zSrc} ${zGen}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PUBLIC  "RRDLLX_SHARED"
                      PRIVATE "RRDLLX_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC  "rrdllx/include"
                      PRIVATE "rrdllx/src"
                              "${CMAKE_CURRENT_BINARY_DIR}/rrdllx/src")
install(
  DIRECTORY   "rrdllx/include/"
  DESTINATION "include/")

# rrDLLe (c executable)
find_package(Check)
aux_source_directory_con("rrdlle" zSrc RECURSE)
add_executable_con(
  rrDLLe              ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "rrdlle"
  LINK_LIBRARIES      PRIVATE rrDLLc
                              rrDLLx
                              Check::check)

# rrDLLz (cxx execatable)
conan_cmake_run(
  REQUIRES    gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)
aux_source_directory_con("rrdllz" zSrc RECURSE)
add_executable_con(
  rrDLLz              ${zSrc}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "rrdllz"
  LINK_LIBRARIES      PRIVATE rrDLLc
                              rrDLLx
                              CONAN_PKG::gtest)
