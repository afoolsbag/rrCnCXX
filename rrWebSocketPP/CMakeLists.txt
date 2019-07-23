#            _    _      _     _____            _        _  ____________
#           | |  | |    | |   /  ___|          | |      | | | ___ \ ___ \
#  _ __ _ __| |  | | ___| |__ \ `--.  ___   ___| | _____| |_| |_/ / |_/ /
# | '__| '__| |/\| |/ _ \ '_ \ `--. \/ _ \ / __| |/ / _ \ __|  __/|  __/
# | |  | |  \  /\  /  __/ |_) /\__/ / (_) | (__|   <  __/ |_| |   | |
# |_|  |_|   \/  \/ \___|_.__/\____/ \___/ \___|_|\_\___|\__\_|   \_|
# zhengrr
# 2019-04-22 – 2019-07-23
# Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

string(TIMESTAMP sYear       "%Y")
string(TIMESTAMP sMonth      "%m")
string(TIMESTAMP sDay        "%d")
string(TIMESTAMP sHourMinute "%H%M")

project_ex(
  rrWebSocketPP
  VERSION   ${sYear}.${sMonth}.${sDay}.${sHourMinute}
  LANGUAGES CXX)

include_conan_script()

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8
  VISIBLE_DEFAULT_HIDDEN
  WARNING_AS_ERROR)

add_doxygen_con(
  rrWebSocketPPdoc)

find_package(WebSocketPP)
conan_cmake_run(
  REQUIRES    asio/1.12.2@bincrafters/stable
              gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS
  BUILD       missing)

aux_source_directory_con("." zTest)
add_executable_con(
  rrWebSocketPPTest   ${zTest}
  PROPERTIES          CXX_STANDARD          20
                      CXX_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PRIVATE _WEBSOCKETPP_CPP11_STL_
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE CONAN_PKG::asio
                              CONAN_PKG::gtest
                              WebSocketPP::websocketpp)

add_test(NAME rrWebSocketPPTest COMMAND rrWebSocketPPTest)
