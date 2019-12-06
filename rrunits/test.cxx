/// \copyright Unlicense

#include <iostream>

#include <gtest/gtest.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4127)
#include <units.h>
#pragma warning(pop)
#endif

using namespace std;

namespace rrunits {

TEST(units, tfs)
{
    using namespace units::literals;
    const units::energy::calorie_t heat {15000_J};
    cout << heat << '\n';
}

}
