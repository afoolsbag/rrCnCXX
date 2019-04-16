//===-- Executable ----------------------------------------------*- C++ -*-===//
///
/// \version 2019-04-16
/// \since 2016-10-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>

#include "rrdllc/lib.h"
#include "rrdllcxx/lib.hxx"

using namespace std;

int main()
{
    {
        rrdllc_version_t v {};
        if (rrdllc_version(&v) != rrdllc_success)
            return EXIT_FAILURE;
        cout << "rrDLLc version " << v.major << "." << v.minor << "." << v.patch << "." << v.tweak << "\n";
    }

    {
        const auto v = rrdllcxx::version();
        cout << "rrDLLcxx version " << v.major << "." << v.minor << "." << v.patch << "." << v.tweak << "\n";
    }

    {
        rrdllcxx::rrdllcxx_t x;
        x.plus(5);
        x.minus(2);
        cout << "rrDLLcxx result: " << x.equals() << "\n";
    }

    return EXIT_SUCCESS;
}
