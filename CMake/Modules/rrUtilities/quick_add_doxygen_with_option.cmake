#            _   _ _   _ _ _ _   _                                       zhengrr
#  _ __ _ __| | | | |_(_| (_| |_(_) ___ ___               2016-10-8 – 2017-12-27
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
#     [SPECIAL API|DEV]
#   )
function(quick_add_doxygen_with_option)
  set(oneValueKeywords "SPECIAL")
  cmake_parse_arguments(PARSE_ARGV 0 "" "" "${oneValueKeywords}" "")
  if(DEFINED _UNPARSED_ARGUMENTS)
    message(SEND_ERROR "Unexpected arguments(${_UNPARSED_ARGUMENTS}).")
    return()
  endif()

  string(TOUPPER "${PROJECT_NAME}" projectNameUpper)
  string(TOLOWER "${PROJECT_NAME}" projectNameLower)

  if(NOT DEFINED _SPECIAL)
    set(textName "documentation")
    set(optionName "${projectNameUpper}_GENERATE_DOC")
    set(targetName "${projectNameLower}_doc")
  elseif("${_SPECIAL}" STREQUAL "API")
    set(textName "API documentation")
    set(optionName "${projectNameUpper}_GENERATE_APIDOC")
    set(targetName "${projectNameLower}_apidoc")
  elseif("${_SPECIAL}" STREQUAL "DEV")
    set(textName "developing documentation")
    set(optionName "${projectNameUpper}_GENERATE_DEVDOC")
    set(targetName "${projectNameLower}_devdoc")
  else()
    message(SEND_ERROR "Undesirable SPECIAL(${_SPECIAL}).")
    return()
  endif()

  find_package(Doxygen)
  option(${optionName} "Generate ${textName} (requires Doxygen)." ${DOXYGEN_FOUND})
  if(NOT ${optionName})
    return()
  endif()
  if(NOT DOXYGEN_FOUND)
    message(SEND_ERROR "Doxygen is needed to generate the ${textName}.")
    return()
  endif()

  set(doxyfile_in "${PROJECT_SOURCE_DIR}/doxygen/Doxyfile.in")
  set(doxyfile "${PROJECT_BINARY_DIR}/doxygen/Doxyfile")
  configure_file(${doxyfile_in} ${doxyfile} @ONLY)

  file(GLOB srcfiles "*.h" "*.H" "*.hh" "*.hpp" "*.hxx")
  list(APPEND srcfiles ${doxyfile_in})
  source_group("" FILES ${srcfiles})

  add_custom_target(${targetName}
    COMMAND "${DOXYGEN_EXECUTABLE}" "${doxyfile}"
    WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
    COMMENT "Generating ${textName} with Doxygen."
    VERBATIM
    SOURCES ${srcfiles})
  install(DIRECTORY "${PROJECT_BINARY_DIR}/doxygen/docs/" DESTINATION "docs")
endfunction()
