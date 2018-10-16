//===-- Universally Unique Identifier ---------------------------*- C++ -*-===//
///
/// \file
/// \brief Universally Unique Identifier
/// \sa <https://boost.org/doc/libs/1_68_0/libs/uuid/doc/index.html>
///
/// \version 2018-10-15
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
    using namespace boost::uuids;

    random_generator gen;
    uuid id {gen()};
}

}//namespace rrboost::test
