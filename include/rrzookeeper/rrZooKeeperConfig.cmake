cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

get_filename_component(_rrZooKeeper_install_prefix "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)

add_library(
  rrZooKeeper INTERFACE)

target_compile_features(
  rrZooKeeper INTERFACE cxx_std_17)

target_include_directories(
  rrZooKeeper INTERFACE "${_rrZooKeeper_install_prefix}/include")

if(TARGET zookeeper::zookeeper_mt)
  target_link_libraries(
    rrZooKeeper INTERFACE zookeeper::zookeeper_mt)
endif()

target_sources(
  rrZooKeeper INTERFACE "${_rrZooKeeper_install_prefix}/include/rrzookeeper/rrzookeeper.hxx"
                        "${_rrZooKeeper_install_prefix}/include/rrzookeeper/rrzookeeper.inl"
                        "${_rrZooKeeper_install_prefix}/include/rrzookeeper/rrZooKeeperConfig.cmake")

get_target_property(_rrZooKeeper_sources rrZooKeeper INTERFACE_SOURCES)
source_group(TREE "${_rrZooKeeper_install_prefix}" FILES ${_rrZooKeeper_sources})

set(rrZooKeeper_LIBRARIES rrZooKeeper)
