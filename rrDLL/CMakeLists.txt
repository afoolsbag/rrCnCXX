#           ______ _      _
#           |  _  \ |    | |
#  _ __ _ __| | | | |    | |
# | '__| '__| | | | |    | |     zhengrr
# | |  | |  | |/ /| |____| |____ 2019-01-14 – 2019-04-02
# |_|  |_|  |___/ \_____/\_____/ Unlicense

project(rrDLL VERSION 2018.04.02 LANGUAGES C CXX)
project_more()
compile_option(RECOMMENDED_WARNING_LEVEL MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

# RRC (C Library)
set(sIncDir "rrc/include/")
set(sSrcDir "rrc/src/")
set(sGenDir "${CMAKE_CURRENT_BINARY_DIR}/rrc/src/")
configure_file("${sSrcDir}cfg.h.in" "${sGenDir}cfg.h" @ONLY)
aux_source_directory_ex(zInc DIRECTORY "${sIncDir}" RECURSE GROUP_ROOT "include/")
aux_source_directory_ex(zSrc DIRECTORY "${sSrcDir}" RECURSE GROUP_ROOT "src/")
aux_source_directory_ex(zGen DIRECTORY "${sGenDir}" RECURSE GROUP_ROOT "generated/")
add_library_ex(
  NAME_PREFIX          "rrc"
  SHARED               ${zInc} ${zSrc} ${zGen}
  TARGET_NAME_VARIABLE sRrc
  C11
  COMPILE_DEFINITIONS  PUBLIC  "RRC_SHARED"
  INCLUDE_DIRECTORIES  PUBLIC  "."
                               "${sIncDir}"
                       PRIVATE "${sSrcDir}"
                               "${sGenDir}")

# RRX (C++ Library)
set(sIncDir "rrx/include/")
set(sSrcDir "rrx/src/")
set(sGenDir "${CMAKE_CURRENT_BINARY_DIR}/rrx/src/")
configure_file("${sSrcDir}cfg.hxx.in" "${sGenDir}cfg.hxx" @ONLY)
aux_source_directory_ex(zInc DIRECTORY "${sIncDir}" RECURSE GROUP_ROOT "include/")
aux_source_directory_ex(zSrc DIRECTORY "${sSrcDir}" RECURSE GROUP_ROOT "src/")
aux_source_directory_ex(zGen DIRECTORY "${sGenDir}" RECURSE GROUP_ROOT "generated/")
add_library_ex(
  NAME_PREFIX          "rrx"
  SHARED               ${zInc} ${zSrc} ${zGen}
  TARGET_NAME_VARIABLE sRrx
  CXX17
  COMPILE_DEFINITIONS  PUBLIC  "RRX_SHARED"
  INCLUDE_DIRECTORIES  PUBLIC  "."
                               "${sIncDir}"
                       PRIVATE "${sSrcDir}"
                               "${sGenDir}")

# RRS (C Executable)
set(sSrcDir "rrs/src/")
aux_source_directory_ex(zSrc DIRECTORY "${sSrcDir}" RECURSE GROUP_ROOT "src/")
add_executable_ex(
  NAME_PREFIX         "rrs"
                      ${zSrc}
  C11
  INCLUDE_DIRECTORIES PRIVATE "${sSrcDir}"
  LINK_LIBRARIES      ${sRrc}
                      ${sRrx}
  POST_COPIES         ${sRrc}
                      ${sRrx})

# RRZ (C++ Executable)
set(sSrcDir "rrz/src/")
aux_source_directory_ex(zSrc DIRECTORY "${sSrcDir}" RECURSE GROUP_ROOT "src/")
add_executable_ex(
  NAME_PREFIX         "rrz"
                      ${zSrc}
  CXX17
  INCLUDE_DIRECTORIES PRIVATE "${sSrcDir}"
  LINK_LIBRARIES      ${sRrc}
                      ${sRrx}
  POST_COPIES         ${sRrc}
                      ${sRrx})
