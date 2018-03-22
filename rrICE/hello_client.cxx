//===-- Hello Client --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Hello¿Í»§¶Ë
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
#include "HelloSlice.h"

int main(int argc, char *argv[])
{
    try {
        Ice::CommunicatorHolder icech(argc, argv);  // ice communicator holder
        auto proxy = icech->stringToProxy("HelloService: default -p 10000");
        auto hellosvc = Ice::checkedCast<HelloSlice::HelloServiceItfPrx>(proxy);  // hello service
        if (!hellosvc)
            throw std::runtime_error("Incalid proxy");
        hellosvc->sayHello("Hello World!");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
