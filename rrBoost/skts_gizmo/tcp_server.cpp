/// \copyright Unlicense

#include "tcp_server.hpp"

#include <boost/bind.hpp>

#include <rrspdlog.hxx>

using namespace std;
using boost::asio::ip::tcp;

tcp_server::tcp_server(boost::asio::io_context &io_context, uint16_t port) :
    io_context_{ io_context },
    acceptor_{ io_context, tcp::endpoint{ tcp::v4(), port } }
{
    SPDLOG_INFO("The server start listening on port {}.", port);
    async_accept();
}

void tcp_server::async_accept()
{
    auto connection_container = tcp_connection::create(io_context_);
    acceptor_.async_accept(
        connection_container->socket(),
        boost::bind(&tcp_server::on_accepted, this, connection_container, boost::asio::placeholders::error));
}

void tcp_server::on_accepted(tcp_connection::ptr conn_ptr, const boost::system::error_code &err) noexcept
{
    try {
        if (!err) {
            conn_ptr->start();
        } else {
            SPDLOG_INFO("Callback {} was invoked with error {}.", __func__, err.message());
        }
        async_accept();

    } catch (const exception &e) {
        SPDLOG_WARN("Caught standard exception in {} callback: {}.", __func__, e.what());

    } catch (...) {
        SPDLOG_WARN("Caught non-standard exception in {} callback.", __func__);
    }

}
