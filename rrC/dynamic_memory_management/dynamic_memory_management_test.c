/*===-- C Memory Management Library ----------------------------*- C -*-===*//**
 *
 * \defgroup gMem C 内存管理库
 * \ingroup gRef
 *
 * \sa ["C 内存管理库"](http://zh.cppreference.com/w/c/memory). *cppreference.com*.
 *
 * \version 2018-07-10
 * \since 2016-12-02
 * \authors zhengrr
 * \copyright The Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <stdint.h>
#include <stdlib.h>

#include <check/check.h>

#include "_test.h"

/**
 * \brief 分配内存。
 *        Memory Allocation.
 *
 * \sa <http://zh.cppreference.com/w/c/memory/malloc>
 * \sa <http://zh.cppreference.com/w/c/memory/free>
 */
START_TEST(tf_malloc)
{
    uint8_t *p = malloc(sizeof(uint8_t));
    if (!p) {
        ck_abort_msg("Not Enough Memory");
        return;
    }

    *p = UINT8_MAX;
    ck_assert_int_eq(*p, UINT8_MAX);

    free(p);
    p = NULL;
}
END_TEST;

/**
 * \brief 分配并清零内存。
 *        Clear Allocation.
 *
 * \sa <http://zh.cppreference.com/w/c/memory/calloc>
 */
START_TEST(tf_calloc)
{
    int *p = calloc(1, sizeof(int));
    if (!p) {
        ck_abort_msg("Not Enough Memory");
        return;
    }

    ck_assert_int_eq(*p, 0);

    free(p);
    p = NULL;
}
END_TEST;

/**
 * \brief 重新分配内存。
 *        Re-Allocation.
 *
 * \sa <http://zh.cppreference.com/w/c/memory/realloc>
 */
START_TEST(tf_realloc)
{
    uint8_t *p = realloc(NULL, 1 * sizeof(uint8_t));
    if (!p) {
        ck_abort_msg("Not Enough Memory");
        return;
    }

    *p = UINT8_MAX;
    ck_assert_int_eq(*p, UINT8_MAX);

    uint8_t *tmp = p;
    p = realloc(tmp, 2 * sizeof(uint8_t));
    if (!p) {
        free(tmp);
        ck_abort_msg("Not Enough Memory");
        return;
    }
    tmp = NULL;

    p[1] = UINT8_MAX;
    ck_assert_int_eq(p[0], UINT8_MAX);
    ck_assert_int_eq(p[1], UINT8_MAX);

    free(p);
    p = NULL;
}
END_TEST;

/** @} */

TCase *tc_dynamic_memory_management(void)
{
    TCase *const tc = tcase_create("dynamic_memory_management");
    tcase_add_test(tc, tf_malloc);
    tcase_add_test(tc, tf_calloc);
    tcase_add_test(tc, tf_realloc);
    return tc;
}
