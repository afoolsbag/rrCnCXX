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
    SPDLOG_INFO("The service starts listening port {}.", port);
    start_accept();
}

void tcp_server::start_accept()
{
    auto connection_container = tcp_connection::create(io_context_);
    acceptor_.async_accept(
        connection_container->socket(),
        boost::bind(&tcp_server::handle_accept, this, connection_container, boost::asio::placeholders::error));
}

void tcp_server::handle_accept(boost::shared_ptr<tcp_connection> connection, const boost::system::error_code &error)
{
    if (!error)
        connection->start();
    start_accept();
}
