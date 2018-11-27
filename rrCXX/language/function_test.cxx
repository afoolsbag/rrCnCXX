//===-- Function ------------------------------------------------*- C++ -*-===//
///
/// \defgroup gFunction 函数
/// \ingroup gLanguage
///
/// \version 2018-11-27
/// \since 2018-09-20
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma warning(push)
#pragma warning(disable: 4514 4571 4623 4625 4626 4668 4710 4774 4820 5026 5027)

#include <gsl/gsl>

#include <gtest/gtest.h>

#pragma warning(pop)

using namespace gsl;

namespace rrcxx {

/// \addtogroup gFunction
/// @{

/// \brief 带前置和后置条件的函数。
/// \pre `0 <= width && 0 <= height`
/// \post `0 <= return_value`
static int area(const int width, const int height)
{
    Expects(0 <= width && 0 <= height);

    const int return_value = width * height;

    Ensures(0 <= return_value);
    return return_value;
}

TEST(function, expects_ensures)
{
    area(2, 3);
}

/// @}

}//namespace rrcxx
