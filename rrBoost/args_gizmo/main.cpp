//===------------------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 一个小玩意儿，用于展示通过命令行、配置文件或环境变量对程序进行配置
/// \sa <https://boost.org/doc/libs/1_70_0/doc/html/program_options.html>
///
/// \version 2019-08-15
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

int main(int argc, char *argv[]) noexcept
{
    try {
        locale::global(locale {".UTF-8"});

        const rrargsgizmo::appopts opts {argc, argv};

        if (opts->help) {
            opts.print_help(cout);
            return EXIT_SUCCESS;
        }

        if (opts->version) {
            cout << "version 1.3.3.7\n";
            return EXIT_SUCCESS;
        }

        if (opts->debug)
            opts.print_options(cout);

        return EXIT_SUCCESS;

    } catch (const exception &e) {
        cerr << "无法恢复的错误，在主函数中捕获异常：" << e.what() << "\n"
            "程序即将退出。\n";
        return EXIT_FAILURE;

    } catch (...) {
        cerr << "无法恢复的错误，在主函数中捕获非标准异常，程序即将退出。\n";
        return EXIT_FAILURE;

    }
}
