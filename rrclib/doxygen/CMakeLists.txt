find_package(Doxygen)
option(${PROJECT_NAME_UPPER}_GEN_API_DOC
    "Generate API documentation (requires Doxygen)." ${DOXYGEN_FOUND})
if(${PROJECT_NAME_UPPER}_GEN_API_DOC)
  if(NOT DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen is needed to generate the API documentation.")
  endif()

  set(doxyfile_in "${PROJECT_SOURCE_DIR}/doxygen/Doxyfile.in")
  set(doxyfile "${PROJECT_BINARY_DIR}/doxygen/Doxyfile")
  configure_file(${doxyfile_in} ${doxyfile} @ONLY)

  file(GLOB source_files "*.h")
  list(APPEND source_files ${doxyfile_in})
  source_group("\\" FILES ${source_files})

  add_custom_target(${PROJECT_NAME_LOWER}_api_doc
      COMMAND "${DOXYGEN_EXECUTABLE}" "${doxyfile}"
      WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
      COMMENT "Generating API documentation with Doxygen."
      VERBATIM
      SOURCES ${source_files})
  install(DIRECTORY "${PROJECT_BINARY_DIR}/doxygen/docs/" DESTINATION "docs")
endif()
