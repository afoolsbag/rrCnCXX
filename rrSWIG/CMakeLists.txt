#            _____  _    _ _____ _____
#           /  ___|| |  | |_   _|  __ \
#  _ __ _ __\ `--. | |  | | | | | |  \/
# | '__| '__|`--. \| |/\| | | | | | __  zhengrr
# | |  | |  /\__/ /\  /\  /_| |_| |_\ \ 2019-01-14 – 2020-04-30
# |_|  |_|  \____/  \/  \/ \___/ \____/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

project_ex(
  rrSWIG
  TIME_AS_VERSION
  LANGUAGES C CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

#-------------------------------------------------------------------------------
# zhengrr's library by C

configure_file("rrlibc/src/cfg.h.in" "rrlibc/src/cfg.h" @ONLY)
aux_source_directory_con("rrlibc/include"                         zInclude   RECURSE PREFIX "include")
aux_source_directory_con("rrlibc/src"                             zSrc       RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrlibc/src" zGenerated RECURSE PREFIX "generated")
add_library_con(
  rrlibc
  SHARED              ${zInclude} ${zSrc} ${zGenerated}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
                      SOVERSION           1.0.0
  COMPILE_DEFINITIONS PUBLIC              "RRLIBC_SHARED"
                      PRIVATE             "RRLIBC_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC              "rrlibc/include"
                      PRIVATE             "rrlibc/src"
                                          "${CMAKE_CURRENT_BINARY_DIR}/rrlibc/src")
install(
  DIRECTORY   "rrlibc/include/"
  DESTINATION "include/")

#-------------------------------------------------------------------------------
# zhengrr's library by C++

configure_file("rrlibx/src/cfg.hxx.in" "rrlibx/src/cfg.hxx" @ONLY)
aux_source_directory_con("rrlibx/include"                         zInclude   RECURSE PREFIX "include")
aux_source_directory_con("rrlibx/src"                             zSrc       RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrlibx/src" zGenerated RECURSE PREFIX "generated")
add_library_con(
  rrlibx
  SHARED              ${zInclude} ${zSrc} ${zGenerated}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
                      SOVERSION             1.0.0
  COMPILE_DEFINITIONS PUBLIC                "RRLIBX_SHARED"
                      PRIVATE               "RRLIBX_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC                "rrlibx/include"
                      PRIVATE               "rrlibx/src"
                                            "${CMAKE_CURRENT_BINARY_DIR}/rrlibx/src")
if(CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(rrlibx PRIVATE stdc++fs)
endif()
install(
  DIRECTORY   "rrlibx/include/"
  DESTINATION "include/")

#-------------------------------------------------------------------------------
# zhengrr's executable by C

find_package(Check REQUIRED)
aux_source_directory_con("rrexec" zSrc RECURSE)
add_executable_con(
  rrexec              ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  COMPILE_OPTIONS     PRIVATE             $<$<CXX_COMPILER_ID:MSVC>:/wd4100>
  INCLUDE_DIRECTORIES PRIVATE             "rrexec"
  LINK_LIBRARIES      PRIVATE             rrlibc
                                          rrlibx
                                          Check::check)
add_test(NAME rrexec COMMAND rrexec)

#-------------------------------------------------------------------------------
# zhengrr's executable by C++

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
aux_source_directory_con("rrexex" zSrc RECURSE)
add_executable_con(
  rrexex              ${zSrc}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE               "rrexex"
  LINK_LIBRARIES      PRIVATE               rrlibc
                                            rrlibx
                                            GTest::gtest_main)

add_test(NAME rrexex COMMAND rrexex)

#-------------------------------------------------------------------------------
# zhengrr's library by C++ with SWIG

find_package(SWIG)
if(SWIG_FOUND)

  add_library_swig(
    rrlibx_swig_csharp
    SHARED
    SWIG_LANGUAGE  CSHARP
    SWIG_INTERFACE "rrlibx/rrlibx.swg"
    SWIG_ARGUMENTS "-namespace"          "RrSwig"
    PROPERTIES     CXX_STANDARD          20
                   CXX_STANDARD_REQUIRED ON
    LINK_LIBRARIES rrlibx)

  add_library_swig(
    rrlibx_swig_java
    SHARED
    SWIG_LANGUAGE  JAVA
    SWIG_INTERFACE "rrlibx/rrlibx.swg"
    SWIG_ARGUMENTS "-package"            "rrswig"
    PROPERTIES     CXX_STANDARD          20
                   CXX_STANDARD_REQUIRED ON
    LINK_LIBRARIES rrlibx)

endif()
