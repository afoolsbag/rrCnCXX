#            _____  _    _ _____ _____
#           /  ___|| |  | |_   _|  __ \
#  _ __ _ __\ `--. | |  | | | | | |  \/
# | '__| '__|`--. \| |/\| | | | | | __  zhengrr
# | |  | |  /\__/ /\  /\  /_| |_| |_\ \ 2019-01-14 – 2019-07-18
# |_|  |_|  \____/  \/  \/ \___/ \____/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

include_hunter_gate_script()

project_ex(
  rrSWIG
  TIME_AS_VERSION
  LANGUAGES C CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

#-------------------------------------------------------------------------------
# rrlc
configure_file("rrlc/src/cfg.h.in" "rrlc/src/cfg.h" @ONLY)
aux_source_directory_con("rrlc/include"                         zInclude   RECURSE PREFIX "include")
aux_source_directory_con("rrlc/src"                             zSrc       RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrlc/src" zGenerated RECURSE PREFIX "generated")
add_library_con(
  rrlc
  SHARED              ${zInclude} ${zSrc} ${zGenerated}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
                      SOVERSION           1.0.0
  COMPILE_DEFINITIONS PUBLIC  "RRLC_SHARED"
                      PRIVATE "RRLC_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC  "rrlc/include"
                      PRIVATE "rrlc/src"
                              "${CMAKE_CURRENT_BINARY_DIR}/rrlc/src")
install(
  DIRECTORY   "rrlc/include/"
  DESTINATION "include/")

#-------------------------------------------------------------------------------
# rrlx
configure_file("rrlx/src/cfg.hxx.in" "rrlx/src/cfg.hxx" @ONLY)
aux_source_directory_con("rrlx/include"                         zInclude   RECURSE PREFIX "include")
aux_source_directory_con("rrlx/src"                             zSrc       RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/rrlx/src" zGenerated RECURSE PREFIX "generated")
add_library_con(
  rrlx
  SHARED              ${zInclude} ${zSrc} ${zGenerated}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
                      SOVERSION             1.0.0
  COMPILE_DEFINITIONS PUBLIC  "RRLX_SHARED"
                      PRIVATE "RRLX_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC  "rrlx/include"
                      PRIVATE "rrlx/src"
                              "${CMAKE_CURRENT_BINARY_DIR}/rrlx/src")
if(CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(rrlx PRIVATE stdc++fs)
endif()
install(
  DIRECTORY   "rrlx/include/"
  DESTINATION "include/")

#-------------------------------------------------------------------------------
# rrlctest
find_package(Check REQUIRED)
aux_source_directory_con("rrlctest" zSrc RECURSE)
add_executable_con(
  rrlctest             ${zSrc}
  PROPERTIES          C_STANDARD          11
                      C_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "rrlctest"
  LINK_LIBRARIES      PRIVATE rrlc
                              rrlx
                              Check::check)

add_test(NAME rrlctest COMMAND rrlctest)

#-------------------------------------------------------------------------------
# rrlxtest
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
aux_source_directory_con("rrlxtest" zSrc RECURSE)
add_executable_con(
  rrlxtest             ${zSrc}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "rrlxtest"
  LINK_LIBRARIES      PRIVATE rrlc
                              rrlx
                              GTest::main)

add_test(NAME rrlxtest COMMAND rrlxtest)

#-------------------------------------------------------------------------------
# rrlxswg
find_package(SWIG)
if(SWIG_FOUND)

  function(add_swig_library_con _BASENAME _LANGUAGE _INPUT_SWG_FILE _OUTPUT_PARENT_DIR)
    set(zMutValKws COMMAND_OPTIONS
                   LINK_LIBRARIES)
    cmake_parse_arguments(PARSE_ARGV 2 "" "" "" "${zMutValKws}")

    string(TOLOWER "${_LANGUAGE}" sLanguageLower)
	get_filename_component(sSwgNameWle "${_INPUT_SWG_FILE}" NAME_WLE)

    file(MAKE_DIRECTORY "${_OUTPUT_PARENT_DIR}/${sLanguageLower}")
    execute_process(
      COMMAND "${SWIG_EXECUTABLE}"
              "-c++"               "-o"      "${_OUTPUT_PARENT_DIR}/${sLanguageLower}/${sSwgNameWle}_wrap.cpp"
              "-${sLanguageLower}" "-outdir" "${_OUTPUT_PARENT_DIR}/${sLanguageLower}"
              ${_COMMAND_OPTIONS}
              "${_INPUT_SWG_FILE}"
      RESULTS_VARIABLE sResultCode)
    if(NOT sResultCode EQUAL 0)
      message(FATAL_ERROR "Gennerate SWIG ${sLanguageLower} files from interface file failed: ${sResultCode}")
    endif()

    aux_source_directory_con("${_OUTPUT_PARENT_DIR}/${sLanguageLower}" zGen PREFIX "generated")
    add_library_con(
      "${_BASENAME}_${sLanguageLower}"
      SHARED              "${_INPUT_SWG_FILE}" ${zGen}
      PROPERTIES          CXX_STANDARD          17
                          CXX_STANDARD_REQUIRED ON
      INCLUDE_DIRECTORIES PRIVATE "${_OUTPUT_PARENT_DIR}/${sLanguageLower}"
	  LINK_LIBRARIES      PRIVATE ${_LINK_LIBRARIES})
  endfunction()

  set(sSwg       "${CMAKE_CURRENT_SOURCE_DIR}/rrlx/rrlx.swg")
  set(sSwgOutput "${CMAKE_CURRENT_BINARY_DIR}/rrlx/rrlx.swg")

  math(EXPR sIntGoZize "8 * ${CMAKE_SIZEOF_VOID_P}")

  add_swig_library_con(rrlxswg CSharp     "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg D          "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg Go         "${sSwg}" "${sSwgOutput}" COMMAND_OPTIONS "-intgosize" "${sIntGoZize}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg Guile      "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg Java       "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg JavaScript "${sSwg}" "${sSwgOutput}" COMMAND_OPTIONS "-node" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg Lua        "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg Octave     "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg Perl5      "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg Php7       "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg Python     "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg R          "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg Ruby       "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg SciLab     "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  add_swig_library_con(rrlxswg Tcl8       "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
  #add_swig_library_con(rrlxswg Xml        "${sSwg}" "${sSwgOutput}" LINK_LIBRARIES rrlx)
endif()
