#            _____ _
#           |  _  | |
#  _ __ _ __| | | | |_
# | '__| '__| | | | __| zhengrr
# | |  | |  \ \/' / |_  2016-06-28 – 2019-03-15
# |_|  |_|   \_/\_\\__| Unlicense

project(rrQt VERSION 2019.03.15 LANGUAGES CXX)
project_more()
compile_option(RECOMMENDED_WARNING_LEVEL MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen(WITH_OPTION)

if(3.12 VERSION_LESS CMAKE_VERSION)
  cmake_policy(SET CMP0074 NEW)
endif()
find_package(Qt5Package)
find_package(Qt5 COMPONENTS Core Gui LinguistTools Quick Test Widgets)
set_property(GLOBAL PROPERTY AUTOGEN_SOURCE_GROUP "generated")
conan_cmake_run(
  REQUIRES gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)

aux_source_directory_ex(zTest DIRECTORY "test/" RECURSE QT GROUP_ROOT "test/")

add_executable_ex(
  NAME "test" "ygen.dox" ${zTest} CXX17
  INCLUDE_DIRECTORIES PRIVATE "test/"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gtest)

aux_add_subdirectories(WITH_OPTION OPTION_NAME_PREFIX "${PROJECT_NAME_UPPER}_")
