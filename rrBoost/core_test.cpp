//===-- Core ----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 核心实用工具
/// \sa <https://boost.org/doc/libs/master/libs/core/doc/html/index.html>
///
/// \version 2019-09-19
/// \since 2019-09-19
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <vector>

#include <boost/core/addressof.hpp>
#include <boost/core/alloc_construct.hpp>
#include <boost/core/checked_delete.hpp>
#include <boost/core/default_allocator.hpp>
#include <boost/core/demangle.hpp>
#include <boost/core/empty_value.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/core/exchange.hpp>
#include <boost/core/explicit_operator_bool.hpp>
#include <boost/core/first_scalar.hpp>
#include <boost/core/ignore_unused.hpp>
#include <boost/core/is_same.hpp>
#include <boost/core/lightweight_test.hpp>
#include <boost/core/no_exceptions_support.hpp>
#include <boost/core/noinit_adaptor.hpp>
#include <boost/core/noncopyable.hpp>
#include <boost/core/null_deleter.hpp>
#include <boost/core/pointer_traits.hpp>
#include <boost/core/quick_exit.hpp>
#include <boost/core/ref.hpp>
#include <boost/core/scoped_enum.hpp>
#include <boost/core/swap.hpp>
#include <boost/core/typeinfo.hpp>
#include <boost/core/uncaught_exceptions.hpp>
#include <boost/core/use_default.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace rrboost {

/// \details 明确地取对象地址，避免因可能的 `&` 运算符重载造成的影响。
TEST(core, addressof)
{
    const int value {};
    const int *const ptr {boost::addressof(value)};
    ASSERT_EQ(value, *ptr);
}

TEST(core, alloc_construct)
{}

TEST(core, checked_delete)
{}

TEST(core, default_allocator)
{}

/// \details 从函数签名还原为可读的函数名。
TEST(core, demangle)
{
    const char *const name = typeid(vector<int>).name();
    cout << "name:     " << name << '\n';
    cout << "demangle: " << boost::core::demangle(name) << '\n';
}

TEST(core, empty_value)
{}

TEST(core, enable_if)
{}

/// \sa <https://boost.org/doc/libs/master/libs/core/doc/html/core/exchange.html>
TEST(core, exchange)
{}

TEST(core, explicit_operator_bool)
{}

TEST(core, first_scalar)
{}

TEST(core, ignore_unused)
{
    int maybe_unused;
    boost::ignore_unused(maybe_unused);
}

TEST(core, is_same)
{}

TEST(core, lightweight_test)
{}

TEST(core, no_exceptions_support)
{
    BOOST_TRY
    {

    }
    BOOST_CATCH(const std::exception &e)
    {
        boost::ignore_unused(e);
    }
    BOOST_CATCH(...)
    {
        BOOST_RETHROW;
    }
    BOOST_CATCH_END;
}

TEST(core, noinit_adaptor)
{}

TEST(core, noncopyable)
{
    class clazz : private boost::noncopyable {};
}

/// \details 空置删除器，用以替换默认删除器，改变删除行为。
TEST(core, null_deleter)
{}

TEST(core, pointer_traits)
{}

TEST(core, quick_exit)
{}

TEST(core, ref)
{}

TEST(core, scoped_enum)
{
    BOOST_SCOPED_ENUM_DECLARE_BEGIN(log_level)
    {
        silence,
            fatal,        ///< 致命：检测到程序功能受阻，程序发生了无法自行弥补的意外状况，继续运行将
            error,        ///< 错误：检测到程序功能受阻，
            warning,      ///< 警告：检测到程序运行不良而备有预案，情况仍在掌控之中：可自行弥补、恢复正轨
            information,  ///< 信息：
            debug,        ///< 调试：
            trace         ///< 跟踪：
    }
    BOOST_SCOPED_ENUM_DECLARE_END(log_level)
}

TEST(core, swap)
{
    int x = 1, y = 2;
    boost::swap(x, y);
    ASSERT_EQ(1, y);
    ASSERT_EQ(2, x);
}

TEST(core, typeinfo)
{}

TEST(core, uncaught_exceptions)
{}

TEST(core, use_default)
{}

}
