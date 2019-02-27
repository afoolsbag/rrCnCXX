//===-- Executable ----------------------------------------------*- C++ -*-===//
///
/// \version 2019-02-27
/// \since 2016-10-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>

#include "rrc/lib.h"
#include "rrx/lib.hxx"

using namespace std;

int main()
{
    {
        rrc_version_t v {};
        if (rrc_version(&v) != rrc_success)
            return EXIT_FAILURE;
        cout << "rrc version " << v.major << "." << v.minor << "." << v.patch << "." << v.tweak << "\n";
    }

    {
        const auto v = rrx::version();
        cout << "rrx version " << v.major << "." << v.minor << "." << v.patch << "." << v.tweak << "\n";
    }

    {
        rrx::rrx_t x;
        x.plus(5);
        x.minus(2);
        cout << "rrx result: " << x.equals() << "\n";
    }

    return EXIT_SUCCESS;
}
