#             ___                  
#            / _ \                 
#  _ __ _ __/ /_\ \_   ___ __ ___  
# | '__| '__|  _  \ \ / / '__/ _ \  zhengrr
# | |  | |  | | | |\ V /| | | (_) | 2018-04-02 – 2019-07-10
# |_|  |_|  \_| |_/ \_/ |_|  \___/  Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrAvro
  VERSION   2019.07.10
  LANGUAGES CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen_con(
  rrAvroDoc)

find_package(AvroCpp)
conan_cmake_run(
  REQUIRES    boost/1.70.0@conan/stable
              gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

execute_process(
  COMMAND "${AvroCpp_avrogencpp_EXECUTABLE}"
          -n rravro
          -i "${CMAKE_CURRENT_SOURCE_DIR}/RecordType.json"
          -o "${CMAKE_CURRENT_BINARY_DIR}/RecordType.hh"
  RESULTS_VARIABLE sResultCode)
if(NOT sResultCode EQUAL 0)
  message(FATAL_ERROR "Gennerate schema c++ file from definition file failed: ${sResultCode}")
endif()

aux_source_directory_con("."                           zTest EXTENSIONS ".json" PREFIX "test")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}" zGen                     PREFIX "generated")
add_executable_ex(
  rrAvroTest          ${zTest} ${zGen}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "."
                              "${CMAKE_CURRENT_BINARY_DIR}"
  LINK_LIBRARIES      PRIVATE AvroCpp::avrocpp
                              CONAN_PKG::gtest
                              CONAN_PKG::boost)

add_custom_command(
  TARGET rrAvroTest POST_BUILD
  COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
          "${CMAKE_CURRENT_SOURCE_DIR}/RecordType.json"
          "$<TARGET_FILE_DIR:rrAvroTest>"
  COMMENT "Copy schema definition file to target directory")
