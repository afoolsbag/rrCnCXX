//===-- Flow Control --------------------------------------------*- C++ -*-===//
///
/// \defgroup gFlowControl 流控制
/// \ingroup gLanguage
///
/// \version 2019-01-28
/// \since 2018-09-19
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <random>
#include <gsl/gsl>

#include <gtest/gtest.h>

#include "cxx_versions.hxx"

using namespace std;
using namespace gsl;

namespace rrcxx {

/// \addtogroup gFlowControl
/// @{

/// \brief `switch` 语句。
/// \sa <https://zh.cppreference.com/w/cpp/language/switch>
TEST(flow_control, switch)
{
    random_device dev;
    default_random_engine eng(dev());

#if _MSC_VER
    const uniform_int_distribution<> dis(1, 6);
#else
    uniform_int_distribution<> dis(1, 6);
#endif

    const auto condition {dis(eng)};

#if P0188R1
    switch (condition) {
    case 1:
        [[fallthrough]];
    case 2:
        [[fallthrough]];
    case 3:
        // do something
        break;
    case 4:
        [[fallthrough]];
    case 5:
        [[fallthrough]];
    case 6:
        // do something
        break;
    default:
        throw logic_error("Unexpected switch routing.");
    }
#endif
}

/// \brief `goto` 语句和 `goto finished` 技巧。
/// \remarks ES.76: 避免 goto
/// \sa <https://zh.cppreference.com/w/cpp/language/goto>
TEST(flow_control, goto_finished)
{
    constexpr int imax {10};
    constexpr int jmax {10};
    constexpr int kmax {10};

    for (int i = 0; i < imax; ++i) {
        for (int j = 0; j < jmax; ++j) {
            for (int k = 0; k < kmax; ++k) {
                if (i + j + k == 21)
                    goto finished;
            }
        }
    }
finished:

    return;
}

/// \brief `goto exit` 技巧。
/// \remarks NR.6: 请勿如此：把所有清理操作放在函数末尾并使用 `goto exit`
TEST(flow_control, goto_exit)
{
    void *tmp1 {nullptr};
    void *tmp2 {nullptr};
    void *tmp3 {nullptr};

    tmp1 = malloc(sizeof(int));
    if (!tmp1)
        goto exit;
    tmp2 = malloc(sizeof(int));
    if (!tmp2)
        goto exit;

    tmp3 = malloc(sizeof(int));
    if (!tmp3)
        goto exit;

exit:
    if (tmp1)
        free(tmp1);
    if (tmp2)
        free(tmp2);
    if (tmp3)
        free(tmp3);
}

/// \brief `gsl::finally`
/// \remarks 替代 `goto exit` 技巧。
TEST(flow_control, gsl_finally)
{
    const auto tmp1 {malloc(sizeof(int))};
    if (!tmp1)
        return;
    const auto tmp1_final_action {finally([&tmp1] { free(tmp1); })};

    const auto tmp2 {malloc(sizeof(int))};
    if (!tmp2)
        return;
    const auto tmp2_final_action {finally([&tmp2] { free(tmp2); })};

    const auto tmp3 {malloc(sizeof(int))};
    if (!tmp3)
        return;
    const auto tmp3_final_action {finally([&tmp3] { free(tmp3); })};
}

/// @}

}//namespace rrcxx
