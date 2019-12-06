//===-- Units ---------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Thread
/// \sa <https://boost.org/doc/libs/master/libs/units/>
///
/// \version 2019-12-06
/// \since 2019-12-05
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <boost/units/systems/information.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/io.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace units = ::boost::units;
namespace information = ::boost::units::information;
namespace si = ::boost::units::si;

//
// 十分简单的需求：
// 能量存储为焦耳值，如何取得对应的卡路里值？
//

//
// 复合单位的字符串输出
//

namespace boost::units {
std::string name_string(const si::velocity &) { return "meters per second"; }
std::string symbol_string(const si::velocity &) { return "m/s"; }
}

namespace rrboost {
TEST(units, output_for_composite_units)
{
    const units::quantity<si::length> length {15.0 * si::meter};
    const units::quantity<si::time> time {15.0 * si::second};
    const units::quantity<si::velocity> velocity = length / time;
    cout << velocity << endl;
}
}

//
// 自动缩放单位（输出）
//

namespace rrboost {
TEST(units, automatically_scaled_units)
{
    const units::quantity<si::length> length {1234 * si::meter};
    cout << length << '\n';
    cout << units::engineering_prefix << length << units::no_prefix << '\n';

    const units::quantity<information::info> info {50000 * information::byte};
    cout << info << '\n';
    cout << units::binary_prefix << info << units::no_prefix << '\n';
}
}
