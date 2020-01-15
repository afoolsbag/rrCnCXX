//===-- Swap, Forward and Move ----------------------------------*- C++ -*-===//
///
/// \defgroup groupSwapForwardAndMove Swap, Forward and Move
/// \ingroup groupUtility
///
/// \version 2020-01-15
/// \since 2019-07-28
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <utility>

#include <gtest/gtest.h>

using namespace std;

namespace rrcxx {
/// \addtogroup groupSwapForwardAndMove
/// @{

static void func(int &) { cout << "lvalue ref\n"; }
static void func(int &&) { cout << "rvalue ref\n"; }
static void func(const int &) { cout << "const lvalue ref\n"; }
static void func(const int &&) { cout << "const rvalue ref\n"; }
static void func(volatile int &) { cout << "volatile lvalue ref\n"; }
static void func(volatile int &&) { cout << "volatile rvalue ref\n"; }
static void func(const volatile int &) { cout << "const volatile lvalue ref\n"; }
static void func(const volatile int &&) { cout << "const volatile rvalue ref\n"; }
template<typename T> static void wrap(T &&v) { func(forward<T>(v)); }

/// \brief 完美转发
/// \details 将参数的值和类型一并转发
/// \sa <https://stackoverflow.com/questions/3582001>
TEST(swap_forward_and_move, perfect_forwarding)
{
    // lvalue
    int i {};
    wrap(i);

    // rvalue
    wrap(move(i));

    wrap(1);

    // const lvalue
    const int c {};
    wrap(c);

    // const rvalue
    wrap(move(c));

    // volatile lvalue
    volatile int v {};
    wrap(v);

    // volatile rvalue
    wrap(move(v));

    // const volatile lvalue
    const volatile int cv {};
    wrap(cv);

    // const volatile rvalue
    wrap(move(cv));
}

/// @}
}
