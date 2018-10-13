//===-- Hello World Server --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Hello World 服务端。
///
/// \author zhengrr
/// \version 2018-10-13
/// \since 2017-12-13
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>
using namespace std;

#include <Ice/Ice.h>
#include "service.h"

class EchoServiceImpl: public rrIce::EchoService {
public:
    string echo(string message, const Ice::Current &cur) final
    {
        cout << "\necho:\n"
            << cur.con->toString() << "\n"
            << message << "\n";
        return message;
    }
};

int main(int argc, char *argv[])
{
    system("CHCP 65001");

    try {
        // 通讯器
        Ice::CommunicatorHolder ich(argc, argv);

        // 适配器
        auto adapter = ich->createObjectAdapterWithEndpoints("LocalHost", "default -p 10000");

        // 侍从
        const auto servant = make_shared<EchoServiceImpl>();

        adapter->add(servant, Ice::stringToIdentity("EchoService"));
        adapter->activate();

        ich->waitForShutdown();

    } catch (const exception &e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;
}
