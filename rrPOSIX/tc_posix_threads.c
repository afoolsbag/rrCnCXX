/*===-- POSIX Threads ------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 可移植操作系统接口线程。
 *
 * \version 2019-02-18
 * \since 2019-02-15
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>

#include <pthread.h>

#include <check.h>

#include "ts.h"

static void *thrd_func(void *data)
{
    puts("Buling Bulo，我是个机器人～");
    return NULL;
}

START_TEST(tf_pthreads)
{
    pthread_t thrd;
    ck_assert(!pthread_create(&thrd, NULL, thrd_func, NULL));
    ck_assert(!pthread_join(thrd, NULL));
}
END_TEST;

TCase *tc_posix_threads(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_pthreads);
    return tc;
}
