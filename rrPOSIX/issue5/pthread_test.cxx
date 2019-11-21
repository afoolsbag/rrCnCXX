//===-- POSIX Threads -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 可移植操作系统接口线程。
///
/// \version 2019-06-04
/// \since 2019-02-15
// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdio>

#include <pthread.h>

#include <gtest/gtest.h>

static void *thrd_func(void *data)
{
    puts("Buling Bulo，我是个机器人～");
    return NULL;
}

TEST(pthread, pthreads)
{
    pthread_t thrd;
    ASSERT_TRUE(!pthread_create(&thrd, NULL, thrd_func, NULL));
    ASSERT_TRUE(!pthread_join(thrd, NULL));
}
