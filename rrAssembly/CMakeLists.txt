#             ___                         _     _       
#            / _ \                       | |   | |      
#  _ __ _ __/ /_\ \___ ___  ___ _ __ ___ | |__ | |_   _ 
# | '__| '__|  _  / __/ __|/ _ \ '_ ` _ \| '_ \| | | | |
# | |  | |  | | | \__ \__ \  __/ | | | | | |_) | | |_| |
# |_|  |_|  \_| |_/___/___/\___|_| |_| |_|_.__/|_|\__, | zhengrr
#                                                  __/ | 2019-10-15 – 2019-11-15
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

add_doxygen_con(
  rrAssemblyDoc)

conan_cmake_run(
  REQUIRES    benchmark/1.5.0
              gsl_microsoft/2.0.0@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("include" zInclude RECURSE PREFIX "include")
add_library_ex(
  rrAssembly          INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_17
  COMPILE_OPTIONS     INTERFACE $<$<CXX_COMPILER_ID:MSVC>:/arch:AVX2>
  INCLUDE_DIRECTORIES INTERFACE "include"
  SOURCES             INTERFACE ${zInclude})

aux_source_directory_con("test" zTest RECURSE PREFIX "test")
add_executable_con(
  rrAssemblyTest      ${zTest}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      CONAN_PKG::benchmark
                      CONAN_PKG::gsl_microsoft
                      rrAssembly)

add_test(NAME rrAssemblytest COMMAND rrAssemblytest)
