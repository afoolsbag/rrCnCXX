#           ______ _____ _____ _______   __
#           | ___ \  _  /  ___|_   _\ \ / /
#  _ __ _ __| |_/ / | | \ `--.  | |  \ V /
# | '__| '__|  __/| | | |`--. \ | |  /   \  zhengrr
# | |  | |  | |   \ \_/ /\__/ /_| |_/ /^\ \ 2019-02-15 – 2019-11-13
# |_|  |_|  \_|    \___/\____/ \___/\/   \/ Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

# 加载额外模块

include(CTest)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
include(rrCMake)

include_hunter_gate_script()

# 配置项目信息和全局编译选项

product_ex(
  rrPOSIX
  TIME_AS_VERSION
  LANGUAGES C CXX
  AUTHORS   "zhengrr"
  LICENSE   "Unlicense")

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

# 文档：rrPOSIXdoc

add_doxygen_con(
  rrPOSIXdoc)

# 共享库：rrPOSIX

configure_file("src/project.h.in" "src/project.h" @ONLY)
aux_source_directory_con("include/"                         zInc RECURSE PREFIX "include")
aux_source_directory_con("src"                              zSrc RECURSE PREFIX "src")
aux_source_directory_con("${CMAKE_CURRENT_BINARY_DIR}/src/" zGen RECURSE PREFIX "generated")
add_library_con(
  rrPOSIX
  STATIC     ${zInc} ${zSrc} ${zGen}
  PROPERTIES CXX_STANDARD          17
             CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PUBLIC  "include/"
                              "include/linux/usr/include"
                              "include/linux/usr/include/x86_64-linux-gnu"
                      PRIVATE "src/"
                              "${CMAKE_CURRENT_BINARY_DIR}/src")

install(
  DIRECTORY   "include"
  DESTINATION ".")

# 测试程序：rrPOSIXtest

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

aux_source_directory_con("test" zSrc RECURSE PREFIX "test")
add_executable_con(
  rrPOSIXtest         ${zSrc}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "test"
                              "include/linux/usr/include"
                              "include/linux/usr/include/x86_64-linux-gnu"
  LINK_LIBRARIES      PRIVATE rrPOSIX
                              GTest::main)

add_test(NAME rrPOSIXtest COMMAND rrPOSIXtest)

# 安装包
# https://cmake.org/cmake/help/latest/module/CPack.html
# https://cmake.org/cmake/help/latest/cpack_gen/archive.html

set(CPACK_GENERATOR             TGZ)

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
set(CPACK_PACKAGE_CHECKSUM      SHA256)

include(CPack)
