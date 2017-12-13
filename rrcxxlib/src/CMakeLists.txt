add_definitions("-D${PROJECT_NAME_WITHOUT_HYPHEN_UPPER}__EXPORTS")

if(MSVC)
  add_compile_options("/wd4464")  # relative include path contains '..'
  add_compile_options("/wd4514")  # unreferenced inline function
  add_compile_options("/wd4819")  # character cannot be represented
  add_compile_options("/wd4820")  # bytes padding added
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
source_file_helper(
    RECURSE CONFIGURE INSTALL CPP
    SRC_VAR source_files
    GRP_DIR "/")

option(${PROJECT_NAME_UPPER}_COMPILE_STATIC "Build static library." ON)
if(${PROJECT_NAME_UPPER}_COMPILE_STATIC)
  add_library(${PROJECT_NAME_LOWER}_static STATIC ${source_files})
  set_target_properties(${PROJECT_NAME_LOWER}_static PROPERTIES
      CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON
      OUTPUT_NAME "${PROJECT_NAME}" CLEAN_DIRECT_OUTPUT ON)
  install(TARGETS ${PROJECT_NAME_LOWER}_static DESTINATION "lib")
endif()

option(${PROJECT_NAME_UPPER}_COMPILE_SHARED "Build shared library." ON)
if(${PROJECT_NAME_UPPER}_COMPILE_SHARED)
  add_library(${PROJECT_NAME_LOWER}_shared SHARED ${source_files})
  set_target_properties(${PROJECT_NAME_LOWER}_shared PROPERTIES
      CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON
      OUTPUT_NAME "${PROJECT_NAME}" CLEAN_DIRECT_OUTPUT ON
      VERSION "${PROJECT_VERSION}" SOVERSION "${PROJECT_VERSION}")
  install(TARGETS ${PROJECT_NAME_LOWER}_shared DESTINATION "lib")
endif()
