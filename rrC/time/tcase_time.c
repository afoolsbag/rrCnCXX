/*===-- Date and Time Utilities --------------------------------*- C -*-===*//**
 *
 * \defgroup gTime 日期和时间工具
 * \ingroup gRef
 *
 * \sa ["Date and time utilities"](http://en.cppreference.com/w/c/chrono). *cppreference.com*.
 *
 * \version 2018-04-18
 * \since 2016-12-02
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <time.h>

#include <check/check.h>

#include "cver.h"
#include "time/tsuite_time.h"

/**
 * \brief 初始化日历时间。
 *        Initialize calendar-time.
 */
static
struct tm *
init_caltm(struct tm *const caltmptr,
	   const int years, const int months, const int days,
	   const int hours, const int minutes, const int seconds)
{
	memset(caltmptr, 0x00, sizeof(*caltmptr));
	caltmptr->tm_sec = seconds;
	caltmptr->tm_min = minutes;
	caltmptr->tm_hour = hours;
	caltmptr->tm_mday = days;
	caltmptr->tm_mon = months - 1;
	caltmptr->tm_year = years - 1900;
	mktime(caltmptr);
	return caltmptr;
}

/**
 * \brief Initialize calendar-time date.
 */
static
struct tm *
init_caltm_date(struct tm *const caltmptr,
		const int years, const int months, const int days)
{
	return init_caltm(caltmptr, years, months, days, 0, 0, 0);
}

/**
 * \brief 日历时间。
 * \sa ["tm"](http://en.cppreference.com/w/c/chrono/tm). *cppreference.com*.
 * \sa ["mktime"](http://en.cppreference.com/w/c/chrono/mktime). *cppreference.com*.
 */
START_TEST(test_calendar_time)
	struct tm beijing2008;
	init_caltm_date(&beijing2008, 2008, 8, 8);
	ck_assert_str_eq(asctime(&beijing2008), "Fri Aug 08 00:00:00 2008\n");

	time_t epochtm = time(NULL);  /* epoch tm */
	struct tm utctm;  /* utc time */
	memcpy(&utctm, gmtime(&epochtm), sizeof(struct tm));
	struct tm lcltm;  /* local time */
	memcpy(&lcltm, localtime(&epochtm), sizeof(struct tm));
END_TEST

/**
 * \brief 纪元时间。
 * \sa ["time_t"](http://en.cppreference.com/w/c/chrono/time_t). *cppreference.com*.
 * \sa ["time"](http://en.cppreference.com/w/c/chrono/time). *cppreference.com*.
 * \sa ["difftime"](http://en.cppreference.com/w/c/chrono/difftime). *cppreference.com*.
 * \sa ["what is the difference between difftime and '-'?"](https://stackoverflow.com/questions/13855890/). *Stack Overflow*.
 */
START_TEST(test_epoch_time)
	const time_t begin_time = time(NULL);
	const time_t end_time = time(NULL);
	const double running_time = difftime(end_time, begin_time);

	(void) running_time;
END_TEST

/**
 * \brief 时钟时间。
 * \sa ["clock_t"](http://en.cppreference.com/w/c/chrono/clock_t). *cppreference.com*.
 * \sa ["time"](http://en.cppreference.com/w/c/chrono/time). *cppreference.com*.
 */
START_TEST(test_clock_time)
	const clock_t begin_clock = clock();
	const clock_t end_clock = clock();
	const double processor_time =
		(end_clock - begin_clock) / (double) CLOCKS_PER_SEC;

	(void) processor_time;
END_TEST

/**
 * \brief 确切时间。
 * \sa ["timespec"](http://en.cppreference.com/w/c/chrono/timespec). *cppreference.com*.
 */
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
