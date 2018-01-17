/**
 * \file
 * \brief 日期和时间工具
 * \sa ["Date and time utilities"](http://en.cppreference.com/w/c/chrono). *cppreference.com*.
 * \sa ["what is the difference between difftime and '-'?"](https://stackoverflow.com/questions/13855890/). *Stack Overflow*.
 * \author zhengrr
 * \date 2016-12-2 – 2018-1-17
 * \copyright The MIT License
 */

#include <stdio.h>
#include <time.h>

#include "c_standard_version.h"

/**
 * \brief 时间操作
 * \sa ["tm"](http://en.cppreference.com/w/c/chrono/tm). *cppreference.com*.
 * \sa ["time_t"](http://en.cppreference.com/w/c/chrono/time_t). *cppreference.com*.
 * \sa ["clock_t"](http://en.cppreference.com/w/c/chrono/clock_t). *cppreference.com*.
 * \sa ["timespec"](http://en.cppreference.com/w/c/chrono/timespec). *cppreference.com*.
 */
void time_manipulation(void)
{
	/* 分解时间 */
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
	printf("~ %d-%d-%d.\n",
	       1900 + olympic_games_2012.tm_year,
	       1 + olympic_games_2012.tm_mon,
	       olympic_games_2012.tm_mday);

	/* 日历时间 */
	const time_t beg_time = time(NULL);
	const time_t end_time = time(NULL);
	printf("Running time: %g sec.\n",
	       difftime(end_time, beg_time));

	/* 时钟时间 */
	const clock_t beg_clock = clock();
	const clock_t end_clock = clock();
	printf("Processor time used: %g sec.\n",
	       (end_clock - beg_clock) / (double) CLOCKS_PER_SEC);

#if CSTD11
	/* 规格时间 */
	struct timespec time_in_seconds_and_nanoseconds;
#endif
}

int main(void)
{
	time_manipulation();
}
