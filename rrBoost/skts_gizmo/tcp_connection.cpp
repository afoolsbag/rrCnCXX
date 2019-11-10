/// \copyright Unlicense

#include "tcp_connection.hpp"

#include <boost/bind.hpp>

#include <rrspdlog.hxx>

using namespace std;
using boost::asio::ip::tcp;

tcp_connection::ptr tcp_connection::create(boost::asio::io_context &io_context)
{
    return ptr{ new tcp_connection{ io_context } };
}

tcp::socket &tcp_connection::socket()
{
    return socket_;
}

void tcp_connection::start()
{
    remote_address_ = socket_.remote_endpoint().address().to_string();
    remote_port_ = socket_.remote_endpoint().port();
    SPDLOG_INFO("New connect from {}:{}.", remote_address_, remote_port_);
    async_receive();
}

tcp_connection::~tcp_connection() noexcept
{
    if (!remote_address_.empty()) {
        assert(remote_port_ != 0);
        SPDLOG_INFO("Disconnect with {}:{}.", remote_address_, remote_port_);
    }
}

tcp_connection::tcp_connection(boost::asio::io_context &io_context) :
    socket_{ io_context }
{}

void tcp_connection::async_receive()
{
    auto req_ptr = boost::make_shared<boost::asio::streambuf>();
    boost::asio::async_read_until(
        socket_,
        *req_ptr,
        '\0',
        boost::bind(&tcp_connection::on_received, shared_from_this(), req_ptr, boost::asio::placeholders::error));
}

void tcp_connection::on_received(streambuf_ptr req_ptr, const boost::system::error_code &err) noexcept
{
    try {
        if (!err) {
            const string request_message{ istreambuf_iterator<char>{req_ptr.get()}, istreambuf_iterator<char>{} };
            SPDLOG_DEBUG("New request by {}:{}: {}", remote_address_, remote_port_, request_message);
            async_send("hello, world");
            async_receive();
        } else {
            SPDLOG_INFO("Callback {} was invoked with error {}.", __func__, err.message());
        }

    } catch (const exception &e) {
        SPDLOG_WARN("Caught standard exception in {} callback: {}.", __func__, e.what());

    } catch (...) {
        SPDLOG_WARN("Caught non-standard exception in {} callback.", __func__);
    }
}

void tcp_connection::async_send(const string &res)
{
    auto res_ptr = boost::make_shared<string>(res);
    boost::asio::async_write(
        socket_,
        boost::asio::buffer(*res_ptr),
        boost::bind(&tcp_connection::on_sended, shared_from_this(), res_ptr, boost::asio::placeholders::error));
}

void tcp_connection::on_sended(string_ptr res_ptr, const boost::system::error_code &err) noexcept
{
    try {
        if (!err) {
            (void)res_ptr;
        } else {
            SPDLOG_INFO("Callback {} was invoked with error {}.", __func__, err.message());
        }

    } catch (const exception &e) {
        SPDLOG_WARN("Caught standard exception in {} callback: {}.", __func__, e.what());

    } catch (...) {
        SPDLOG_WARN("Caught non-standard exception in {} callback.", __func__);
    }
}
