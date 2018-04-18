/*===-- Algorithms ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup g_algo 算法
 * \ingroup g_ref
 *
 * \sa ["Algorithms"](http://en.cppreference.com/w/c/algorithm). *cppreference.com*.
 *
 * \version 2018-04-17
 * \date 2018-01-17
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <stdlib.h>

#include <check/check.h>

#include "algo/tsuite_algo.h"

static int compare_ints(const void *left_value, const void *right_value)
{
	const int left_int = *(const int *) left_value;
	const int right_int = *(const int *) right_value;
	return (left_int > right_int) - (left_int < right_int);
}

START_TEST(test_qsort)
	int array[] = {3, 0, 2, 1};
	qsort(array, sizeof array / sizeof *array, sizeof *array, compare_ints);
	ck_assert_int_eq(array[0], 0);
	ck_assert_int_eq(array[1], 1);
	ck_assert_int_eq(array[2], 2);
	ck_assert_int_eq(array[3], 3);
END_TEST

/** @} */

TCase *tcase_algo(void)
{
	TCase *tcase = tcase_create("algo");

	tcase_add_test(tcase, test_qsort);

	return tcase;
}
