project("rrMFC_PWMFC_3_3_VisualKB" LANGUAGES CXX)
make_project_extra_variables()

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)

include_directories("C:/Program Files (x86)/Microsoft Visual Studio 9.0/VC/atlmfc/include")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
source_files_helper(
  RECURSE CONFIGURE CPP
  SRC_VAR source_files
  GRP_DIR "/")

option(${PROJECT_NAME_UPPER}_COMPILE_EXE "Build executable file." ON)
if(${PROJECT_NAME_UPPER}_COMPILE_EXE)
  add_executable(${PROJECT_NAME_LOWER}_exe WIN32 ${source_files})
  set_target_properties(${PROJECT_NAME_LOWER}_exe PROPERTIES
    CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME ${PROJECT_NAME} CLEAN_DIRECT_OUTPUT ON)
  install(TARGETS ${PROJECT_NAME_LOWER}_exe DESTINATION "bin")
endif()
