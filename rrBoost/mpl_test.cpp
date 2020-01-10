//===-- Boost.MPL -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Boost 元编程库
/// \sa <https://boost.org/doc/libs/master/libs/mpl/>
///
/// \version 2020-01-10
/// \since 2019-09-05
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <boost/dll.hpp>
#include <gtest/gtest.h>

using namespace std;
namespace mpl = boost::mpl;

namespace rrboost {

/// \brief 编译期常量，基础类型
TEST(mpl, basic)
{
    using int_13_type = mpl::int_<13>;
    static_assert(int_13_type::value == 13);
}

}
