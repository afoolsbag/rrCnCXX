#            _____  _    _ _____ _____
#           /  ___|| |  | |_   _|  __ \
#  _ __ _ __\ `--. | |  | | | | | |  \/
# | '__| '__|`--. \| |/\| | | | | | __  zhengrr
# | |  | |  /\__/ /\  /\  /_| |_| |_\ \ 2019-01-14 – 2019-08-28
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

configure_file("rrlc/src/cfg.h.in" "rrlc/src/cfg.h" @ONLY)
aux_source_directory_con("rrlc/include"                         zInclude   RECURSE PREFIX "include")
aux_source_directory_con("rrlc/src"                             zSrc       RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrlc/src" zGenerated RECURSE PREFIX "generated")
add_library_con(
  rrlc
  SHARED              ${zInclude} ${zSrc} ${zGenerated}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
                      SOVERSION           1.0.0
  COMPILE_DEFINITIONS PUBLIC  "RRLC_SHARED"
                      PRIVATE "RRLC_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC  "rrlc/include"
                      PRIVATE "rrlc/src"
                              "${CMAKE_CURRENT_BINARY_DIR}/rrlc/src")
install(
  DIRECTORY   "rrlc/include/"
  DESTINATION "include/")

#-------------------------------------------------------------------------------
# zhengrr's library by C++

configure_file("rrlx/src/cfg.hxx.in" "rrlx/src/cfg.hxx" @ONLY)
aux_source_directory_con("rrlx/include"                         zInclude   RECURSE PREFIX "include")
aux_source_directory_con("rrlx/src"                             zSrc       RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrlx/src" zGenerated RECURSE PREFIX "generated")
add_library_con(
  rrlx
  SHARED              ${zInclude} ${zSrc} ${zGenerated}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
                      SOVERSION             1.0.0
  COMPILE_DEFINITIONS PUBLIC  "RRLX_SHARED"
                      PRIVATE "RRLX_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC  "rrlx/include"
                      PRIVATE "rrlx/src"
                              "${CMAKE_CURRENT_BINARY_DIR}/rrlx/src")
if(CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(rrlx PRIVATE stdc++fs)
endif()
install(
  DIRECTORY   "rrlx/include/"
  DESTINATION "include/")

#-------------------------------------------------------------------------------
# zhengrr's test by C

find_package(Check REQUIRED)
aux_source_directory_con("rrtc" zSrc RECURSE)
add_executable_con(
  rrtc                ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "rrtc"
  LINK_LIBRARIES      PRIVATE rrlc
                              rrlx
                              Check::check)

add_test(NAME rrtc COMMAND rrtc)

#-------------------------------------------------------------------------------
# zhengrr's test by C++

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
aux_source_directory_con("rrtx" zSrc RECURSE)
add_executable_con(
  rrtx                ${zSrc}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "rrtx"
  LINK_LIBRARIES      PRIVATE rrlc
                              rrlx
                              GTest::gtest_main)

add_test(NAME rrtx COMMAND rrtx)

#-------------------------------------------------------------------------------
# zhengrr's library by C++ with SWIG

find_package(SWIG)
if(SWIG_FOUND)

  add_library_swig(
    rrlxswigcsharp
    SHARED
    SWIG_LANGUAGE  CSHARP
    SWIG_INTERFACE "rrlx/rrlx.swg"
    SWIG_ARGUMENTS "-namespace"          "RrSwig"
    PROPERTIES     CXX_STANDARD          20
                   CXX_STANDARD_REQUIRED ON
    LINK_LIBRARIES rrlx)

  add_library_swig(
    rrlxswigjava
    SHARED
    SWIG_LANGUAGE  JAVA
    SWIG_INTERFACE "rrlx/rrlx.swg"
    SWIG_ARGUMENTS "-package"            "rrswig"
    PROPERTIES     CXX_STANDARD          20
                   CXX_STANDARD_REQUIRED ON
    LINK_LIBRARIES rrlx)

endif()
