find_package(LIVE555 REQUIRED)
if(WIN32)
  set(socket_libraries "ws2_32.lib")
endif()

include_directories(${LIVE555_INCLUDE_DIRS})
set(CMAKE_INCLUDE_CURRENT_DIR ON)
source_file_helper(
    RECURSE CONFIGURE CPP
    SRC_VAR source_files
    GRP_DIR "/")

option(${PROJECT_NAME_UPPER}_COMPILE_EXE "Build executable file." ON)
if(${PROJECT_NAME_UPPER}_COMPILE_EXE)
  add_executable(${PROJECT_NAME_LOWER}_exe ${source_files})
  target_link_libraries(${PROJECT_NAME_LOWER}_exe ${LIVE555_LIBRARIES} ${socket_libraries})
  set_target_properties(${PROJECT_NAME_LOWER}_exe PROPERTIES
      CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON
      OUTPUT_NAME "${PROJECT_NAME}" CLEAN_DIRECT_OUTPUT ON)
  install(TARGETS ${PROJECT_NAME_LOWER}_exe DESTINATION "bin")
endif()
