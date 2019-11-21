//===-- Preprocessor --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 预处理器。
/// \sa <https://boost.org/doc/libs/master/libs/preprocessor/doc/index.html>
///
/// \version 2019-09-05
/// \since 2019-09-05
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <gsl/gsl>

#include <gtest/gtest.h>

#include "preprocessor_self_iteration.hpp"

using namespace std;
using namespace gsl;

namespace rrboost {

//==============================================================================
// A.4.1 重复 Repetition

/// \brief 高阶宏函数，生成以逗号分隔的列表。
/// \param count 重复次数，有效范围 `[0, BOOST_PP_LIMIT_REPEAT]`
/// \param macro 宏函数，形如 `macro(z, n, data)`
/// \param data  用户数据，若未使用则传入 `~`、`@` 或 `$`
/// \result 宏扩展为 `macro(z, 0, data), macro(z, 1, data), ... macro(z, count - 1, data)`
#define RR_BOOST_PP_ENUM(count, macro, data)

/// \brief 高阶宏函数，生成以逗号分隔的参数列表。
/// \param count 重复次数，有效范围 `[0, BOOST_PP_LIMIT_REPEAT]`
/// \param param 参数文本
/// \result 宏扩展为 `param ## 0, param ## 1, ... param ## count - 1`
#define RR_BOOST_PP_ENUM_PARAMS(count, param)

/// \brief 高阶宏函数，生成以逗号分隔的位移列表，移去了 `n = 0` 时的情况。
/// \param count 重复次数，有效范围 `[0, BOOST_PP_LIMIT_REPEAT]`
/// \param macro 宏函数，形如 `macro(z, n, data)`
/// \param data  用户数据，若未使用则传入 `~`、`@` 或 `$`
/// \result 宏扩展为 `macro(z, 1, data), ... macro(z, count - 1, data)`
#define RR_BOOST_PP_ENUM_SHIFTED(count, macro, data)

/// \brief 高阶宏函数，生成含前导逗号的，以逗号分隔的列表。
/// \param count 重复次数，有效范围 `[0, BOOST_PP_LIMIT_REPEAT]`
/// \param macro 宏函数，形如 `macro(z, n, data)`
/// \param data  用户数据，若未使用则传入 `~`、`@` 或 `$`
/// \result 宏扩展为 `, macro(z, 0, data), macro(z, 1, data), ... macro(z, count - 1, data)`
#define RR_BOOST_PP_ENUM_TRAILING(count, macro, data)

/// \brief 高阶宏函数，快速水平重复构造。
/// \param count 重复次数，有效范围 `[0, BOOST_PP_LIMIT_REPEAT]`
/// \param macro 宏函数，形如 `macro(z, n, data)`
/// \param data  用户数据，若未使用则传入 `~`、`@` 或 `$`
/// \result 宏扩展为 `macro(z, 0, data) macro(z, 1, data) ... macro(z, count - 1, data)`
#define RR_BOOST_PP_REPEAT(count, macro, data)

//==============================================================================
// A.4.2 算术、逻辑和比较运算 Arithmetic, Logical, and Comparison Operations

//------------------------------------------------------------------------------
// 算术运算 Arithmetic Operations
// ADD x+y https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/add.html
// DEC x-1 https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/dec.html
// DIV x/y https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/div.html
// INC x+1 https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/inc.html
// MOD x%y https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/mod.html
// MUL x*y https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/mul.html
// SUB x-y https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/sub.html
// 输入和输出均为区间 [0, BOOST_PP_LIMIT_MAG] 中的整数。

//------------------------------------------------------------------------------
// 整型逻辑运算 Integer Logical Operations
// AND  x&&y    https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/and.html
// NOR  !(x||y) https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/nor.html
// OR   x||y    https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/or.html
// XOR          https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/xor.html
// NOT  x?0:1   https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/not.html
// BOOL x?1:0   https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/bool.html
// 输入为区间 [0, BOOST_PP_LIMIT_MAG] 中的整数，输出为 0 或 1。

//------------------------------------------------------------------------------
// 位逻辑运算 Bit Logical Operations
// BITAND x&&y    https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/bitand.html
// BITNOR !(x||y) https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/bitnor.html
// BITOR  x||y    https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/bitor.html
// BITXOR         https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/bitxor.html
// COMPL  x?0:1   https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/compl.html
// 输入和输出均为 0 或 1。相较整型逻辑运算效率更高。

//------------------------------------------------------------------------------
// 比较运算 Comparison Operations
// EQUAL         x==y?1:0 https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/equal.html
// NOT_EQUAL     x!=y?1:0 https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/not_equal.html
// LESS          x<y?1:0 https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/less.html
// LESS_EQUAL    x<=y?1:0 https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/less_equal.html
// GREATER       x?y?1:0 https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/greater.html
// GREATER_EQUAL x>=y?1:0 https://boost.org/doc/libs/master/libs/preprocessor/doc/ref/greater_equal.html
// 输入为区间 [0, BOOST_PP_LIMIT_MAG] 中的整数，输出为 0 或 1。

//==============================================================================
// A.4.3 控制结构 Control Structures

//==============================================================================
// A.4.5 数据类型 Data Types

//------------------------------------------------------------------------------
// A.4.5.1 序列 Sequences

/// \brief 高阶宏函数，遍历序列中的每一元素。
/// \param macro 宏函数，形如 `macro(r, data, elem)`
/// \param data  用户数据，若未使用则传入 `~`、`@` 或 `$`
/// \param seq   序列，如 `(a)(b)(c)`
/// \result 宏扩展为 `macro(r, data, a) macro(r, data, b) macro(r, data, c)`
#define RR_BOOST_PP_SEQ_FOR_EACH(macro, data, seq)

//------------------------------------------------------------------------------
// A.4.5.2 元组 Tuples

//------------------------------------------------------------------------------
// A.4.5.3 数组 Arrays

//------------------------------------------------------------------------------
// A.4.5.4 列表 Lists

/// \brief 高阶宏函数，遍历列表中的每一元素。
/// \param macro 宏函数，形如 `macro(r, data, elem)`
/// \param data  用户数据，若未使用则传入 `~`、`@` 或 `$`
/// \param seq   序列，如 `(a, (b, (c, BOOST_PP_NIL)))`
/// \result 宏扩展为 `macro(r, data, a) macro(r, data, b) macro(r, data, c)`
#define RR_BOOST_PP_LIST_FOR_EACH(macro, data, seq)

TEST(preprocessor, self_iteration)
{
    static_assert(sample10 == 10);
}

}
