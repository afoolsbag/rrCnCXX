/// \copyright Unlicense

#pragma once
#ifndef TCP_SERVER_HPP_
#define TCP_SERVER_HPP_

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
    /// \brief 异步接受下一个连接
    void async_accept();

    /// \brief 异步接受到连接时的回调
    /// \param conn_ptr 连接共享指针（connection pointer）
    /// \param err      错误码（error code）
    void on_accepted(tcp_connection::ptr conn_ptr, const boost::system::error_code &err) noexcept;

    boost::asio::io_context &io_context_;
    boost::asio::ip::tcp::acceptor acceptor_;
};

#endif
