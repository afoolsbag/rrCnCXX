//===-- Hello World Server --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Hello World 服务端。
///
/// \author zhengrr
/// \version 2018-10-10
/// \since 2017-12-13
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>
using namespace std;

#include <Ice/Ice.h>
#include "service.h"

///
/// \brief Implement
///
class HelloWorldServiceImpl: public rrIce::HelloWorldService {
public:
    void putHelloWorld(string str, const Ice::Current &) final
    {
        cout << "hello, world\n"
            << str << "\n";
    }
};

int main(int argc, char *argv[])
{
    try {
        // 通讯器
        Ice::CommunicatorHolder ich(argc, argv);

        // 适配器
        auto adapter = ich->createObjectAdapterWithEndpoints("HelloWorldServiceAdapter", "default -p 10000");

        // 侍从
        const auto servant = make_shared<HelloWorldServiceImpl>();

        adapter->add(servant, Ice::stringToIdentity("HelloWorldService"));
        adapter->activate();

        ich->waitForShutdown();

    } catch (const exception &e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;
}
