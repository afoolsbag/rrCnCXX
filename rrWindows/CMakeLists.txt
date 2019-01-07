#          __        ___           _
#  _ __ _ _\ \      / (_)_ __   __| | _____      _____
# | '__| '__\ \ /\ / /| | '_ \ / _` |/ _ \ \ /\ / / __| zhengrr
# | |  | |   \ V  V / | | | | | (_| | (_) \ V  V /\__ \ 2016-10-12 – 2019-01-04
# |_|  |_|    \_/\_/  |_|_| |_|\__,_|\___/ \_/\_/ |___/ Unlicense

project(rrWindows VERSION 2019.1.4 LANGUAGES C)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen(OPTIMIZE_OUTPUT_FOR_C)

add_definitions("-D_UNICODE")
remove_definitions("-D_MBCS")

configure_file("src/project.h.in" "src/project.h" @ONLY)
aux_source_directory_ex(zInclude   DIRECTORY "include/" RECURSE                  GROUP_ROOT "include/")
aux_source_directory_ex(zSrc       DIRECTORY "src/"     RECURSE EXTENSIONS ".rc" GROUP_ROOT "src/")
aux_source_directory_ex(zGenerated DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/src/"  GROUP_ROOT "generated/")

add_library_ex(
  SHARED ${zInclude} ${zSrc} ${zGenerated} TARGET_NAME_VARIABLE sRrwindowsLib C11
  COMPILE_DEFINITIONS PUBLIC  "RRWINDOWS_SHARED"
  INCLUDE_DIRECTORIES PUBLIC  "include/"
                      PRIVATE "src/"
                              "${CMAKE_CURRENT_BINARY_DIR}/src/")

find_package(Check)

configure_file("test/project.h.in" "test/project.h" @ONLY)
aux_source_directory_ex(zTest      DIRECTORY "test/"    RECURSE EXTENSIONS ".rc" GROUP_ROOT "test/")
aux_source_directory_ex(zGenerated DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/test/" GROUP_ROOT "generated/")

add_executable_ex(
  NAME "test" ${zTest} ${zGenerated} "ygen.dox" C11
  INCLUDE_DIRECTORIES PRIVATE "test/"
                              "${CMAKE_CURRENT_BINARY_DIR}/test/"
  LINK_LIBRARIES      PRIVATE Check::check
                              ${sRrwindowsLib}
  POST_COPIES                 ${sRrwindowsLib})
