//===-- Lockfree ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Lockfree
/// \sa <https://boost.org/doc/libs/1_69_0/doc/html/lockfree.html>
///
/// \version 2019-09-03
/// \since 2019-02-28
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <boost/lockfree/queue.hpp>
#include <boost/lockfree/spsc_queue.hpp>
#include <boost/lockfree/stack.hpp>
#include <gtest/gtest.h>

using namespace std;
namespace blf = boost::lockfree;

namespace rrboost {

/// \details 支持多个生产者、多个消费者的无锁队列
TEST(lockfree, queue)
{
    blf::queue<int> queue {100};
}

/// \details 支持多个生产者、多个消费者的无锁栈
TEST(lockfree, stack)
{
    blf::stack<int> stack {100};
}

/// \details 支持单个生产者、单个消费者的无锁队列，较 `queue` 效率更高
TEST(lockfree, spsc_queue)
{
    blf::spsc_queue<int> spsc_queue {100};
}

}//namespace rrboost
