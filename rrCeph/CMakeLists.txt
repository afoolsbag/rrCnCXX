#            _____            _     
#           /  __ \          | |    
#  _ __ _ __| /  \/ ___ _ __ | |__  
# | '__| '__| |    / _ \ '_ \| '_ \ 
# | |  | |  | \__/\  __/ |_) | | | |
# |_|  |_|   \____/\___| .__/|_| |_| zhengrr
#                      | |           2019-07-29 – 2019-07-29
#                      |_|           Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

project_ex(
  rrCeph
  TIME_AS_VERSION
  LANGUAGES CXX)

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

find_package(S3)
aux_source_directory_ex("wrapper" zWrapper RECURSE PREFIX "wrapper")
add_library_ex(
  rrCephWraper        INTERFACE
  COMPILE_FEATURES    INTERFACE cxx_std_11
  INCLUDE_DIRECTORIES INTERFACE "wrapper"
  LINK_LIBRARIES      INTERFACE S3::s3
  SOURCES             INTERFACE ${zWrapper})

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
aux_source_directory_ex("test" zTest RECURSE PREFIX "test")
add_executable_con(
  rrCephTest          ${zTest}
  PROPERTIES          CXX_STANDARD          11
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "test"
  LINK_LIBRARIES      PRIVATE rrCephWraper
                              GTest::main)

add_test(NAME rrCephTest COMMAND rrCephTest)
