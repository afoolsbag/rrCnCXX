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
#include "rrx/lib.h"

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
        rrx_version_t v {};
        if (rrx_version(&v) != rrx_success)
            return EXIT_FAILURE;
        cout << "rrx version " << v.major << "." << v.minor << "." << v.patch << "." << v.tweak << "\n";
    }

    {
        rrx_handle_t h;
        rrx_construct(&h);
        rrx_plus(h, 5);
        rrx_minus(h, 2);
        int r;
        rrx_equals(h, &r);
        rrx_destruct(h);
        cout << "rrx result: " << r << "\n";
    }

    return EXIT_SUCCESS;
}
