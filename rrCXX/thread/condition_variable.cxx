//===-- Condition Variable --------------------------------------*- C++ -*-===//
///
/// \defgroup gConditionVariable 条件变量
/// \ingroup gThread
///
/// \version 2019-07-29
/// \since 2019-07-29
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <condition_variable>
#include <mutex>
#include <thread>

#include <gtest/gtest.h>

#include "cxx_versions.hxx"

using namespace std;

namespace rrcxx {
/// @addtogroup gConditionVariable
/// @{

TEST(condition_variable, no_conditon)
{
    mutex mtx;
    condition_variable cv;

    bool worker_waiting {true};
    thread worker {[&] {
        unique_lock lk {mtx};  // 锁定互斥
        cv.wait(lk);           // 解锁互斥并等待通知
        worker_waiting = false;
    }};

    // 线程 worker 仍在等待通知
    this_thread::sleep_for(1ms);
    ASSERT_TRUE(worker_waiting);

    // 唤醒 worker
    cv.notify_one();
    this_thread::sleep_for(1ms);
    ASSERT_FALSE(worker_waiting);

    worker.join();
}

TEST(condition_variable, three_conditons)
{
    mutex mtx;
    condition_variable cv;
    bool cond1 {false}, cond2 {false}, cond3 {false};

    bool worker_waiting {true};
    thread worker {[&] {
        unique_lock lk {mtx};  // 锁定互斥
        cv.wait(lk, [&] {return cond1 && cond2 && cond3; });  // 解锁互斥、等待通知并判断条件
        worker_waiting = false;
    }};

    // 在互斥量锁定中改写条件
    {
        lock_guard lg {mtx};
        cond1 = true;
    }
    cv.notify_one();

    // 条件不符，线程 worker 仍在等待
    this_thread::sleep_for(1ms);
    ASSERT_TRUE(worker_waiting);

    // 在互斥量锁定中改写条件
    {
        lock_guard lg {mtx};
        cond2 = true;
        cond3 = true;
    }
    this_thread::sleep_for(1ms);
    ASSERT_TRUE(worker_waiting);

    // 条件符合，成功唤醒 worker
    cv.notify_one();
    this_thread::sleep_for(1ms);
    ASSERT_FALSE(worker_waiting);

    worker.join();
}

/// @}
}
