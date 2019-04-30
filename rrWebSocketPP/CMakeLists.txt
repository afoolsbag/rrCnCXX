#            _    _      _     _____            _        _  ____________
#           | |  | |    | |   /  ___|          | |      | | | ___ \ ___ \
#  _ __ _ __| |  | | ___| |__ \ `--.  ___   ___| | _____| |_| |_/ / |_/ /
# | '__| '__| |/\| |/ _ \ '_ \ `--. \/ _ \ / __| |/ / _ \ __|  __/|  __/
# | |  | |  \  /\  /  __/ |_) /\__/ / (_) | (__|   <  __/ |_| |   | |
# |_|  |_|   \/  \/ \___|_.__/\____/ \___/ \___|_|\_\___|\__\_|   \_|
# zhengrr
# 2019-04-22 – 2019-04-21
# Unlicense

cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project_ex(
  rrWebSocketPP
  VERSION   2019.04.23
  LANGUAGES CXX)

add_compile_options_ex(
  RECOMMENDED_WARNING_LEVEL
  MULTIPLE_PROCESSES
  UTF-8)

add_doxygen_con(
  rrWebSocketPPdoc)

find_package(WebSocketPP)
conan_cmake_run(
  REQUIRES    asio/1.12.0@bincrafters/stable
              gtest/1.8.1@bincrafters/stable
  BASIC_SETUP CMAKE_TARGETS)

add_executable_con(
  rrWsDbgSvr          "debug_server.cpp"
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PRIVATE _WEBSOCKETPP_CPP11_STL_
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE CONAN_PKG::asio
                              WebSocketPP::websocketpp)

add_executable_con(
  rrWsDgbClt          "debug_client.cpp"
  PROPERTIES          CXX_STANDARD          17
                      CXX_STANDARD_REQUIRED ON
  COMPILE_DEFINITIONS PRIVATE _WEBSOCKETPP_CPP11_STL_
  INCLUDE_DIRECTORIES PRIVATE "."
  LINK_LIBRARIES      PRIVATE CONAN_PKG::asio
                              WebSocketPP::websocketpp)