/*===-- Clock Time ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup gClkTm 时钟时间
 * \ingroup gTime
 *
 * \version 2018-06-19
 * \since 2016-12-02
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
 *
*//*===--------------------------------------------------------------------===*/

#define __STDC_WANT_LIB_EXT1__ 1
#include <time.h>

#include <check/check.h>

#include "rrc/def.h"
#include "rrc/adp.h"

#include "_test.h"

/**
 * \brief 时钟时间。
 *
 * \sa ["clock_t"](http://en.cppreference.com/w/c/chrono/clock_t). *cppreference.com*.
 * \sa ["time"](http://en.cppreference.com/w/c/chrono/time). *cppreference.com*.
 */
START_TEST(test_clktm)
	const clock_t sclk = clock();  /**< start clock */
	const clock_t eclk = clock();  /**< end clock */
	const double spent = (sclk - eclk) / (double) CLOCKS_PER_SEC;

	UNUSED(spent);
END_TEST

/** @} */

TCase *tcase_clktm(void)
{
	TCase *tcase = tcase_create("clktm");
	tcase_add_test(tcase, test_clktm);
	return tcase;
}
