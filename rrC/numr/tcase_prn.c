/*===-- Pseudo-Random Number -----------------------------------*- C -*-===*//**
 *
 * \defgroup gPRN 伪随机数
 * \ingroup gNumr
 *
 * \sa ["Pseudo-random number generation"](http://en.cppreference.com/w/c/numeric/random). *cppreference.com*.
 *
 * \version 2018-04-25
 * \since 2016-10-10
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdlib.h>
#include <time.h>

#include <check/check.h>

#include "numr/tsuite_numr.h"

/** \brief Generate Pseudo-Random Number (By Current Time).
 *         依据当前时间生成伪随机数。
 *  \returns 生成的伪随机数，范围在 [0, RAND_MAX]。 */
static int genprn(void)
{
	srand((unsigned) time(NULL));
	return rand();
}

START_TEST(test_genpr)
	genprn();
END_TEST

/** @} */

TCase *tcase_prn(void)
{
	TCase *tcase = tcase_create("prn");
	tcase_add_test(tcase, test_genpr);
	return tcase;
}
