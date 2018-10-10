//===-- Hello Client --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Hello客户端
///
/// \author zhengrr
/// \version 2018-03-22
/// \since 2017-12-13
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include <Ice/Ice.h>
#include "HelloWorld.h"

int main(int argc, char *argv[])
{
    try {
        Ice::CommunicatorHolder iceCH(argc, argv);  // ice communicator holder
        auto proxy = iceCH->stringToProxy("HelloWorldService: default -p 10000");
        auto service = Ice::checkedCast<rrIce::HelloWorldServicePrx>(proxy);  // hello service
        if (!service)
            throw std::runtime_error("Incalid proxy");
        service->HelloWorld("Hello World!");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
