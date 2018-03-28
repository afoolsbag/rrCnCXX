/*===-- Date and Time Utilities --------------------------------*- C -*-===*//**
 *
 * \defgroup g_time 日期和时间工具
 * \ingroup g_ref
 *
 * \sa ["Date and time utilities"](http://en.cppreference.com/w/c/chrono). *cppreference.com*.
 *
 * \version 2018-03-28
 * \since 2016-12-02
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <inttypes.h>
#include <time.h>

#include <check.h>
#include "std.h"
#include "time/tsuite_time.h"

/** \brief 日历时间
 *  \sa ["tm"](http://en.cppreference.com/w/c/chrono/tm). *cppreference.com*.
 *  \sa ["mktime"](http://en.cppreference.com/w/c/chrono/mktime). *cppreference.com*. */
START_TEST(test_calendar_time)
	struct tm beijing2008 = {
		.tm_year = 2008 - 1900, .tm_mon = 8 - 1, .tm_mday = 8,
		.tm_hour = 0, .tm_min = 0, .tm_sec = 0,
		.tm_isdst = -1};

	ck_assert_int_eq(1900 + beijing2008.tm_year, 2008);
	ck_assert_int_eq(1 + beijing2008.tm_mon, 8);
	ck_assert_int_eq(beijing2008.tm_mday, 8);

	beijing2008.tm_mday += 16;
	mktime(&beijing2008);

	ck_assert_int_eq(1900 + beijing2008.tm_year, 2008);
	ck_assert_int_eq(1 + beijing2008.tm_mon, 8);
	ck_assert_int_eq(beijing2008.tm_mday, 24);
END_TEST

/** \brief 纪元时间
 *  \sa ["time_t"](http://en.cppreference.com/w/c/chrono/time_t). *cppreference.com*.
 *  \sa ["time"](http://en.cppreference.com/w/c/chrono/time). *cppreference.com*.
 *  \sa ["difftime"](http://en.cppreference.com/w/c/chrono/difftime). *cppreference.com*.
 *  \sa ["what is the difference between difftime and '-'?"](https://stackoverflow.com/questions/13855890/). *Stack Overflow*. */
START_TEST(test_epoch_time)
	const time_t begin_time = time(NULL);
	const time_t end_time = time(NULL);
	const double running_time = difftime(end_time, begin_time);

	(void) running_time;
END_TEST

/** \brief 时钟时间
 *  \sa ["clock_t"](http://en.cppreference.com/w/c/chrono/clock_t). *cppreference.com*.
 *  \sa ["time"](http://en.cppreference.com/w/c/chrono/time). *cppreference.com*. */
START_TEST(test_clock_time)
	const clock_t begin_clock = clock();
	const clock_t end_clock = clock();
	const double processor_time =
		(end_clock - begin_clock) / (double) CLOCKS_PER_SEC;

	(void) processor_time;
END_TEST

/** \brief 确切时间
 *  \sa ["timespec"](http://en.cppreference.com/w/c/chrono/timespec). *cppreference.com*. */
START_TEST(test_specifying_time)
#if C11
/*
	struct timespec spec;
	timespec_get(&spec, TIME_UTC);
 */
#endif
END_TEST

/** @} */

TCase *tcase_time(void)
{
	TCase *tcase = tcase_create("time");

	tcase_add_test(tcase, test_calendar_time);
	tcase_add_test(tcase, test_epoch_time);
	tcase_add_test(tcase, test_clock_time);
	tcase_add_test(tcase, test_specifying_time);

	return tcase;
}
