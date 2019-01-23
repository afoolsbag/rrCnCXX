#            _____                  _____ _   _
#           |  _  |                /  __ \ | | |
#  _ __ _ __| | | |_ __   ___ _ __ | /  \/ | | |
# | '__| '__| | | | '_ \ / _ \ '_ \| |   | | | |
# | |  | |  \ \_/ / |_) |  __/ | | | \__/\ \_/ /
# |_|  |_|   \___/| .__/ \___|_| |_|\____/\___/  zhengrr
#                 | |                            2018-01-22 – 2019-01-22
#                 |_|                            Unlicense

project(rrOpenCV VERSION 2019.01.22 LANGUAGES CXX)
project_more()
compile_option(MULTIPLE_PROCESSES UTF-8 WARNING_AS_ERROR)

add_doxygen(WITH_OPTION)

conan_cmake_run(
  REQUIRES gsl_microsoft/2.0.0@bincrafters/stable
           gtest/1.8.1@bincrafters/stable
           opencv/4.0.1@conan/stable
  BASIC_SETUP CMAKE_TARGETS)

aux_source_directory_ex(zUnitTestSrc RECURSE BASE_MATCHES "test$")
add_executable_ex(
  NAME UnitTest ${zUnitTestSrc} CXX17
  INCLUDE_DIRECTORIES PRIVATE "./"
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gsl_microsoft
                              CONAN_PKG::gtest
                              CONAN_PKG::opencv)

add_executable_ex(
  NAME core_Blending "core/blending_app.cpp" FLAT_GROUP
  LINK_LIBRARIES PRIVATE CONAN_PKG::gsl_microsoft CONAN_PKG::opencv)
add_executable_ex(
  NAME core_ContBrt "core/contbrt_app.cpp" FLAT_GROUP
  LINK_LIBRARIES PRIVATE CONAN_PKG::gsl_microsoft CONAN_PKG::opencv)
add_executable_ex(
  NAME core_Drawing "core/drawing_app.cpp" FLAT_GROUP
  LINK_LIBRARIES PRIVATE CONAN_PKG::gsl_microsoft CONAN_PKG::opencv)
add_executable_ex(
  NAME core_Random "core/random_app.cpp" FLAT_GROUP
  LINK_LIBRARIES PRIVATE CONAN_PKG::gsl_microsoft CONAN_PKG::opencv)

add_executable_ex(
  NAME highgui_Trackbar "highgui/trackbar_app.cpp" FLAT_GROUP
  LINK_LIBRARIES PRIVATE CONAN_PKG::gsl_microsoft CONAN_PKG::opencv)
add_executable_ex(
  NAME highgui_Exp "highgui/exp_app.cpp" FLAT_GROUP
  LINK_LIBRARIES PRIVATE CONAN_PKG::gsl_microsoft CONAN_PKG::opencv)
add_executable_ex(
  NAME highgui_Display "highgui/display_app.cpp" FLAT_GROUP
  LINK_LIBRARIES PRIVATE CONAN_PKG::gsl_microsoft CONAN_PKG::opencv)

add_executable_ex(
  NAME imgproc_Blur "imgproc/blur_app.cpp" FLAT_GROUP
  LINK_LIBRARIES PRIVATE CONAN_PKG::gsl_microsoft CONAN_PKG::opencv)
add_executable_ex(
  NAME imgproc_Morph "imgproc/morph_app.cpp" FLAT_GROUP
  LINK_LIBRARIES PRIVATE CONAN_PKG::gsl_microsoft CONAN_PKG::opencv)
