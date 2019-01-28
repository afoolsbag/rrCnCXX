/*===-- Atomic Operations --------------------------------------*- C -*-===*//**
 *
 * \defgroup gAtom 原子操作
 * \ingroup gRef
 *
 * \sa ["原子操作库"](https://zh.cppreference.com/w/c/atomic). *cppreference.com*.
 *
 * \version 2019-01-28
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <check/check.h>

#include "_test.h"
#include "c_versions.h"

#if ATOMICS
# include <stdatomic.h>
#endif

#pragma warning(disable: 4100)

START_TEST(tf_atomic_int)
{
#if ATOMICS
    atomic_int aint;
#endif
}
END_TEST;

/** @} */

TCase *tc_atomic_operations(void)
{
    TCase *const tc = tcase_create("atomic_operations");
    tcase_add_test(tc, tf_atomic_int);
    return tc;
}
