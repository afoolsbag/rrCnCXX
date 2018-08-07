/*===-- Epoch Time ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup gEpoTm 纪元时间
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

#include "rrC/def.h"
#include "rrC/cver.h"

#include "test.h"

/**
 * \brief 纪元时间。
 *
 * \sa ["time_t"](http://en.cppreference.com/w/c/chrono/time_t). *cppreference.com*.
 * \sa ["time"](http://en.cppreference.com/w/c/chrono/time). *cppreference.com*.
 * \sa ["difftime"](http://en.cppreference.com/w/c/chrono/difftime). *cppreference.com*.
 * \sa ["what is the difference between difftime and '-'?"](https://stackoverflow.com/questions/13855890/). *Stack Overflow*.
 */
START_TEST(test_epotm)
	time_t sepo;  /**< start epoch */
	time(&sepo);
	time_t eepo;  /**< end epoch */
	time(&eepo);
	const double spent = difftime(sepo, eepo);

	UNUSED(spent);
END_TEST

/** @} */

TCase *tcase_epotm(void)
{
	TCase *tcase = tcase_create("epotm");
	tcase_add_test(tcase, test_epotm);
	return tcase;
}
