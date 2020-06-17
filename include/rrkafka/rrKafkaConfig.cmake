cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

get_filename_component(_rrKafka_install_prefix "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)

add_library(
  rrKafka INTERFACE)

target_compile_features(
  rrKafka INTERFACE cxx_std_17)

target_include_directories(
  rrKafka INTERFACE "${_rrKafka_install_prefix}/include")

if(TARGET RdKafka::rdkafka++)
  target_link_libraries(
    rrKafka INTERFACE RdKafka::rdkafka++)
endif()

target_sources(
  rrKafka INTERFACE "${_rrKafka_install_prefix}/include/rrkafka/rrkafka.hxx"
                    "${_rrKafka_install_prefix}/include/rrkafka/rrkafka.inl"
                    "${_rrKafka_install_prefix}/include/rrkafka/rrKafkaConfig.cmake")

get_target_property(_rrKafka_sources rrKafka INTERFACE_SOURCES)
source_group(TREE "${_rrKafka_install_prefix}" FILES ${_rrKafka_sources})

set(rrKafka_LIBRARIES rrKafka)
