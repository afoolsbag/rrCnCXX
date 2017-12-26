#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___               2016-10-8 – 2017-12-26
# | '__| '__| | | | __| | | | __| |/ _ / __|                     The MIT License
# | |  | |  | |_| | |_| | | | |_| |  __\__ \
# |_|  |_|   \___/ \__|_|_|_|\__|_|\___|___/ rrUtilities by FIGlet
#            _     _                _                  _                       _
#   __ _  __| | __| | ___ _   _ ___| |_ ___  _ __ ___ | |_ __ _ _ __ __ _  ___| |_
#  / _` |/ _` |/ _` |/ __| | | / __| __/ _ \| '_ ` _ \| __/ _` | '__/ _` |/ _ | __|
# | (_| | (_| | (_| | (__| |_| \__ | || (_) | | | | | | || (_| | | | (_| |  __| |_
#  \__,_|\__,_|\__,_|\___|\__,_|___/\__\___/|_| |_| |_|\__\__,_|_|  \__, |\___|\__|
#                                       add_custom_target by FIGlet |___/

# .rst
# .. command:: quick_add_doxygen_with_option
#
#  简便生成Ｄｏｘｙｇｅｎ文档::
#
#   quick_add_doxygen_with_option(
#     [SPECIAL <API|DEV>]
#   )
function(quick_add_doxygen_with_option)

  set(opts)
  set(ovks "SPECIAL")
  set(mvks)
  cmake_parse_arguments("ARG" "${opts}" "${ovks}" "${mvks}" ${ARGN})
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  if(NOT DEFINED _SPECIAL)
    set(text "documentation")
    set(upper "DOC")
    set(lower "doc")
  elseif("${_SPECIAL}" STREQUAL "API")
    set(text "API documentation")
    set(upper "API_DOC")
    set(lower "api_doc")
  elseif("${_SPECIAL}" STREQUAL "DEV")
    set(text "developing documentation")
    set(upper "DEV_DOC")
    set(lower "dev_doc")
  else()
    message(SEND_ERROR "Undesirable SPECIAL(${_SPECIAL}).")
    return()
  endif()

  find_package(Doxygen)
  option(${PROJECT_NAME_UPPER}_GEN_${upper} "Generate ${text} (requires Doxygen)." ${DOXYGEN_FOUND})
  if(${PROJECT_NAME_UPPER}_GEN_${upper})
    if(NOT DOXYGEN_FOUND)
      message(SEND_ERROR "Doxygen is needed to generate the ${text}.")
      return()
    endif()

    set(doxyfile_in "${PROJECT_SOURCE_DIR}/doxygen/Doxyfile.in")
    set(doxyfile    "${PROJECT_BINARY_DIR}/doxygen/Doxyfile")
    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    file(GLOB srcfiles "*.h" "*.hpp")
    list(APPEND srcfiles ${doxyfile_in})
    source_group("" FILES ${srcfiles})

    add_custom_target(${PROJECT_NAME_LOWER}_${lower}
      COMMAND "${DOXYGEN_EXECUTABLE}" "${doxyfile}"
      WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
      COMMENT "Generating ${text} with Doxygen."
      VERBATIM
      SOURCES ${srcfiles})
    install(DIRECTORY "${PROJECT_BINARY_DIR}/doxygen/docs/" DESTINATION "docs")
  endif()

endfunction()
