//===-- Flow Control --------------------------------------------*- C++ -*-===//
///
/// \defgroup gFlowCtrl 流控制
/// \ingroup gLang
///
/// \version 2018-10-15
/// \since 2018-09-19
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <random>
using namespace std;
#include <gsl/gsl>
using namespace gsl;

#include <gtest/gtest.h>

#include "cxx_versions.hxx"

namespace rrcxx::test {

/// \addtogroup gFlowCtrl
/// @{

/// \brief `switch` 语句。
/// \sa <https://zh.cppreference.com/w/cpp/language/switch>
TEST(flow_control, switch)
{
    random_device rdev;
    default_random_engine reng(rdev());
    const uniform_int_distribution<> rdis(1, 6);

    const auto condition {rdis(reng)};

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

/// \brief `goto` 语句。
/// \remarks NR.6: 请勿如此：把所有清理操作放在函数末尾并使用 `goto exit`
/// \sa <https://zh.cppreference.com/w/cpp/language/goto>
TEST(flow_control, goto)
{
    const auto memory {malloc(sizeof(int))};
    if (memory == nullptr)
        FAIL();
    goto exit;
exit:
    free(memory);
}

/// \brief `gsl::finally`
TEST(flow_control, gsl_finally)
{
    const auto memory {malloc(sizeof(int))};
    if (memory == nullptr)
        FAIL();
    const auto memory_defer {finally([&memory] { free(memory); })};
}

/// @}

}//namespace rrcxx::test
