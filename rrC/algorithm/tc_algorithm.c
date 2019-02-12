/**
 * \addtogroup gAlgorithm
 * @{
 */

#include <stdlib.h>

#include <check.h>

#include "ts_algorithm.h"

static int cmp(const void *lhs, const void *rhs)
{
    const int l = *(const int *)lhs;
    const int r = *(const int *)rhs;
    return (l > r) - (l < r);
}

/**
 * \brief 快速排序（Quick Sort）
 * \details 对一个范围内的拥有一定未指定类型的元素排序。
 * \remark 虽然名字是快速排序，但实际上 C 标准没有限定其实现方式。
 *
 * \sa <http://zh.cppreference.com/w/c/algorithm/qsort>
 */
START_TEST(tf_qsort)
{
    int data[] = {5, 3, 2, 1, 6, 8, 0, 4, 9, 7};
    const size_t size = sizeof data[0];
    const size_t count = sizeof data / sizeof data[0];

    qsort(data, count, size, cmp);

    for (size_t i = 0; i < count; ++i)
        ck_assert_int_eq(data[i], i);
}
END_TEST;

/**
 * \brief 二分查找（Binary Search）
 * \details 在未指定类型的数组中搜索一个元素。
 * \remark 虽然名字是二分查找，但实际上 C 标准没有限定其实现方式。
 *
 * \pre 待搜索数组必须是有序的。
 *
 * \sa <http://zh.cppreference.com/w/c/algorithm/bsearch>
 */
START_TEST(tf_bsearch)
{
    const int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    const size_t size = sizeof data[0];
    const size_t count = sizeof data / sizeof data[0];

    const int key = 6;

    const int *const rst = bsearch(&key, data, count, size, cmp);

    if (rst)
        ck_assert_int_eq(*rst, 6);
    else
        ck_abort();
}
END_TEST;

/**
 * @}
 */

TCase *tc_algorithm(void)
{
    TCase *const tc = tcase_create("algorithm");
    tcase_add_test(tc, tf_qsort);
    tcase_add_test(tc, tf_bsearch);
    return tc;
}
