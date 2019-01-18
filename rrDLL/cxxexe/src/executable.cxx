//===-- Executable ----------------------------------------------*- C++ -*-===//
///
/// \version 2019-01-18
/// \since 2016-10-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>

#include "clib/library.h"
#include "cxxlib/library.hxx"

using namespace std;

int main(int argc, char *argv[])
{
    const auto clibver {clib_version()};
    cout << "clib version: " << clibver.major << "." << clibver.minor << "." << clibver.patch << "." << clibver.tweak << "\n";

    cxxlib_handle_t h = nullptr;
    cxxlib_construct(&h);
    cxxlib_plus(h, 5);
    cxxlib_minus(h, 2);
    int result;
    cxxlib_equals(h, &result);
    cxxlib_destruct(h);
    cout << "cxxlib result: " << result << "\n";

    return EXIT_SUCCESS;
}
