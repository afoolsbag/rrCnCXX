/*===-- Specifying Time ----------------------------------------*- C -*-===*//**
 *
 * \defgroup gSpecTm 确切时间
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
#include "rrc/ver.h"

#include "test.h"

/**
 * \brief 确切时间。
 *
 * \sa ["timespec"](http://en.cppreference.com/w/c/chrono/timespec). *cppreference.com*.
 */
START_TEST(test_spectm)
#if C11
	struct timespec spec;
	//timespec_get(&spec, TIME_UTC);
	UNUSED(spec);
#endif
END_TEST

/** @} */

TCase *tcase_spectm(void)
{
	TCase *tcase = tcase_create("spectm");
	tcase_add_test(tcase, test_spectm);
	return tcase;
}
