/*===-- Calendar Time ------------------------------------------*- C -*-===*//**
 *
 * \defgroup gCalTm 日历时间
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
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

#include <check/check.h>

#include "rrc/ver.h"

#include "test.h"

/**
 * \brief 日历时间。
 *
 * \sa ["tm"](http://en.cppreference.com/w/c/chrono/tm). *cppreference.com*.
 * \sa ["mktime"](http://en.cppreference.com/w/c/chrono/mktime). *cppreference.com*.
 */
START_TEST(test_caltm)
{
    struct tm caltm;  /**< calendar time */
    memset(&caltm, 0x00, sizeof(caltm));
    caltm.tm_sec = 0;             /*[0, 60]*/
    caltm.tm_min = 0;             /*[0, 59]*/
    caltm.tm_hour = 0;            /*[0, 23]*/
    caltm.tm_mday = 1;            /*[1, 31]*/
    caltm.tm_mon = 1 - 1;         /*[0, 11]*/
    caltm.tm_year = 1900 - 1900;  /*[0, ∞)*/
    mktime(&caltm);
    ck_assert_str_eq(asctime(&caltm), "Sun Jan  1 00:00:00 1900\n");
}
END_TEST;

/**
 * \brief 从纪元时间转换到日历时间。
 */
START_TEST(test_caltm_from_epochtm)
{
    struct tm utctm;  /**< utc (calendar) time */
    struct tm lcltm;  /**< local (calendar) time */

    time_t epochtm;  /**< epoch time */
    time(&epochtm);

#if LIB_EXT1
    gmtime_s(&utctm, &epochtm);
#else
    memcpy(&utctm, gmtime(&epochtm), sizeof(utctm));
#endif

#if LIB_EXT1
    localtime_s(&lcltm, &epochtm);
#else
    memcpy(&lcltm, localtime(&epochtm), sizeof(lcltm));
#endif
}
END_TEST;

/** @} */

TCase *tcase_caltm(void)
{
    TCase *tcase = tcase_create("caltm");
    tcase_add_test(tcase, test_caltm);
    tcase_add_test(tcase, test_caltm_from_epochtm);
    return tcase;
}
