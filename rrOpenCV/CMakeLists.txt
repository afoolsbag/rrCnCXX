#            _____                  _____ _   _
#           |  _  |                /  __ \ | | |
#  _ __ _ __| | | |_ __   ___ _ __ | /  \/ | | |
# | '__| '__| | | | '_ \ / _ \ '_ \| |   | | | |
# | |  | |  \ \_/ / |_) |  __/ | | | \__/\ \_/ /
# |_|  |_|   \___/| .__/ \___|_| |_|\____/\___/  zhengrr
#                 | |                            2018-01-22 – 2019-10-22
#                 |_|                            Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrOpenCV
  TIME_AS_VERSION
  LANGUAGES CXX)

include_conan_script()

add_compile_options_ex(
  DISABLE_LANGUAGE_EXTENSIONS
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

add_doxygen_con(
  rrOpenCVdoc)

conan_cmake_run(
  REQUIRES    gsl_microsoft/2.0.0@bincrafters/stable
              gtest/1.8.1@bincrafters/stable
              opencv/4.1.1@conan/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

macro(quickadd_opencv_executable)
  get_filename_component(pDirName "${CMAKE_CURRENT_LIST_DIR}" NAME)
  aux_source_directory_con("." zSrc RECURSE)
  add_executable_con(
    ${PROJECT_NAME}_${pDirName} ${zSrc}
    PROPERTIES                  CXX_STANDARD          20
                                CXX_STANDARD_REQUIRED ON
    INCLUDE_DIRECTORIES         PRIVATE "."
    LINK_LIBRARIES              PRIVATE CONAN_PKG::gsl_microsoft
                                        CONAN_PKG::gtest
                                        CONAN_PKG::opencv)
endmacro()

add_aux_subdirectories_con(WITHOUT_OPTION)
