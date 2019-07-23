/// \copyright Unlicense

#include <system_error>

#include "client.hpp"

using namespace std;

namespace rrwebsocketpp {

client::client()
{
    using websocketpp::lib::placeholders::_1;
    using websocketpp::lib::placeholders::_2;
    using websocketpp::lib::bind;

    // 设定日志配置
    ep_.clear_access_channels(websocketpp::log::alevel::all);
    ep_.set_error_channels(websocketpp::log::elevel::all);

    // 初始化 ASIO
    ep_.init_asio();

    // 注册回调
    ep_.set_socket_init_handler(bind(&client::on_socket_init, this, _1));
    //ep_.set_tls_init_handler(bind(&client::on_tls_init, this, _1));
    ep_.set_open_handler(bind(&client::on_open, this, _1));
    ep_.set_close_handler(bind(&client::on_close, this, _1));
    ep_.set_fail_handler(bind(&client::on_fail, this, _1));
    ep_.set_ping_handler(bind(&client::on_ping, this, _1, _2));
    ep_.set_pong_handler(bind(&client::on_pong, this, _1, _2));
    ep_.set_pong_timeout_handler(bind(&client::on_pong_timeout, this, _1, _2));
    ep_.set_interrupt_handler(bind(&client::on_interrupt, this, _1));
    ep_.set_http_handler(bind(&client::on_http, this, _1));
    ep_.set_validate_handler(bind(&client::on_validate, this, _1));
    ep_.set_message_handler(bind(&client::on_message, this, _1, _2));
}

void client::start(const string &uri)
{
    error_code ec;
    const auto con = ep_.get_connection(uri, ec);
    if (ec)
        throw system_error(ec);

    ep_.connect(con);

    // 启动 ASIO io_service 运行循环
    ep_.run();
}

void client::on_socket_init([[maybe_unused]] websocketpp::connection_hdl hdl)
{}

void client::on_tls_init([[maybe_unused]] websocketpp::connection_hdl hdl)
{}

void client::on_open([[maybe_unused]] websocketpp::connection_hdl hdl)
{
    try {
        cout << "CLIENT> CONNECTED" << '\n'
            << "CLIENT> send \"hello, world\" ..." << endl;
        ep_.send(hdl, "hello, world", websocketpp::frame::opcode::text);
    } catch (const websocketpp::exception &e) {
        cerr << "CLIENT> send failed: " << e.what() << endl;
    }
}

void client::on_close([[maybe_unused]] websocketpp::connection_hdl hdl)
{}

void client::on_fail([[maybe_unused]] websocketpp::connection_hdl hdl)
{
    const auto con = ep_.get_con_from_hdl(hdl);

    cerr << "CLIENT> FAIL HANDLER" << '\n'
        << "CLIENT>" << con->get_state() << '\n'
        << "CLIENT>" << con->get_local_close_code() << ": " << con->get_local_close_reason() << '\n'
        << "CLIENT>" << con->get_remote_close_code() << ": " << con->get_remote_close_reason() << '\n'
        << "CLIENT>" << con->get_ec() << ": " << con->get_ec().message() << endl;
}

bool client::on_ping([[maybe_unused]] websocketpp::connection_hdl hdl, [[maybe_unused]] string payload)
{
    return true;
}

void client::on_pong([[maybe_unused]] websocketpp::connection_hdl hdl, [[maybe_unused]] string payload)
{}

void client::on_pong_timeout([[maybe_unused]] websocketpp::connection_hdl hdl, [[maybe_unused]] string payload)
{}

void client::on_interrupt([[maybe_unused]] websocketpp::connection_hdl hdl)
{}

void client::on_http([[maybe_unused]] websocketpp::connection_hdl hdl)
{}

bool client::on_validate([[maybe_unused]] websocketpp::connection_hdl hdl)
{
    return true;
}

void client::on_message([[maybe_unused]] websocketpp::connection_hdl hdl, [[maybe_unused]] endpoint::message_ptr msg)
{
    const auto con = ep_.get_con_from_hdl(hdl);

    cout << "CLIENT> NEW MESSAGE RECEIVED\n"
        << "CLIENT> from: " << con->get_remote_endpoint() << "\n"
        << "CLIENT> payload: " << msg->get_payload() << endl;

    ep_.stop();
}

}
