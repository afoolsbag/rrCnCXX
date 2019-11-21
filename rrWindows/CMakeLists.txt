#            _    _ _           _
#           | |  | (_)         | |
#  _ __ _ __| |  | |_ _ __   __| | _____      _____
# | '__| '__| |/\| | | '_ \ / _` |/ _ \ \ /\ / / __| zhengrr
# | |  | |  \  /\  / | | | | (_| | (_) \ V  V /\__ \ 2016-10-12 – 2019-10-08
# |_|  |_|   \/  \/|_|_| |_|\__,_|\___/ \_/\_/ |___/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

# 加载额外模块

include(CTest)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
include(rrCMake)

include_hunter_gate_script()

# 配置项目信息和全局编译选项

product_ex(
  rrWindows
  TIME_AS_VERSION
  LANGUAGES C CXX
  AUTHORS   "zhengrr"
  LICENSE   "Unlicense")

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

# 文档：rrWindowsDoc

add_doxygen_con(
  rrWindowsDoc)

# 共享库：rrWindows

hunter_add_package(Microsoft.GSL)
find_package(Microsoft.GSL CONFIG REQUIRED)

configure_file("src/project.hxx.in" "src/project.hxx" @ONLY)
aux_source_directory_con("include"                         zInc RECURSE                  PREFIX "include")
aux_source_directory_con("src"                             zSrc RECURSE EXTENSIONS ".rc" PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/src" zGen                          PREFIX "generated")
add_library_con(
  rrWindows
  SHARED              ${zInc} ${zSrc} ${zGen} "README.md" "develop.dox"
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PUBLIC  "RRWINDOWS_SHARED"
                              "_WIN32_WINNT=0x0A00"  # Windows 10
                      PRIVATE "RRWINDOWS_EXPORTS"
  INCLUDE_DIRECTORIES PUBLIC  "include"
                      PRIVATE "src"
                              "${CMAKE_CURRENT_BINARY_DIR}/src"
  LINK_LIBRARIES      PRIVATE Microsoft.GSL::GSL)

install(
  DIRECTORY   "include"
  DESTINATION ".")

# 测试程序：rrWindowsTest

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

configure_file("test/project.hxx.in" "test/project.hxx" @ONLY)

aux_source_directory_ex("test"                             zTest RECURSE EXTENSIONS ".rc" PREFIX "test")
aux_source_directory_ex("${CMAKE_CURRENT_BINARY_DIR}/test" zGen                           PREFIX "generated")
add_executable_con(
  rrWindowsTest       ${zTest} ${zGen} "README.md" "develop.dox"
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "test"
                              "${CMAKE_CURRENT_BINARY_DIR}/test"
  LINK_LIBRARIES      PRIVATE rrWindows
                              GTest::gtest)

add_test(NAME rrWindowsTest COMMAND rrWindowsTest)

# 程序：rrWdt

configure_file("wdt/project.hxx.in" "wdt/project.hxx" @ONLY)
aux_source_directory_con("wdt"                             zWdt RECURSE EXTENSIONS ".rc" PREFIX "wdt")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/wdt" zGen                          PREFIX "generated")
add_executable_con(
  rrWdt               ${zWdt} ${zGen} "README.md" "develop.dox"
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PRIVATE "_UNICODE"
  INCLUDE_DIRECTORIES PRIVATE "wdt"
                              "${CMAKE_CURRENT_BINARY_DIR}/wdt"
  LINK_LIBRARIES      PRIVATE rrWindows)

# 安装包
# https://cmake.org/cmake/help/latest/module/CPack.html
# https://cmake.org/cmake/help/latest/cpack_gen/wix.html

set(CPACK_GENERATOR             WIX)

set(CPACK_PACKAGE_NAME          "${PRODUCT_NAME}")
math(EXPR nTmp                  "${PRODUCT_VERSION_MAJOR} % 100")
set(CPACK_PACKAGE_VERSION_MAJOR "${nTmp}")
math(EXPR nTmp                  "${PRODUCT_VERSION_MINOR} % 100")
set(CPACK_PACKAGE_VERSION_MINOR "${nTmp}")
math(EXPR nTmp                  "${PRODUCT_VERSION_PATCH} % 100")
set(CPACK_PACKAGE_VERSION_PATCH "${nTmp}")
set(CPACK_PACKAGE_DESCRIPTION   "${PRODUCT_DESCRIPTION}")
set(CPACK_PACKAGE_HOMEPAGE_URL  "${PRODUCT_HOMEPAGE_URL}")
set(CPACK_PACKAGE_VENDOR        "${PRODUCT_AUTHORS}")

set(CPACK_RESOURCE_FILE_LICENSE "${PRODUCT_SOURCE_DIR}/UNLICENSE.txt")
set(CPACK_RESOURCE_FILE_README  "${PRODUCT_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_EXECUTABLES   "rrWindowsTest" "rrWindowsTest"
                                "rrWdt"         "rrWdt")
set(CPACK_PACKAGE_CHECKSUM      SHA256)

set(CPACK_WIX_CULTURES          zh-CN)

include(CPack)
