#                          _ _
#                         | | |
#  _ __ _ __ ___ _ __   __| | | ___   __ _
# | '__| '__/ __| '_ \ / _` | |/ _ \ / _` |
# | |  | |  \__ \ |_) | (_| | | (_) | (_| |
# |_|  |_|  |___/ .__/ \__,_|_|\___/ \__, | zhengrr
#               | |                   __/ | 2018-08-04 – 2020-06-17
#               |_|                  |___/  Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

rr_project(
  rrspdlog
  TIME_AS_VERSION
  LANGUAGES CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

include_conan_script()
conan_cmake_run(
  REQUIRES    boost/1.73.0
              gtest/1.10.0
              spdlog/1.6.1
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

find_package(rrspdlog CONFIG HINTS "${PRODUCT_SOURCE_DIR}/include/rrspdlog")

aux_source_directory_con("." zTest RECURSE)
add_executable_con(
  rrspdlogTest        ${zTest}
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE rrspdlog
                              CONAN_PKG::gtest
                              CONAN_PKG::boost
                              $<$<PLATFORM_ID:Linux>:dl>
                              $<$<PLATFORM_ID:Linux>:stdc++fs>)

add_test(NAME rrspdlogTest COMMAND rrspdlogTest)
