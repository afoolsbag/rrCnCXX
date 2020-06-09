#            _____  _    _ _____ _____
#           /  ___|| |  | |_   _|  __ \
#  _ __ _ __\ `--. | |  | | | | | |  \/
# | '__| '__|`--. \| |/\| | | | | | __  zhengrr
# | |  | |  /\__/ /\  /\  /_| |_| |_\ \ 2019-01-14 – 2020-06-03
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


configure_file("rrc/src/cfg.h.in" "rrc/src/cfg.h" @ONLY)
aux_source_directory_con("rrc/include"                         zInclude   RECURSE PREFIX "include")
aux_source_directory_con("rrc/src"                             zSrc       RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrc/src" zGenerated RECURSE PREFIX "generated")
add_library_con(
  rrc
  SHARED              ${zInclude} ${zSrc} ${zGenerated}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
                      BUILD_RPATH         "$ORIGIN"
                      INSTALL_RPATH       "$ORIGIN"
                      SOVERSION           1.0.0
  COMPILE_DEFINITIONS PUBLIC              "RRC_SHARED"
                      PRIVATE             "RRC_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC              "rrc/include"
                      PRIVATE             "rrc/src"
                                          "${CMAKE_CURRENT_BINARY_DIR}/rrc/src")
install(
  DIRECTORY   "rrc/include/"
  DESTINATION "include/")


configure_file("rrx/src/cfg.hxx.in" "rrx/src/cfg.hxx" @ONLY)
aux_source_directory_con("rrx/include"                         zInclude   RECURSE PREFIX "include")
aux_source_directory_con("rrx/src"                             zSrc       RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrx/src" zGenerated RECURSE PREFIX "generated")
add_library_con(
  rrx
  SHARED              ${zInclude} ${zSrc} ${zGenerated}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
                      BUILD_RPATH           "$ORIGIN"
                      INSTALL_RPATH         "$ORIGIN"
                      SOVERSION             1.0.0
  COMPILE_DEFINITIONS PUBLIC                "RRX_SHARED"
                      PRIVATE               "RRX_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC                "rrx/include"
                      PRIVATE               "rrx/src"
                                            "${CMAKE_CURRENT_BINARY_DIR}/rrx/src")
if(CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(rrx PRIVATE stdc++fs)
endif()
install(
  DIRECTORY   "rrx/include/"
  DESTINATION "include/")


find_package(Check REQUIRED)
aux_source_directory_con("rrctest" zSrc RECURSE)
add_executable_con(
  rrctest             ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
                      BUILD_RPATH         "$ORIGIN"
                      INSTALL_RPATH       "$ORIGIN"
  COMPILE_OPTIONS     PRIVATE             $<$<CXX_COMPILER_ID:MSVC>:/wd4100>
  INCLUDE_DIRECTORIES PRIVATE             "rrctest"
  LINK_LIBRARIES      PRIVATE             rrc
                                          rrx
                                          Check::check)
add_test(NAME rrctest COMMAND rrctest)


hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
aux_source_directory_con("rrxtest" zSrc RECURSE)
add_executable_con(
  rrxtest             ${zSrc}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
                      BUILD_RPATH           "$ORIGIN"
                      INSTALL_RPATH         "$ORIGIN"
  INCLUDE_DIRECTORIES PRIVATE               "rrxtest"
  LINK_LIBRARIES      PRIVATE               rrc
                                            rrx
                                            GTest::gtest_main)
add_test(NAME rrexex COMMAND rrexex)


find_package(SWIG)
if(SWIG_FOUND)

  add_library_swig(
    rrx_swig_csharp
    SHARED
    SWIG_LANGUAGE  CSHARP
    SWIG_INTERFACE "rrx/rrx.swg"
    SWIG_ARGUMENTS "-namespace"          "RrSwig"
    PROPERTIES     CXX_STANDARD          20
                   CXX_STANDARD_REQUIRED ON
    LINK_LIBRARIES rrx)

  add_library_swig(
    rrx_swig_java
    SHARED
    SWIG_LANGUAGE  JAVA
    SWIG_INTERFACE "rrx/rrx.swg"
    SWIG_ARGUMENTS "-package"            "rrswig"
    PROPERTIES     CXX_STANDARD          20
                   CXX_STANDARD_REQUIRED ON
    LINK_LIBRARIES rrx)

endif()
