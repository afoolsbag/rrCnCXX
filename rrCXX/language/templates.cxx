//===-- Templates -----------------------------------------------*- C++ -*-===//
///
/// \defgroup gTemplates 模板
/// \ingroup gLanguage
///
/// \version 2019-07-25
/// \since 2019-07-25
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <gtest/gtest.h>

using namespace std;

namespace rrcxx {
/// \addtogroup gTemplates
/// @{

//------------------------------------------------------------------------------
// 函数模板
//------------------------------------------------------------------------------

/// \brief 简单的函数模板。
template<typename T1, typename T2>
const auto &max(const T1 &lhv, const T2 &rhv)
{
    return lhv > rhv ? lhv : rhv;
}

TEST(templates, max_test)
{
    const int lhv = 1;
    const int rhv = 2;
    ASSERT_EQ(rhv, max(lhv, rhv));
}

//------------------------------------------------------------------------------
// 类模板
//------------------------------------------------------------------------------

/// \brief 简单的类模板。
/// \tparam T    类型
/// \tparam dvoT 默认值，default value of T
template<
    typename T = int,
    T dvoT = T {}
> class value_wrapper {
public:
    [[nodiscard]] const T &get() const { return value_; }
    void set(const T &value) { value_ = value; }
private:
    T value_ {dvoT};
};

TEST(templates, wrapper_test)
{
    value_wrapper wrap;
    ASSERT_EQ(0, wrap.get());
}

//------------------------------------------------------------------------------
// 模板的特性和策略
//------------------------------------------------------------------------------

/// \brief 模板函数 `accumulate` 中类型 `T` 的特性模板。
/// \details 可以仅声明而不定义默认特性模板，以迫使用户明确每个类型的特性特化。
template<typename T> struct accumulate_traits {
    using return_t = T;
    static constexpr return_t zero {};
};
/// \brief 模板函数 `accumulate`中类型 `char` 的特性特化。
template<> struct accumulate_traits<char> {
    using return_t = int;
    static constexpr return_t zero {};
};

/// \brief 函数模板 `accumulate` 的 `add` 策略。
struct accumulate_add_policy {
    template<typename T1, typename T2>
    static void accumulate(T1 &total, const T2 &value)
    {
        total += value;
    }
};
/// \brief 函数模板 `accumulate` 的 `multiply` 策略。
struct accumulate_multiply_policy {
    template<typename T1, typename T2>
    static void accumulate(T1 &total, const T2 &value)
    {
        total *= value;
    }
};

/// \brief 累积。
/// \tparam T      类型
/// \tparam Policy 策略
/// \tparam Traits 特性
template<
    typename T,
    typename Policy = accumulate_add_policy,
    typename Traits = accumulate_traits<T>
> typename Traits::return_t accumulate(const T *beg, const T *end)
{
    typename Traits::return_t total {Traits::zero};
    while (beg != end) {
        Policy::accumulate(total, *beg);
        ++beg;
    }
    return total;
}

TEST(templates, accumulate_test)
{
    {
        int tv[] {1, 2, 3, 4};
        ASSERT_EQ(10, accumulate(&tv[0], &tv[4]));
    }

    {
        char tv[] {100, 100, 100, 100};
        ASSERT_EQ(400, accumulate(&tv[0], &tv[4]));
    }
}

/// @}
}
