//===-- Lexical Cast --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Lexical Cast
/// \sa <https://boost.org/doc/libs/1_68_0/doc/html/boost_lexical_cast.html>
///
/// \version 2018-10-16
/// \since 2018-10-15
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
using namespace std;

#include <boost/lexical_cast.hpp>
#include <gtest/gtest.h>

namespace rrboost::test {

TEST(lexical_cast, string_2_number)
{
    using namespace boost;

    try {
        lexical_cast<short>("32767");
    } catch (const bad_lexical_cast &e) {
        cerr << e.what() << "\n";
        FAIL();
    }

    ASSERT_THROW(lexical_cast<uint8_t>("32768"), bad_lexical_cast);
}

}//namespace rrboost::test
