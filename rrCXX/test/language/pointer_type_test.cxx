//===-- Pointer Type --------------------------------------------*- C++ -*-===//
///
/// \defgroup gPtr 指针类型
/// \ingroup gGen
///
/// \version 2018-09-20
/// \since 2018-09-20
/// \author zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <gsl/gsl>

#include <gtest/gtest.h>

namespace rrcxx::test {

/// \addtogroup gPtr
/// @{

/// \brief 具所有权指针。
TEST(pointer, gsl_owner)
{
    const auto new_int {[]() -> gsl::owner<int *> {
        return new int;
    }};

    const auto p {new_int()};
    delete p;
}

/// \brief 非空指针。
TEST(pointer, gsl_not_null)
{}

/// @}

}//namespace rrcxx::test
