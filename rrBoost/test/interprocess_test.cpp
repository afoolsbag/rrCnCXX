//===-- Interprocess --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Format
/// \sa <https://boost.org/doc/libs/master/libs/interprocess/index.html>
///
/// \version 2019-09-09
/// \since 2019-09-02
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <gsl/gsl>

#include <boost/interprocess/sync/named_mutex.hpp>
#include <gtest/gtest.h>

using namespace std;
using namespace gsl;
namespace bip = boost::interprocess;

namespace rrboost {

/// \details 异常中止时可能不调用析构，因而不可用于单例应用的判断。
TEST(interprocess, gft)
{
    constexpr char name[] {"rrBoostTest"};
    try {
        bip::named_mutex {bip::create_only, name};
    } catch (const bip::interprocess_exception &e) {
        cout << "create named mutex failed: " << e.what() << '\n';
        return;
    }
    const auto auto_remove_named_mutex = finally([&] { bip::named_mutex::remove(name); });
}

}
