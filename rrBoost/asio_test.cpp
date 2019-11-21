//===-- Asio ----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Asio
/// \details Portable networking and other low-level I/O, including sockets, timers, hostname resolution, socket iostreams, serial ports, file descriptors and Windows HANDLEs.
/// \details 可移植的网络和其他底层 I/O，包括套接字、计时器、主机名解析、套接字 I/O 流、串行端口、文件描述符和 Windows 句柄。
///
/// \sa <https://boost.org/doc/libs/master/libs/asio/>
/// \sa [Boost.Asio C++ 网络编程](https://mmoaay.gitbooks.io/boost-asio-cpp-network-programming-chinese/)
///
/// \version 2019-11-09
/// \since 2019-01-08
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <boost/array.hpp>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996)
#endif
#include <boost/asio.hpp>
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#include <boost/bind.hpp>
#include <gtest/gtest.h>

using namespace std;

template <typename T>
void tag(const T &label) noexcept
{
    const auto now = chrono::steady_clock::now();
    const auto since_epoch_mss = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch());

    cout << "[" << since_epoch_mss.count() << "ms] " << label << "\n";
}

namespace rrboost {

TEST(asio, wait)
{
    using namespace chrono_literals;

    boost::asio::io_context io;

    boost::asio::steady_timer timer(io, 10ms);
    tag("waiting...");

#if 1  // exception style
    try {
        timer.wait();
    } catch (const boost::system::system_error &e) {
        cerr << e.what() << endl;
    }
#else  // error code style
    boost::system::error_code ec;
    timer.wait(ec);
    if (ec)
        cerr << system_error(ec).what() << endl;
#endif
    tag("timeout.");
}

TEST(asio, async_wait)
{
    using namespace chrono_literals;

    boost::asio::io_context io;

    const auto now {chrono::steady_clock::now()};
    boost::asio::steady_timer timer1(io, now + 10ms);
    timer1.async_wait([](const boost::system::error_code &/*e*/) {
        tag("timer1 timeout and callback.");
    });
    boost::asio::steady_timer timer2(io, now + 20ms);
    timer2.async_wait([](const boost::system::error_code &/*e*/) {
        tag("timer2 timeout and callback.");
    });
    tag("waiting...");

    io.run();
    tag("io run return.");
}

TEST(asio, async_wait_arg)
{
    using namespace chrono_literals;

    const auto callback {[](const boost::system::error_code &/*e*/, const string &arg) -> void {
        tag(arg);
    }};

    boost::asio::io_context io;

    boost::asio::steady_timer timer(io, 10ms);
    timer.async_wait(boost::bind<void>(callback, boost::asio::placeholders::error, "Aoi Shigure"));

    io.run();
}

TEST(asio, tcp)
{
    namespace asio = boost::asio;
    using asio::ip::address;
    using asio::ip::tcp;

    thread server([] {
        try {
            asio::io_context io;

            tcp::endpoint listening_ep(tcp::v4(), 49152);
            tcp::acceptor acceptor(io, listening_ep);

            while (true) {
                tcp::socket socket(io);
                acceptor.accept(socket);

                // read from client
                array<char, 1024> buf;
                const auto len = socket.read_some(asio::buffer(buf));
                cout.write(buf.data(), len) << "\n";

                // write to client
                socket.write_some(asio::buffer("TCP server: Hello, TCP client."));

                // disconnect
                break;
            }

        } catch (const exception &e) {
            cerr << "TCP server: " << e.what() << endl;

        }
    });

    thread client([] {
        try {
            asio::io_context io;

#if 1  // ip address
            const tcp::endpoint server_ep(address::from_string("127.0.0.1"), 49152);

            tcp::socket socket(io);
            socket.connect(server_ep);
#else  // domain name
            tcp::resolver resolver(io);
            const auto server_eps {resolver.resolve("localhost", "49152")};

            tcp::socket socket(io);
            asio::connect(socket, server_eps);
#endif
            // write to server
            socket.write_some(asio::buffer("TCP client: Hello, TCP server."));

            // read from server
            array<char, 1024> buf;
            while (true) {
                try {
                    const auto len = socket.read_some(asio::buffer(buf));
                    cout.write(buf.data(), len);
                } catch (const boost::system::system_error &e) {
                    if (e.code() == asio::error::eof)
                        break;
                    throw;
                }
            }
            cout << "\n";

        } catch (const exception &e) {
            cerr << "TCP client: " << e.what() << endl;

        }
    });

    server.join();
    client.join();
}

TEST(asio, udp)
{
    namespace asio = boost::asio;
    using asio::ip::address;
    using asio::ip::udp;

    thread server([] {
        try {
            asio::io_context io;

            udp::endpoint listening_ep(udp::v4(), 49152);
            udp::socket socket(io, listening_ep);

            array<char, 65535> buf;
            while (true) {
                udp::endpoint remote_ep;
                const auto len = socket.receive_from(asio::buffer(buf), remote_ep);
                cout.write(buf.data(), len) << "\n";

                socket.send_to(asio::buffer("UDP server: Hello, UDP client."), remote_ep);
                break;
            }

        } catch (const exception &e) {
            cerr << "UDP server: " << e.what() << endl;

        }
    });

    thread client([] {
        try {
            asio::io_context io;

            udp::socket socket(io);
            socket.open(udp::v4());

            const udp::endpoint server_receiver_ep(address::from_string("127.0.0.1"), 49152);
            socket.send_to(asio::buffer("UDP client: Hello, UDP server."), server_receiver_ep);

            array<char, 65535> buf;
            udp::endpoint server_sender_ep;
            const auto len = socket.receive_from(asio::buffer(buf), server_sender_ep);
            cout.write(buf.data(), len) << "\n";

        } catch (const exception &e) {
            cerr << "UDP client: " << e.what() << endl;

        }
    });

    server.join();
    client.join();
}

}
