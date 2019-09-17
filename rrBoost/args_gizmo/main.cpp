//===------------------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 一个小玩意儿，用于展示通过命令行、配置文件或环境变量对程序进行配置
/// \sa <https://boost.org/doc/libs/master/doc/html/program_options.html>
///
/// \version 2019-09-17
/// \since 2018-04-02
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>
#include <locale>

#include "appopts.hpp"

using namespace std;

constexpr char figlet_logo[] {
    R"(            ___                _____ _                     )" "\n"
    R"(           / _ \              |  __ (_)                    )" "\n"
    R"( _ __ _ __/ /_\ \_ __ __ _ ___| |  \/_ _____ __ ___   ___  )" "\n"
    R"(| '__| '__|  _  | '__/ _` / __| | __| |_  / '_ ` _ \ / _ \ )" "\n"
    R"(| |  | |  | | | | | | (_| \__ \ |_\ \ |/ /| | | | | | (_) |)" "\n"
    R"(|_|  |_|  \_| |_/_|  \__, |___/\____/_/___|_| |_| |_|\___/ )" "\n"
    R"(                      __/ |                                )" "\n"
    R"(                     |___/                                 )" "\n"};

int main(int argc, char *argv[]) noexcept
{
    try {
        locale::global(locale {".UTF-8"});

        const appopts opts {argc, argv};

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
