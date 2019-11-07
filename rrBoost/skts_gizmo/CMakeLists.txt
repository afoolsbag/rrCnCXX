conan_cmake_run(
  REQUIRES    spdlog/1.3.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("../../rrspdlog/wrapper" zWrapper RECURSE PREFIX "rrspdlog/wrapper")
add_library_ex(
  rrspdlogWrapperForSktsGizmo INTERFACE
  COMPILE_FEATURES            INTERFACE cxx_std_17
  INCLUDE_DIRECTORIES         INTERFACE "../../rrspdlog/wrapper"
  LINK_LIBRARIES              INTERFACE CONAN_PKG::spdlog
  SOURCES                     INTERFACE ${zWrapper})

aux_source_directory_con("." zSrc)
add_executable_con(
  rrSktsGizmo         ${zSrc}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE $<$<PLATFORM_ID:Linux>:dl>
                              $<$<PLATFORM_ID:Linux>:stdc++fs>
                              CONAN_PKG::boost
                              rrspdlogWrapperForSktsGizmo)
if(WIN32)
  target_compile_definitions(rrSktsGizmo PRIVATE "_WIN32_WINNT=0x0A00"  # Windows 10
                                                 "_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS")
endif()
