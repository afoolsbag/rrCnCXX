/*===-- Algorithms ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup gAlgo 算法
 * \ingroup gRef
 *
 * \sa ["Algorithms"](http://en.cppreference.com/w/c/algorithm). *cppreference.com*.
 *
 * \version 2018-04-19
 * \date 2018-01-17
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <stdbool.h>
#include <stdlib.h>

#include <check/check.h>

#include "algo/tsuite_algo.h"

#define countof(array) (sizeof(array) / sizeof((array)[0]))

/**
 * \param lhs left hand side.
 * \param rhs right hand side.
 */
static int int_cmp(const void *lhs, const void *rhs)
{
	const int l = *(const int *) lhs;
	const int r = *(const int *) rhs;
	return (l > r) - (l < r);
}

START_TEST(test_qsort)
	int ints[] = {3, 0, 2, 1};
	qsort(ints, countof(ints), sizeof(ints[0]), int_cmp);
	ck_assert_int_eq(ints[0], 0);
	ck_assert_int_eq(ints[1], 1);
	ck_assert_int_eq(ints[2], 2);
	ck_assert_int_eq(ints[3], 3);
END_TEST

struct data_t {
	int id;
	void *ptr;
};

static int data_cmp(const void *lhs, const void *rhs)
{
	const struct data_t *const l = lhs;
	const struct data_t *const r = rhs;
	return (l->id > r->id) - (l->id < r->id);
}

START_TEST(test_bsearch)
	struct data_t data[] = {{.id = 3},
				{.id = 0},
				{.id = 2},
				{.id = 1}};
	const struct data_t key = {.id = 2};

	qsort(data, countof(data), sizeof(data[0]), data_cmp);
	const struct data_t *const rst
		= bsearch(&key, data, countof(data), sizeof(data[0]), data_cmp);

	if (rst)
		ck_assert_int_eq(rst->id, 2);
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
