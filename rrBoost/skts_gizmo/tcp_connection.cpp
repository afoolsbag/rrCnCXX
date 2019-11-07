/// \copyright Unlicense
///
#include "tcp_connection.hpp"

#include <boost/bind.hpp>
#include <boost/system/system_error.hpp>
#include <boost/smart_ptr.hpp>

#include <rrspdlog.hxx>

using namespace std;
using boost::asio::ip::tcp;

boost::shared_ptr<tcp_connection> tcp_connection::create(boost::asio::io_context &io_context)
{
    return boost::shared_ptr<tcp_connection>{new tcp_connection{ io_context }};
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
    start_receive_request();
}

tcp_connection::~tcp_connection() noexcept
{
    SPDLOG_INFO("Disconnect with {}:{}.", remote_address_, remote_port_);
}

tcp_connection::tcp_connection(boost::asio::io_context &io_context) :
    socket_{ io_context }
{}

void tcp_connection::start_receive_request()
{
    auto request_buffer = boost::make_shared<boost::asio::streambuf>();
    boost::asio::async_read_until(
        socket_,
        *request_buffer,
        '\0',
        boost::bind(&tcp_connection::handle_receive, shared_from_this(), request_buffer, boost::asio::placeholders::error));
}

void tcp_connection::handle_receive(boost::shared_ptr<boost::asio::streambuf> request, const boost::system::error_code &error) noexcept
{
    try {
        if (!error) {
            const string request_message{ istreambuf_iterator<char>{&*request}, istreambuf_iterator<char>{} };
            SPDLOG_DEBUG("New request by {}:{}: {}", remote_address_, remote_port_, request_message);
            start_send_response("hello");
            start_receive_request();
        } else {
            throw boost::system::system_error{ error };
        }

    } catch (const exception &e) {
        SPDLOG_WARN("Caught standard exception in {} function: {}", __func__, e.what());

    } catch (...) {
        SPDLOG_WARN("Caught non-standard exception in {}} function.", __func__);
    }
}

void tcp_connection::start_send_response(const string &response)
{
    auto response_buffer = boost::make_shared<string>(response);
    boost::asio::async_write(
        socket_,
        boost::asio::buffer(*response_buffer),
        boost::bind(&tcp_connection::handle_send, shared_from_this(), response_buffer, boost::asio::placeholders::error));
}

void tcp_connection::handle_send(boost::shared_ptr<string> response, const boost::system::error_code &error) noexcept
{
    try {
        if (!error) {
            (void)response;
        } else {
            throw boost::system::system_error{ error };
        }

    } catch (const exception &e) {
        SPDLOG_WARN("Caught standard exception in {} function: {}", __func__, e.what());

    } catch (...) {
        SPDLOG_WARN("Caught non-standard exception in {} function.", __func__);
    }
}
