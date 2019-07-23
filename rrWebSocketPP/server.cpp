/// \copyright Unlicense

#ifdef _MSC_VER
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#endif

#include "server.hpp"

using namespace std;

namespace rrwebsocketpp {

server::server()
{
    using websocketpp::lib::placeholders::_1;
    using websocketpp::lib::placeholders::_2;
    using websocketpp::lib::bind;

    // 设定日志配置
    ep_.clear_access_channels(websocketpp::log::alevel::all);
    ep_.set_error_channels(websocketpp::log::elevel::all);

    // 初始化 ASIO
    ep_.init_asio();
    ep_.set_reuse_addr(true);

    // 注册回调
    ep_.set_socket_init_handler(bind(&server::on_socket_init, this, _1));
    //ep_.set_tls_init_handler(bind(&server::on_tls_init, this, _1));
    ep_.set_open_handler(bind(&server::on_open, this, _1));
    ep_.set_close_handler(bind(&server::on_close, this, _1));
    ep_.set_fail_handler(bind(&server::on_fail, this, _1));
    ep_.set_ping_handler(bind(&server::on_ping, this, _1, _2));
    ep_.set_pong_handler(bind(&server::on_pong, this, _1, _2));
    ep_.set_pong_timeout_handler(bind(&server::on_pong_timeout, this, _1, _2));
    ep_.set_interrupt_handler(bind(&server::on_interrupt, this, _1));
    ep_.set_http_handler(bind(&server::on_http, this, _1));
    ep_.set_validate_handler(bind(&server::on_validate, this, _1));
    ep_.set_message_handler(bind(&server::on_message, this, _1, _2));
}

void server::start(std::uint16_t port)
{
    // 监听端口
    ep_.listen(port);

    // 启动服务请求接收循环
    ep_.start_accept();

    // 启动 ASIO io_service 运行循环
    ep_.run();
}

void server::on_socket_init([[maybe_unused]] websocketpp::connection_hdl hdl)
{}

void server::on_tls_init([[maybe_unused]] websocketpp::connection_hdl hdl)
{}

void server::on_open([[maybe_unused]] websocketpp::connection_hdl hdl)
{}

void server::on_close([[maybe_unused]] websocketpp::connection_hdl hdl)
{}

void server::on_fail([[maybe_unused]] websocketpp::connection_hdl hdl)
{
    const auto con = ep_.get_con_from_hdl(hdl);

    cerr << "SERVER> FAIL HANDLER" << '\n'
        << "SERVER>" << con->get_state() << '\n'
        << "SERVER>" << con->get_local_close_code() << ": " << con->get_local_close_reason() << '\n'
        << "SERVER>" << con->get_remote_close_code() << ": " << con->get_remote_close_reason() << '\n'
        << "SERVER>" << con->get_ec() << ": " << con->get_ec().message() << endl;
}

bool server::on_ping([[maybe_unused]] websocketpp::connection_hdl hdl, [[maybe_unused]] string payload)
{
    return true;
}

void server::on_pong([[maybe_unused]] websocketpp::connection_hdl hdl, [[maybe_unused]] string payload)
{}

void server::on_pong_timeout([[maybe_unused]] websocketpp::connection_hdl hdl, [[maybe_unused]] string payload)
{}

void server::on_interrupt([[maybe_unused]] websocketpp::connection_hdl hdl)
{}

void server::on_http([[maybe_unused]] websocketpp::connection_hdl hdl)
{}

bool server::on_validate([[maybe_unused]] websocketpp::connection_hdl hdl)
{
    return true;
}

void server::on_message([[maybe_unused]] websocketpp::connection_hdl hdl, [[maybe_unused]] endpoint::message_ptr msg)
{
    const auto con = ep_.get_con_from_hdl(hdl);

    cout << "SERVER> NEW MESSAGE RECEIVED\n"
        << "SERVER> from: " << con->get_remote_endpoint() << "\n"
        << "SERVER> payload: " << msg->get_payload() << endl;

    try {
        cout << "SERVER> echo back..." << endl;
        ep_.send(hdl, msg->get_payload(), msg->get_opcode());
    } catch (const websocketpp::exception &e) {
        cerr << "SERVER> echo failed: " << e.what() << endl;
    }

    ep_.stop();
}

}
