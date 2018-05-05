/*===-- Algorithms ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup gAlgo 算法
 * \ingroup gRef
 *
 * \sa ["Algorithms"](http://en.cppreference.com/w/c/algorithm). *cppreference.com*.
 *
 * \version 2018-04-27
 * \since 2018-01-17
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <stdbool.h>
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

/** \brief 更快排序（Quicker Sort）。
 *         对一个范围内的拥有一定未指定类型的元素排序。
 *  \remark 虽然名字是更快排序，但实际上C标准并未限定其实现方式。
 *  \sa <http://en.cppreference.com/w/c/algorithm/qsort> */
START_TEST(test_qsort)
	int data[] = {3, 0, 2, 1};
	qsort(data, countof(data), sizeof(data[0]), cmp);
	ck_assert_int_eq(data[0], 0);
	ck_assert_int_eq(data[1], 1);
	ck_assert_int_eq(data[2], 2);
	ck_assert_int_eq(data[3], 3);
END_TEST

/** \brief 二分搜索（Binary Search）。
 *         在未指定类型的数组中搜索一个元素。
 *  \note 待搜索数组必须是有序的。
 *  \sa <http://en.cppreference.com/w/c/algorithm/bsearch> */
START_TEST(test_bsearch)
	int data[] = {3, 0, 2, 1};
	const int key = 2;

	qsort(data, countof(data), sizeof(data[0]), cmp);
	const int *const rst = bsearch(
		&key, data, countof(data), sizeof(data[0]), cmp);

	if (rst)
		ck_assert_int_eq(*rst, 2);
	else
		ck_assert(false);
END_TEST

/** @} */

TCase *tcase_algo(void)
{
	TCase *tcase = tcase_create("algo");

	tcase_add_test(tcase, test_qsort);
	tcase_add_test(tcase, test_bsearch);

	return tcase;
}
