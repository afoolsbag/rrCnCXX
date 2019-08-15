//===-- Lexical Cast --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Lexical Cast
/// \sa <https://boost.org/doc/libs/1_68_0/doc/html/boost_lexical_cast.html>
///
/// \version 2019-07-10
/// \since 2018-10-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdint>

#include <boost/lexical_cast.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace rrboost {

TEST(lexical_cast, string_to_number)
{
    ASSERT_NO_THROW(boost::lexical_cast<int16_t>("32767"));
    ASSERT_THROW(boost::lexical_cast<uint8_t>("32768"), boost::bad_lexical_cast);
}

}
