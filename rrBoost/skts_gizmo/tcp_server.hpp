/// \copyright Unlicense

#pragma once
#ifndef TCP_SERVICE_HPP_
#define TCP_SERVICE_HPP_

#include <cstdint>
#include <boost/asio.hpp>

#include "tcp_connection.hpp"

/// \brief 传输控制协议（某端口的）伺服器
class tcp_server {
public:
    /// \biref 构造函数
    /// \details 初始化接收器，并监听端口
    explicit tcp_server(boost::asio::io_context &io_context, std::uint16_t port);

private:
    /// \brief 等待接受下一个连接
    void start_accept();

    /// \brief 处理接受到的连接
    void handle_accept(boost::shared_ptr<tcp_connection> new_connection, const boost::system::error_code &error);

    boost::asio::io_context &io_context_;
    boost::asio::ip::tcp::acceptor acceptor_;
};

#endif
