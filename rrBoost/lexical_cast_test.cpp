//===-- Lexical Cast --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Lexical Cast
/// \sa <https://boost.org/doc/libs/1_68_0/doc/html/boost_lexical_cast.html>
///
/// \version 2018-10-17
/// \since 2018-10-15
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <boost/lexical_cast.hpp>
#include <gtest/gtest.h>

namespace rrboost::test {

TEST(lexical_cast, string_2_number)
{
    try {
        boost::lexical_cast<short>("32767");
    } catch (const boost::bad_lexical_cast &e) {
        FAIL() << e.what();
    }

    ASSERT_THROW(boost::lexical_cast<uint8_t>("32768"), boost::bad_lexical_cast);
}

}//namespace rrboost::test
