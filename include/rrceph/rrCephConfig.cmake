cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

get_filename_component(_rrCeph_install_prefix "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)

add_library(
  rrCeph INTERFACE)

target_compile_features(
  rrCeph INTERFACE cxx_std_11)

target_include_directories(
  rrCeph INTERFACE "${_rrCeph_install_prefix}/include")

if(TARGET s3::s3)
  # From Hunter
  target_link_libraries(
    rrCeph INTERFACE s3::s3)
elseif(TARGET S3::s3)
  # From System
  target_link_libraries(
    rrCeph INTERFACE S3::s3)
endif()

target_sources(
  rrCeph INTERFACE "${_rrCeph_install_prefix}/include/rrceph/s3.hxx"
                    "${_rrCeph_install_prefix}/include/rrceph/s3.inl"
                    "${_rrCeph_install_prefix}/include/rrceph/rrCephConfig.cmake")

get_target_property(_rrCeph_sources rrCeph INTERFACE_SOURCES)
source_group(TREE "${_rrCeph_install_prefix}" FILES ${_rrCeph_sources})

set(rrCeph_LIBRARIES rrCeph)
