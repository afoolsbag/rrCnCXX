//===-- Debug Client --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Debug Client
///
/// \version 2019-04-23
/// \since 2019-04-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS

#include <iostream>
#include <string>

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

using namespace std;

class client {
public:
    using endpoint = websocketpp::client<websocketpp::config::asio_client>;

    explicit client()
    {
        using namespace placeholders;

        ep_.clear_access_channels(websocketpp::log::alevel::all);
        ep_.set_error_channels(websocketpp::log::elevel::all);

        ep_.init_asio();

        ep_.set_socket_init_handler(bind(&client::on_socket_init, this, _1));
        ep_.set_open_handler(bind(&client::on_open, this, _1));
        ep_.set_message_handler(bind(&client::on_message, this, _1, _2));
        ep_.set_close_handler(bind(&client::on_close, this, _1));
        ep_.set_fail_handler(bind(&client::on_fail, this, _1));
    }

    void start(const string &uri = "ws://localhost:9012")
    {
        error_code ec;
        const auto con = ep_.get_connection(uri, ec);
        if (ec)
            throw system_error(ec);

        ep_.connect(con);

        ep_.run();
    }

private:
    void on_socket_init(websocketpp::connection_hdl hdl)
    {}

    void on_open(websocketpp::connection_hdl hdl)
    {
        ep_.send(hdl, "hello server", websocketpp::frame::opcode::text);
    }

    void on_message(websocketpp::connection_hdl hdl, endpoint::message_ptr msg)
    {
        cout << "Received message: " << msg->get_payload() << endl;
    }

    void on_close(websocketpp::connection_hdl hdl)
    {}

    void on_fail(websocketpp::connection_hdl hdl)
    {
        const auto con = ep_.get_con_from_hdl(hdl);

        cerr << "Fail handler" << '\n'
            << con->get_state() << '\n'
            << con->get_local_close_code() << ": " << con->get_local_close_reason() << '\n'
            << con->get_remote_close_code() << ": " << con->get_remote_close_reason() << '\n'
            << con->get_ec() << ": " << con->get_ec().message() << endl;
    }

    endpoint ep_;
};

int main()
{
    try {
        client clt;
        clt.start();

    } catch (const websocketpp::exception &e) {
        cerr << e.what() << endl;

    } catch (const exception &e) {
        cerr << e.what() << endl;

    } catch (...) {
        cerr << "Other exception" << endl;

    }
}
