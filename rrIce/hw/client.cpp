//===-- Hello World Client --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Hello World 客户端。
///
/// \author zhengrr
/// \version 2018-10-10
/// \since 2017-12-13
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;

#include <Ice/Ice.h>
#include "service.h"

int main(int argc, char *argv[])
{
    try {
        // 通讯器
        const Ice::CommunicatorHolder ich(argc, argv);

        // 代理
        const auto proxy = ich->stringToProxy("HelloWorldService: default -p 10000");

        // 服务
        auto service = Ice::checkedCast<rrIce::HelloWorldServicePrx>(proxy);
        if (!service)
            throw runtime_error("Incalid proxy");

        service->putHelloWorld("wow");

    } catch (const exception &e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;
}
