//===------------------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 一个小玩意儿，提供简单的 TCP 服务
/// \sa <https://boost.org/doc/libs/master/doc/html/boost_asio.html>
/// \sa <https://boost.org/doc/libs/master/doc/html/program_options.html>
///
/// \version 2019-11-07
/// \since 2018-04-02
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <iostream>
#include <locale>

#include <boost/asio.hpp>

#include <rrspdlog.hxx>

#include "appopts.hpp"
#include "tcp_server.hpp"

using namespace std;
using boost::asio::ip::tcp;

constexpr char figlet_logo[]{
    R"(           _____ _    _       _____ _                     )" "\n"
    R"(          /  ___| |  | |     |  __ (_)                    )" "\n"
    R"( _ __ _ __\ `--.| | _| |_ ___| |  \/_ _____ __ ___   ___  )" "\n"
    R"(| '__| '__|`--. \ |/ / __/ __| | __| |_  / '_ ` _ \ / _ \ )" "\n"
    R"(| |  | |  /\__/ /   <| |_\__ \ |_\ \ |/ /| | | | | | (_) |)" "\n"
    R"(|_|  |_|  \____/|_|\_\\__|___/\____/_/___|_| |_| |_|\___/ )" "\n" };

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) noexcept
{
    const appopts opts = [&]() noexcept -> appopts {
        try {
            return appopts{ argc, argv };
        } catch (const exception &e) {
            cerr << "Fatal error, parse configurations failed: " << e.what() << '\n';
            cerr << "The program will be closed.";
            exit(EXIT_FAILURE);
        } catch (...) {
            cerr << "Fatal error, parse configurations failed with non-standard exception.\n";
            cerr << "The program will be closed.";
            exit(EXIT_FAILURE);
        }
    }();

    try {
        rrspdlog::initialize_as_default(opts->logs_directory.c_str());
    } catch (const exception &e) {
        cerr << "Fatal error, initialize logger failed: " << e.what() << '\n';
        cerr << "The program will be closed.";
        return EXIT_FAILURE;
    } catch (...) {
        cerr << "Fatal error, initialize logger failed with non-standard exception.\n";
        cerr << "The program will be closed.";
        return EXIT_FAILURE;
    }

    try {
        locale::global(locale{ "C.UTF-8" });

        if (opts->debug) {
            opts.print_options(cout);
#ifndef NDEBUG
            opts.launch_debugger();
#endif
        }

        if (opts->help) {
            cout << figlet_logo;
            opts.print_help(cout);
            return EXIT_SUCCESS;
        }

        if (opts->version) {
            cout << "version 1.3.3.7\n";
            return EXIT_SUCCESS;
        }

        boost::asio::io_context io_context;
        tcp_server server{ io_context, opts->export_port };
        io_context.run();

        return EXIT_SUCCESS;

    } catch (const exception &e) {
        SPDLOG_CRITICAL("Caught standard exception in main function: {}", e.what());
        return EXIT_FAILURE;

    } catch (...) {
        SPDLOG_CRITICAL("Caught non-standard exception in main function");
        return EXIT_FAILURE;

    }
}
