set(CMAKE_INCLUDE_CURRENT_DIR ON)

facile_add_executable(SUBNAME "TcpClient"
  "tcp_client.c")

facile_add_executable(SUBNAME "TcpServer"
  "tcp_server.c")

facile_add_executable(SUBNAME "UdpClient"
  "udp_client.c")

facile_add_executable(SUBNAME "UdpServer"
  "udp_server.c")
