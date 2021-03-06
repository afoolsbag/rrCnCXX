#           ______                 _
#           | ___ \               | |
#  _ __ _ __| |_/ / ___   ___  ___| |_
# | '__| '__| ___ \/ _ \ / _ \/ __| __| zhengrr
# | |  | |  | |_/ / (_) | (_) \__ \ |_  2016-10-27 – 2020-04-30
# |_|  |_|  \____/ \___/ \___/|___/\__| Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrBoost
  TIME_AS_VERSION
  LANGUAGES CXX)

include_conan_script()

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

add_doxygen_con(
  rrBoostDoc)

conan_cmake_run(
  REQUIRES    boost/1.72.0
              gtest/1.10.0
              ms-gsl/2.1.0
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)
#conan_cmake_run(
#  REQUIRES    boost/1.71.0@conan/stable
#              gsl_microsoft/2.0.0@bincrafters/stable
#              gtest/1.8.1@bincrafters/stable
#  BASIC_SETUP CMAKE_TARGETS
#  BUILD       missing)
# OPTIONS     boost:header_only=True

aux_source_directory_con("." zTest)
add_executable_con(
  rrBoostTest         ${zTest}
                      "README.md"
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PRIVATE $<$<PLATFORM_ID:Windows>:_WIN32_WINNT=0x0A00>  # Windows 10
                              $<$<CXX_COMPILER_ID:MSVC>:_CRT_SECURE_NO_WARNINGS>
                              $<$<CXX_COMPILER_ID:MSVC>:_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS>
  COMPILE_OPTIONS     PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wno-error=unused-function>
                              $<$<CXX_COMPILER_ID:MSVC>:/EHs>                # Boost.Coroutine2
                              $<$<CXX_COMPILER_ID:MSVC>:/GL->                # Boost.Coroutine2
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE CONAN_PKG::gtest
                              CONAN_PKG::boost
                              CONAN_PKG::ms-gsl
                              $<$<PLATFORM_ID:Linux>:dl>
                              $<$<PLATFORM_ID:Linux>:rt>)

add_test(NAME rrBoostTest COMMAND rrBoostTest)
