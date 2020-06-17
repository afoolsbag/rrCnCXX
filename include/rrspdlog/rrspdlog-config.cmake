cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

get_filename_component(_rrspdlog_install_prefix "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)

add_library(
  rrspdlog INTERFACE)

target_compile_features(
  rrspdlog INTERFACE cxx_std_17)

target_include_directories(
  rrspdlog INTERFACE "${_rrspdlog_install_prefix}/include")

if(TARGET CONAN_PKG::spdlog)
  target_link_libraries(
    rrspdlog INTERFACE CONAN_PKG::spdlog)
elseif(TARGET spdlog::spdlog)
  target_link_libraries(
    rrspdlog INTERFACE spdlog::spdlog)
endif()

target_sources(
  rrspdlog INTERFACE "${_rrspdlog_install_prefix}/include/rrspdlog/rrspdlog.hxx"
                     "${_rrspdlog_install_prefix}/include/rrspdlog/rrspdlog.inl"
                     "${_rrspdlog_install_prefix}/include/rrspdlog/rrspdlog-config.cmake")

get_target_property(_rrspdlog_sources rrspdlog INTERFACE_SOURCES)
source_group(TREE "${_rrspdlog_install_prefix}" FILES ${_rrspdlog_sources})

set(rrspdlog_LIBRARIES rrspdlog)
