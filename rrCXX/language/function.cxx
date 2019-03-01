//===-- Function ------------------------------------------------*- C++ -*-===//
///
/// \defgroup gFunction 函数
/// \ingroup gLanguage
///
/// \version 2019-01-28
/// \since 2018-09-20
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <gsl/gsl>

#include <gtest/gtest.h>

using namespace gsl;

namespace rrcxx {

/// \addtogroup gFunction
/// @{

/// \brief 带前置和后置条件的函数。
/// \pre  `0 <= width && 0 <= height`
/// \post `0 <= return_value`
static int area(const int width, const int height)
{
    Expects(0 <= width && 0 <= height);

    const int area = width * height;

    Ensures(0 <= area);
    return area;
}

TEST(function, expects_ensures)
{
    area(2, 3);
}

/// @}

}//namespace rrcxx
