#             ___                         _     _       
#            / _ \                       | |   | |      
#  _ __ _ __/ /_\ \___ ___  ___ _ __ ___ | |__ | |_   _ 
# | '__| '__|  _  / __/ __|/ _ \ '_ ` _ \| '_ \| | | | |
# | |  | |  | | | \__ \__ \  __/ | | | | | |_) | | |_| |
# |_|  |_|  \_| |_/___/___/\___|_| |_| |_|_.__/|_|\__, | zhengrr
#                                                  __/ | 2019-10-15 – 2019-11-20
#                                                 |___/  Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrAssembly
  TIME_AS_VERSION
  LANGUAGES CXX ASM)

include_conan_script()

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

conan_cmake_run(
  REQUIRES    benchmark/1.5.0
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

add_doxygen_con(
  rrAssemblyDoc)

aux_source_directory_con("../include/rrassembly" zWrapper RECURSE PREFIX "include/rrassembly")
add_library_ex(
  rrAssembly          INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_17
  COMPILE_OPTIONS     INTERFACE $<$<CXX_COMPILER_ID:MSVC>:/arch:AVX2>
  INCLUDE_DIRECTORIES INTERFACE "../include"
  SOURCES             INTERFACE ${zWrapper})

aux_source_directory_con("." zTest RECURSE)
add_executable_con(
  rrAssemblyTest      ${zTest}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      PRIVATE               rrAssembly
                                            CONAN_PKG::benchmark)

add_test(NAME rrAssemblytest COMMAND rrAssemblyTest)
