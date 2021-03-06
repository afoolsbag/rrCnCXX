//===-- Non-Modifying Sequence Operations -----------------------*- C++ -*-===//
///
/// \defgroup gNonModifyingSequenceOperations 不修改序列的操作
/// \ingroup gAlgorithm
///
/// \version 2019-08-01
/// \since 2018-06-21
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cctype>
#include <algorithm>
#include <vector>
#include <gsl/gsl>

#include <gtest/gtest.h>

#include "cxx_versions.hxx"

#if NORMALIZED_MSC_VERSION
#include <execution>
#endif

using namespace std;
using namespace gsl;

#if NORMALIZED_GNUC_VERSION
#define index gsl::index
#endif

namespace {
void ltrim(std::string &text)
{
    text.erase(
        text.begin(),
        std::find_if(text.begin(), text.end(), [](int ch) { return !std::isspace(ch); })
    );
}
void rtrim(std::string &text)
{
    text.erase(
        std::find_if(text.rbegin(), text.rend(), [](int ch) { return !std::isspace(ch); }).base(),
        text.end()
    );
}
void trim(std::string &text)
{
    ltrim(text);
    rtrim(text);
}
}

namespace rrcxx {
/// \addtogroup gNonModifyingSequenceOperations
/// @{

/// \brief 查找。
///
/// \remarks P.1: 在代码中直接表达你的想法
///
/// \sa <https://zh.cppreference.com/w/cpp/algorithm/find>
TEST(non_modifying_sequence_operations, find)
{
    const vector<int> v {1, 2, 3, 4, 5};
    const int t {3};

    // 不太好
    index a = -1;
    for (index i = 0; i < static_cast<index>(size(v)); ++i) {
        if (v[static_cast<size_t>(i)] == t) {
            a = i;
            break;
        }
    }
    ASSERT_EQ(v[static_cast<size_t>(a)], t);

    // 好
    auto const p {find(begin(v), end(v), t)};
    ASSERT_EQ(*p, t);
}


TEST(non_modifying_sequence_operations, trim)
{
    auto string = "  hello, world  "s;
    trim(string);
    ASSERT_EQ("hello, world", string);
}

/// \brief 遍历。
///
/// \note
/// 查找具有更加替代方案的一般模式：
/// *   简单 `for` 循环 vs. 范围 `for` 循环
/// *   `f(T*, int)` 接口 vs. `f(span<T>)` 接口
/// *   循环变量出现在过大的范围中
/// *   裸的 `new` 和 `delete`
/// *   带有大量内建类型的形参的函数
///
/// \remarks P.3: 表达你的设计意图
///
/// \sa <https://zh.cppreference.com/w/cpp/algorithm/for_each>
/// \sa [*C++C.G. P.3*](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rp-what)
TEST(non_modifying_sequence_operations, for_each)
{
    vector<int> v {1, 2, 3, 4, 5};

    // 不太好
    for (index i = 0; i < static_cast<index>(v.size()); ++i)
        (void)v[i];

    // 好
    for (const auto &x : v)
        (void)x;
    // 若需要修改，则使用
    for (auto &x : v)
        (void)x;

    // 更好
    for_each(cbegin(v), cend(v), [](const int &x) {
        (void)x;
    });
    // 若需要修改，则使用
    for_each(begin(v), end(v), [](int &x) {
        (void)x;
    });
#if NORMALIZED_MSC_VERSION
    // 若允许并行执行，则使用
    for_each(execution::par, begin(v), end(v), [](int &x) {
        (void)x;
    });
#endif
}

/// @}
}
