#          _____
#         |_   _|
#  _ __ _ __| |  ___ ___
# | '__| '__| | / __/ _ \ zhengrr
# | |  | | _| || (_|  __/ 2018-03-21 – 2019-10-28
# |_|  |_| \___/\___\___| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrIce
  TIME_AS_VERSION
  LANGUAGES CXX)

include_conan_script()

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

add_doxygen_con(
  rrIceDoc)

find_package(Ice COMPONENTS Ice++11 IceDiscovery++11 IceLocatorDiscovery++11 IceSSL++11)
conan_cmake_run(
  REQUIRES    gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

set(sSlice       "${CMAKE_CURRENT_SOURCE_DIR}/Service.ice")
set(sSliceOutput "${CMAKE_CURRENT_BINARY_DIR}/Service.ice")

file(MAKE_DIRECTORY "${sSliceOutput}/cpp")
execute_process(
  COMMAND "${Ice_SLICE2CPP_EXECUTABLE}"
          "--output-dir=${sSliceOutput}/cpp"
          "${sSlice}"
  RESULTS_VARIABLE sResultCode)
if(NOT sResultCode EQUAL 0)
  message(FATAL_ERROR "Gennerate slice c++ file from definition file failed: ${sResultCode}")
endif()

aux_source_directory_con("."                   zSrc EXTENSIONS ".ice")
aux_source_directory_con("${sSliceOutput}/cpp" zGen PREFIX "generated")

add_executable_con(
  rrIceTest           ${zSrc} ${zGen}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PRIVATE "ICE_CPP11_MAPPING"
  INCLUDE_DIRECTORIES PRIVATE "."
                              "${sSliceOutput}/cpp"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gtest
                              Ice::Ice++11
                              Ice::IceDiscovery++11
                              Ice::IceLocatorDiscovery++11
                              Ice::IceSSL++11)

file(MAKE_DIRECTORY "${sSliceOutput}/cs")
execute_process(COMMAND "${Ice_SLICE2CS_EXECUTABLE}"     "--output-dir=${sSliceOutput}/cs"     "${sSlice}")
file(MAKE_DIRECTORY "${sSliceOutput}/html")
execute_process(COMMAND "${Ice_SLICE2HTML_EXECUTABLE}"   "--output-dir=${sSliceOutput}/html"   "${sSlice}")
file(MAKE_DIRECTORY "${sSliceOutput}/java")
execute_process(COMMAND "${Ice_SLICE2JAVA_EXECUTABLE}"   "--output-dir=${sSliceOutput}/java"   "${sSlice}")
file(MAKE_DIRECTORY "${sSliceOutput}/js")
execute_process(COMMAND "${Ice_SLICE2JS_EXECUTABLE}"     "--output-dir=${sSliceOutput}/js"     "${sSlice}")
file(MAKE_DIRECTORY "${sSliceOutput}/matlab")
execute_process(COMMAND "${Ice_SLICE2MATLAB_EXECUTABLE}" "--output-dir=${sSliceOutput}/matlab" "${sSlice}")
file(MAKE_DIRECTORY "${sSliceOutput}/objc")
execute_process(COMMAND "${Ice_SLICE2OBJC_EXECUTABLE}"   "--output-dir=${sSliceOutput}/objc"   "${sSlice}")
file(MAKE_DIRECTORY "${sSliceOutput}/php")
execute_process(COMMAND "${Ice_SLICE2PHP_EXECUTABLE}"    "--output-dir=${sSliceOutput}/php"    "${sSlice}")
file(MAKE_DIRECTORY "${sSliceOutput}/py")
execute_process(COMMAND "${Ice_SLICE2PY_EXECUTABLE}"     "--output-dir=${sSliceOutput}/py"     "${sSlice}")
file(MAKE_DIRECTORY "${sSliceOutput}/rb")
execute_process(COMMAND "${Ice_SLICE2RB_EXECUTABLE}"     "--output-dir=${sSliceOutput}/rb"     "${sSlice}")
