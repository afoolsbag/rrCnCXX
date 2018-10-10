//===-- Hello Server --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Hello服务器
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
#include "HelloWorld.h"

///
/// \brief Hello Service Implement
///
class HelloWorldServiceImpl: public rrIce::HelloWorldService {
public:
    virtual void HelloWorld(const ::std::string &str, const ::Ice::Current &) override;
};

void
HelloWorldServiceImpl::
HelloWorld(const ::std::string &str, const ::Ice::Current &)
{
    std::cout << str << std::endl;
}

int main(int argc, char *argv[])
{
    try {
        Ice::CommunicatorHolder iceCH(argc, argv);  // ice communicator holder
        auto adapter = iceCH->createObjectAdapterWithEndpoints("HelloWorldServiceAdapter", "default -p 10000");
        auto servant = new HelloWorldServiceImpl;  // leak?
        adapter->add(servant, Ice::stringToIdentity("HelloWorldService"));
        adapter->activate();
        iceCH->waitForShutdown();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
