//===-- Universally Unique Identifier ---------------------------*- C++ -*-===//
///
/// \file
/// \brief Universally Unique Identifier
/// \sa <https://boost.org/doc/libs/1_68_0/libs/uuid/doc/index.html>
///
/// \version 2018-10-17
/// \since 2018-10-15
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid.hpp>
#include <gtest/gtest.h>

namespace rrboost::test {

TEST(uuid, first_step)
{
    boost::uuids::random_generator gen;
    const auto uuid {gen()};
}

}//namespace rrboost::test
