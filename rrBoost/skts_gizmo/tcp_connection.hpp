/// \copyright Unlicense

#pragma once
#ifndef TCP_CONNECTION_HPP_
#define TCP_CONNECTION_HPP_

#include <string>

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/smart_ptr.hpp>

class tcp_connection : public boost::enable_shared_from_this<tcp_connection> {
public:
    using ptr = boost::shared_ptr<tcp_connection>;
    using streambuf_ptr = boost::shared_ptr<boost::asio::streambuf>;
    using string_ptr = boost::shared_ptr<std::string>;

    static ptr create(boost::asio::io_context &io_context);

    boost::asio::ip::tcp::socket &socket();

    void start();

    virtual ~tcp_connection() noexcept;

private:
    explicit tcp_connection(boost::asio::io_context &io_context);

    /// \biref 异步接受下一个请求
    void async_receive();

    /// \brief 异步接受到请求时的回调
    /// \param req_ptr 请求报文共享指针（request pointer）
    /// \param err     错误码（error code）
    void on_received(streambuf_ptr req_ptr, const boost::system::error_code &err) noexcept;
public:
    /// \biref 异步发送下一个回应
    /// \param res 回应报文（response）
    inline void async_send(const std::string &res);
private:
    /// \biref 异步发送出回应时的回调
    /// \param res_ptr 回应报文共享指针（response pointer）
    /// \param err     错误码（error code）
    void on_sended(string_ptr res_ptr, const boost::system::error_code &err) noexcept;

    boost::asio::ip::tcp::socket socket_;
    std::string remote_address_;
    std::uint16_t remote_port_ {};
};

#endif
