/*===-- Algorithms ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup gAlgo 算法
 * \ingroup gRef
 *
 * \sa ["算法"](https://zh.cppreference.com/w/c/algorithm). *cppreference.com*.
 *
 * \version 2018-12-29
 * \since 2018-06-20
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#pragma warning(push)
#pragma warning(disable: 4668)

#include <stdlib.h>

#include <check/check.h>

#pragma warning(pop)

#include "_test.h"

#pragma warning(disable: 4100)

#define countof(array) (sizeof(array) / sizeof((array)[0]))

static int cmp(const void *lhs, const void *rhs)
{
    const int l = *(const int *)lhs;
    const int r = *(const int *)rhs;
    return (l > r) - (l < r);
}

/**
 * \brief 快速排序。
 *        Quick Sort.
 * \details 对一个范围内的拥有一定未指定类型的元素排序。
 * \remark 虽然名字是快速排序，但实际上 C 标准没有限定其实现方式。
 *
 * \sa <http://zh.cppreference.com/w/c/algorithm/qsort>
 */
START_TEST(tf_qsort)
{
    int data[] = {3, 0, 2, 1};

    qsort(data, countof(data), sizeof data[0], cmp);

    ck_assert_int_eq(data[0], 0);
    ck_assert_int_eq(data[1], 1);
    ck_assert_int_eq(data[2], 2);
    ck_assert_int_eq(data[3], 3);
}
END_TEST;

/**
 * \brief 二分查找。
 *        Binary Search.
 * \details 在未指定类型的数组中搜索一个元素。
 * \remark 虽然名字是二分查找，但实际上 C 标准没有限定其实现方式。
 *
 * \pre 待搜索数组必须是有序的。
 *
 * \sa <http://zh.cppreference.com/w/c/algorithm/bsearch>
 */
START_TEST(tf_bsearch)
{
    const int data[] = {0, 1, 2, 3};
    const int key = 2;

    const int *const rst = bsearch(&key, data, countof(data), sizeof data[0], cmp);

    if (rst)
        ck_assert_int_eq(*rst, 2);
    else
        ck_abort();
}
END_TEST;

/** @} */

TCase *tc_algorithms(void)
{
    TCase *const tc = tcase_create("algorithms");
    tcase_add_test(tc, tf_qsort);
    tcase_add_test(tc, tf_bsearch);
    return tc;
}
