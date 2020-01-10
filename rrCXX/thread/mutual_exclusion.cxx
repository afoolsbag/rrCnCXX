//===-- Mutual Exclusion ----------------------------------------*- C++ -*-===//
///
/// \defgroup groupMutualExclusion 互斥
/// \ingroup groupThread
///
/// \version 2020-01-09
/// \since 2019-07-29
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <mutex>
#include <shared_mutex>

#include <gtest/gtest.h>

#include "cxx_versions.hxx"

using namespace std;

namespace rrcxx {
/// @addtogroup groupMutualExclusion
/// @{

/// \brief 互斥量
TEST(mutual_exclusion, mutex)
{
    static mutex mtx;

    // 锁定互斥，若互斥不可用则阻塞等待
    mtx.lock();
    // ...
    mtx.unlock();

    // 尝试锁定互斥，若互斥不可用则返回
    if (mtx.try_lock()) {
        // ...
        mtx.unlock();
    }
}

/// \brief 严格基于作用域、RAII 风格的单互斥量所有权包装器
TEST(mutual_exclusion, lock_guard)
{
    static mutex mtx;

    lock_guard lg {mtx};
    // ...
}

/// \brief 严格基于作用域、RAII 风格的多互斥量所有权包装器
TEST(mutual_exclusion, scoped_lock)
{
    static mutex mtx1, mtx2;

    scoped_lock sl {mtx1, mtx2};
    // ...
}

/// \brief 可移动的互斥量所有权包装器
TEST(mutual_exclusion, unique_lock)
{
    
}

/// \brief 共享互斥量
TEST(mutual_exclusion, shared_mutex)
{
    static shared_mutex mtx;

    // “写”锁定：同一时间，仅允许单个线程独占此互斥量
    // 若互斥量已被其它线程独占、或已被共享，则此时此线程无法独占此互斥量，阻塞等待
    mtx.lock();
    // ...
    mtx.unlock();

    // “读”锁定：同一时间，可以有多个线程共享此互斥量
    // 若互斥量已被独占，则此时此线程无法共享此互斥量，阻塞等待
    mtx.lock_shared();
    // ...
    mtx.unlock_shared();
}

/// \brief 可移动的共享互斥量所有权包装器
TEST(mutual_exclusion, shared_lock)
{
    
}

/// @}
}
