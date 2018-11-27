/*===-- Date and Time Utilities --------------------------------*- C -*-===*//**
 *
 * \defgroup gTime 日期和时间工具
 * \ingroup gRef
 *
 * \sa ["日期和时间工具"](https://zh.cppreference.com/w/c/chrono). *cppreference.com*.
 *
 * \version 2018-11-27
 * \since 2016-12-02
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#pragma warning(push)
#pragma warning(disable: 4820)

#include <time.h>

#include <check/check.h>

#pragma warning(pop)

#include "_test.h"
#include "c_versions.h"

#pragma warning(disable: 4100)

/**
 * \brief 日历时间。
 *        Calendar Time.
 *
 * \sa ["tm"](http://en.cppreference.com/w/c/chrono/tm). *cppreference.com*.
 * \sa ["mktime"](http://en.cppreference.com/w/c/chrono/mktime). *cppreference.com*.
 */
START_TEST(tf_struct_tm)
{
    struct tm time;
    memset(&time, 0x00, sizeof time);
    time.tm_sec = 0;             /*[0, 60]*/
    time.tm_min = 0;             /*[0, 59]*/
    time.tm_hour = 0;            /*[0, 23]*/
    time.tm_mday = 1;            /*[1, 31]*/
    time.tm_mon = 1 - 1;         /*[0, 11]*/
    time.tm_year = 1900 - 1900;  /*[0, ∞)*/
    mktime(&time);
}
END_TEST;

/**
 * \brief 纪元时间。
 *        Epoch Time.
 *
 * \sa ["time_t"](http://en.cppreference.com/w/c/chrono/time_t). *cppreference.com*.
 * \sa ["time"](http://en.cppreference.com/w/c/chrono/time). *cppreference.com*.
 * \sa ["difftime"](http://en.cppreference.com/w/c/chrono/difftime). *cppreference.com*.
 * \sa ["what is the difference between difftime and '-'?"](https://stackoverflow.com/questions/13855890/). *Stack Overflow*.
 */
START_TEST(tf_time_t)
{
    time_t start;
    time(&start);
    time_t end;
    time(&end);
    const double costs = difftime(start, end);
    (void)costs;
}
END_TEST;

/**
 * \brief 处理器时间。
 *        Processor Time.
 *
 * \sa ["clock_t"](http://en.cppreference.com/w/c/chrono/clock_t). *cppreference.com*.
 * \sa ["time"](http://en.cppreference.com/w/c/chrono/time). *cppreference.com*.
 */
START_TEST(tf_clock_t)
{
    const clock_t start = clock();
    const clock_t end = clock();
    const double costs = (start - end) / (double)CLOCKS_PER_SEC;
    (void)costs;
}
END_TEST;

/**
 * \brief 秒和纳秒时间。
 *
 * \sa ["timespec"](http://en.cppreference.com/w/c/chrono/timespec). *cppreference.com*.
 */
START_TEST(tf_timespec)
{
#if C11
    struct timespec spec;
    timespec_get(&spec, TIME_UTC);
#endif
}
END_TEST;

/**
 * \brief 纪元时间到日历时间。
 */
START_TEST(tf_time_t_2_struct_tm)
{
    struct tm utc;
    struct tm local;

    time_t epoch;
    time(&epoch);

#if LIB_EXT1
    gmtime_s(&utc, &epoch);
#else
    memcpy(&utc, gmtime(&epoch), sizeof utc);
#endif

#if LIB_EXT1
    localtime_s(&local, &epoch);
#else
    memcpy(&local, localtime(&epoch), sizeof local);
#endif
}
END_TEST;

/** @} */

TCase *tc_date_and_time_utilities(void)
{
    TCase *const tc = tcase_create("date_and_time_utilities");
    tcase_add_test(tc, tf_struct_tm);
    tcase_add_test(tc, tf_time_t);
    tcase_add_test(tc, tf_clock_t);
    tcase_add_test(tc, tf_timespec);
    tcase_add_test(tc, tf_time_t_2_struct_tm);
    return tc;
}
