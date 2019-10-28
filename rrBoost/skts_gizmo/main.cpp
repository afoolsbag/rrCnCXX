//===------------------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 一个小玩意儿，用于展示套接字
/// \sa <https://boost.org/doc/libs/master/doc/html/boost_asio.html>
///
/// \version 2019-10-28
/// \since 2019-10-28
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#include <cstdlib>
#include <iostream>
#include <locale>

#include <boost/asio.hpp>

using namespace std;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) noexcept
{
    using tcp = boost::asio::ip::tcp;
    constexpr uint16_t port {49152};

    try {
        locale::global(locale {".UTF-8"});

        boost::asio::io_context io;

        tcp::endpoint listening_ep {tcp::v4(), port};
        tcp::acceptor acceptor {io, listening_ep};

        cout << "Listening port " << port << "..." << endl;

        array<char, 65535> buf {};
        while (true) {
            // 等待连接
            tcp::socket socket {io};
            acceptor.accept(socket);
            cout << '\n';
            cout << "New connection from " << socket.remote_endpoint().address() << ':' << socket.remote_endpoint().port() << " and data:\n";

            // 接受数据
            const auto len = socket.read_some(boost::asio::buffer(buf));
            cout.write(buf.data(), len) << "\n";

            // 发送数据
            socket.write_some(boost::asio::buffer(buf));

            // 断开连接
        }

        return EXIT_SUCCESS;

    } catch (const exception &e) {
        cerr << "Fatal error, caught standard exception in main function: " << e.what() << '\n';
        cerr << "The program exit.\n";
        return EXIT_FAILURE;

    } catch (...) {
        cerr << "Fatal error, caught non-standard exception in main function\n";
        cerr << "The program exit.\n";
        return EXIT_FAILURE;

    }
}
