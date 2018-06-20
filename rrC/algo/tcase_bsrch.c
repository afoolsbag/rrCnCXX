/*===-- Binary Search  -----------------------------------------*- C -*-===*//**
 *
 * \defgroup gBSrch 二分搜索
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
 * \brief 二分搜索（Binary Search）。
 * \details 在未指定类型的数组中搜索一个元素。
 * \note 待搜索数组必须是有序的。
 *
 * \sa <http://en.cppreference.com/w/c/algorithm/bsearch>
 */
START_TEST(test_bsearch)
	int data[] = {3, 0, 2, 1};
	qsort(data, countof(data), sizeof(data[0]), cmp);
	const int key = 2;

	const int *const rst =
		bsearch(&key, data, countof(data), sizeof(data[0]), cmp);

	if (rst)
		ck_assert_int_eq(*rst, 2);
	else
		ck_assert(false);
END_TEST

/** @} */

TCase *tcase_bsrch(void)
{
	TCase *tcase = tcase_create("bsrch");
	tcase_add_test(tcase, test_bsearch);
	return tcase;
}
