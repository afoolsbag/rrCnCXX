#            _____            _     
#           /  __ \          | |    
#  _ __ _ __| /  \/ ___ _ __ | |__  
# | '__| '__| |    / _ \ '_ \| '_ \ 
# | |  | |  | \__/\  __/ |_) | | | |
# |_|  |_|   \____/\___| .__/|_| |_| zhengrr
#                      | |           2019-07-29 – 2020-06-17
#                      |_|           Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

project_ex(
  rrCeph
  TIME_AS_VERSION
  LANGUAGES CXX)

include_conan_script()

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

conan_cmake_run(
  REQUIRES    gtest/1.10.0
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

#if(UNIX)
#  find_package(S3 REQUIRED)
#elseif(WIN32)
#endif()
hunter_add_package(s3)
find_package(s3 CONFIG REQUIRED)
find_package(rrCeph REQUIRED CONFIG HINTS "${PRODUCT_SOURCE_DIR}/include/rrceph")

aux_source_directory_ex("." zTest RECURSE)
add_executable_con(
  rrCephTest          ${zTest}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "."
  LINK_LIBRARIES      PRIVATE               rrCeph
                                            CONAN_PKG::gtest)

add_test(NAME rrCephTest COMMAND rrCephTest)
