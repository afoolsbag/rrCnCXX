#             ___                         _     _       
#            / _ \                       | |   | |      
#  _ __ _ __/ /_\ \___ ___  ___ _ __ ___ | |__ | |_   _ 
# | '__| '__|  _  / __/ __|/ _ \ '_ ` _ \| '_ \| | | | |
# | |  | |  | | | \__ \__ \  __/ | | | | | |_) | | |_| |
# |_|  |_|  \_| |_/___/___/\___|_| |_| |_|_.__/|_|\__, | zhengrr
#                                                  __/ | 2019-10-15 – 2019-10-15
#                                                 |___/  Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrAssembly
  TIME_AS_VERSION
  LANGUAGES C CXX ASM)

include_conan_script()

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

conan_cmake_run(
  REQUIRES    gsl_microsoft/2.0.0@bincrafters/stable
              gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("." zTest RECURSE)
add_executable_con(
  rrAssemblytest      ${zTest}
  PROPERTIES          C_STANDARD            11
                      C_STANDARD_REQUIRED   ON
                      CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      CONAN_PKG::gsl_microsoft
                      CONAN_PKG::gtest)

add_test(NAME rrAssemblytest COMMAND rrAssemblytest)
