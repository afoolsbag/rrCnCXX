#include <array>
#include <memory>
#include <set>
#include <string>

#include "rrposix/get_local_ips.hxx"

#include <gtest/gtest.h>

using namespace std;

namespace rrposix {

TEST(getip, st1) {
    const auto ips = get_local_ips();
    for (const auto &ip : ips)
        cout << ip.first << ": " << ip.second << '\n';
}

}
