/*===-- Variadic Functions -------------------------------------*- C -*-===*//**
 *
 * \defgroup g_time 日期和时间工具
 * \ingroup g_ref
 *
 * \sa ["Date and time utilities"](http://en.cppreference.com/w/c/chrono). *cppreference.com*.
 *
 * \author zhengrr
 * \date 2016-12-2 – 2-7
 * \copyright The MIT License
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <stdio.h>
#include <time.h>

#include "std.h"

#include "test.h"

/**
 * \brief 日历时间
 *
 * \sa ["tm"](http://en.cppreference.com/w/c/chrono/tm). *cppreference.com*.
 * \sa ["mktime"](http://en.cppreference.com/w/c/chrono/mktime). *cppreference.com*.
 */
START_TEST(calendar_time)
	struct tm olympic_games_2012 = {
		.tm_year = 2012 - 1900, .tm_mon = 7 - 1, .tm_mday = 27,
		.tm_hour = 0, .tm_min = 0, .tm_sec = 0,
		.tm_isdst = -1};

	printf("2012 olympic games, %d-%d-%d",
	       1900 + olympic_games_2012.tm_year,
	       1 + olympic_games_2012.tm_mon,
	       olympic_games_2012.tm_mday);

	olympic_games_2012.tm_mday += 16;
	mktime(&olympic_games_2012);

	printf(" ~ %d-%d-%d.\n",
	       1900 + olympic_games_2012.tm_year,
	       1 + olympic_games_2012.tm_mon,
	       olympic_games_2012.tm_mday);
END_TEST

/**
 * \brief 纪元时间
 *
 * \sa ["time_t"](http://en.cppreference.com/w/c/chrono/time_t). *cppreference.com*.
 * \sa ["time"](http://en.cppreference.com/w/c/chrono/time). *cppreference.com*.
 * \sa ["difftime"](http://en.cppreference.com/w/c/chrono/difftime). *cppreference.com*.
 * \sa ["what is the difference between difftime and '-'?"](https://stackoverflow.com/questions/13855890/). *Stack Overflow*.
 */
START_TEST(epoch_time)
	const time_t beg_time = time(NULL);
	const time_t end_time = time(NULL);
	printf("Running time: %g sec.\n",
	       difftime(end_time, beg_time));
END_TEST

/**
 * \brief 时钟时间
 *
 * \sa ["clock_t"](http://en.cppreference.com/w/c/chrono/clock_t). *cppreference.com*.
 * \sa ["time"](http://en.cppreference.com/w/c/chrono/time). *cppreference.com*.
 */
START_TEST(clock_time)
	const clock_t beg_clock = clock();
	const clock_t end_clock = clock();
	printf("Processor time used: %g sec.\n",
	       (end_clock - beg_clock) / (double) CLOCKS_PER_SEC);
END_TEST

/**
 * \brief 确切时间
 * \sa ["timespec"](http://en.cppreference.com/w/c/chrono/timespec). *cppreference.com*.
 */
START_TEST(specifying_time)
#if C11
	struct timespec time_in_seconds_and_nanoseconds;
#endif
END_TEST

/** @} */

TCase *time_tcs(void)
{
	TCase *tcs = tcase_create("time");
	tcase_add_test(tcs, calendar_time);
	tcase_add_test(tcs, epoch_time);
	tcase_add_test(tcs, clock_time);
	tcase_add_test(tcs, specifying_time);
	return tcs;
}
