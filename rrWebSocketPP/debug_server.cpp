//===-- Echo Server ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Echo Server
///
/// \version 2019-04-23
/// \since 2019-04-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS

#include <iostream>

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

using namespace std;

class server {
public:
    using endpoint = websocketpp::server<websocketpp::config::asio>;

    explicit server()
    {
        using namespace placeholders;

        ep_.clear_access_channels(websocketpp::log::alevel::all);
        ep_.set_error_channels(websocketpp::log::elevel::all);

        ep_.init_asio();
        ep_.set_reuse_addr(true);

        ep_.set_open_handler(bind(&server::on_open, this, _1));
        ep_.set_message_handler(bind(&server::on_message, this, _1, _2));
        ep_.set_close_handler(bind(&server::on_close, this, _1));
        ep_.set_fail_handler(bind(&server::on_fail, this, _1));
    }

    void start(uint16_t port = 9012)
    {
        ep_.listen(port);
        ep_.start_accept();
        ep_.run();
    }

private:
    void on_socket_init(websocketpp::connection_hdl hdl)
    {}

    void on_open(websocketpp::connection_hdl hdl)
    {}

    void on_message(websocketpp::connection_hdl hdl, endpoint::message_ptr msg)
    {
        cout << "Received message: " << msg->get_payload() << endl;
        try {
            ep_.send(hdl, msg->get_payload(), msg->get_opcode());
        } catch (const websocketpp::exception &e) {
            cerr << "Echo failed: " << e.what() << endl;
        }
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
        server svr;
        svr.start();

    } catch (const websocketpp::exception &e) {
        cerr << e.what() << endl;

    } catch (const exception &e) {
        cerr << e.what() << endl;

    } catch (...) {
        cerr << "Other exception" << endl;

    }
}
