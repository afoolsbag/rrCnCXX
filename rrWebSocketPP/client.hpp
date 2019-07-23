//===-- Client --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Client
///
/// \version 2019-07-23
/// \since 2019-04-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRWEBSOCKETPP_CLIENT_HPP_
#define RRWEBSOCKETPP_CLIENT_HPP_

#include <string>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4127 4244)
#endif
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#ifdef _MSC_VER
#pragma warning(pop)
#endif

namespace rrwebsocketpp {

class client final {
public:
    using endpoint = websocketpp::client<websocketpp::config::asio_client>;

    explicit client();
    void start(const std::string &uri = "ws://localhost:9012");

protected:
    void on_socket_init(websocketpp::connection_hdl hdl);
    void on_tls_init(websocketpp::connection_hdl hdl);

    /// \brief WebSocket 连接成功回调
    /// \details 对于每一个 WebSocket 连接请求，都会触发 `on_open` 或 `on_fail` 其中之一。
    /// \param hdl 连接句柄
    void on_open(websocketpp::connection_hdl hdl);

    /// \brief WebSocket 连接关闭回调
    /// \details 对于每一个 WebSocket 连接，都会在其断开时调用 `on_close`。
    /// \param hdl 连接句柄
    void on_close(websocketpp::connection_hdl hdl);

    /// \brief WebSocket 连接失败回调
    /// \details 对于每一个 WebSocket 连接请求，都会触发 `on_open` 或 `on_fail` 其中之一。
    /// \param hdl 连接句柄
    void on_fail(websocketpp::connection_hdl hdl);

    /// \brief WebSocket 接收 Ping 控制帧回调
    /// \details 当从 WebSocket 连接中收到 Ping 控制帧时调用。
    /// \param hdl     连接句柄
    /// \param payload Ping 载荷，一块 126 字节的二进制数据。
    /// \returns `true`  发送此次 Pong 帧响应\n
    ///          `false` 抑制此次 Pong 帧响应
    bool on_ping(websocketpp::connection_hdl hdl, std::string payload);

    /// \brief WebSocket 接收 Pong 控制帧回调
    /// \details 当从 WebSocket 连接中收到 Pong 控制帧时调用。
    /// \param hdl     连接句柄
    /// \param payload Pong 载荷，一块 126 字节的二进制数据。
    void on_pong(websocketpp::connection_hdl hdl, std::string payload);

    /// \brief WebSocket 接收 Pong 控制帧超时回调
    /// \details 当向 WebSocket 连接中发送 Ping 控制帧后，超过指定时间还未收到 Pong 控制帧时调用。
    /// \param hdl     连接句柄
    /// \param payload Ping 载荷，一块 126 字节的二进制数据。
    void on_pong_timeout(websocketpp::connection_hdl hdl, std::string payload);

    /// \brief WebSocket 连接中断回调
    /// \details 当从 WebSocket 连接中收到中断请求时调用。
    /// \param hdl 连接句柄
    void on_interrupt(websocketpp::connection_hdl hdl);

    /// \brief 常规 HTTP 请求
    /// \details 一般用于返回静态资源，如仪表盘 HTTP 页面等。
    /// \param hdl 连接句柄
    /// \warning WebSocket++ 旨在实现高性能 WebSocket 服务而非 HTTP 服务，\n
    ///          其 HTTP 模块仅提供基础功能，未作调优，不适用于高并发环境。
    void on_http(websocketpp::connection_hdl hdl);

    /// \brief WebSocket 连接验证回调
    /// \details 当 WebSocket 连接握手后，在从 WebSocket 连接中接收消息前调用。
    /// \param hdl 连接句柄
    /// \returns `true`  接受此连接\n
    ///          `false` 拒绝此连接
    bool on_validate(websocketpp::connection_hdl hdl);

    /// \brief 消息处理回调
    /// \param hdl 连接句柄
    /// \param msg 消息指针
    void on_message(websocketpp::connection_hdl hdl, endpoint::message_ptr msg);

private:
    endpoint ep_;
};

}

#endif
