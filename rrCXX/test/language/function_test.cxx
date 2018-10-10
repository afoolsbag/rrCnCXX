//===-- Function ------------------------------------------------*- C++ -*-===//
///
/// \defgroup gFunc 函数
/// \ingroup gLang
///
/// \version 2018-10-10
/// \since 2018-09-20
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <gsl/gsl>
using namespace gsl;

namespace rrcxx::test {

/// \addtogroup gFunc
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

/// @}

}//namespace rrcxx::test
