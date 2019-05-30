#            _____ _
#           |  _  | |
#  _ __ _ __| | | | |_
# | '__| '__| | | | __| zhengrr
# | |  | |  \ \/' / |_  2016-06-28 – 2019-03-15
# |_|  |_|   \_/\_\\__| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrQt
  VERSION   2019.05.08
  LANGUAGES CXX)

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  WARNING_AS_ERROR)

add_doxygen_con(
  rrQtDoc)

find_package(Qt5Config)
find_package(Qt5 COMPONENTS Core Gui LinguistTools Quick Test Widgets)
set_property(GLOBAL PROPERTY AUTOGEN_SOURCE_GROUP "generated")
conan_cmake_run(
  REQUIRES    gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)

aux_source_directory_con("test" zTest RECURSE QT)
add_executable_con(
  rrQtTest            ${zTest}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "test/"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gtest)

add_aux_subdirectories_con(PREFIX "${PROJECT_NAME_UPPER}")
