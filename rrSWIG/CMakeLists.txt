#            _____  _    _ _____ _____
#           /  ___|| |  | |_   _|  __ \
#  _ __ _ __\ `--. | |  | | | | | |  \/
# | '__| '__|`--. \| |/\| | | | | | __  zhengrr
# | |  | |  /\__/ /\  /\  /_| |_| |_\ \ 2019-01-14 – 2021-04-22
# |_|  |_|  \____/  \/  \/ \___/ \____/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

rr_project(
  rrSWIG
  TIME_AS_VERSION
  LANGUAGES C CXX)

rr_add_compile_options(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

# conan
rr_include_conan_script()
#[[
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
conan_cmake_configure(
  REQUIRES   gtest/1.10.0
             libcheck/0.15.2
  GENERATORS cmake_find_package_multi)
foreach(sBuildType IN LISTS CMAKE_CONFIGURATION_TYPES)
  conan_cmake_autodetect(
    zConanSettings
    BUILD_TYPE        ${sBuildType})
  conan_cmake_install(
    PATH_OR_REFERENCE .
    BUILD             missing
    REMOTE            conan-center
    SETTINGS          ${zConanSettings})
endforeach()
#]]
conan_cmake_run(
  REQUIRES    gtest/1.10.0
              libcheck/0.15.2
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

# rrc
configure_file("rrc/src/cfg.h.in" "rrc/src/cfg.h" @ONLY)
rr_aux_source_directory_with_convention("rrc/include"                         zInclude   RECURSE PREFIX "include")
rr_aux_source_directory_with_convention("rrc/src"                             zSrc       RECURSE PREFIX "src")
rr_aux_source_directory_with_convention("${CMAKE_CURRENT_BINARY_DIR}/rrc/src" zGenerated RECURSE PREFIX "generated")
rr_add_library_wcon(
  rrc
  SHARED              ${zInclude} ${zSrc} ${zGenerated}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
                      BUILD_RPATH         "$ORIGIN"
                      INSTALL_RPATH       "$ORIGIN"
                      SOVERSION           1.0.0
  COMPILE_DEFINITIONS PUBLIC              "RRC_SHARED"
                      PRIVATE             "RRC_EXPORTS"
  COMPILE_OPTIONS     PRIVATE             $<$<C_COMPILER_ID:MSVC>:/wd5105>
  INCLUDE_DIRECTORIES PUBLIC              "rrc/include"
                      PRIVATE             "rrc/src"
                                          "${CMAKE_CURRENT_BINARY_DIR}/rrc/src")
install(
  DIRECTORY   "rrc/include/"
  DESTINATION "include/")

# rrx
configure_file("rrx/src/cfg.hxx.in" "rrx/src/cfg.hxx" @ONLY)
rr_aux_source_directory_with_convention("rrx/include"                         zInclude   RECURSE PREFIX "include")
rr_aux_source_directory_with_convention("rrx/src"                             zSrc       RECURSE PREFIX "src")
rr_aux_source_directory_with_convention("${CMAKE_CURRENT_BINARY_DIR}/rrx/src" zGenerated RECURSE PREFIX "generated")
rr_add_library_wcon(
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
                                            "${CMAKE_CURRENT_BINARY_DIR}/rrx/src"
  LINK_LIBRARIES      PRIVATE               $<$<CXX_COMPILER_ID:GNU>:stdc++fs>)
install(
  DIRECTORY   "rrx/include/"
  DESTINATION "include/")

# rrctest
#find_package(libcheck CONFIG REQUIRED)
rr_aux_source_directory_with_convention("rrctest" zSrc RECURSE)
rr_add_executable_wcon(
  rrctest             ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
                      BUILD_RPATH         "$ORIGIN"
                      INSTALL_RPATH       "$ORIGIN"
  COMPILE_OPTIONS     PRIVATE             $<$<C_COMPILER_ID:MSVC>:/wd4100>
  INCLUDE_DIRECTORIES PRIVATE             "rrctest"
  LINK_LIBRARIES      PRIVATE             rrc
                                          rrx
                                          #libcheck::libcheck)
                                          CONAN_PKG::libcheck)
add_test(NAME rrctest COMMAND rrctest)

# rrxtest
#find_package(gtest CONFIG REQUIRED)
rr_aux_source_directory_with_convention("rrxtest" zSrc RECURSE)
rr_add_executable_wcon(
  rrxtest             ${zSrc}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
                      BUILD_RPATH           "$ORIGIN"
                      INSTALL_RPATH         "$ORIGIN"
  INCLUDE_DIRECTORIES PRIVATE               "rrxtest"
  LINK_LIBRARIES      PRIVATE               rrc
                                            rrx
                                            #gtest::gtest)
                                            CONAN_PKG::gtest)
add_test(NAME rrexex COMMAND rrexex)

# rrx_swig_*
find_package(SWIG)
if(SWIG_FOUND)

  rr_add_library_wconswig(
    rrx_swig_csharp
    SHARED
    SWIG_LANGUAGE  CSHARP
    SWIG_INTERFACE "rrx/rrx.swg"
    SWIG_ARGUMENTS "-namespace"          "RrSwig"
    PROPERTIES     CXX_STANDARD          20
                   CXX_STANDARD_REQUIRED ON
    LINK_LIBRARIES rrx)

  rr_add_library_wconswig(
    rrx_swig_java
    SHARED
    SWIG_LANGUAGE  JAVA
    SWIG_INTERFACE "rrx/rrx.swg"
    SWIG_ARGUMENTS "-package"            "rrswig"
    PROPERTIES     CXX_STANDARD          20
                   CXX_STANDARD_REQUIRED ON
    LINK_LIBRARIES rrx)

endif()
