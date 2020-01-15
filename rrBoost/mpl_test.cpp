//===-- Boost.MPL -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Boost 元编程库
/// \sa <https://boost.org/doc/libs/master/libs/mpl/>
///
/// \version 2020-01-14
/// \since 2019-09-05
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <type_traits>

#include <boost/mpl/at.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/char.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/pop_back.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/set_c.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/size_t.hpp>
#include <boost/mpl/string.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector_c.hpp>
#include <gtest/gtest.h>

using namespace std;
namespace mpl = boost::mpl;

namespace rrboost {

/// \brief 编译期常量的类型包装。
/// \details 每一个编译期常量的类型包装都是零元元函数，提供 `()` 方法，返回它自身。
TEST(mpl, type_wrapper_for_compile_time_constant)
{
    using bool_true_type = mpl::bool_<true>;
    static_assert(bool_true_type::value == true);

    using char_a_type = mpl::char_<'a'>;
    static_assert(char_a_type::value == 'a');

    using int_13_type = mpl::int_<13>;
    static_assert(int_13_type::value == 13);

    using long_1337_type = mpl::long_<1337>;
    static_assert(long_1337_type::value == 1337);

    using size_t_0_type = mpl::size_t<0>;
    static_assert(size_t_0_type::value == 0);

    using long_long_19920525_type = mpl::integral_c<long long, 19920525>;
    static_assert(long_long_19920525_type::value == 19920525);
}

/// \brief 元编程断言
/// \details 相较于 `static_assert` 提供更多信息
/// \sa <https://boost.org/doc/libs/master/libs/mpl/doc/refmanual/asserts.html>
TEST(mpl, assert)
{
    BOOST_MPL_ASSERT((mpl::bool_<true>));
    BOOST_MPL_ASSERT_NOT((mpl::bool_<false>));
    BOOST_MPL_ASSERT_RELATION((mpl::int_<1337>::value), == , 1337);
}

/// \brief 类型容器：可变数组
TEST(mpl, vector)
{}

/// \brief 类型容器：链表
TEST(mpl, list)
{}

/// \brief 类型容器：双端队列
TEST(mpl, deque)
{}

/// \brief 类型容器：集合
TEST(mpl, set)
{}

/// \brief 类型容器：映射
TEST(mpl, map)
{}

struct value_printer {
    template< typename U > void operator()(U x)
    {
        std::cout << x << '\n';
    }
};

/// \brief 编译期常量类型包装的容器：范围
/// \sa <https://www.boost.org/doc/libs/master/libs/mpl/doc/refmanual/range-c.html>
TEST(mpl, range_c)
{
    using range0to9 = mpl::range_c<int, 0, 10>;

    BOOST_MPL_ASSERT_RELATION((mpl::size<range0to9>::value), == , 10);
    BOOST_MPL_ASSERT_NOT((mpl::empty<range0to9>));

    BOOST_MPL_ASSERT_RELATION((mpl::front<range0to9>::type::value), == , 0);
    BOOST_MPL_ASSERT_RELATION((mpl::back<range0to9>::type::value), == , 9);
    BOOST_MPL_ASSERT_RELATION((mpl::at_c<range0to9, 5>::type::value), == , 5);
}

/// \brief 编译期常量类型包装的容器：可变数组
TEST(mpl, vector_c)
{
    using vector1to8 = mpl::vector_c<int, 1, 2, 3, 4, 5, 6, 7, 8>;
    using vector1to9 = mpl::push_back<vector1to8, mpl::int_<9>>::type;
    using vector0to9 = mpl::push_front<vector1to9, mpl::int_<0>>::type;

    BOOST_MPL_ASSERT_RELATION((mpl::size<vector0to9>::value), == , 10);
    BOOST_MPL_ASSERT_NOT((mpl::empty<vector0to9>));

    BOOST_MPL_ASSERT_RELATION((mpl::front<vector0to9>::type::value), == , 0);
    BOOST_MPL_ASSERT_RELATION((mpl::back<vector0to9>::type::value), == , 9);
    BOOST_MPL_ASSERT_RELATION((mpl::at_c<vector0to9, 5>::type::value), == , 5);
}

/// \brief 编译期常量类型包装的容器：链表
TEST(mpl, list_c)
{}

/// \brief 编译期常量类型包装的容器：集合
TEST(mpl, set_c)
{}

/// \brief 编译期常量类型包装的容器：字符串
TEST(mpl, string)
{}

/// \brief 
TEST(mpl, for_each)
{
    using range0to9 = mpl::range_c<int, 0, 10>;
    mpl::for_each<range0to9>([](auto n) {
        using N = decltype(n);
        cout << N::value << '\t' << n << '\n';
    });
}

}
