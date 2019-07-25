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

/// \brief 简单的类模板。
template<typename T = int>
class wrapper {
public:
    [[nodiscard]] const T &get() const { return value_; }
    void set(const T &value) { value_ = value; }
private:
    T value_ {};
};

TEST(templates, wrapper_test)
{
    wrapper wrap;
    ASSERT_EQ(0, wrap.get());
}

/// @}
}
