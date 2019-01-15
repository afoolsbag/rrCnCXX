#           ______ _      _
#           |  _  \ |    | |
#  _ __ _ __| | | | |    | |
# | '__| '__| | | | |    | |     zhengrr
# | |  | |  | |/ /| |____| |____ 2019-01-14 – 2019-01-15
# |_|  |_|  |___/ \_____/\_____/ Unlicense

project(rrDLL VERSION 2018.01.15 LANGUAGES C CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

# Library Write In C
configure_file("lwic/src/config.h.in" "lwic/src/config.h" @ONLY)
aux_source_directory_ex(zLwicInclude   DIRECTORY "lwic/include/"                         RECURSE GROUP_ROOT "include/")
aux_source_directory_ex(zLwicSrc       DIRECTORY "lwic/src/"                             RECURSE GROUP_ROOT "src/")
aux_source_directory_ex(zLwicGenerated DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lwic/src/" RECURSE GROUP_ROOT "generated/")
add_library_ex(
  NAME lwic SHARED ${zLwicInclude} ${zLwicSrc} ${zLwicGenerated} TARGET_NAME_VARIABLE sLwic C11
  COMPILE_DEFINITIONS PUBLIC  "RRDLL_LWIC_SHARED"
  INCLUDE_DIRECTORIES PUBLIC  "lwic/include/"
                      PRIVATE "lwic/src/"
                              "${CMAKE_CURRENT_BINARY_DIR}/lwic/src/")

# Library Write In C++
configure_file("lwicxx/src/config.hxx.in" "lwicxx/src/config.hxx" @ONLY)
aux_source_directory_ex(zLwicxxInclude   DIRECTORY "lwicxx/include/"                         RECURSE GROUP_ROOT "include/")
aux_source_directory_ex(zLwicxxSrc       DIRECTORY "lwicxx/src/"                             RECURSE GROUP_ROOT "src/")
aux_source_directory_ex(zLwicxxGenerated DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lwicxx/src/" RECURSE GROUP_ROOT "generated/")
add_library_ex(
  NAME lwicxx SHARED ${zLwicxxInclude} ${zLwicxxSrc} ${zLwicxxGenerated} TARGET_NAME_VARIABLE sLwicxx CXX17
  COMPILE_DEFINITIONS PUBLIC  "RRDLL_LWICXX_SHARED"
  INCLUDE_DIRECTORIES PUBLIC  "lwicxx/include/"
                      PRIVATE "lwicxx/src/"
                              "${CMAKE_CURRENT_BINARY_DIR}/lwicxx/src/")

# Executable Write In C
aux_source_directory_ex(zEwicSrc DIRECTORY "ewic/src" RECURSE GROUP_ROOT "src/")
add_executable_ex(
  NAME ewic ${zEwicSrc} C11
  INCLUDE_DIRECTORIES PRIVATE "ewic/src/"
  LINK_LIBRARIES ${sLwic} ${sLwicxx}
  POST_COPIES    ${sLwic} ${sLwicxx})

# Executable Write In C++
aux_source_directory_ex(zEwicxxSrc DIRECTORY "ewicxx/src" RECURSE GROUP_ROOT "src/")
add_executable_ex(
  NAME ewicxx ${zEwicxxSrc} CXX17
  INCLUDE_DIRECTORIES PRIVATE "ewicxx/src/"
  LINK_LIBRARIES ${sLwic} ${sLwicxx}
  POST_COPIES    ${sLwic} ${sLwicxx})
