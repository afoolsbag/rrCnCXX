/*===-- C Memory Management Library ----------------------------*- C -*-===*//**
 *
 * \defgroup gMem C内存管理库
 * \ingroup gRef
 *
 * \sa ["C 内存管理库"](http://zh.cppreference.com/w/c/memory). *cppreference.com*.
 *
 * \version 2018-07-10
 * \since 2016-12-02
 * \authors zhengrr
 * \copyright The MIT License
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
START_TEST(test_malloc)
{
    uint8_t *int_ptr = malloc(sizeof(uint8_t));
    if (NULL == int_ptr) {
        ck_abort_msg("Not Enough Memory");
        return;
    }

    *int_ptr = UINT8_MAX;
    ck_assert_int_eq(*int_ptr, UINT8_MAX);

    free(int_ptr);
    int_ptr = NULL;

    (void)int_ptr;
}
END_TEST;

/**
 * \brief 分配并清零内存。
 *        Clear Allocation.
 *
 * \sa <http://zh.cppreference.com/w/c/memory/calloc>
 */
START_TEST(test_calloc)
{
    int *int_ptr = calloc(1, sizeof(int));
    if (NULL == int_ptr) {
        ck_abort_msg("Not Enough Memory");
        return;
    }

    ck_assert_int_eq(*int_ptr, 0);

    free(int_ptr);
    int_ptr = NULL;

    (void)int_ptr;
}
END_TEST;

/**
 * \brief 重新分配内存。
 *        Re-Allocation.
 *
 * \sa <http://zh.cppreference.com/w/c/memory/realloc>
 */
START_TEST(test_realloc)
{
    uint8_t *int_ptr = realloc(NULL, 1 * sizeof(uint8_t));
    if (NULL == int_ptr) {
        ck_abort_msg("Not Enough Memory");
        return;
    }

    *int_ptr = UINT8_MAX;
    ck_assert_int_eq(*int_ptr, UINT8_MAX);

    uint8_t *temp_ptr = int_ptr;
    int_ptr = realloc(temp_ptr, 2 * sizeof(uint8_t));
    if (NULL == int_ptr) {
        free(int_ptr);
        ck_abort_msg("Not Enough Memory");
        return;
    }
    temp_ptr = NULL;

    int_ptr[1] = UINT8_MAX;
    ck_assert_int_eq(int_ptr[0], UINT8_MAX);
    ck_assert_int_eq(int_ptr[1], UINT8_MAX);

    free(int_ptr);
    int_ptr = NULL;

    (void)temp_ptr;
    (void)int_ptr;
}
END_TEST;

/** @} */

TCase *tcase_mem(void)
{
    TCase *tcase = tcase_create("mem");
    tcase_add_test(tcase, test_malloc);
    tcase_add_test(tcase, test_calloc);
    tcase_add_test(tcase, test_realloc);
    return tcase;
}
