set(CMAKE_INCLUDE_CURRENT_DIR ON)
source_file_helper(
    RECURSE CONFIGURE C
    SRC_VAR source_files
    GRP_DIR "/")

option(${PROJECT_NAME_UPPER}_COMPILE_EXE "Build executable file." ON)
if(${PROJECT_NAME_UPPER}_COMPILE_EXE)
  add_executable(${PROJECT_NAME_LOWER}_exe ${source_files})
  set_target_properties(${PROJECT_NAME_LOWER}_exe PROPERTIES
      C_STANDARD 11 C_STANDARD_REQUIRED ON
      OUTPUT_NAME "${PROJECT_NAME}" CLEAN_DIRECT_OUTPUT ON)
  install(TARGETS ${PROJECT_NAME_LOWER}_exe DESTINATION "bin")
endif()
