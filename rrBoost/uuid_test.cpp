//===-- Universally Unique Identifier ---------------------------*- C++ -*-===//
///
/// \file
/// \brief Universally Unique Identifier
/// \sa <https://boost.org/doc/libs/1_68_0/libs/uuid/doc/index.html>
///
/// \version 2019-07-10
/// \since 2018-10-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace rrboost {

TEST(uuid, great_first_step)
{
    boost::uuids::random_generator gen;
    const auto uuid = gen();
    cout << "UUID: " << boost::uuids::to_string(uuid);
}

}//namespace rrboost
