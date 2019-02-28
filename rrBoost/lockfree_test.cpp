//===-- Lockfree ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Lockfree
/// \sa <https://boost.org/doc/libs/1_69_0/doc/html/lockfree.html>
///
/// \version 2019-02-28
/// \since 2019-02-28
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <boost/lockfree/queue.hpp>
#include <gtest/gtest.h>

using namespace std;
namespace lockfree = boost::lockfree;

namespace rrboost {

/// \details 支持多个生产者、多个消费者的无锁队列
TEST(lockfree, queue)
{
}

/// \details 支持多个生产者、多个消费者的无锁栈
TEST(lockfree, stack)
{}

/// \details 支持单个生产者、单个消费者的无锁队列，较 `queue` 效率更高
TEST(lockfree, spsc_queue)
{}

}//namespace rrboost
