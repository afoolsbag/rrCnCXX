/// \copyright Unlicense

#pragma once
#ifndef TCP_CONNECTION_HPP_
#define TCP_CONNECTION_HPP_

#include <string>

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

class tcp_connection : public boost::enable_shared_from_this<tcp_connection> {
public:
    static boost::shared_ptr<tcp_connection> create(boost::asio::io_context &io_context);

    boost::asio::ip::tcp::socket &socket();

    void start();

    virtual ~tcp_connection() noexcept;

private:
    explicit tcp_connection(boost::asio::io_context &io_context);

    /// \biref 等待接受下一个请求
    void start_receive_request();

    /// \brief 处理接受到的请求
    void handle_receive(boost::shared_ptr<boost::asio::streambuf> request, const boost::system::error_code &error) noexcept;
public:
    /// \biref 等待发送下一个回应
    inline void start_send_response(const std::string &response);
private:
    /// \biref 处理发送出的回应
    void handle_send(boost::shared_ptr<std::string> response, const boost::system::error_code &error) noexcept;

    boost::asio::ip::tcp::socket socket_;
    std::string remote_address_;
    std::uint16_t remote_port_ {};
};

#endif
