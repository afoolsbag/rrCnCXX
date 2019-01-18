#           ______ _      _
#           |  _  \ |    | |
#  _ __ _ __| | | | |    | |
# | '__| '__| | | | |    | |     zhengrr
# | |  | |  | |/ /| |____| |____ 2019-01-14 – 2019-01-18
# |_|  |_|  |___/ \_____/\_____/ Unlicense

project(rrDLL VERSION 2018.01.18 LANGUAGES C CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

# C Library
configure_file("clib/src/config.h.in" "clib/src/config.h" @ONLY)
aux_source_directory_ex(zClibInclude   DIRECTORY "clib/include/"                         RECURSE GROUP_ROOT "include/")
aux_source_directory_ex(zClibSrc       DIRECTORY "clib/src/"                             RECURSE GROUP_ROOT "src/")
aux_source_directory_ex(zClibGenerated DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/clib/src/" RECURSE GROUP_ROOT "generated/")
add_library_ex(
  NAME clib SHARED ${zClibInclude} ${zClibSrc} ${zClibGenerated} TARGET_NAME_VARIABLE sClib C11
  COMPILE_DEFINITIONS PUBLIC  "CLIB_SHARED"
  INCLUDE_DIRECTORIES PUBLIC  "clib/include/"
                      PRIVATE "clib/src/"
                              "${CMAKE_CURRENT_BINARY_DIR}/clib/src/")

# C++ Library
configure_file("cxxlib/src/config.hxx.in" "cxxlib/src/config.hxx" @ONLY)
aux_source_directory_ex(zCxxlibInclude   DIRECTORY "cxxlib/include/"                         RECURSE GROUP_ROOT "include/")
aux_source_directory_ex(zCxxlibSrc       DIRECTORY "cxxlib/src/"                             RECURSE GROUP_ROOT "src/")
aux_source_directory_ex(zCxxlibGenerated DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/cxxlib/src/" RECURSE GROUP_ROOT "generated/")
add_library_ex(
  NAME cxxlib SHARED ${zCxxlibInclude} ${zCxxlibSrc} ${zCxxlibGenerated} TARGET_NAME_VARIABLE sCxxlib CXX17
  COMPILE_DEFINITIONS PUBLIC  "CXXLIB_SHARED"
  INCLUDE_DIRECTORIES PUBLIC  "cxxlib/include/"
                      PRIVATE "cxxlib/src/"
                              "${CMAKE_CURRENT_BINARY_DIR}/cxxlib/src/")

# C Executable
aux_source_directory_ex(zCexeSrc DIRECTORY "cexe/src" RECURSE GROUP_ROOT "src/")
add_executable_ex(
  NAME cexe ${zCexeSrc} C11
  INCLUDE_DIRECTORIES PRIVATE "cexe/src/"
  LINK_LIBRARIES ${sClib} ${sCxxlib}
  POST_COPIES    ${sClib} ${sCxxlib})

# C++ Executable
aux_source_directory_ex(zCxxexeSrc DIRECTORY "cxxexe/src" RECURSE GROUP_ROOT "src/")
add_executable_ex(
  NAME cxxexe ${zCxxexeSrc} CXX17
  INCLUDE_DIRECTORIES PRIVATE "cxxexe/src/"
  LINK_LIBRARIES ${sClib} ${sCxxlib}
  POST_COPIES    ${sClib} ${sCxxlib})
