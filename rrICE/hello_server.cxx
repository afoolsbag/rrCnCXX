//===-- Hello Server --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Hello·þÎñÆ÷
///
/// \author zhengrr
/// \version 2018-03-22
/// \since 2017-12-13
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>
#include <memory>

#include <Ice/Ice.h>
#include "HelloSlice.h"

/// \brief Hello Service Implement
class HelloServiceImpl: public HelloSlice::HelloServiceItf {
public:
    void sayHello(const std::string &str, const Ice::Current &) override;
};

void HelloServiceImpl::sayHello(const std::string &str, const Ice::Current &)
{
    std::cout << str << std::endl;
}

int main(int argc, char *argv[])
{
    try {
        Ice::CommunicatorHolder icech(argc, argv);  // ice communicator holder
        auto adapter = icech->createObjectAdapterWithEndpoints("HelloServiceAdapter", "default -p 10000");
        auto servant = new HelloServiceImpl;  // leak?
        adapter->add(servant, Ice::stringToIdentity("HelloService"));
        adapter->activate();
        icech->waitForShutdown();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
