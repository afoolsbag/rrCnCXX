//===-- Flow Control --------------------------------------------*- C++ -*-===//
///
/// \defgroup gFlowCtrl 流控制
/// \ingroup gLang
///
/// \version 2018-09-19
/// \since 2018-09-19
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <random>
#include <gsl/gsl>

#include <gtest/gtest.h>
#include "rrcxx/cxx_versions.hxx"

namespace rrcxx::test {

/// \addtogroup gFlowCtrl
/// @{

/// \brief `switch` 语句。
/// \sa <https://zh.cppreference.com/w/cpp/language/switch>
TEST(flow_control, switch)
{
    std::random_device random_device;
    std::default_random_engine random_engine(random_device());
    const std::uniform_int_distribution<> uniform_distribution(1, 6);

    const auto condition {uniform_distribution(random_engine)};

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
        throw std::logic_error("Unexpected switch routing.");
    }
#endif
}

/// \brief `goto` 语句。
/// \sa <https://zh.cppreference.com/w/cpp/language/goto>
TEST(flow_control, goto)
{
    const auto memory {std::malloc(sizeof(std::byte))};
    if (memory == nullptr)
        FAIL();
    goto exit;
exit:
    std::free(memory);
}

/// \brief `gsl::finally`
TEST(flow_control, gsl_finally)
{
    const auto memory {std::malloc(sizeof(std::byte))};
    if (memory == nullptr)
        FAIL();
    const auto memory_defer {gsl::finally([memory] { std::free(memory); })};
}

/// @}

}//namespace rrcxx::test
