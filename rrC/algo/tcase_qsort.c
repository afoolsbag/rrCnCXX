/*===-- Quicker Sort -------------------------------------------*- C -*-===*//**
 *
 * \defgroup gQSort 更快排序
 * \ingroup gAlgo
 *
 * \version 2018-06-20
 * \since 2018-06-20
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <stdlib.h>

#include <check/check.h>

#include "cdef.h"
#include "tsuite_algo.h"

static int cmp(const void *lhs, const void *rhs)
{
	const int l = *(const int *) lhs;
	const int r = *(const int *) rhs;
	return (l > r) - (l < r);
}

/**
 * \brief 更快排序（Quicker Sort）。
 * \details 对一个范围内的拥有一定未指定类型的元素排序。
 * \remark 虽然名字是更快排序，但实际上C标准没有限定其实现方式。
 *
 * \sa <http://en.cppreference.com/w/c/algorithm/qsort>
 */
START_TEST(test_qsort)
	int data[] = {3, 0, 2, 1};
	qsort(data, countof(data), sizeof(data[0]), cmp);
	ck_assert_int_eq(data[0], 0);
	ck_assert_int_eq(data[1], 1);
	ck_assert_int_eq(data[2], 2);
	ck_assert_int_eq(data[3], 3);
END_TEST

/** @} */

TCase *tcase_qsort(void)
{
	TCase *tcase = tcase_create("qsort");
	tcase_add_test(tcase, test_qsort);
	return tcase;
}
