//===-- Asio --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Asio
/// \sa <https://boost.org/doc/libs/1_69_0/doc/html/boost_asio.html>
///
/// \version 2019-01-09
/// \since 2019-01-08
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma warning(push)
#pragma warning(disable: 4996)

#include <iostream>

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <gtest/gtest.h>
#include <boost/thread/xtime.hpp>

using namespace std;

#pragma warning(pop)

namespace rrboost::test {

/// cout (with) leader milliseconds
static inline ostream &coutlms()
{
    return cout
        << "At "
        << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count()
        << "ms, ";
}

TEST(asio, wait)
{
    using namespace chrono_literals;

    boost::asio::io_context ioctx;

    coutlms() << "before the timer construction.\n";
    boost::asio::steady_timer timer(ioctx, 10ms);
    timer.wait();
    coutlms() << "after the timer.wait.\n";
}

/// 异步 Asio 使用硬件中断实现回调，除回调线程外，不阻塞其他线程。
TEST(asio, async_wait)
{
    using namespace chrono_literals;

    boost::asio::io_context ioctx;

    coutlms() << "before the timer construction.\n";
    boost::asio::steady_timer timer(ioctx, chrono::steady_clock::now() + 10ms);
    timer.async_wait([](const boost::system::error_code &/*e*/) {
        coutlms() << "in the timer callback.\n";
    });
    coutlms() << "after the timer.async_wait.\n";

    ioctx.run();
    coutlms() << "after the ioctx.run.\n";
}

TEST(asio, async_wait_with_arg)
{
    using namespace chrono_literals;

    const auto callback {[](const boost::system::error_code &/*e*/, const string &arg) -> void {
        cout << "Time out with \"" << arg << "\" from async_wait_with_arg callback.\n";
    }};

    boost::asio::io_context ioctx;

    boost::asio::steady_timer timer(ioctx, 10ms);
    timer.async_wait(boost::bind<void>(callback, boost::asio::placeholders::error, "aoishigure"));

    ioctx.run();
}

TEST(asio, tcp)
{
    thread server([] {
        try {
            boost::asio::io_context io;

            boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 49152);
            boost::asio::ip::tcp::acceptor acceptor(io, endpoint);

            while (true) {
                boost::asio::ip::tcp::socket socket(io);
                acceptor.accept(socket);

                string message = "Message from tcp server.";

                boost::asio::write(socket, boost::asio::buffer(message));
                break;
            }

        } catch (const exception &e) {
            cerr << "tcp server: " << e.what() << endl;

        }
    });

    thread client([] {
        try {
            boost::asio::io_context ioctx;
            
            boost::asio::ip::tcp::resolver resolver(ioctx);
            const auto server_eps {resolver.resolve("127.0.0.1", "49152")};

            boost::asio::ip::tcp::socket socket(ioctx);
            boost::asio::connect(socket, server_eps);

            array<char, 128> buf;
            while (true) {
                boost::system::error_code ec;
                const size_t len = socket.read_some(boost::asio::buffer(buf), ec);

                if (ec == boost::asio::error::eof)
                    break;
                if (ec)
                    throw system_error(ec);

                cout.write(buf.data(), len) << endl;
            }

        } catch (const exception &e) {
            cerr << "tcp client: " << e.what() << endl;

        }
    });

    server.join();
    client.join();
}

TEST(asio, udp)
{
    thread server([] {
        try {
            boost::asio::io_context ioctx;

            boost::asio::ip::udp::endpoint listening_ep(boost::asio::ip::udp::v4(), 49152);
            boost::asio::ip::udp::socket socket(ioctx, listening_ep);

            array<char, 128> buf;
            while (true) {

                boost::system::error_code ec;
                boost::asio::ip::udp::endpoint remote_ep;
                const size_t len = socket.receive_from(boost::asio::buffer(buf), remote_ep);

                if (ec == boost::asio::error::eof)
                    break;
                if (ec)
                    throw system_error(ec);

                cout.write(buf.data(), len) << endl;

                const string msg {"Message from udp server."};
                socket.send_to(boost::asio::buffer(msg), remote_ep);

                break;
            }

        } catch (const exception &e) {
            cerr << e.what() << endl;

        }
    });

    thread client([] {
        try {
            boost::asio::io_context io;

            boost::asio::ip::udp::resolver resolver(io);
            const auto server_eps = resolver.resolve("127.0.0.1", "49152");

            boost::asio::ip::udp::socket socket(io);
            socket.open(boost::asio::ip::udp::v4());

            const string msg{"Message from udp client."};
            socket.send_to(boost::asio::buffer(msg), *server_eps.begin());

            boost::array<char, 128> buf;
            boost::asio::ip::udp::endpoint sender_ep;
            size_t len = socket.receive_from(boost::asio::buffer(buf), sender_ep);
            cout.write(buf.data(), len) << endl;

        } catch (const exception &e) {
            cerr << e.what() << endl;

        }
    });

    server.join();
    client.join();
}

}//namespace rrboost::test
