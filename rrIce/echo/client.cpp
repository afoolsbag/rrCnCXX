//===-- Hello World Client --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Hello World 客户端。
///
/// \author zhengrr
/// \version 2018-10-13
/// \since 2017-12-13
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
using namespace std;

#include <Ice/Ice.h>
#include "service.h"

int main(int argc, char *argv[])
{
    system("CHCP 65001");

    try {
        // 通讯器
        const Ice::CommunicatorHolder ich(argc, argv);

        // 代理
        const auto proxy = ich->stringToProxy("EchoService: default -p 10000");

        // 服务
        auto service = Ice::checkedCast<rrIce::EchoServicePrx>(proxy);
        if (!service)
            throw runtime_error("Incalid proxy");

        int i {};
        while (true) {
            try {
                cout << "\necho:\n";
                cout << service->echo("message-" + to_string(++i)) << "\n";
            } catch (const exception &e) {
                cerr << e.what() << "\n";
            }

            using namespace chrono_literals;
            this_thread::sleep_for(1s);
        }

    } catch (const exception &e) {
        cerr << e.what() << "\n";
        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;
}
