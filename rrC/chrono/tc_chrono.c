/**
 * \addtogroup gChrono
 * @{
 */

#include <stdio.h>
#include <time.h>

#include <check/check.h>

#include "ts_chrono.h"

#define countof(array) (sizeof(array) / sizeof((array)[0]))

/**
 * \brief POSIX 时间
 * \remark 虽然实现通常使用 POSIX 时间实现 `time_t`，但实际上 C 标准没有限定其实现方式。
 *
 * \sa ["Unix time"](https://wikipedia.org/wiki/Unix_time). *Wikipedia*.
 * \sa ["what is the difference between difftime and '-'?"](https://stackoverflow.com/questions/13855890/). *Stack Overflow*.
 */
START_TEST(tf_time_t)
{
    /* 获取当前系统时间 */
    const time_t t1 = time(NULL);
    ck_assert(t1 != -1);

    /* 另一种书写风格 */
    time_t t2;
    time(&t2);
    ck_assert(t2 != -1);

    /* 俩时间之差，以秒为单位 */
    const double inr = difftime(t2, t1);
    (void)inr;
}
END_TEST;

/**
 * \brief 时间结构体
 * \details 可读的时间结构体。
 */
START_TEST(tf_struct_tm)
{
    /* 设置时间结构体，将其重整并返回对应的 POSIX 时间 */
    struct tm love;
    memset(&love, 0x00, sizeof love);
    love.tm_year = 1992 - 1900;
    love.tm_mon = 6 - 1;
    love.tm_mday = 25;
    const time_t to = mktime(&love);

    /* 获取当前时间，并转换为对应的时间结构体，值为协调世界时 */
    const time_t t1 = time(NULL);
    struct tm t1s;
    gmtime_s(&t1s, &t1);

    /* 获取当前时间，并转换为对应的时间结构体，值为本地时 */
    const time_t t2 = time(NULL);
    struct tm t2s;
    localtime_s(&t2s, &t2);

    /* 时间结构体转换为字符串 */
    char buf1[20];
    strftime(buf1, countof(buf1), "%Y-%m-%dT%H:%M:%S", &t1s);
    printf("t1: %s\n", buf1);

    /* 或者简单地 */
    char buf2[26];
    asctime_s(buf2, countof(buf2), &t2s);
    printf("t2: %s", buf2);

    /* 又或 */
    char buf3[26];
    ctime_s(buf3, countof(buf3), &to);
    printf("to: %s", buf3);
}
END_TEST;

/**
 * \brief 时钟时间
 */
START_TEST(tf_clock_t)
{
    const clock_t start = clock();
    /* do something */
    const clock_t end = clock();
    const double costs_in_seconds = (start - end) / (double)CLOCKS_PER_SEC;

    (void)costs_in_seconds;
}
END_TEST;

/**
 * \brief 纳秒时间
 */
START_TEST(tf_timespec)
{
    struct timespec spec;
    timespec_get(&spec, TIME_UTC);
}
END_TEST;

/**
 * @}
 */

TCase *tc_chrono(void)
{
    TCase *const tc = tcase_create("chrono");
    tcase_add_test(tc, tf_struct_tm);
    tcase_add_test(tc, tf_time_t);
    tcase_add_test(tc, tf_clock_t);
    tcase_add_test(tc, tf_timespec);
    return tc;
}
