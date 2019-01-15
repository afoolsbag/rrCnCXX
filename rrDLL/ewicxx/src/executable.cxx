//===-- Executable ----------------------------------------------*- C++ -*-===//
///
/// \version 2019-01-15
/// \since 2016-10-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iostream>

#include "lwic/library.h"
#include "lwicxx/library.hxx"

using namespace std;

int main(int argc, char *argv[])
{
    const auto lwicVer {rrdll_lwic_version()};
    cout << "lwic version: " << lwicVer.major << "." << lwicVer.minor << "." << lwicVer.patch << "." << lwicVer.tweak << "\n";

    rrdll_lwicxx_handle_t lwicxxHdl = nullptr;
    rrdll_lwicxx_construct(&lwicxxHdl);
    rrdll_lwicxx_plus(lwicxxHdl, 5);
    rrdll_lwicxx_minus(lwicxxHdl, 2);
    int result;
    rrdll_lwicxx_equals(lwicxxHdl, &result);
    rrdll_lwicxx_destruct(lwicxxHdl);
    cout << "lwicxx result: " << result << "\n";

    return EXIT_SUCCESS;
}
